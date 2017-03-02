/*
 * Doodlebug.h
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Organism.h"

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

class Doodlebug:public Organism {
public:
	Doodlebug(int X,int Y);
	virtual ~Doodlebug(){}

	int type();
	void print();
	void move() {

	}

	void starvation() {

	}

	void breed() {

	}
};

#endif /* DOODLEBUG_H_ */
