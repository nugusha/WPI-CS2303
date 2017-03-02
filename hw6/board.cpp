/*
 * board.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Organism.h"

using namespace std;

extern int pause;
extern int gridsize;
int check(int x,int y){  // checks if (x,y) is in the range of board
	if(x<0 || y<0 || x>=gridsize || y>=gridsize)return 0;
	return 1;
}

void printStep(int gridsize, Organism*** a) {
	for(int i = 0; i < gridsize; i++) {
		for(int j = 0; j < gridsize; j++) {
			a[i][j]->print();
		}
		cout<<endl;
	}
	cout<<endl;
}

void playOne(int gridsize, Organism*** curBoard, int time_steps,int count=1) {
	int rows,cols;
	rows=cols=gridsize;

	//cout<<time_steps<<" "<<count<<endl;

	Organism ***newBoard = (Organism ***)malloc(sizeof(Organism**)*gridsize);


	if(time_steps == 0) {
		return;
	}

	for(int i = 0; i < rows; i++) {
		newBoard[i] = (Organism**)malloc(cols * sizeof(Organism*));
	}



	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			newBoard[i][j] = new Organism();
		}
	}

	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++)
			curBoard[i][j]->x=i,
			curBoard[i][j]->y=j;


	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++){
			if(curBoard[i][j]->type()==0)continue;

			if(curBoard[i][j]->type()==2){

				pair<int,int>new_loc = curBoard[i][j]->move(curBoard,newBoard);

				if(new_loc==make_pair(-1,-1)){

					newBoard[i][j]=curBoard[i][j]->getnew();
					newBoard[i][j]->timer++;
				}

			}
		}


	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++){
			if(curBoard[i][j]->type()==0)continue;
			if(curBoard[i][j]->type()==1 && newBoard[i][j]->type()!=2){
				pair<int,int>new_loc = curBoard[i][j]->move(curBoard,newBoard);

				if(new_loc==make_pair(-1,-1)){

					newBoard[i][j]=curBoard[i][j]->getnew();
					newBoard[i][j]->timer++;
				}
			}
		}



	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++){
			if(newBoard[i][j]->type()==0)continue;
			if(newBoard[i][j]->type()==2) {
				newBoard[i][j]->starvation(newBoard);
			}
			if(newBoard[i][j]->time_to_bread()){
					newBoard[i][j]->breed(curBoard,newBoard);//cout<<"!!!"<<endl;
			}
		}

//cout<<"!!!!"<<endl;

	int er3 = 0;

	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++){
			if(newBoard[i][j]==NULL)newBoard[i][j]=new Organism();
		}




	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(newBoard[i][j]->type() > 0) {
				er3 = 1;
			}
		}
	}


	printStep(gridsize, newBoard);



	if(!er3) {
	//	cout<<er1<<" "<<er2<<" "<<er3<<" !"<<endl;
		exit(0);
	}







	if(pause!=0 && count%pause==0) {
		getchar();
	}



		for(int i = 0; i < rows; i++) {
			free(curBoard[i]);
		}

		free(curBoard);


//	cout<<time_steps<<endl;
	playOne(gridsize, newBoard, time_steps - 1,count+1);
}
