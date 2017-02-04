#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"
extern int Total;
FILE *out;
FILE **in;
int main(int argc, char *argv[]) {
	out=fopen(argv[1],"w");
	in=malloc((argc-2)*sizeof(FILE));

	for(int i=2;i<argc;i++){
		in[i-2]=fopen(argv[i],"r");
	}
	char *word;
	word=malloc(100*sizeof(char));

	char ***words=(char ***)malloc(sizeof(char**)*(argc-2));
	int *wordsize=malloc(sizeof(int)*(argc-2));

	for(int i=0;i<argc-2;i++){
		int counter=0,p=1;
		while(1){
			p=fscanf(in[i],"%s",word);
			if(p!=1)break;
			word=strdup(change(word));
			if(strlen(word)>0)
				counter++,Total++;
		}
		words[i]=(char **)malloc(sizeof(char*)*counter);
		wordsize[i]=counter;
		rewind(in[i]);

		int N=0;
		p=1;
		while(1){
			p=fscanf(in[i],"%s",word);

			if(p!=1)break;

			word=strdup(change(word));
			if(strlen(word)==0)continue;

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

	return 0;
}
