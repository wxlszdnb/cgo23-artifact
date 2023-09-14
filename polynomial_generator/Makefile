all: polygen-estrin-fma

polygen-estrin-fma: rlibm-fast.h piecewise-small-estrin-fma.cpp
	g++ -I$(PYTHON_INCLUDE) -g -O2 -I$(SOPLEX_INCLUDE) -std=c++11 piecewise-small-estrin-fma.cpp  $(SOPLEX_LIB) -o polygen-estrin-fma -l$(PYTHON_LIB) -lgmp -lz -lm

clean:
	rm -f *~ polygen-estrin-fma 

