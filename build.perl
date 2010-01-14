#! /usr/bin/perl

##		Copyright (c) William Whitty 2010
##
##     This file is part of GSC. 
##
##     GSC is free software: you can redistribute it and/or modify
##     it under the terms of the GNU Lesser General Public License as published by
##     the Free Software Foundation, either version 3 of the License, or
##     (at your option) any later version.
##
##     GSC is distributed in the hope that it will be useful,
##     but WITHOUT ANY WARRANTY; without even the implied warranty of
##     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##     GNU Lesser General Public License for more details.
##
##     You should have received a copy of the GNU Lesser General Public License
##     along with GSC.  If not, see <http:##www.gnu.org/licenses/>.

my $FLAGS = "-lSDL -lGL -lGLU";
my $LIBS  = "-g -Wall";

sub shared {
	my $C_FILES = `find . -regex \".*.cpp\" -printf "%p "`;
	system("clear");
	my $command = "g++ $C_FILES $FLAGS $LIBS -o GSC.so -shared\n";
	print $command and system($command);
}

sub static {
	system("mkdir bin");

	my @C_FILES = `find . -regex ".*.cpp"`;
	system("clear");
	foreach (@C_FILES) {
		chop;
		m/.*\/(.*)\.cpp/;
		my $name = $1;

		my $command = "g++ $_ $FLAGS $LIBS -o bin/$name.o -c\n";
		print $command and system($command);
	}

	print "\nLinking . . .\n\n";
	my $command = "ar rc libGSC.a bin/*.o\n";
	print $command and system($command);
}

print "Usage: $0 <BUILD-TYPE>\nBUILD TYPES:\n\tshared - compile GSC into a shared library for dynamic runtime linking.
\tstatic - compile GSC into a static library for compilation linking.\n" and exit unless @ARGV;

while ((my $arg = shift(@ARGV))) {
	if ($arg =~ "shared")      { shared; }
	elsif ($arg =~ "static")   { static; }
}
