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

	Event* now=new Event();

	while(tell_queue.TOP()->gettime()<this->time){
		// if customers arrival time is more than tellers time when he got free, teller should go idle.
		//            And because many tellers may go idle at the same time, or some
		//            tellers may go idle multiple times in a row we use while loop to handle such cases.

		Event* now2=new Event();
		now2=(tell_queue.TOP());    //  get top customer from the top of priority_queue
		tell_queue.REMOVE();       //  remove him from priority queue
		now2->addtimeto(now2->getidle());// add idle time to his time
		tell_queue.ADD(now2);       // push it back to the priority queue

		Total_idle_time+=now2->getidle();   // add idle time to total idle time
		Times_idle++;           // increment number of times idle
	}
	now=tell_queue.TOP();
	tell_queue.REMOVE();

	int trans_time=1+rand()%500; // transaction time from 1 second to 500

	now->addtimeto(trans_time);

	Total_time+=(now->gettime()-this->time);
	Total_trans_time+=trans_time;

	tell_queue.ADD(now);
}
extern int* cust_in_line;
extern int tellers;
extern TellerQueue* tell_queues;

void Customer::Action2(){


	int minimum=0,num_of_min=0;

	for(int i=0;i<tellers;i++)
		if(cust_in_line[minimum]>cust_in_line[i])  // find the index of the line
			minimum=i;							// with minimum number of customers

	for(int i=0;i<tellers;i++)					// find number of minimums
		if(cust_in_line[minimum]==cust_in_line[i])
			num_of_min++;

	int randnum=rand()%num_of_min;  // random in which line the customer should go

	for(int i=0;i<tellers;i++)       // add the customer in randnum-th line
			if(cust_in_line[minimum]==cust_in_line[i]){
				if(randnum==0){
					cust_in_line[i]++;
					tell_queues[i].ADD(this);
					break;
				}
				randnum--;
			}
}

int Customer::gettime(){
	return time;
}

extern int simulation_time;
Event* Customer::add(){
	int newtime=rand()%simulation_time;
	Event* in=new Customer(newtime);
	return in;
}
