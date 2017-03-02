/*
 * Ant.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Ant.h"
#include "board.h"
#include "Organism.h"

using namespace std;

//extern int gridsize;
extern vector<pair<int,int> >moves;

Ant::Ant(int X,int Y) {
	x=X;
	y=Y;
}// end Ant

void Ant::print(){
	cout<<"o";
	return;
}// end print
int Ant::type(){
	return 1;
}// end type
pair<int,int> Ant::move(Organism*** curBoard, Organism*** newBoard){

	random_shuffle(moves.begin(),moves.end());
	for(int i=0;i<4;i++){	// check surroundings
		int newx=x+moves[i].first;
		int newy=y+moves[i].second;

		if(!check(newx,newy))continue;

		if(curBoard[newx][newy]->type()>0 ||
		   newBoard[newx][newy]->type()!=0){
			continue;  // not empty
		}else{
				newBoard[newx][newy]=new Ant(newx,newy);
				newBoard[newx][newy]->timer=timer+1;

				return make_pair(x,y);
			}
		}


	return make_pair(-1,-1);
}// end move
Organism* Ant::getnew(){
	Ant* a=new Ant(x,y);
	a->timer=timer;
	return a;
}// end getnew
int Ant::time_to_bread(){
	return(timer>=3);
}// end time_to_breed
void Ant::breed(Organism*** curBoard, Organism*** newBoard){

	random_shuffle(moves.begin(),moves.end());
	random_shuffle(moves.begin(),moves.end());
	for(int i=0;i<4;i++){	// check surroundings
		int newx=x+moves[i].first;
		int newy=y+moves[i].second;

		if(!check(newx,newy))continue;

		if(newBoard[newx][newy]->type()==0){
				newBoard[newx][newy]=new Ant(newx,newy);
				newBoard[newx][newy]->timer=0;
				timer=0;
				return ;
			}
		}



	return;
}// end breed
