/*
 * teller.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */


#ifndef TELLER_H_
#define TELLER_H_

#include "event.h"
class Teller: public Event{
private:
public:
	int idle_time;
	int time;
		Teller(){}
		Teller(int idle_t){
			time = 0;
			idle_time=idle_t;
		}

	void Action();
	void addtimeto(int trans_time);
	int getidle();
	int gettime();
	Event* addd();


	virtual ~Teller(){}
};

class TellerQueue{
public:
	std::priority_queue<Event *,std::vector<Event *>,cmp> thequeue;
	TellerQueue(){}
	Event* TOP();
	void REMOVE();
	void ADD(Event *a);
};


#endif /* TELLER_H_ */
