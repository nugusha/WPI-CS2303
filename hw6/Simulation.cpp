/*
 * Simulation.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "board.h"

using namespace std;


Organism*** a;
//int** fix;

int gridsize, doodlebugs, ants, time_steps, seed, pause;

int main(int argc, char *argv[]) {


	gridsize = atoi(argv[1]);
	doodlebugs = atoi(argv[2]);
	ants = atoi(argv[3]);
	time_steps = atoi(argv[4]);
	if(atoi(argv[5]) == 0) {
		seed = 1;
	}else{
		seed= atoi(argv[5]);
	}
	if(argc < 6) {
		pause = 0;
	} else {
		pause = atoi(argv[6]);
	}

	srand(seed);

	a = (Organism ***)malloc(sizeof(Organism**)*gridsize);
	for(int i=0;i<gridsize;i++){
		a[i] = (Organism **)malloc(sizeof(Organism*)*gridsize);
	}
/*
	fix = (int **)malloc(sizeof(int*)*gridsize);
	for(int i=0;i<gridsize;i++){
		fix[i] = (int *)malloc(sizeof(int)*gridsize);
	}
*/

	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++){
			a[i][j]=NULL;
		}

	int ANTS=ants;

	while(ANTS){
		int X=rand()%gridsize;
		int Y=rand()%gridsize;
		if(a[X][Y]!=NULL)continue;
		ANTS--;
		a[X][Y]=new Ant(X,Y);
	}

	int DOODLES=doodlebugs;

	while(DOODLES){
		int X=rand()%gridsize;
		int Y=rand()%gridsize;
		if(a[X][Y]!=NULL)continue;
		DOODLES--;
		a[X][Y]=new Doodlebug(X,Y);
	}


	for(int i=0;i<gridsize;i++)
		for(int j=0;j<gridsize;j++){
			if(a[i][j]==NULL)a[i][j]=new Organism();
		}

	cout<<"!!!"<<endl;
	printStep(gridsize, a);
	cout<<"!!"<<endl;

	playOne(gridsize, a, a, time_steps);




	return 0;
}
