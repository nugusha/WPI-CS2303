/*
 * life.c
 * Created by Nugzar Chkhaidze nchkhaidze
 */
#include<stdlib.h>
#include<stdio.h>

#include"life.h"

char print,pause;
int rows,columns,gens;

int main(int argc, char *argv[]){
	FILE *fp;


	rows = atoi(argv[1]);
	columns = atoi(argv[2]);
	gens = atoi(argv[3]);
	fp = fopen(argv[4],"r");
	print = argv[5][0];
	pause = argv[6][0];

	if(rows<=0 || columns<=0){
		printf("Wrong dimensions\n");
		return 0;
	}
	if(argc!=7){
		printf("Wrong number of arguments\n");
		return 0;
	}
	if(!fp){
		printf("No file!\n");
		return 0;
	}
	if(print!='y' && print!='n'){
			printf("Wrong character for print\n");
			return 0;
	}
	if(pause!='y' && pause!='n'){
			printf("Wrong character for pause\n");
			return 0;
	}




	int **B  = (int **)malloc(sizeof(int*)*rows);
	for (int i = 0; i < rows; i++) {// iterate through rows and create a row
		B[i] = (int*)malloc(columns * sizeof (int));
	}

	int cur_row=0;
	int cur_col=0;

	while(1){// read characters until eof
		char c=fgetc(fp);
		if(feof(fp))break;
	//	printf("%d %d %d <----\n",cur_row,cur_col,c+0);
		if(c==13)continue;
		if(c=='\n'){
			cur_col=0;
			cur_row++;
		}else
		if(c!='x' && c!='o'){
			printf("Wrong Character\n");
			return 0;
		}else{

			B[cur_row][cur_col]=(c=='x');// stores 'x' as 1
			cur_col++;// stores 'o'as 0
		}
	}


/*
	printf("%d %d %d\n",rows,columns,gens);
*/
	print_array(rows,columns,B);


	PlayOne(rows,columns,B,B,gens);


    for(int i=0;i<rows;i++){
    	free(B[i]);
    }
    free(B);


	return 0;
}
