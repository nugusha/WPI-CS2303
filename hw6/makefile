#
#  makefile
#
#  Created on: Feb 27, 2017
#      Author: Nugzar Chkhaidze & Daniel Sullivan
#

CFLAGS = -g -Wall

PA6: Organism.o Ant.o Doodlebug.o Simulation.o
	g++ $(CFLAGS) Simulation.o Organism.o Ant.o Doodlebug.o -o PA6

Organism.o: Organism.cpp Organism.h
	g++ $(CFLAGS) -c Organism.cpp
	
Ant.o: Ant.cpp Ant.h
	g++ $(CFLAGS) -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h
	g++ $(CFLAGS) -c Doodlebug.cpp
	
Simulation.o: Simulation.cpp
	g++ $(CFLAGS) -c Simulation.cpp

clean:
	rm -f *.o *.exe PA6
	
all: PA6
	
