.PHONY: clear

DEPS:=deps/slog/slog.h

all: obj/nani_matrix.o

obj/nani_matrix.o: src/nani_matrix.c $(DEPS) 
	cc -c -o $@ $< $(CCFLAGS)

clear:
	rm bin/*
