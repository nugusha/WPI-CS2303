/*
 *  tree.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Danniel Sullivan
 */

#ifndef TREE_H_
#define TREE_H_


int Total;
struct avl_vertex{
	int count,height;
	char *node_word;

	struct avl_vertex *Left;
	struct avl_vertex *Right;
};
typedef struct avl_vertex node;

node* add(node *now,char *word);
void  print_words(node *x);
int compare(char *A,char*B);
node *rightRotate(node *y);
node *leftRotate(node *x);
int getBalance(node *N);
int height(node *N);


#endif /* TREE_H_ */
