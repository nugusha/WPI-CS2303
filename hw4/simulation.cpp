/*
 * simulation.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<queue>
#include<iostream>
#include"event.h"
#include"customer.h"
#include"teller.h"
using namespace std;
int simulation_time;
double seed=-1;
int Total_time;
int Total_idle_time;
int Times_idle;
int Total_trans_time;
int customers,tellers;
void solve1(int customers,int tellers);
void solve2(int customers,int tellers);
void print();
Teller tel;
Customer cust;
Event* sample_teller=&tel;
Event* sample_customer=&cust;
TellerQueue tell_queue;

int main(int argc,char *argv[]) {

    customers=atoi(argv[1]);
	tellers=atoi(argv[2]);
	simulation_time=atoi(argv[3]);
	if(argc>=5)seed=atof(argv[4]);else
		seed=-1;


	srand(seed);

	solve1(customers, tellers);
	//solve2(customers, tellers);

	print();


	return 0;
}
void solve1(int customers,int tellers){

	EventQueue *eq=new EventQueue();

	for(int i=0;i<customers;i++){  // generating new customers
		eq->thequeue.push(sample_customer->add());
	}

	for(int i=0;i<tellers;i++){  // generating new tellers
		eq->thequeue.push(sample_teller->add());
	}


	while(!eq->thequeue.empty()){
		eq->getnew();
//		cout<<"!"<<endl;
	}

}
void print(){
	printf("%d %d\n",customers,tellers);
	printf("%d %.2f\n",Total_time,double(Total_time)/double(customers));
	printf("%d %d\n",Total_idle_time,Times_idle);
	printf("%d %.2f\n",Total_trans_time,double(Total_trans_time)/double(customers));
}
