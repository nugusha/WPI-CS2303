/*
 * teller.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#include "teller.h"

extern TellerQueue tell_queue;
void Teller::Action(){

	cout<<"fuck you, teller"<<endl;
	tell_queue.thequeue.push(this);

	cout<<"fuck you, s"<<endl;

}
void Teller::addtimeto(int trans_time){
	this->time+=trans_time;
}

int Teller::gettime(){
	return time;
}
int Teller::getidle(){
	return idle_time;
}

Event* Teller::addd(){
	int idle=1+rand()%600;
	Event* in=new Teller(idle);
	return in;
}

Event* TellerQueue::TOP(){
	return thequeue.top();
}
void TellerQueue::REMOVE(){
	thequeue.pop();
}
void TellerQueue::ADD(Event *a){
	thequeue.push(a);
}
