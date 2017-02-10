#
#  makefile
#
#  Created on: Feb 9, 2017
#      Author: Nugzar Chkhaidze & Daniel Sullivan
#
CFLAGS = -g

all: qSim

qSim: teller.o customer.o event.o simulation.o
	gcc -Wall $(CFLAGS) teller.o customer.o event.o simulation.o -o qSim

teller.o: teller.cpp teller.h event.h
	gcc -Wall $(CFLAGS) -c teller.cpp
	
customer.o: customer.cpp customer.h event.h
	gcc -Wall $(CFLAGS) -c customer.cpp
	
simulation.o: simulation.cpp
	gcc -Wall $(CFLAGS) -c simulation.cpp

event.o: event.cpp event.h
	gcc -Wall $(CFLAGS) -c event.cpp
	
clean:
	rm -f *.o *.exe qSim
