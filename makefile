GCC = gcc -g

all: rando.c
	$(GCC) rando.c -o file

clean:
	rm *~

run: all
	./file
