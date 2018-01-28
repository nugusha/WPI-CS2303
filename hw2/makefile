$CFLAGS= -g

life: board.o life.o
	gcc $(CFLAGS) -Wall life.o board.o -o life -lm
	
board.o: board.c
	gcc $(CFLAGS) -Wall -c board.c
	
life.o: life.h life.c
	gcc $(CFLAGS) -Wall -c life.c -lm

	
clean:
	rm -f *.o life
	
all: life
