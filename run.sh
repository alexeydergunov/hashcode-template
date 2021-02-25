#!/bin/bash

set -e

g++ --std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align main.cpp 2>log_compile.txt
echo "Compilation completed"

# do nothing if exists
mkdir -p answers

# TODO add calls for all output files
./a.out  a  seed=sa c1=1 c2=2  2>log_a.txt
./a.out  b  seed=sb c1=3 c2=4  2>log_b.txt

echo "Running completed"

./pack.py
echo "Choosing best answers completed"
