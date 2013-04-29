#!/usr/bin/perl

use v5.10;
use strict;
use warnings;

use LWP::Simple;
use JSON;
use URI;
use IO::File;
use File::Spec::Functions;

if(scalar @ARGV < 1)
{
	say "Usage: $0 <output dir>\n";
	exit -1;
}

our @patches;
$patches[0] = "Air";
$patches[36] = "Block Moved By Piston";
$patches[26] = "Bed";
$patches[34] = "Piston Extension";
$patches[43] = "Double Slabs";
$patches[59] = "Wheat";
$patches[93] = "Repeater (off)";
$patches[94] = "Repeater (on)";

$patches[104] = "Pumpkin Stem";
$patches[105] = "Melon Stem";
$patches[115] = "Nether Wart";
$patches[117] = "Brewing Stand";
$patches[118] = "Cauldron";
$patches[119] = "End Portal";
$patches[120] = "End Portal Block";
$patches[123] = "Redstone Lamp (off)";
$patches[124] = "Redstone Lamp (on)";
$patches[125] = "Wooden Double Slab";
$patches[131] = "Tripwire Hook";
$patches[132] = "Tripwire";
$patches[140] = "Flower Pot";
$patches[141] = "Carrots";
$patches[142] = "Potatoes";
$patches[144] = "Mob Head";
#$patches[] = "";
#$patches[] = "";
#$patches[] = "";
#$patches[] = "";


our $file_dir = $ARGV[0];
our $src_file_name = catfile($file_dir, 'BlockMaps.cpp');
our $hdr_file_name = catfile($file_dir, 'BlockMaps.h');

our $src_fh = IO::File->new(">".$src_file_name) or die "failed to open $src_file_name for writing: $!";
our $hdr_fh = IO::File->new(">".$hdr_file_name) or die "failed to open $hdr_file_name for writing: $!";

our $key = '51342be4c0953';
our $request = 'itemdata';
our $base_url = 'http://api.mineverse.com/q.php';

our $url = URI->new($base_url);
$url->query_form(key => $key, request => $request);

say "url: $url";
our $json = get($url->as_string);

our $data = decode_json($json);
our @in_items;
map { $in_items[$_] = $data->{'items'}{$_} } keys %{$data->{"items"}};
our @out_items;
our @out_subitems;

use Data::Dump qw/dump/;
#say dump($in_items);

for (my $i = 0; $i < scalar(@in_items) && $i < 256; $i++)
{
	my $item = $in_items[$i];
	my $item_id = $i;
	
	if(exists $item->{'subitems'})
	{
		#say "got a compound item $i";
		for my $subitem (@{$item->{'subitems'}})
		{
			my $d_item_id = (($item_id << 4) | $subitem->{'d'});
			if(!defined $out_subitems[$item_id])
			{
				$out_subitems[$item_id] = [];
			}
			
			$out_subitems[$item_id][$subitem->{'d'}] = { 'id' => $item_id, 'data' => $subitem->{'d'}, 'd_item_id' => $d_item_id, 'name' => $subitem->{'itemname'} };
		}
	}
	if(defined $in_items[$i])
	{
		$out_items[$item_id] = { 'id' => $item_id, 'data' => 0, 'd_item_id' => $item_id, 'name' => $item->{'item_name'} };
	}
}

# fix air block
#$out_items[0] = { 'id' => 0, 'data' => 0, 'd_item_id' => 0, 'name' => 'Air' };

say $hdr_fh "#ifndef BLOCKMAPS_H_GUARD";
say $hdr_fh "#define BLOCKMAPS_H_GUARD\n";
say $hdr_fh "#include <cstdint>\n";
say $hdr_fh "#define BLOCK_COUNT ".scalar(@out_items);
say $hdr_fh "extern const char *BlockNames[BLOCK_COUNT];";

say $src_fh "#include \"BlockMaps.h\"\n";
say $src_fh "const char *BlockNames[BLOCK_COUNT] = {";
for(my $i = 0; $i < scalar(@out_items); $i++)
{
	my $real_name = defined $patches[$i] ? $patches[$i] : $out_items[$i]{'name'};

	if(!defined $real_name) # || defined $out_subitems[$i])
	{
		say $src_fh "\t0, // $i";
		next;
	}
	
	
	say $src_fh "\t\"".$real_name."\", // $i";
}
say $src_fh "};\n";

say $hdr_fh "struct SubBlockRange { uint32_t start; uint32_t num; };";
say $hdr_fh "extern SubBlockRange subBlockRange[BLOCK_COUNT];";

say $src_fh "SubBlockRange subBlockRange[BLOCK_COUNT] = {";
our @subblock_names;
our $subblock_pos = 0;
for (my $i = 0; $i < scalar(@out_items); $i++)
{
	my $block = $out_subitems[$i];
	if(!defined $block)
	{
		say $src_fh "\t{ 0, 0 },";
		next;
	}
	
	my $start = $subblock_pos;
	my $num = scalar(@$block);
	
	say $src_fh "\t{ $start, $num }, // ".$block->[0]{'id'};
	for my $subblock (@$block)
	{
		push @subblock_names, { 'name' => $subblock->{'name'}, 'id' => $subblock->{'id'}, 'data' => $subblock->{'data'} };
	}
	
	$subblock_pos += $num;
}

say $src_fh "};\n";

say $hdr_fh "#define SUBBLOCKNAME_COUNT ".scalar(@subblock_names);
say $hdr_fh "extern const char *SubBlockNames[SUBBLOCKNAME_COUNT];\n";
say $hdr_fh "#endif";

say $src_fh "const char *SubBlockNames[SUBBLOCKNAME_COUNT] = {";
for my $info (@subblock_names)
{
	my $name = $info->{'name'};
	my $id = $info->{'id'};
	my $d = $info->{'data'};
	
	say $src_fh "\t\"$name\", // $id:$d";
}
say $src_fh "};";
say "Done.";


$src_fh->close();
$hdr_fh->close();

