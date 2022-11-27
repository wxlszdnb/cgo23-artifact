CC = gcc

funcs = log log2 log10 exp 

src = $(patsubst %, %.c, $(funcs))
obj = $(patsubst %, %, $(funcs))


all: $(obj)

%: %.c
	$(CC) -std=c11 -O0 -DIGNORE_SPECIAL_INPUT -frounding-math -fsignaling-nans -I../ -I../../libm  $^ libcrlibm.a -lgmp -lm -o $@

clean:
	rm -rf *.o $(funcs) *~ *.txt
