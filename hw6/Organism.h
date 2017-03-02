/*
 * Organism.h
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

using namespace std;

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism {
public:
	Organism();
	virtual ~Organism(){}

	int x, y;
	int timer;
	int eattimer;

	virtual void print();
	virtual int type(){return 0;}
	virtual Organism* getnew(){return NULL;}
	virtual int time_to_bread(){return 0;}
	virtual pair<int,int> move(Organism*** curBoard, Organism*** newBoard){return make_pair(-1,-1);}
	virtual void breed(Organism*** curBoard, Organism*** newBoard){return ;}
	virtual void starvation(Organism*** newBoard){return;}

};

#endif /* ORGANISM_H_ */
