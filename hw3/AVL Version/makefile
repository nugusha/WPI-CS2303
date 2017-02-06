#
#  makefile
#
#  Created on: Feb 2, 2017
#      Author: Nugzar Chkhaidze & Danniel Sullivan
#
CFLAGS = -g

all: PA3

PA3: bst.o tree.o process.o
	gcc -Wall $(CFLAGS) bst.o tree.o process.o -o PA3

bst.o: bst.c process.h
	gcc -Wall $(CFLAGS) -c bst.c
	
process.o: process.c process.h tree.h
	gcc -Wall $(CFLAGS) -c process.c
	
tree.o: tree.c tree.h
	gcc -Wall $(CFLAGS) -c tree.c
	
clean:
	rm -f *.o *.exe PA3