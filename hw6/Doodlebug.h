/*
 * Doodlebug.h
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Organism.h"

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

class Doodlebug:public Organism {
public:
	Doodlebug(int X,int Y);
	virtual ~Doodlebug(){}


	int type();
	void print();
	pair<int,int> move(Organism*** curBoard, Organism*** newBoard);
	pair<int,int> tryeat(Organism*** curBoard, Organism*** newBoard);

	void starvation(Organism*** curBoard);
	int time_to_bread();
	Organism* getnew();

	void breed(Organism*** curBoard, Organism*** newBoard);
};

#endif /* DOODLEBUG_H_ */
