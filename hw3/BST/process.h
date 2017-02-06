/*
 *  process.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Danniel Sullivan
 */

#ifndef PROCESS_H_
#define PROCESS_H_

char* final;
int check(char c);
void change(char* word);
void process(char ***words,int n,int *wordsize,FILE *out);

#endif /* PROCESS_H_ */
