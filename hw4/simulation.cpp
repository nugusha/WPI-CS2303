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
#include<fstream>
#include"event.h"
#include"customer.h"
#include"teller.h"
#include"simulation.h"
using namespace std;
int simulation_time;
double seed=-1;
int Total_time;
int Total_idle_time;
int Times_idle;
int Total_trans_time;
int customers,tellers;
int* cust_in_line;
void solve1(int customers,int tellers);
void solve2(int customers,int tellers);
void print();
Teller tel;
Customer cust;
Event* sample_teller=&tel;
Event* sample_customer=&cust;
Event** all_tellers;
Event** all_customers;
TellerQueue tell_queue;
TellerQueue* tell_queues;
EventQueue *eq;
int main(int argc,char *argv[]) {

	freopen("a.out","w",stdout);
    customers=atoi(argv[1]);
	tellers=atoi(argv[2]);
	simulation_time=atoi(argv[3]);
	if(argc>=5)seed=atof(argv[4]);else
		seed=-1;

	if(seed==-1)seed=rand();

	srand(seed+1);

	printf("Simulation time  - %d\n",simulation_time);
	printf("Transaction time between       %5d - %d\n",1,500);
	printf("Idle time between              %5d - %d\n",1,600);
	printf("Customers and Tellers          %5d - %d\n",customers,tellers);
	cout<<endl<<endl<<endl;

	cout<<"Simulation with one line"<<endl<<endl;

	solve1(customers, tellers);
	print();
	Total_time=Total_idle_time=Times_idle=Total_trans_time=0;

	cout<<endl<<endl<<endl;

	cout<<"Simulation with multiple line"<<endl<<endl;


	solve2(customers, tellers);

	print();


	return 0;
}
void solve1(int customers,int tellers){

	eq=new EventQueue();

	all_customers=new Event*[customers];
	all_tellers=new Event*[tellers];
	for(int i=0;i<customers;i++){  // generating new customers
    	all_customers[i]=sample_customer->add();
		eq->thequeue.push(all_customers[i]);// pushes in the priority queue
	}

	for(int i=0;i<tellers;i++){  // generating new tellers
		all_tellers[i]=sample_teller->add();
		eq->thequeue.push(all_tellers[i]);// pushes in the priority queue
	}


	while(!eq->thequeue.empty()){ // process members of eventqueue
		eq->getnew();
	}

	// free memory
	for(int i=0;i<customers;i++)
		delete(all_customers[i]);
	delete(all_customers);
	for(int i=0;i<tellers;i++)
		delete(all_tellers[i]);
	delete(all_tellers);

	delete(eq);
}
void solve2(int customers,int tellers){

	tell_queues=new TellerQueue[tellers];
	eq=new EventQueue();


	all_customers=new Event*[customers];
	all_tellers=new Event*[tellers];
	for(int i=0;i<customers;i++){  // generating new customers
    	all_customers[i]=sample_customer->add();
		eq->thequeue.push(all_customers[i]); // pushes in the priority queue
	}

	for(int i=0;i<tellers;i++){  // generating new tellers
		all_tellers[i]=sample_teller->add();
		all_tellers[i]->lineNumber=i;
		eq->thequeue.push(all_tellers[i]); // pushes in the priority queue
	}
	cust_in_line=new int[tellers];
	for(int i=0;i<tellers;i++)cust_in_line[i]=0;

	while(!eq->thequeue.empty()){// process members of eventqueue
		eq->getnew2();
	}


	// free memory
	for(int i=0;i<customers;i++)
		delete(all_customers[i]);
	delete(all_customers);

	for(int i=0;i<tellers;i++)
		delete(all_tellers[i]);

	delete(all_tellers);
}

void print(){
	printf("Average transaction time                      %7.2f\n",double(Total_trans_time)/double(customers));
	printf("Total idle time - Times_idle                  %7d %d\n",Total_idle_time,Times_idle);
	printf("Total time -  Average waiting time            %7d %.2f\n",Total_time,double(Total_time)/double(customers));

}
