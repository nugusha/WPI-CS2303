/*
 * customer.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include "event.h"
class Customer: public Event{
private:
public:
	int time;    // time is arrival time
	Customer(){}
	Customer(int t){
		time=t;
	}
	void Action();
	void Action2();
	int gettime();
	Event* add();


	virtual ~Customer(){}
};


#endif /* CUSTOMER_H_ */
