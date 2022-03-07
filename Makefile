GCC = GCC

all: pipe


pipe: main.c
	gcc main.c -o pipe -Wall -pedantic

.PHONY: clean run

run:
	./pipe

clean:
	rm -rf pipe