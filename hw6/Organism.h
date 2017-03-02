/*
 * Organism.h
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism {
public:
	Organism();
	virtual ~Organism(){}

	int x, y;
	int timer;

	virtual void print();
	virtual int type(){return 0;}
	virtual void move(){return ;}
	virtual void breed(){return ;}

};

#endif /* ORGANISM_H_ */
