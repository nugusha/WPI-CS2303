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
	Organism* getnew();

	pair<int,int> move(Organism*** A, Organism*** B);
	void breed(Organism*** A, Organism*** B);
	int time_to_bread();

};

#endif /* ANT_H_ */
