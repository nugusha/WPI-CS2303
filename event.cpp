/*
 * event.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>

#include "event.h"
#include "teller.h"
#include "customer.h"



void EventQueue::getnew(){
	Event *now=thequeue.top();

	now->Action();

	thequeue.pop();
}
