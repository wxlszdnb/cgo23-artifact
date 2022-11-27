CC = gcc

funcs = Log2 Log2-adapt Log2-estrin Log2-estrin-fma Exp2 Exp2-adapt	\
Exp2-estrin Exp2-estrin-fma Log10 Log10-estrin Log10-estrin-fma Log	\
Log-estrin Log-estrin-fma Exp10 Exp10-adapt Exp10-estrin		\
Exp10-estrin-fma Exp Exp-adapt Exp-estrin Exp-estrin-fma


src = $(patsubst %, %.c, $(funcs))
obj = $(patsubst %, %, $(funcs))


all: $(obj)

%: %.c
	$(CC) -O3 -std=c11 -I../libm  $^ ../libm/rlibm.a -lgmp -lm -o $@

clean:
	rm -rf *.o $(funcs) *~ *.txt
