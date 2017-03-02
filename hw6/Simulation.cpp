/*
 * Simulation.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "board.h"

using namespace std;


Organism*** a;
vector<pair<int,int> >moves;
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
	}// end args

	srand(seed);

	a = (Organism ***)malloc(sizeof(Organism**)*gridsize);
	for(int i=0;i<gridsize;i++){								// allocates memory for the grid
		a[i] = (Organism **)malloc(sizeof(Organism*)*gridsize);
	}// end allocation
/*
	fix = (int **)malloc(sizeof(int*)*gridsize);
	for(int i=0;i<gridsize;i++){
		fix[i] = (int *)malloc(sizeof(int)*gridsize);
	}
*/

	for(int i=0;i<gridsize;i++)			//goes through rows
		for(int j=0;j<gridsize;j++){	//goes through columns
			a[i][j]=NULL;				// makes the spot empty, in this case NULL
		}// end NULL placements

	int ANTS=ants;

	while(ANTS){	// randomly places the ants throughout the grid
		int X=rand()%gridsize;
		int Y=rand()%gridsize;
		if(a[X][Y]!=NULL)continue;
		ANTS--;
		a[X][Y]=new Ant(X,Y);
	}// end ant placement

	int DOODLES=doodlebugs;

	while(DOODLES){	// randomly places the doodlebugs throughout the grid
		int X=rand()%gridsize;
		int Y=rand()%gridsize;
		if(a[X][Y]!=NULL)continue;
		DOODLES--;
		a[X][Y]=new Doodlebug(X,Y);
	}// end doodlebug placement


	for(int i=0;i<gridsize;i++)		// goes through rows
		for(int j=0;j<gridsize;j++){// goes through cols
			if(a[i][j]==NULL)a[i][j]=new Organism();	// replaces NULL spots with new Organisms
		}// ned NULL replacement

	moves.push_back(make_pair(0,-1));  // up
	moves.push_back(make_pair(1,0));   // right
	moves.push_back(make_pair(0,1));   // down
	moves.push_back(make_pair(-1,0));  // left

	//cout<<"!!!"<<endl;
	printStep(gridsize, a);
//	cout<<"!!"<<endl;

	playOne(gridsize,  a, time_steps);



	return 0;
}
