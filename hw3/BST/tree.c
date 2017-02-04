#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
extern FILE *out;
extern int unique_words;
node* add(node *now,char *word){
	if(now==NULL){
		unique_words++;
		now=malloc(sizeof(node));

		now->Left=NULL;
		now->Right=NULL;
		now->count=1;
		now->node_word=malloc(sizeof(char)*(int)strlen(word));
		now->node_word=strdup(word);
		return now;
	}
	int cmp=compare(word,now->node_word);

	if(cmp==0){
		now->count++;
		return now;
	}

	if(cmp==-1){
		now->Left=add(now->Left,word);
	}else{
		now->Right=add(now->Right,word);
	}
	return now;
};
void  print_words(node *now){
	if(now==NULL)return;

	print_words(now->Left);

	fprintf(out,"%6d\t%s\n",now->count,now->node_word);

	print_words(now->Right);
};
int compare(char *A,char *B){
	int len1=strlen(A);
	int len2=strlen(B);
	int min_len=len1;
	if(len2<len1)min_len=len2;

	for(int i=0;i<min_len;i++){
		if(A[i]<B[i])return -1;
		if(A[i]>B[i])return 1;
	}

	if(len1==len2)return 0;
	if(len1>len2)return 1;else
		return -1;
};
