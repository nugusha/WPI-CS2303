/*
 *  bst.c
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Danniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <sys/time.h>
#include <unistd.h>

// Prototypes for time functions
void print_timeval(struct timeval t);
struct timeval timediff(struct timeval time1, struct timeval time2);

// Symbolic constant(s)

/* Number of microsenconfds in a second. We need the 'L'
   because this is a long constant. */
#define USEC_IN_SEC (1000000L)

/** Program which demonstrates how to get and use a timestamp.
 * @return 0
 */




#include "process.h"
extern int Total;
FILE *out;
FILE **in;
int main(int argc, char *argv[]) {
	struct timeval start_time; // time stamps for start and end of sorting
	struct timeval end_time;
	struct timeval job_time; // Elapsed time while doing the job
	  gettimeofday(&start_time, NULL);




	out=fopen(argv[1],"w");
	in=malloc((argc-2)*sizeof(FILE));

	for(int i=2;i<argc;i++){
		in[i-2]=fopen(argv[i],"r");
	}
	char *word;
	word=malloc(10000*sizeof(char));

	char ***words=(char ***)malloc(sizeof(char**)*(argc-2));
	int *wordsize=malloc(sizeof(int)*(argc-2));

	for(int i=0;i<argc-2;i++){
		int counter=0,p=1;
		while(1){
			p=fscanf(in[i],"%s",word);
			if(p!=1)break;
			change(word);

			if(word[0]!='\0')
				{counter++;Total++;}
		}
		words[i]=(char **)malloc(sizeof(char*)*counter);
		wordsize[i]=counter;
		rewind(in[i]);

		int N=0;
		p=1;
		while(1){
			p=fscanf(in[i],"%s",word);

			if(p!=1)break;

			change(word);
			if(word[0]=='\0')continue;

			N++;
			words[i][N-1] = strdup(word);
		}
	}
	process(words,argc-2,wordsize,out);

	for(int i=0;i<argc-2;i++){
		for(int j=0;j<wordsize[i];j++)
			free(words[i][j]);
		free(words[i]);
	}
	free(words);free(word);free(wordsize);

	for(int i=0;i<argc-2;i++)
		free(in[i]);
	free(in);
	free(final);


	gettimeofday(&end_time, NULL); // Get timestamp at end

	  printf("---|--Timestamp before: ");
	  print_timeval(start_time);
	  printf("Timestamp after: ");
	  print_timeval(end_time);

	  /* This next line fills in the fields of a timeval struct
	     with the difference between the two timestamps. */
	  job_time = timediff(start_time, end_time);
	  printf("Time difference: ");
	  print_timeval(job_time);

	  return 0;

	return 0;
}


/** Prints the contents of a timeval struct.
 * @param t Struct to print.
 */
void print_timeval(struct timeval t) {
  printf("Seconds: %ld, microseconds: %ld\n", t.tv_sec, t.tv_usec);
}

/** Calculates difference between two timestamps.
 * Note that this takes structs as parameters and returns a struct;
 * it does not use pointers.
 * @param time1 A time stamp
 * @param time2 another timestamp (assumed same as or later than time 1)
 * @return A timeval struct representing time2 - time1
 */
struct timeval timediff(struct timeval time1, struct timeval time2) {
  struct timeval diff;

  diff.tv_sec = time2.tv_sec - time1.tv_sec;
  diff.tv_usec = time2.tv_usec - time1.tv_usec;

  /* Check if time2 usec was less than time1 usec.
     If so, need to wraparound. */
  if (diff.tv_usec < 0) {
    // It was! So, add 1,000,000 (one whole second) usec to usec
    // and decrease sec by one to match.
    diff.tv_sec--;
    diff.tv_usec += USEC_IN_SEC;
  }

  return diff;
}
