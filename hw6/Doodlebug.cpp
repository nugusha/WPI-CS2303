/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Doodlebug.h"
#include "board.h"

using namespace std;
extern vector<pair<int,int> >moves;
Doodlebug::Doodlebug(int X,int Y) {
	x=X;
	y=Y;
}// end Doodlebug
void Doodlebug::print(){
	cout<<"x";
	return;
}// end print
int Doodlebug::type(){
	return 2;
}// end type
int Doodlebug::time_to_bread(){
	return(timer>=8);
}// end time_to_breed
pair<int,int> Doodlebug::tryeat(Organism*** curBoard, Organism*** newBoard){


	random_shuffle(moves.begin(),moves.end());
	for(int i=0;i<4;i++){// check surroundings
		int newx=x+moves[i].first;
		int newy=y+moves[i].second;

		if(!check(newx,newy))continue;

		if(curBoard[newx][newy]->type()==1 && newBoard[newx][newy]->type()==0){
				newBoard[newx][newy]=new Doodlebug(newx,newy);
				newBoard[newx][newy]->timer=timer+1;
				newBoard[newx][newy]->eattimer=0;

				return make_pair(x,y);
			}
		}


	return make_pair(-1,-1);
}// end tryeat
pair<int,int> Doodlebug::move(Organism*** curBoard, Organism*** newBoard){

	pair<int, int>trial=this->tryeat(curBoard,newBoard);
	if(trial != make_pair(-1,-1)) {
		return trial;
	}


	random_shuffle(moves.begin(),moves.end());
	for(int i=0;i<4;i++){// checks surroundings
		int newx=x+moves[i].first;
		int newy=y+moves[i].second;

		if(!check(newx,newy))continue;

		if(curBoard[newx][newy]->type()>0 ||
		   newBoard[newx][newy]->type()!=0){
			continue;  // not empty
		}else{
				newBoard[newx][newy]=new Doodlebug(newx,newy);
				newBoard[newx][newy]->timer=timer+1;
				newBoard[newx][newy]->eattimer=eattimer+1;

				return make_pair(x,y);
			}
		}


	return make_pair(-1,-1);

}// end move
void Doodlebug::breed(Organism*** curBoard, Organism*** newBoard){
	random_shuffle(moves.begin(),moves.end());
		random_shuffle(moves.begin(),moves.end());
		for(int i=0;i<4;i++){// check surroundings
			int newx=x+moves[i].first;
			int newy=y+moves[i].second;

			if(!check(newx,newy))continue;

			if(newBoard[newx][newy]->type()==0){
					newBoard[newx][newy]=new Doodlebug(newx,newy);
					newBoard[newx][newy]->timer=0;
					timer=0;
					return ;
				}
			}



		return;
}
Organism* Doodlebug::getnew(){
	Doodlebug* a=new Doodlebug(x,y);
	a->timer=timer;
	a->eattimer=eattimer;
	return a;
}// end getnew

void Doodlebug::starvation(Organism*** newBoard) {
	if(eattimer >= 3) {
		newBoard[x][y] = new Organism();
		return ;
	}
}// end starvation

