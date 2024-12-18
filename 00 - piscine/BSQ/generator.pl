#!/usr/bin/perl
use warnings;
use strict;
open(FICHIER, ">stock.txt");
die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print FICHIER "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print FICHIER "o";
        }
        else {
            print FICHIER ".";
        }
}
print FICHIER "\n";
}
close(FICHIER);
