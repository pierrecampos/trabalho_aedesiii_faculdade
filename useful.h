#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Custom library
#include "structures.h"

int sizeFile(char *urlFile);
int typesOfresearch(char *type);
void isNullVector(wordStruct *testStructure[], int position);
void isNull(wordStruct *testStructure);
int countWords(char *string);