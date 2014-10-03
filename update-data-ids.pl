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

my @repeater_names = (sub {
	my @base_names = ( 'North', 'East', 'South', 'West' );
	my @tick_names = ( '1 Tick', '2 Tick', '3 Tick', '4 Tick' );
	
	my @names;
	
	for (my $i = 0; $i < scalar @base_names; $i++)
	{
		$names[$i] = $base_names[$i];
		for (my $j = 0; $j < scalar @tick_names; $j++)
		{
			$names[$i | (1 << (($j/2)+2))] = $base_names[$i] . ' ' . $tick_names[$j];
		}
	}
	
	return @names;
})->();

my @comparator_names = (sub {
	my @base_names = ( 'North', 'East', 'South', 'West' );
	my @names;
	
	for (my $i = 0; $i < scalar @base_names; $i++)
	{
		$names[$i] = $base_names[$i] . ' Comparison';
		$names[$i | 0x8] = $base_names[$i] . ' Comparison Powered';
		
		$names[$i | 0x4] = $base_names[$i] . ' Subtraction';
		$names[$i | 0x4 | 0x8] = $base_names[$i] . ' Subtraction Powered';
	}
	
	return @names;
})->();

our @button_names = (sub {
	my @base_names = ( undef, 'East', 'West', 'South', 'North', 'Up' );
	my @names;
	
	for (my $i = 1; $i < scalar @base_names; $i++)
	{
		$names[$i] = $base_names[$i];
		$names[$i | 0x8] = $base_names[$i].' Pressed';
	}
	
	return @names;
})->();

our @mushroom_names = ( 'Pores', 'Cap T+W+N', 'Cap T+N', 'Cap T+N+E', 'Cap T+W', 'Cap T', 'Cap T+E', 'Cap T+S+W', 'Cap T+S', 'Cap T+E+S', 'Stem + Pores T+B', undef, undef, undef, 'Cap All', 'Stem All' );

our @door_names = (sub {
	my @names;
	my @bottom_names = ( 'West', 'North', 'East', 'South' );
	my @top_names = ( 'Right', 'Left' );
	
	# bottom
	
	for (my $i = 0; $i < scalar @bottom_names; $i++)
	{
		$names[$i] = 'Bottom ' . $bottom_names[$i] . ' Closed';
		$names[$i | 0x4] = 'Bottom ' . $bottom_names[$i] . ' Open';
	}
	
	# top
	for (my $i = 0; $i < scalar @top_names; $i++)
	{
		$names[$i | 0x8] = 'Top ' . $top_names[$i];
	}
	
	return @names;
})->();

our @stairs_names = (sub {
	my @base_names = ( 'East', 'West', 'South', 'North' );
	my @names;
	for (my $i = 0; $i < scalar @base_names; $i++)
	{
		$names[$i | 0x4] = $base_names[$i] . ' Upside Down';
	}
	
	return @names;
})->();
	
our @tree_names = ( 'Oak', 'Spruce', 'Birch', 'Jungle', 'Acacia', 'Dark Oak' );
our @color_names = ( 'Regular', 'Orange', 'Magenta', 'Light Blue', 'Yellow', 'Lime', 'Pink', 'Gray', 'Light Gray', 'Cyan', 'Purple', 'Blue', 'Green', 'Red', 'Black' );

our %metadata = (
	'sand' => [ 'Sand', 'Red Sand' ],
	'planks' => \@tree_names,
	'sapling' => \@tree_names,
	'log' => [ 'Oak', 'Spruce', 'Birch', 'Jungle', 'Oak E/W', 'Spruce E/W', 'Birch E/W', 'Jungle E/W', 'Oak N/S', 'Spruce N/S', 'Birch N/S', 'Jungle N/S', 'Oak Bark', 'Spruce Bark', 'Birch Bark', 'Jungle Bark' ],
	'log2' => [ 'Acacia', 'Dark Oak', 'Acacia PH', 'Dark Oak PH', 'Acacia E/W', 'Dark Oak E/W', 'Acacia E/W PH', 'Dark Oak E/W PH', 'Acacia N/S', 'Dark Oak N/S', 'Acacia N/S PH', 'Dark Oak N/S PH', 'Acacia Bark', 'Dark Oak Bark', 'Acacia Bark PH', 'Dark Oak Bark PH' ],
	'leaves' => [ 'Oak', 'Pine/Spruce', 'Birch', 'Jungle' ],
	'leaves2' => [ 'Acacia', 'Dark Oak' ],
	'wool' => \@color_names,
	'carpet' => \@color_names,
	'stained_hardened_clay' => \@color_names,
	'stained_glass' => \@color_names,
	'stained_glass_pane' => \@color_names,
	'torch' => [ 'Floor', 'East', 'West', 'South', 'North' ],
	'stone_slab' => [ 'Stone', 'Sandstone', 'Wood', 'Cobblestone', 'Brick', 'Stone Brick', 'Nether Brick', 'Quartz', 'Stone Double', 'Sandstone Double', undef, undef, undef, undef, undef, 'Quartz Double' ],
	'double_stone_slab' => [ 'Stone', 'Sandstone', 'Wood', 'Cobblestone', 'Brick', 'Stone Brick', 'Nether Brick', 'Quartz', 'Stone Double', 'Sandstone Double', undef, undef, undef, undef, undef, 'Quartz Double' ],
	'wooden_slab' => [ 'Oak', 'Spruce', 'Birch', 'Jungle', 'Acacia', 'Dark Oak', undef, undef, undef, 'Oak Top', 'Spruce Top', 'Birch Top', 'Jungle Top', 'Acacia Top', 'Dark Oak Top' ],
	'double_wooden_slab' => [ 'Oak', 'Spruce', 'Birch', 'Jungle', 'Acacia', 'Dark Oak', undef, undef, undef, 'Oak Top', 'Spruce Top', 'Birch Top', 'Jungle Top', 'Acacia Top', 'Dark Oak Top' ],
	'sandstone' => [ 'Normal', 'Chiseled', 'Smooth' ],
	'bed' => (sub {
		my @base_names = ( 'South', 'West', 'North', 'East' );
		my @names = @base_names;
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i | 0x4] = $base_names[$i] . ' Occupied';
			$names[$i | 0x8] = $base_names[$i] . ' Head';
			$names[$i | 0x4 | 0x8] = $base_names[$i] . ' Occupied Head';
		}
		
		return \@names;
	})->(),
	'grass' => [ 'Shrub', 'Grass', 'Fern', 'Shrub2' ],
	'yellow_flower' => [ 'Dandelion' ],
	'red_flower' => [ 'Poppy', 'Blue Orchid', 'Allium', 'Azure Bluet', 'Red Tulip', 'White Tulip', 'Pink Tulip', 'Oxeye Daisy' ],
	'double_plant' => (sub {
		my @base_names = ( 'Sunflower', 'Lilac', 'Double Tallgrass', 'Large Fern', 'Rose Bush', 'Peony' );
		my @names = @base_names;
		for (my $i = 0x8; $i < scalar @base_names; $i++)
		{
			$names[$i] = $base_names[$i] . ' Top';
		}
		
		return \@names;
	})->(),
	'piston' => (sub {
		my @base_names = ( 'Down', 'Up', 'North', 'South', 'West', 'East' );
		my @names = @base_names;
			for (my $i = 0; $i < scalar @base_names; $i++)
			{
				$names[$i | 0x8] = $base_names[$i] . ' Extended';
			}
			
			return \@names;
	})->(),
	'piston_extension' => (sub {
		my @base_names = ( 'Down', 'Up', 'North', 'South', 'West', 'East' );
		my @names = @base_names;
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i | 0x8] = $base_names[$i] . ' Sticky';
		}
		
		return \@names;
	})->(),
	'stairs' => \@stairs_names,
	'stone_stairs' => \@stairs_names,
	'brick_stairs' => \@stairs_names,
	'stone_brick_stairs' => \@stairs_names,
	'nether_brick_stairs' => \@stairs_names,
	'quartz_stairs' => \@stairs_names,
	'acacia_stairs' => \@stairs_names,
	'dark_oak_stairs' => \@stairs_names,
	'oak_stairs' => \@stairs_names,
	'spruce_stairs' => \@stairs_names,
	'birch_stairs' => \@stairs_names,
	'jungle_stairs' => \@stairs_names,
	'sandstone_stairs' => \@stairs_names,
	'redstone_wire' => (sub {
		my @names = map { $_ } 0 .. 0xF;
		return \@names;
	})->(),
	'crops' => [ 0, 1, 2, 3, 4, 5, 6, 7 ],
	'farmland' => [ 'dry', map { 'wet '.$_ } 0x1 .. 0x8 ],
	'standing_sign' => [ 'South', 'South-Southwest', 'Southwest', 'West-Southwest', 'West', 'West-Northwest', 'Northwest', 'North-Northwest', 'North', 'North-Northeast', 'Northeast', 'East-Northeast', 'East', 'East-Southeast', 'Southeast', 'South-Southeast' ],
	'wooden_door' => \@door_names,
	'iron_door' => \@door_names,
	'rail' => [ 'Flat N/S', 'Flat E/W', 'Asc East', 'Asc West', 'Asc North', 'Asc South', 'Corner N/W', 'Corner N/E', 'Corner S/E', 'Corner S/W' ],
	'golden_rail' => (sub {
		my @base_names = ( 'Flat N/S', 'Flat E/W', 'Asc East', 'Asc West', 'Asc North', 'Asc South', 'Corner N/W', 'Corner N/E', 'Corner S/E', 'Corner S/W' );
		my @names = @base_names;
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i | 0x8] = $base_names[$i] . ' Powered';
		}
		
		return \@names;
	})->(),
	'ladder' => [ undef, undef, 'North', 'South', 'West', 'East' ],
	'wall_sign' => [ undef, undef, 'North', 'South', 'West', 'East' ],
	'furnace' => [ undef, undef, 'North', 'South', 'West', 'East' ],
	'lit_furnace' => [ undef, undef, 'North', 'South', 'West', 'East' ],
	'chest' => [ undef, undef, 'North', 'South', 'West', 'East' ],
	'ender_chest' => [ undef, undef, 'North', 'South', 'West', 'East' ],
	'trapped_chest' => [ undef, undef, 'North', 'South', 'West', 'East' ],
	'dispenser' => [ 'Down', 'Up', 'North', 'South', 'West', 'East' ],
	'dropper' => [ 'Down', 'Up', 'North', 'South', 'West', 'East' ],
	'hopper' => [ 'Down', 'Up', 'North', 'South', 'West', 'East' ],
	'lever' => (sub {
		my @base_names = ( 'Ceiling East', 'East', 'West', 'South', 'North', 'Ground South', 'Ground East', 'Ceiling South' );
		my @names;
		
		for(my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i] = $base_names[$i] . ' Off';
			$names[$i | 0x8] = $base_names[$i] . ' On';
		}
		
		return \@names;
	})->(),
	'stone_pressure_plate' => [ undef, 'Pressed' ],
	'wooden_pressure_plate' => [ undef, 'Pressed' ] ,
	'light_weighted_pressure_plate' => [ undef, 'Pressed' ],
	'heavy_weighted_pressure_plate' => [ undef, 'Pressed' ],
	'stone_button' => \@button_names,
	'wooden_button' => \@button_names,
	'snow_layer' => [ 0, 1, 2, 3, 4, 5, 6, 7 ],
	'cactus' => [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ],
	'reeds' => [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ],
	'jukebox' => [ 'Empty', '13', 'Cat', 'Blocks', 'Chirp', 'Far', 'Mall', 'Mellohi', 'Stal', 'Strad', 'Ward', '11', 'wait' ],
	'pumpkin' => [ 'South', 'West', 'North', 'East', '' ],
	'lit_pumpkin' => [ 'South', 'West', 'North', 'East', '' ],
	'cake' => [ 0, 1, 2, 3, 4, 5 ],
	'unpowered_repeater' => \@repeater_names,
	'powered_repeater' => \@repeater_names,
	'unpowered_comparator' => \@comparator_names,
	'powered_comparator' => \@comparator_names, # this block is not used post 1.5
	'trapdoor' => (sub {
		my @base_names = ( 'South', 'North', 'East', 'West' );
		my @names;
		
		for(my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i] = $base_names[$i] . ' Closed Bottom';
			$names[$i | 0x8] = $base_names[$i] . ' Closed Top';
			
			$names[$i | 0x4] = $base_names[$i] . ' Open Bottom';
			$names[$i | 0x4 | 0x8] = $base_names[$i] . ' Open Top';
		}
		
		return \@names;
	})->(),
	
	'monster_egg' => [ 'Stone', 'Cobblestone', 'Stone Brick', 'Mossy Stone Brick', 'Cracked Stone Brick', 'Chiseled Stone Brick' ],
	'stonebrick' => [ 'Stone', 'Mossy', 'Cracked', 'Chiseled' ],
	'brown_mushroom_block' => \@mushroom_names,
	'red_mushroom_block' => \@mushroom_names,
	'pumpkin_stem' => [ 0, 1, 2, 3, 4, 5, 6, 7 ],
	'melon_stem' => [ 0, 1, 2, 3, 4, 5, 6, 7 ],
	'vine' => (sub {
		my @base_names = ( 'S', 'W', 'N', 'E' );
		my @names;
		
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			my $base = $base_names[$i];
			$names[1 << ($i+1)] = $base;
			for (my $j = 0; $j < scalar @base_names; $j++)
			{
				next if $i == $j;
				$base .= '+' . $base_names[$j];
				$names[1 << ($i+1) | 1 << ($j+1)] = $base;
			}
		}
		
		return \@names;
	})->(),
	'fence_gate' => (sub {
		my @base_names = ( 'South', 'West', 'North', 'East' );
		my @names;
		
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i] = $base_names[$i] . ' Closed';
			$names[$i | 0x4] = $base_names[$i] . ' Open';
		}
		
		return \@names;
	})->(),
	'nether_wart' => [ 0, 1, 2, 3 ],
	'brewing_stand' => (sub {
		my @base_names = ( 'E', 'SW', 'NW' );
		my @names;
		
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			my $base = $base_names[$i];
			$names[1 << ($i+1)] = $base;
			for (my $j = 0; $j < scalar @base_names; $j++)
			{
				next if $i == $j;
				$base .= '+' . $base_names[$j];
				$names[1 << ($i+1) | 1 << ($j+1)] = $base;
			}
		}
		
		return \@names;
	})->(),
	'cauldron' => [ 'Empty', '1/3', '2/3', 'Full' ],
	'end_portal_frame' => (sub {
		my @base_names = ( 'South', 'West', 'North', 'East' );
		my @names;
		
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i] = $base_names[$i].' Empty';
			$names[$i | 0x4] = $base_names[$i].' Full';
		}
		
		return \@names;
	})->(),
	'cocoa' => (sub {
		my @base_names = ( 'North', 'East', 'South', 'West' );
		my @size_names = ( 'Small', 'Medium', 'Large', 'EX' );
		my @names;
		
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i] = $base_names[$i] . ' ' . $size_names[0];
			$names[$i | 0x4] = $base_names[$i] . ' ' . $size_names[1];
			$names[$i | 0x8] = $base_names[$i] . ' ' . $size_names[2];
			$names[$i | 0x4 | 0x8] = $base_names[$i] . ' ' . $size_names[3];
		}
		
		return \@names;
	})->(),
	'tripwire_hook' => (sub {
		my @base_names = ( 'South', 'West', 'North', 'East' );
		my @size_names = ( 'NC', 'C', 'A', 'CA' );
		my @names;
		
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i] = $base_names[$i] . ' ' . $size_names[0];
			$names[$i | 0x4] = $base_names[$i] . ' ' . $size_names[1];
			$names[$i | 0x8] = $base_names[$i] . ' ' . $size_names[2];
			$names[$i | 0x4 | 0x8] = $base_names[$i] . ' ' . $size_names[3];
		}
		
		return \@names;
	})->(),
	'tripwire' => (sub {
		my @names;
		
		$names[0] = 'UA';
		$names[1 << 0x4] = 'FA';
		$names[1 << 0x1] = 'LA';
		
		return \@names;
	})->(),
	'cobblestone_wall' => [ 'Plain', 'Mossy' ],
	'flower_pot' => [ 'Empty', 'Poppy', 'Dandelion', 'Oak', 'Spruce', 'Birch', 'Jungle', 'Red Mushroom', 'Brown Mushroom', 'Cactus', 'Dead Bush', 'Fern', 'Acacia', 'Dark Oak' ], # only for pre 1.7?
	'skull' => [ undef, 'Floor', 'North', 'South', 'East', 'West' ],
	'quartz_block' => [ 'Plain', 'Chiseled', 'Vertical Pillar', 'N/S Pillar', 'E/W Pillar' ],
	'coal_ore' => [ 'Coal', 'Charcoal' ],
	'dye' => [ 'Ink Sac', 'Rose Red', 'Cactus Green', 'Cocoa Beans', 'Lapis Lazuli', 'Purple Dye', 'Cyan Dye', 'Light Gray Dye', 'Gray Dye', 'Pink Dye', 'Lime Dye', 'Dandelion Yellow', 'Light Blue Dye', 'Magenta Dye', 'Orange Dye', 'Bone Meal' ],
	'fish' => [ 'Fish', 'Salmon', 'Clownfish', 'Pufferfish' ],
	'anvil' => (sub {
		my @base_names = ( 'North-South', 'East-West' );
		my @damage_names = ( 'No', 'Slightly', 'Very' );
		my @names;
		
		for (my $i = 0; $i < scalar @base_names; $i++)
		{
			$names[$i] = $base_names[$i] . ' ' . $damage_names[0] . ' Damage';
			$names[$i | 0x4] = $base_names[$i] . ' ' . $damage_names[1] . ' Damaged';
			$names[$i | 0x8] = $base_names[$i] . ' ' . $damage_names[2] . ' Damaged';
		}
		
		return \@names;
	})->()
);

#$::RD_HINT = 1; # Parse::RecDescent hints
#$::RD_TRACE = 1; # Parse::RecDescent trace

if(scalar @ARGV < 1)
{
	say "Usage: $0 <path/to/Block.java> <output dir>\n";
	exit -1;
}

our $block_java_path = $ARGV[0];

our $file_dir = $ARGV[1];
our $src_file_name = catfile($file_dir, 'src/BlockMaps.cpp');
our $hdr_file_name = catfile($file_dir, 'include/BlockMaps.h');

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
say $hdr_fh "extern const char *BlockTexNames[BLOCK_COUNT];";

say $src_fh "#include \"BlockMaps.h\"\n";
say $src_fh "const char *BlockNames[BLOCK_COUNT] = {";
for(my $i = 0; $i < scalar(@$blocks); $i++)
{
	#next unless defined $blocks->[$i];
	my $name = defined $blocks->[$i] ? readable_name($blocks->[$i]{'name'}) : '';
	say $src_fh "\t\"".$name."\", // $i";
}
say $src_fh "};\n";

say $src_fh "const char *BlockTexNames[BLOCK_COUNT] = {";
for(my $i = 0; $i < scalar(@$blocks); $i++)
{
	#next unless defined $blocks->[$i];
	my $name = (defined $blocks->[$i] &&
					exists $blocks->[$i]{'props'} &&
					exists $blocks->[$i]{'props'}{'BlockTextureName'}) ?
		$blocks->[$i]{'props'}{'BlockTextureName'} : '';
	say $src_fh "\t\"".$name."\", // $i";
}
say $src_fh "};\n";

say $hdr_fh "struct SubBlockRange { uint32_t start; uint32_t num; };";
say $hdr_fh "extern SubBlockRange subBlockRange[BLOCK_COUNT];";

say $src_fh "SubBlockRange subBlockRange[BLOCK_COUNT] = {";
our @subblock_names;
our $subblock_pos = 0;
for (my $i = 0; $i < scalar(@$blocks); $i++)
{
	if(!defined $blocks->[$i])
	{
		say $src_fh "\t{ 0, 0 },";
		next;
	}
	
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
	next unless defined $block;
	say dump($block);
	my $name = uc define_name($block->{'name'});
	say $hdr_fh "#define BLOCK_$name ".$block->{'id'};
	
	if(exists $block->{'types'})
	{
		for(my $i = 0; $i < scalar(@{$block->{'types'}}); $i++)
		{
			next unless defined $block->{'types'}[$i];
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
	next unless defined $info;
	my $name = defined $info->{'name'} ? readable_name($info->{'name'}) : '';
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
	
	my $var_tree = undef;
	
	for my $line (<$fh>)
	{
		chomp $line;
		next if $line eq '';
		
		#next if $line !~ /\s*public static final Block/;
		
		if($line =~ /^\s*blockRegistry\.addObject\((\d+),\s*"(\w+)",\s*(.*)\);$/)
		#if($line =~ /^\s*public static final Block\w*\s+(\w+)\s*=\s*(.*)$/)
		#if($line =~ /^\s*public static final Block\w*\s+(\w+)\s*=\s*(?:\([^)]+\))?\(new\s+(Block\w*)\s*\((\d+).*setUnlocalizedName\(\"([^"]+)\"\)/)
		{
		
			my $text = $line;
			my $tree = $block_parser->statement($text);
			say "reg: ".$text;
			
			exit(1) unless defined $tree;

			if (scalar @$tree == 1)
			{
				$tree = $tree->[0];
			}
			
			if (defined $var_tree)
			{
				pop @{$tree}; # remove varX
				push @{$tree}, @$var_tree;
				#$tree->[3] = $var_tree;
				$var_tree = undef;
			}
			
			say "full tree: ".dump($tree);
			
			my $block = build_block($2, $tree);
			say "built block: " . dump($block);
			$blocks[$block->{'id'}] = $block;
		#	say "got $1 $2 $3";
		}
		elsif($line =~ /^\s*Block\s+\w+\d+\s*=\s*(.*)$/)
		{
			my $tree = $block_parser->statement($1);
			say "var: ".$1;
			say "var tree: ".dump($tree);
			exit(1) unless defined $tree;
			if (ref $tree->[0] && $tree->[0][0] =~ /^Block\w*$/)
			{
				$var_tree = $tree;
			}
		}
		else
		{
			#say "didn't match: $line";
		}
	}
	
	return \@blocks;
}

sub define_name
{
	my $name = ucfirst(shift);
	$name =~ s|[/\+]||g;
	$name =~ s/[\s_-]+/_/g;
	
	if($name =~ /Slab/)
	{
		$name =~ s/Stone//;
		$name = lcfirst($name);
	}
	
	if($name ne 'Waterlily' && $name !~ /^(?:MushroomCap|Blocks)/)
	{
		$name =~ s/^(block|torch|plant|rail|ore|lava|water|door|stairs|mushroom)(.*)/$2$1/i; 
	}
	
	#$name =~ s/[A-Z][a-z]*+(?!\W)\K/_/gx;
	$name =~ s/^(.*)_$/$1/;
	#chop $name
	
	my $is_block = 0;
	if($name =~ /^block\b/i)
	{
		$name =~ s/^block_(.*)/${1}/i;
		$is_block = 1;
	}
	
	$name .= '_BLOCK' if $is_block;
	
	return $name;
}

sub readable_name
{
	my $name = shift;
	
	$name =~ s/_/ /g;
	$name = join(' ', map { ucfirst } split(' ', $name));
	
	if($name =~ /Slab/)
	{
		$name =~ s/^Stone //;
	}
	
	if($name ne 'Waterlily' && $name !~ /^MushroomCap/)
	{
		$name =~ s/^(block|torch|plant|rail|ore|lava|water|door|stairs|mushroom)(.*)/$2$1/i; 
	}
	
	#$name =~ s/[A-Z][a-z]*+(?!\W)\K/ /gx;
	#chop $name;
	
	return $name;
}

sub build_block
{
	my $name = shift;
	my $arr = shift;
	
	say "block: ".$name;
	$name = 'wool' if $name eq 'cloth';
	
	my %block = (
		name => $name,
		class => $arr->[3][0],
		id => $arr->[1],
		props => {}
	);
	
	if(!defined $block{'id'})
	{
		$block{'id'} = get_block_id($arr->[3][0]);
	}
	
	for (my $i = 1; $i < scalar(@$arr); $i++)
	{
		if(ref($arr->[$i]) eq 'ARRAY' && $arr->[$i][0] =~ /^set(\w+)/)
		{
			$block{'props'}{$1} = $arr->[$i][1];
			say("matched prop: ref:'".ref($arr->[$i])."' ".((ref($arr->[$i]) eq 'ARRAY') ? ' 0:'.$arr->[$i][0] : '')." ".$arr->[$i]);
		}
		else {
			say("unmatched prop? ref:'".ref($arr->[$i])."' ".((ref($arr->[$i]) eq 'ARRAY') ? ' 0:'.$arr->[$i][0] : '')." ".$arr->[$i]);
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
		my $types = get_block_types($name);
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
	my $name = shift;
	
	return exists $metadata{$name} ?  $metadata{$name} : [];
}

sub get_block_types_old
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

# blockRegistry.addObject(3, "dirt", (new BlockDirt()).setHardness(0.5F).setStepSound(soundTypeGravel).setBlockName("dirt").setBlockTextureName("dirt"));
# Block var0 = (new Block(Material.rock)).setHardness(2.0F).setResistance(10.0F).setStepSound(soundTypePiston).setBlockName("stonebrick").setCreativeTab(CreativeTabs.tabBlock).setBlockTextureName("cobblestone");
# blockRegistry.addObject(4, "cobblestone", var0);
# Block var1 = (new BlockWood()).setHardness(2.0F).setResistance(5.0F).setStepSound(soundTypeWood).setBlockName("wood").setBlockTextureName("planks");

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
dotlist: sub_statement(s /./) { if(scalar @item > 3) { $return = [@item[1 .. $#item]]; } else { $return = $item[1]; } }
cast_statement: '(' identifier ')' { $return = $item[2]; }
group_statement: '(' new_obj ')' { $return = $item[2]; }
func_call: identifier list { $return = [ $item[1], @{$item[2]} ]; }

sub_statement: group_statement | new_obj | func_call | identifier | string | number

statement: func_call | dotlist | cast_statement dotlist { $return = $item[2] } | new_obj

EOG

	return new Parse::RecDescent ($grammar) or die "Bad grammar!\n";
}