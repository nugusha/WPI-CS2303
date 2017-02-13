/*
 * customer.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <queue>

#include "customer.h"
#include "teller.h"
using namespace std;
extern TellerQueue tell_queue;
extern int Total_time;
extern int Total_idle_time;
extern int Times_idle;
extern int Total_trans_time;
void Customer::Action(){
	cout<<"fuck you, customer"<<endl;

	Event* now=new Event();

	while(tell_queue.TOP()->gettime()<this->time){
		Event* now2=new Event();
		now2=(tell_queue.TOP());
		tell_queue.REMOVE();
		now2->addtimeto(now2->getidle());
		tell_queue.ADD(now2);

		Total_idle_time+=now2->getidle();
		Times_idle++;
	}
	now=tell_queue.TOP();




	int trans_time=1+rand()%500; // transaction time from 1 second to 500

	now->addtimeto(trans_time);

	Total_time+=(now->gettime()-this->time);
	Total_trans_time+=trans_time;



	tell_queue.thequeue.push(now);


	cout<<"fuck you, customer"<<endl;

}

int Customer::gettime(){
	return time;
}

extern int simulation_time;
Event* Customer::addd(){
	int newtime=rand()%simulation_time;
	Event* in=new Customer(newtime);
	return in;
}
