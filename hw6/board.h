/*
 * board.h
 *
 *  Created on: Feb 28, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#ifndef BOARD_H_
#define BOARD_H_


void printStep(int gridsize, Organism*** a);

void playOne(int gridsize, Organism*** oldBoard, Organism*** curBoard, int time_steps,int count=1);
#endif /* BOARD_H_ */
