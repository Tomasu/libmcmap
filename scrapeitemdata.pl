#!/usr/bin/perl

use v5.10;
use strict;
use warnings;

use pQuery;
use LWP::Simple;
use Data::Dump qw/dump/;

our @blocks;
our @items;
our @potions;
our %data;

our $url = 'http://www.minecraftwiki.net/wiki/Data_values';
our $res = mirror($url, 'itemdata.html');
if($res < 200 || $res > 399)
{
	die "failed to download item data :( ".$res;
}

our $pq = pQuery('itemdata.html');
our $tables = $pq->find('table');

for my $e (map { pQuery($_) } @$tables)
{
	if(matchHeader($e, 'Icon', 'Dec', 'Hex', 'Block type'))
	{
		processTable($e, \@blocks);
	}
	elsif(matchHeader($e, 'Icon', 'Dec', 'Hex', 'Item'))
	{
		processTable($e, \@items);
	}
	elsif(matchHeader($e, 'Dec', 'Hex', 'Potion'))
	{
		processPotionsTable($e, \@potions);
	}
	elsif(matchHeader($e, 'Block', 'dec', 'hex', 'Use'))
	{
		processDataTable($e);
	}
	#elsif(matchHeader($e, 'Icon', 'Value', 'Description'))
	#{
	#	process
	#}
}

for my $block (@blocks)
{
	#say "block[".$block->{'id'}."]: ".$block->{'name'};
}

for my $item (grep { defined $_ } @items)
{
	#say "item[".$item->{'id'}."]: ".$item->{'name'};
}

for my $pot (@potions)
{
	#say "potion[".$pot->{'id'}."]: ".$pot->{'name'};
}

for my $dat (keys %data)
{
	say "data[".$data{$dat}{'name'}."]: ".$data{$dat}{'range'};
	processSubData($data{$dat});
}

sub matchHeader
{
	my $table = shift;
	my @to_match = @_;

	my $headers = $table->find('tr')->eq(0)->find('th');
	return 0 if scalar @to_match != scalar @$headers;

	#say "comparing: ".join(',',@to_match)." against: ".join(',',map { pQuery($_)->text } @$headers);
	for (my $i = 0; $i < scalar @to_match; $i++)
	{
		return 0 if $to_match[$i] ne pQuery($headers->[$i])->text();
	}

	return 1;
}

sub processTable
{
	my $table = shift;
	my $ref = shift;

	my $rows = $table->find('tr');

	for my $row (map { pQuery($_) } @$rows)
	{
		my $pq = $row->find('td');
		next if !scalar(@$pq);

		my @cells = map { pQuery($_)->text } @$pq;
		shift @cells;

		$cells[2] =~ s/\b[DBTI\s]+\b$//;
		#say "row: ".join(', ', @cells);
		$ref->[$cells[0]] = { 'name' => $cells[2], 'id' => $cells[0] };
	}
}

sub processPotionsTable
{
	my $table = shift;
	my $ref = shift;

	my @first_col = map { pQuery($_)->text } @{$table->find('tr th')};

	shift @first_col;
	shift @first_col;
	shift @first_col;

	my $rows = $table->find('tr');

	for(my $i = 0; $i < scalar @first_col; $i++)
	{
		my @cells = map { pQuery($_)->text } @{pQuery($rows->[$i+1])->find('td')};
		$ref->[$first_col[$i]] = { 'id' => $first_col[$i], 'name' => $cells[1] };
	}
}

sub processDataTable
{
	my $table = shift;

	my $rows = $table->find('tr');

	for my $row (map { pQuery($_) } @$rows)
	{
		my $pq = $row->find('td');
		next if !scalar(@$pq);

		my $id = $pq->get(0)->firstChild()->getAttribute('href');
		if($id !~ /^#/)
		{
			say "skipping $id";
			next;
		}

		# remove leading #
		substr($id, 0, 1, '');

		say "id: ".$id;

		my @cells = map { pQuery($_)->text } @$pq;

		##say "row: ".join(', ', @cells);
		$data{$id} = { 'name' => $id, 'range' => $cells[1], 'use' => $cells[3] };
		#$ref->[$cells[0]] = { 'name' => $cells[2], 'id' => $cells[0] };
	}
}

# CHANGE: grab the D tag from the block/item tables and link it to the data fetched here.
sub processSubData
{
	my $dat = shift;

	my $header = $pq->find('#'.$dat->{'name'});
	if(!$header->length)
	{
#		say $dat->{'name'}." not found!";
		return;
	}

	# find the next unordered list or table
	my $node = $header->get(0)->parentNode->nextSiblingRef;
	while($node->tagName ne 'UL' && $node->tagName ne 'TABLE')
	{
		$node = $node->nextSiblingRef;
	}

	if($node->tagName eq 'UL')
	{
		processSubDataList($node);
	}
	elsif($node->tagName eq 'TABLE')
	{
		processSubDataTable($node);
	}
}

sub processSubDataList
{
	my $node = shift;

	my $items = pQuery($node)->find('li');
	for my $item (@$items)
	{
		say "item: ".$item->innerHTML;
	}
}

sub processSubDataTable
{

}
