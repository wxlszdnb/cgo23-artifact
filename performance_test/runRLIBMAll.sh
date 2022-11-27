#!/bin/bash
echo -e "Performance testing"
cd ../libm/
make clean
make
cd ../performance_test/rlibm
make clean
make
echo "taskset -c 2 ./log"
taskset -c 2 ./log
echo "taskset -c 2 ./log_estrin"
taskset -c 2 ./log_estrin
echo "taskset -c 2 ./log_estrin_fma"
taskset -c 2 ./log_estrin_fma
echo "taskset -c 2 ./log2"
taskset -c 2 ./log2
echo "taskset -c 2 ./log_adapt"
taskset -c 2 ./log2_adapt
echo "taskset -c 2 ./log_estrin"
taskset -c 2 ./log2_estrin
echo "taskset -c 2 ./log_estrin_fma"
taskset -c 2 ./log2_estrin_fma
echo "taskset -c 2 ./log10"
taskset -c 2 ./log10
echo "taskset -c 2 ./log10_estrin"
taskset -c 2 ./log10_estrin
echo "taskset -c 2 ./log10_estrin_fma"
taskset -c 2 ./log10_estrin_fma
echo "taskset -c 2 ./exp"
taskset -c 2 ./exp
echo "taskset -c 2 ./exp_adapt"
taskset -c 2 ./exp_adapt
echo "taskset -c 2 ./exp_estrin"
taskset -c 2 ./exp_estrin
echo "taskset -c 2 ./exp_estrin_fma"
taskset -c 2 ./exp_estrin_fma
echo "taskset -c 2 ./exp2"
taskset -c 2 ./exp2
echo "taskset -c 2 ./exp2_adapt"
taskset -c 2 ./exp2_adapt
echo "taskset -c 2 ./exp2_estrin"
taskset -c 2 ./exp2_estrin
echo "taskset -c 2 ./exp2_estrin_fma"
taskset -c 2 ./exp2_estrin_fma
echo "taskset -c 2 ./exp10"
taskset -c 2 ./exp10
echo "taskset -c 2 ./exp10_adapt"
taskset -c 2 ./exp10_adapt
echo "taskset -c 2 ./exp10_estrin"
taskset -c 2 ./exp10_estrin
echo "taskset -c 2 ./exp10_estrin_fma"
taskset -c 2 ./exp10_estrin_fma

# cd ../gcc
# make clean
# make 


# cd ../crlibm 
# make clean
# make 

# cd ..

# echo -e "\033[1mReporting Speedups\033[0m"
# python3 SpeedOverCoreMath.py
# python3 SpeedOverGlibc.py
