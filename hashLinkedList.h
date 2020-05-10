#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Custom library
#include "useful.h"
#include "sortWords.h"
#include "rehash.h"
#include "structures.h"

int prepareInsertionLH(char *word);
hash* createLH(int tableSize);
int insertlinkedHash(wordStruct *tempWS, int position);
void printLH(wordStruct *tempS[]);
void preparePrintLH();
void sortLH(wordStruct *tempWS[]);
int getUseLH();
void deallocateLH();

//Splitter Function
int getTotalWords();
int getInsertedWords();
