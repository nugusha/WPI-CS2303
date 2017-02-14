#
#  makefile
#
#  Created on: Feb 9, 2017
#      Author: Nugzar Chkhaidze & Daniel Sullivan
#
CFLAGS =  -g

all: qSim

qSim: teller.o customer.o event.o simulation.o
	g++ $(CFLAGS) teller.o customer.o event.o simulation.o -o qSim

teller.o: teller.cpp teller.h event.h
	g++ $(CFLAGS) -c teller.cpp
	
customer.o: customer.cpp customer.h teller.h
	g++ $(CFLAGS) -c customer.cpp
	
simulation.o: simulation.cpp simulation.h teller.h event.h customer.h
	g++ $(CFLAGS) -c simulation.cpp

event.o: event.cpp event.h
	g++ $(CFLAGS) -c event.cpp
	
clean:
	rm -f *.o *.exe qSim
