#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Custom library
#include "structures.h"
#include "useful.h"


int binSearch(int left, int right, char *word);
int insertBin(char *word);
void printBinary(int totalWords);
int getUseBinSearch();
void deallocateBin(int totalWords);

//Splitter Function
int getInsertedWords();