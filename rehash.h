#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Custom library
#include "useful.h"
#include "sortWords.h"

int prepareInsertionReHash(char *word);
hash* createHash(int tableSize);
int insertReHash(wordStruct *tempWS, int position);
int genPosition(char *word);
int hashingDivision(int key);
int valueString(char *string);
int linearPolling(int position, int attempt);
void sortReHash();
void printReHash();
int getUseReHash();
void deallocateReHash();



//Splitter Function
int getTotalWords();
int getInsertedWords();
