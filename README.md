# CGO23-artifact for the RLIBM Approach with Estrin's method and FMAs for Polynomial Evaluation

This library provides correctly rounded functions and the polynomial
generator for them using the RLIBM method. The artifact includes: (1)
24 correctly rounded implementations for six elementary functions
using the coefficient adaptation procedure by Knuth, Estrin's method,
and Estrin's method with fused multiply-add operations for polynomial
evaluation, (2) correctness testing framework for the 24 functions,
(3) performance testing framework to demonstrate the performance
improvements over RLIBM and CRLIBM, and (4) polynomial generator for
generating the polynomials using the Estrin's method with fused
multiply-add operations.

# Requirements

To replicate our experiments, we need a Linux machine with gcc
compiler on x86-64 machine. To accurately reproduce our performance
experiments, it is recommended to disable turbo-boost and
hyper-threading in the BIOS. To run the polynomial generator, it is
recommended to have a machine with at least 16 GB of RAM. We need
about 50 GB of storage if all the auxiliary files are unpacked.


# Installation

There are four main things to download the artifact. First, download
the sources from the github repository as follows:

```
git clone https://github.com/rutgers-apl/cgo23-artifact.git
```

Second, download the oracle files for the 6 elementary functions at
[https://go.rutgers.edu/m6ex2hnc] using
the browser and save them to a directory. Let us call the directory:
ORACLE. We will use these oracle files to test the correctness of the
24 functions. One can use the MPFR library to individually test the
correctness. However, the process takes a very long time (close to a
day). Hence, we provide the pre-generated oracle files.

Use the gunzip command to unzip the oracle files in the ORACLE
directory. Each unzipped oracle file is 12GB. We recommend unzipping
only the oracle files corresponding to the specific function being
tested.

For example, unzip the oracle files for Log2 as follows:

```
cd <ORACLE>
gunzip Log2Oracle.gz
cd ..
```


Third, download the interval files for the 6 functions for the
polynomial generator at
[https://rutgers.box.com/s/aeaclmvnez8z0rjjsvcspoflslcu1nof]. These
can be generated using the RLIBM-ALL infrastructure. However, it would
take a long time. Hence, we provide these interval files. Let us call
the directory with these interval files: INTERVALS. Use the gunzip
command to unzip the intervals file in the INTERVALS directory. Each
unzipped file can be up to 5GB.  We recommend unzipping only the
interval file corresponding to the function being tested.

For example, unzip the interval files for Log2 as follows:

```
cd <INTERVALS>
gunzip Float34ROLog2Intervals.gz 
cd ..
```


Fourth, you need to download Soplex-4.0.1 to run the polynomial
generator. Download Soplex-4.0.1 at [https://soplex.zib.de/].

Untar soplex-4.0.1 as
follows:

```
tar -xvf soplex-4.0.1.tar.gz
cd soplex-4.0.1
make clean
make
export SOPLEX_INCLUDE=<SOPLEX_PATH>/src/
export SOPLEX_LIB=<SOPLEX_PATH>/build/lib/libsoplex.a
cd ..
```

Now, we are ready to replicate the results.

# Reproducing Results

## Correctness test

You can test the correctness of all the functions generated from our
libraries using the correctness test infrastructure as follows:

```
cd cgo23_artifact/libm
make
cd ../correctness_test
make
```

To test out the default RLIBM function, you can execute the following
 command, which checks if the implementation produces correctly
 rounded results for all inputs.


```
./Log2 <ORACLE>/Log2Oracle
```

For testing the Log2 function with the coefficient adaptation with Knuth's
method for polynomial evaluation, you execute the following command:

```
./Log2-adapt <ORACLE>/Log2Oracle
```

For testing the $log2f$ with the Estrin's method for polynomial
evaluation, you execute the following command:

```
./Log2-estrin <ORACLE>/Log2Oracle
```

To test $log2f$ with the Estrin's method along with fused multiply-add
operations for the polynomial evaluation and check if produces correct
results for all inputs, you execute the following command:

```
./Log2-estrin-fma <ORACLE>/Log2Oracle
```

You should see an output like the following, which indicates it
produces correct results for all inputs and for multiple representations:

```
Wrong results: 000 (0)
rlibm-latest   wrong result: 0
```


It can take up to 10 minutes for testing each implementation as
described above.  Similarly you can test out the other functions.


## Performance

We provide an automated script to test the performance of the
RLIBM-Knuth, RLIBM-Estrin, and RLIBM-ESTRIN-FMA with respect to the
default RLIBM  implementations. To run the performance testing
framework, execute the following command

```
cd cgo23_artifact/performance_test
sh runRLIBMAll.sh
```

It automatically executes all the 24 implementations of the 6
functions and creates text files with the timing data. This script
takes close to 1 hour to complete execution. To see similar result as
reported in the paper, it is necessary to run the script on machine
with hyper-threading and turbo-boost disabled. It is advised to not
execute other programs simultaneously with the script.

After the script completes, you can run the analysis script that
prints out the speedup with various configurations as follows:

```
python SpeedupOverRLIBM.py
```


It will print out the output as follows:

```
Speedup of RLIBM-Knuth over RLIBM
log: 0.00%
log2: 4.03%
log10: 0.00%
exp: 3.00%
exp2: 7.85%
exp10: 7.27%
Average speedup of RLIBM-Knuth over RLIBM: 3.65%
Speedup of RLIBM-Estrin over RLIBM
log: 12.59%
log2: 16.89%
log10: 8.87%
exp: 12.73%
exp2: 17.80%
exp10: 17.54%
Average speedup of RLIBM-Estrin over RLIBM: 14.36%
Speedup of RLIBM-Estrin-FMA over RLIBM
log: 17.82%
log2: 21.05%
log10: 15.23%
exp: 22.55%
exp2: 28.74%
exp10: 25.01%
Average speedup of RLIBM-Estrin-FMA over RLIBM: 21.66%
```

You can also test the performance speedup of our functions over CRLIBM
with the following command.


```
sh runCRLIBM.sh
```


To identify the speedups with our functions compared to CRLIBM,
execute the following script:

```
python SpeedupOverCRLIBM.py
```

## Generating Polynomials with the RLIBM-Estrin-FMA method

We illustrate the process of generating polynomials by incorporating
the Estrin's method with FMA operations within the RLIBM polynomial
generation framework. To use the polynomial generator, it needs
reduced intervals generated using the RLIBM framework, which we
provide as intervals. It also requires Soplex installed with the the
SOPLEX_INCLUDE and SOPLEX_LIB environment variables set as described
above. We illustrate polynomial generation for the log2 function.

To generate the polynomial for Log2 with the Estrin's method with FMA
operations, execute the following commands.


```
cd cgo23_artifact/polynomial_generator
make
./polygen-estrin-fma log2-estrin-fma.txt <INTERVALS>/Float34ROLog2Intervals
```

The configurations for Log2 polynomials that we generate are in
log2-estrin-fma.txt file.  At the end, the polynomial generator prints
out the polynomial.

Log2 is a full-rank system. There is a single polynomial with no
special inputs. Other systems run for a large number of iterations and
the goal is to find a polynomial with the minimum number of
points. Hence, it is recommended to redirect the output of the
polynomial generator to a file. Those functions can take close to 3-4
hours to perform such exhaustive search.
