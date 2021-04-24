use strict;

my $srcExt = 'cpp';
my $cc = 'g++';
my $cflags = '-g -Wall';
my $default = 'unittests';
my $cc_cflags = '$(CC) $(CFLAGS)';

print "CC = $cc\n";
print "CFLAGS = $cflags\n\n";
print "default: $default\n\n";

my @targets = ();

# Identify the c/cpp source files:
my $srcTxtCmd = "ls *.$srcExt";
my $srcTxt = `$srcTxtCmd`;
my @srcs = split /\n/, $srcTxt;

# Create a space delimited line of source files:
my $srcFilesLine = join(' ', @srcs);

# Create a space delimited line of object files:
my $objFilesLine = $srcFilesLine;
$objFilesLine =~ s/\.$srcExt/.o/g;

print "$default: $objFilesLine\n";
print "\t$cc_cflags -o $default $objFilesLine\n\n";

# Create a build target from each source file, using dependency generation
# from gcc/g++.
for my $src (@srcs) {
  my $result = `g++ -MM $src`;
  push(@targets, $result);
}

foreach my $target (@targets) {
  print $target;
  my @tokens = split /\s+/, $target;
  my $srcFile = $tokens[1];
  print "\t$cc_cflags -c $srcFile\n\n";
}

# Print clean target:
print "clean:\n";
print "\t\$(RM) $default *.o\n";

