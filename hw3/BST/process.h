/*
 * process.h
 *
 *  Created on: Feb 2, 2017
 *      Author: djsully & nugusha
 */

#ifndef PROCESS_H_
#define PROCESS_H_


char* final;
int check(char c);
char* change(char* word);
void process(char ***words,int n,int *wordsize,FILE *out);

#endif /* PROCESS_H_ */
