all: rlibm.a

CC = gcc

rlibmfiles = log2 log2_adapt log2_estrin log2_estrin_fma log10		\
log10_estrin log10_estrin_fma log log_estrin log_estrin_fma exp2	\
exp2_adapt exp2_estrin exp2_estrin_fma exp10 exp10_adapt exp10_estrin	\
exp10_estrin_fma exp exp_adapt exp_estrin exp_estrin_fma

rlibmsrcdir = .
rlibmobjdir = obj

rlibmsrc = $(patsubst %, $(rlibmsrcdir)/%.c, $(rlibmfiles))
rlibmobj = $(patsubst %, $(rlibmobjdir)/%.o, $(rlibmfiles))

$(rlibmobjdir)/%.o: $(rlibmsrcdir)/%.c
	@mkdir -p $(rlibmobjdir)
	$(CC) -std=c11 -march=native -O3  -c $^  -o $@

rlibm.a: $(rlibmobj)
	ar rc $@ $^

clean:
	rm -rf  obj *~ rlibm.a
