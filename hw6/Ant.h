/*
 * Ant.h
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Ant:public Organism {
public:
	Ant(int X,int Y);
	virtual ~Ant(){}

	void print();
	int type();

	void move();
	void breed();
};

#endif /* ANT_H_ */
