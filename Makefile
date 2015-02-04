.PHONY: clean

scheme: scheme.c model.c read.c eval.c print.c
	cc -Wall -ansi -o scheme scheme.c model.c read.c eval.c print.c

clean:
	rm scheme
