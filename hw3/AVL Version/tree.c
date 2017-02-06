/*
 *  tree.c
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Danniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
extern FILE *out;
extern int unique_words;
int max(int a,int b){
	if(a<b)return b;
	return a;
}
// Get Balance factor of node N
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->Left) - height(N->Right);
}

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
node *rightRotate(node *y)
{
    node *x = y->Left;
    node *T2 = x->Right;

    // Perform rotation
    x->Right = y;
    y->Left = T2;

    // Update heights
    y->height = max(height(y->Left), height(y->Right))+1;
    x->height = max(height(x->Left), height(x->Right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
node *leftRotate(node *x)
{
    node *y = x->Right;
    node *T2 = y->Left;

    // Perform rotation
    y->Left = x;
    x->Right = T2;

    //  Update heights
    x->height = max(height(x->Left), height(x->Right))+1;
    y->height = max(height(y->Left), height(y->Right))+1;

    // Return new root
    return y;
}
node* add(node *now,char *word){
	if(now==NULL){
		unique_words++;
		now=malloc(sizeof(node));

		now->Left=NULL;
		now->Right=NULL;
		now->count=1;
		now->height=1;
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


	now->height = 1 + max(height(now->Left),
            			  height(now->Right));

    int balance = getBalance(now);

    if(balance > 1 && compare(word,now->Left->node_word)==1)
    	return rightRotate(now);

    if(balance < -1 && compare(word,now->Right->node_word)==-1)
    	return leftRotate(now);

    // Left Right Case
    if (balance > 1 && compare(word,now->Left->node_word)==1)
    {
        now->Left =  leftRotate(now->Left);
        return rightRotate(now);
    }

    // Right Left Case
    if (balance < -1 && compare(word,now->Right->node_word)==-1)
    {
    	now->Right = rightRotate(now->Right);
        return leftRotate(now);
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
