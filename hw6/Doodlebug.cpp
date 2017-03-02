/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Doodlebug.h"

using namespace std;

Doodlebug::Doodlebug(int X,int Y) {
	x=X;
	y=Y;
}
void Doodlebug::print(){
	cout<<"x";
	return;
}
int Doodlebug::type(){
	return 2;
}
