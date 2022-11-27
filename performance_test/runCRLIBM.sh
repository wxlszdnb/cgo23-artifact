#!/bin/bash
echo -e "Run CRLIBM"
cd crlibm
make clean
make
echo "taskset -c 2 ./log"
taskset -c 2 ./log
echo "taskset -c 2 ./log2"
taskset -c 2 ./log2
echo "taskset -c 2 ./log10"
taskset -c 2 ./log10
echo "taskset -c 2 ./exp"
taskset -c 2 ./exp

