/*
 * board.h
 *
 *  Created on: Feb 28, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Organism.h"

using namespace std;

extern int pause;

void printStep(int gridsize, Organism*** a) {
	for(int i = 0; i < gridsize; i++) {
		for(int j = 0; j < gridsize; j++) {
			a[i][j]->print();
		}
		cout<<endl;
	}
	cout<<endl;
}

void playOne(int gridsize, Organism*** oldBoard, Organism*** curBoard, int time_steps,int count=1) {
	int rows,cols;
	rows=cols=gridsize;

	Organism ***newBoard = (Organism ***)malloc(sizeof(Organism**)*gridsize);


	if(time_steps == 0) {
		return;
	}

	for(int i = 0; i < rows; i++) {
		newBoard[i] = (Organism**)malloc(cols * sizeof(Organism*));
	}



	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			newBoard[i][j] = NULL;
		}
	}


	int er1 = 0;
	int er2 = 0;
	int er3 = 0;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(curBoard[i][j]->type() != newBoard[i][j]->type()) {
				er1 = 1;
			}
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(oldBoard[i][j]->type() != newBoard[i][j]->type()) {
				er2 = 1;
			}
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(newBoard[i][j]->type() > 0) {
				er3 = 1;
			}
		}
	}

	if(!er1 || !er2 || !er3) {
		exit(0);
	}


	printStep(gridsize, newBoard);


	if(count%pause==0) {
		getchar();
	}



	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++){
			curBoard[i][j]->timer++;
			curBoard[i][j]->move();
			curBoard[i][j]->breed();
		}










	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++){
			if(newBoard[i][j]==NULL)newBoard[i][j]=new Organism();
		}


//	playOne(gridsize, curBoard, newBoard, time_steps - 1,count+1);
/*
	for(int i = 0; i < rows; i++) {
		free(newBoard[i]);
	}

	free(newBoard);
*/
}
