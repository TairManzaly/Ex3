CFLAGS = -Wall -g

clean:
	rm -f *.o stringProg

all: stringProg

stringProg: string.o
	gcc $(CFLAGS) -o stringProg string.o
string.o: string.c
	gcc $(CFLAGS) -c string.c