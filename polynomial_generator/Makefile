all: polygen-estrin-fma

polygen-estrin-fma: rlibm-fast.h piecewise-small-estrin-fma.cpp
	g++ -g -O2 -I$(SOPLEX_INCLUDE) -std=c++11 piecewise-small-estrin-fma.cpp  $(SOPLEX_LIB) -o polygen-estrin-fma -lgmp -lz -lm	

clean:
	rm -f *~ polygen-estrin-fma 

