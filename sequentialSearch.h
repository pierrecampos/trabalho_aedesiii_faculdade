#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Custom library
#include "structures.h"
#include "useful.h"

// void resetSequential();
int seqSearch(char *word, int totalWords);
int insertSeq(char *word);
void printSequential(int totalWords);
int getUseSeq();
void deallocateSeq(int totalWords);

//Splitter Function
int getInsertedWords();