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
##     along with GSC.  If not, see <http://www.gnu.org/licenses/>.

my $LIBS  = "`sdl-config --cflags` `sdl-config --libs` -lSDL_net -lGL -lGLU";
my $FLAGS = "-Wall";

my @C_FILES = `find source/ -regex \".*.cpp\" -printf "%p\n"`;

$shared = 0;
$static = 0;

if ($^O eq 'linux') { system("clear"); }
elsif ($^O eq 'MSWin32') { system("cls"); }

sub check_bin {
	if ($^O eq 'linux') { `mkdir bin/` if not -d "bin"; } 
}

sub compile_file_linux ($$) {
	my $file_name = shift;
	my $out_name = shift;

	my $command = "g++ $FLAGS $file_name -c -o $out_name \n";
	print $command and `$command`;
}

sub shared {
	my $command = "g++ bin/*.o $FLAGS $LIBS -o GSC.so -shared\n";
	print $command and `$command`;
}

sub static {
	my $command = "ar rc libGSC.a bin/*.o\n";
	print $command and `$command`;
}

sub compile_linux {
	foreach $file (@C_FILES) {
		chomp $file; $file =~ m/.*\/(.*)\.cpp/;

		if (-f "bin/$1.o") {
			my $out_age  = -M "bin/$1.o";
			my $file_age = -M $file;

			compile_file_linux($file, "bin/$1.o") if ($out_age > $file_age);
		}

		else {  compile_file_linux($file, "bin/$1.o"); }
	}


	shared() if ($shared);
	static() if ($static);

	print "\nBuild complete!\n";
}

sub compile_files {
	compile_linux() if ($^O eq 'linux');
}

sub clean {
	if ($^O eq 'linux') { 
		my $command = "rm -rf bin GSC.so GSC.a\n";
		print $command and `$command`;
	}

	print "\nCleanup complete!\n";
}

while ((my $arg = shift(@ARGV))) {
	if    ($arg =~ "shared")   { $shared = 1; }
	elsif ($arg =~ "static")   { $static = 1; }
	elsif ($arg =~ "clean" )   { clean(); }
}

if ($shared or $static) {
	check_bin();
	compile_files();
}
