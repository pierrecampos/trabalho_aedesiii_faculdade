#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Custom library
#include "structures.h"
#include "useful.h"

int prepareInsertionBTree(char *word);
int insertNode(node** root, wordStruct wS);
void printTree(node* root);
node* getRoot();
int getUseBinTree();
void deallocateTree(node* root);

//Splitter Function
int getInsertedWords();