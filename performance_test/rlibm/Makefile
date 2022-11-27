CC = gcc

funcs = log log_estrin log_estrin_fma log2 log2_adapt log2_estrin	\
log2_estrin_fma log10 log10_estrin log10_estrin_fma exp exp_adapt	\
exp_estrin exp_estrin_fma exp2 exp2_adapt exp2_estrin exp2_estrin_fma	\
exp10 exp10_adapt exp10_estrin exp10_estrin_fma

src = $(patsubst %, %.c, $(funcs))
obj = $(patsubst %, %, $(funcs))


all: $(obj)

%: %.c
	$(CC) -std=c11 -O0 -DIGNORE_SPECIAL_INPUT -frounding-math -fsignaling-nans -I../ -I../../libm  $^ ../../libm/rlibm.a -lgmp -lm -o $@

clean:
	rm -rf *.o $(funcs) *~ *.txt
