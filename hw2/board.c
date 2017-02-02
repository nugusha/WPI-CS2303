/*
 * board.c
 * Created by Nugzar Chkhaidze nchkhaidze
 */
#include<stdlib.h>
#include<stdio.h>
#include"life.h"

char print,pause;
void print_array(int rows,int columns,int *A[]){
	for(int i=0;i<rows;i++){
			for(int j=0;j<columns;j++)
				if(A[i][j])printf("x");else
						printf("o");
			printf("\n");
		}
	return;
}// print_array
void PlayOne(int rows,int columns,int *A[],int *B[],int gens){
	if(gens==0)return;

	int **C  = (int **)malloc(sizeof(int*)*rows);
	int **nei  = (int **)malloc(sizeof(int*)*rows);
	for (int i = 0; i < rows; i++) {
		C[i] = (int *)malloc(columns * sizeof (int));
	}
	for (int i = 0; i < rows; i++) {
		nei[i] = (int*)malloc(columns * sizeof (int));
	}


	for(int i=0;i<rows;i++)// initialize C and nei
		for(int j=0;j<columns;j++)C[i][j]=nei[i][j]=0;

	for(int i=0;i<rows;i++)// iterate though each cell and add to
		for(int j=0;j<columns;j++){//  neighbours if cell is alive
			if(B[i][j]){
				if(i>0)nei[i-1][j]++;
				if(j>0)nei[i][j-1]++;
				if(i+1<rows)nei[i+1][j]++;
				if(j+1<columns)nei[i][j+1]++;

				if(i && j)nei[i-1][j-1]++;
				if(i && j+1<columns)nei[i-1][j+1]++;
				if(i+1<rows && j)nei[i+1][j-1]++;
				if(i+1<rows && j+1<columns)nei[i+1][j+1]++;
			}
		}

	for(int i=0;i<rows;i++)// iterate thought each cell and
		for(int j=0;j<columns;j++){// determine who lives and dies
			if(nei[i][j]<=1 || nei[i][j]>=4)
				C[i][j]=0;else
			if(!B[i][j] && nei[i][j]==3)
				C[i][j]=1;else
			if(B[i][j])C[i][j]=1;else C[i][j]=0;
		}

	if(pause=='y')getchar();
	if(print=='y'){
		print_array(rows,columns,C);
		if(pause=='n')printf("\n");
	}

	int flag1=0,flag2=0,flag3=0;
	for(int i=0;i<rows;i++)// check if B is equal to C
			for(int j=0;j<columns;j++)
				if(B[i][j]!=C[i][j])flag1=1;

	for(int i=0;i<rows;i++)
			    for(int j=0;j<columns;j++)// check if A is C
					if(A[i][j]!=C[i][j])flag2=1;

	for(int i=0;i<rows;i++)
			    for(int j=0;j<columns;j++)// check if all cells are dead
					if(C[i][j]>0)flag3=1;


    for(int i=0;i<rows;i++){
    	free(nei[i]);
    }
free(nei);

    if(!flag1 || !flag2 || !flag3){
    	return;
    }


	PlayOne(rows,columns,B,C,gens-1);

    for(int i=0;i<rows;i++){
    	free(C[i]);
    }
    free(C);

    return;
}// PlayOne


