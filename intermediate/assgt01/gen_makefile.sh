#!/bin/bash
# Configure these:
cc="g++"
cflags="-g -Wall -O3 -std=c++2a"
target="unittests"

# Generate line of object files:
objs=$(ls *.cpp | tr '\n' ' ' | sed -e 's/\.cpp/\.o/g')

# Generate makefile content:
# Define macros:
printf "CC = %s\n" "${cc}"
printf "CFLAGS = %s\n\n" "${cflags}"

# Define default build target:
printf "default: %s\n\n" "${target}"

# Define target and object file dependencies:
printf "%s: %s\n" "${target}" "${objs}"
printf '\t$(CC) $(CFLAGS) -o %s %s\n\n'  "${target}" "${objs}"

# Define target and dependencies for source files:
for f in $(ls *.cpp)
do
  echo "$(${cc} -MM ${f})"
  printf '\t$(CC) $(CFLAGS) -c %s\n' "${f}" 
  echo
done

# Define clean target:
printf "\nclean:\n"
printf '\t$(RM) %s *.o\n\n' "${target}"
