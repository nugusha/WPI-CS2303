#
#  makefile
#
#  Created on: Feb 27, 2017
#      Author: Nugzar Chkhaidze & Daniel Sullivan
#

CFLAGS = -g -Wall

all: PA6

PA6: Organism.o Ant.o Doodlebug.o Simulation.o board.o
	g++ $(CFLAGS) Organism.o Ant.o Doodlebug.o Simulation.o board.o -o PA6

Organism.o: Organism.cpp Organism.h
	g++ $(CFLAGS) -c Organism.cpp
	
Ant.o: Ant.cpp Ant.h
	g++ $(CFLAGS) -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h
	g++ $(CFLAGS) -c Doodlebug.cpp
	
board.o: board.cpp board.h
	g++ $(CFLAGS) -c board.cpp
	
Simulation.o: Simulation.cpp
	g++ $(CFLAGS) -c Simulation.cpp

clean:
	rm -f *.o *.exe PA6
