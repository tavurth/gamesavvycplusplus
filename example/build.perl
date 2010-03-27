#! /usr/bin/perl

my $LIBS  = "-lSDL -lGL -lGLU";
my $FLAGS = "-Wall";

my @C_FILES = `find source/ -regex \".*.cpp\" -printf "%p\n"`;

die "Could not find any files for build\n" if not @C_FILES;

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

	my $command = "g++ bin/*.o $FLAGS $LIBS -o bin/main ../GSC/GSC.so && ./bin/main\n";
	print $command and system("$command");

	print "\nBuild complete!\n";
}

sub compile_files {
	compile_linux() if ($^O eq 'linux');
}

sub clean {
	if ($^O eq 'linux') { 
		my $command = "rm -rf bin\n";
		print $command and `$command`;
	}

	print "\nCleanup complete!\n";
}

while ((my $arg = shift(@ARGV))) {
	if ($arg =~ "clean" )   { clean() and exit(0); }
}

check_bin();
compile_files();
