#!/usr/bin/perl

# MCP based

use v5.10;
use strict;
use warnings;

use LWP::Simple;
use JSON;
use URI;
use IO::File;
use File::Spec::Functions;
use Text::Balanced qw/extract_bracketed/;
use Parse::RecDescent;
use Data::Dump qw/dump/;

#$::RD_HINT = 1; # Parse::RecDescent hints
#$::RD_TRACE = 1; # Parse::RecDescent trace

if(scalar @ARGV < 1)
{
	say "Usage: $0 <path/to/Block.java> <output dir>\n";
	exit -1;
}

our $block_java_path = $ARGV[0];

our $file_dir = $ARGV[1];
our $src_file_name = catfile($file_dir, 'BlockMaps.cpp');
our $hdr_file_name = catfile($file_dir, 'BlockMaps.h');

our $blocks = load_blocks($block_java_path);
#dump($blocks);

#exit(0);

our $src_fh = IO::File->new(">".$src_file_name) or die "failed to open $src_file_name for writing: $!";
our $hdr_fh = IO::File->new(">".$hdr_file_name) or die "failed to open $hdr_file_name for writing: $!";

#say dump($in_items);

# fix air block
#$out_items[0] = { 'id' => 0, 'data' => 0, 'd_item_id' => 0, 'name' => 'Air' };

say $hdr_fh "#ifndef BLOCKMAPS_H_GUARD";
say $hdr_fh "#define BLOCKMAPS_H_GUARD\n";
say $hdr_fh "#include <cstdint>\n";
say $hdr_fh "#define BLOCK_COUNT ".scalar(@$blocks);
say $hdr_fh "extern const char *BlockNames[BLOCK_COUNT];";

say $src_fh "#include \"BlockMaps.h\"\n";
say $src_fh "const char *BlockNames[BLOCK_COUNT] = {";
for(my $i = 0; $i < scalar(@$blocks); $i++)
{
	say $src_fh "\t\"".readable_name($blocks->[$i]{'name'})."\", // $i";
}
say $src_fh "};\n";

say $hdr_fh "struct SubBlockRange { uint32_t start; uint32_t num; };";
say $hdr_fh "extern SubBlockRange subBlockRange[BLOCK_COUNT];";

say $src_fh "SubBlockRange subBlockRange[BLOCK_COUNT] = {";
our @subblock_names;
our $subblock_pos = 0;
for (my $i = 0; $i < scalar(@$blocks); $i++)
{
	my $block = exists $blocks->[$i]{'types'} ? $blocks->[$i]{'types'} : undef;
	if(!defined $block)
	{
		say $src_fh "\t{ 0, 0 },";
		next;
	}
	
	my $start = $subblock_pos;
	my $num = scalar(@$block);
	
	say $src_fh "\t{ $start, $num }, // ".$i;
	for(my $j = 0; $j < $num; $j++)
	{
		push @subblock_names, { 'name' => $block->[$j], 'id' => $i, 'data' => $j };
	}
	
	$subblock_pos += $num;
}

say $src_fh "};\n";

say $hdr_fh "#define SUBBLOCKNAME_COUNT ".scalar(@subblock_names);
say $hdr_fh "extern const char *SubBlockNames[SUBBLOCKNAME_COUNT];\n";

for my $block (@$blocks)
{
	my $name = uc define_name($block->{'name'});
	say $hdr_fh "#define BLOCK_$name ".$block->{'id'};
	
	if(exists $block->{'types'})
	{
		for(my $i = 0; $i < scalar(@{$block->{'types'}}); $i++)
		{
			my $sub_name = uc define_name($block->{'types'}[$i]);
			say $hdr_fh "#define BLOCK_${name}_DATA_${sub_name} $i"; 
		}
	}
}

say $hdr_fh "";

say $hdr_fh "#endif";

say $src_fh "const char *SubBlockNames[SUBBLOCKNAME_COUNT] = {";
for my $info (@subblock_names)
{
	my $name = readable_name($info->{'name'});
	my $id = $info->{'id'};
	my $d = $info->{'data'};
	
	say $src_fh "\t\"$name\", // $id:$d";
}
say $src_fh "};";
say "Done.";


$src_fh->close();
$hdr_fh->close();

sub load_blocks
{
	my $fn = shift;
	my $bn = catfile($fn, 'Block.java');
	my $fh = IO::File->new($bn) || die "failed to load $bn: $!";
	
	my $block_parser = make_block_parser();
	#my $text = q/(new BlockPressurePlateWeighted(147, "blockGold", Material.iron, 64)).setHardness(0.5F).setStepSound(soundWoodFootstep).setUnlocalizedName("weightedPlate_light");/;
	#my $tree = $block_parser->statement($text);
	#say $text;
	#dump($tree);
	#return;
	
	my @blocks;
	
	$blocks[0] = { id => 0, name => 'Air', class => 'BlockAir' };
	
	for my $line (<$fh>)
	{
		chomp $line;
		next if $line eq '';
		
		next if $line !~ /\s*public static final Block/;
		
		if($line =~ /^\s*public static final Block\w*\s+(\w+)\s*=\s*(.*)$/)
		#if($line =~ /^\s*public static final Block\w*\s+(\w+)\s*=\s*(?:\([^)]+\))?\(new\s+(Block\w*)\s*\((\d+).*setUnlocalizedName\(\"([^"]+)\"\)/)
		{
		
			my $text = $2;
			my $tree = $block_parser->statement($text);
			#say $text;
			#dump($tree);
			exit(1) unless defined $tree;

			my $block = build_block($1, $tree);
			#dump($block);
			$blocks[$block->{'id'}] = $block;
		#	say "got $1 $2 $3";
		}
		else
		{
#			say "didn't match: $line";
		}
	}
	
	return \@blocks;
}

sub define_name
{
	my $name = ucfirst(shift);
	
	if($name =~ /Slab/)
	{
		$name =~ s/Stone//;
		$name = lcfirst($name);
	}
	
	if($name ne 'Waterlily' && $name !~ /^MushroomCap/)
	{
		$name =~ s/^(block|torch|plant|rail|ore|lava|water|door|stairs|mushroom)(.*)/$2$1/i; 
	}
	
	$name =~ s/[A-Z][a-z]*+(?!\W)\K/_/gx;
	$name =~ s/^(.*)_$/$1/;
	#chop $name
	
	my $is_block = 0;
	if($name =~ /^block/i)
	{
		$name =~ s/^block_(.*)/${1}/i;
		$is_block = 1;
	}
	
	$name .= '_BLOCK' if $is_block;
	
	return $name;
}

sub readable_name
{
	my $name = ucfirst(shift);
	
	if($name =~ /Slab/)
	{
		$name =~ s/^Stone//;
	}
	
	if($name ne 'Waterlily' && $name !~ /^MushroomCap/)
	{
		$name =~ s/^(block|torch|plant|rail|ore|lava|water|door|stairs|mushroom)(.*)/$2$1/i; 
	}
	
	$name =~ s/[A-Z][a-z]*+(?!\W)\K/ /gx;
	chop $name;
	
	return $name;
}

sub build_block
{
	my $name = shift;
	my $arr = shift;
	
	$name = 'wool' if $name eq 'cloth';
	
	my %block = (
		name => $name,
		class => $arr->[0][0],
		id => $arr->[0][1][0],
		props => {}
	);
	
	if(!defined $block{'id'})
	{
		$block{'id'} = get_block_id($arr->[0][0]);
	}
	
	for (my $i = 1; $i < scalar(@$arr); $i++)
	{
		if($arr->[$i][0] =~ /^set(\w+)/)
		{
			$block{'props'}{$1} = $arr->[$i][1][0];
		}
	}
	
	# check for cloth
	if($block{'id'} == 35)
	{
		$block{'types'} = ['White', 'Orange', 'Magenta', 'Light Blue', 'Yellow',
								'Lime', 'Pink', 'Gray', 'Light Gray', 'Cyan', 'Purple',
								'Blue', 'Brown', 'Green', 'Red', 'Black'];
	}
	else
	{
		my $types = get_block_types($arr->[0][0]);
		if(defined $types)
		{
			$block{'types'} = $types;
		}
	}
	
	return \%block;
}

sub get_block_id
{
	my $class = shift;
	
	my $fn = catfile($block_java_path, $class.'.java');
	my $fh = IO::File->new($fn) || die "failed to load $fn: $!";
	
	local $/;
	my $text = <$fh>;
	my ($id) = ($text =~ /super\((\d+),[^)]+\)/);
	
	return $id;
}

sub get_block_types
{
	my $class = shift;
	
	my $fn = catfile($block_java_path, $class.'.java');
	my $fh = IO::File->new($fn) || die "failed to load $fn: $!";
	
	local $/;
	my $text = <$fh>;
	
	# public static final String[] blockStepTypes = new String[] {"stone", "sand", "wood", "cobble", "brick", "smoothStoneBrick", "netherBrick", "quartz"};
	if($text =~ /public static final String\[\] \w+Types? = new String\[\] {([^}]+)};/)
	{
		my @types = map { s/"//g; s/^ //g; $_ } split ',', $1;
		return \@types;
	}
	
	return;
}

# BlockPistonMoving pistonMoving = new BlockPistonMoving(36);
# Block lavaStill = (new BlockStationary(11, Material.lava)).setHardness(100.0F).setLightValue(1.0F).setUnlocalizedName("lava").disableStats();
# BlockFluid lavaMoving = (BlockFluid)(new BlockFlowing(10, Material.lava)).setHardness(0.0F).setLightValue(1.0F).setUnlocalizedName("lava").disableStats();

sub make_block_parser
{ # <autotree>
$::RD_AUTOACTION = q { $item[1] };
	my $grammar = <<'EOG';

integer: /\-?[0-9]+/ { $return = $item[1] }
float: /\-?[0-9]+\.[0-9]+F/ { $return = $item[1] }
number: float | integer
string: '"' /[^"]+/ '"' { $return = $item[2] }
identifier: /[a-zA-z_]+[a-zA-Z0-9_\.]*/ { $return = $item[1] }

new_obj: 'new' identifier list { $return = [@item[2 .. $#item]]; }
list: '(' sub_statement(s? /,/) ')' { if(scalar @item > 4) { $return = [@item[2 .. $#item-1]]; } else { $return = $item[2]; } }
dotlist: sub_statement(s /./) { if(scalar @item > 2) { $return = [@item[1 .. $#item]]; } else { $return = $item[1]; } }
cast_statement: '(' identifier ')' { $return = $item[2]; }
group_statement: '(' new_obj ')' { $return = $item[2]; }
func_call: identifier list { $return = [ $item[1], $item[2] ]; }

sub_statement: group_statement | new_obj | func_call | identifier | string | number

statement: dotlist ';' | cast_statement dotlist ';' { $return = $item[2] } | new_obj ';'

EOG

	return new Parse::RecDescent ($grammar) or die "Bad grammar!\n";
}