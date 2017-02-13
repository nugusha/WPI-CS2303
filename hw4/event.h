/*
 * event.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */


#ifndef EVENT_H_
#define EVENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

using namespace std;

class Event{
public:
	Event(){}
	virtual Event* addd ()
	      { Event* sample;return (sample); }
	virtual int gettime ()
	      { return (0); }
	virtual int getidle()
	      { return (0); }
	virtual void Action ()
	      { cout<<"!!"<<endl;return ; }
	virtual void addtimeto (int trans_time)
	      { return ; }



	virtual ~Event(){}
};

struct cmp {
    bool operator()(Event *a, Event *b)
    {
        return (a->gettime()<b->gettime());
    }
};

class EventQueue{
public:
	std::priority_queue<Event *,std::vector<Event *>,cmp> thequeue;
	EventQueue(){}
	void getnew();

};


#endif /* EVENT_H_ */
