/*
 *  tree.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Danniel Sullivan
 */

#ifndef TREE_H_
#define TREE_H_


int Total;
struct bst_vertex{
	int count;
	char *node_word;

	struct bst_vertex *Left;
	struct bst_vertex *Right;
};
typedef struct bst_vertex node;

node* add(node *now,char *word);
void  print_words(node *x);
int compare(char *A,char*B);

#endif /* TREE_H_ */
