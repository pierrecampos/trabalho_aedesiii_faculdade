#include "useful.h"

int sizeFile(char *urlFile){
    
    int len;
    FILE *fp = fopen(urlFile, "r");

    if(fp == NULL){
        perror("\n\aError");
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);

    return len;
}

int typesOfresearch(char *type){
    int typeOfResearch = -1;
    if(strcmp(type, "pseq") == 0) typeOfResearch = 0;    
    if(strcmp(type, "pbinaria") == 0) typeOfResearch = 1;    
    if(strcmp(type, "arvore") == 0) typeOfResearch = 2;    
    if(strcmp(type, "haberto") == 0) typeOfResearch = 3;    
    if(strcmp(type, "hlista") == 0) typeOfResearch = 4;
    
    return typeOfResearch;
}

void isNullVector(wordStruct *testStructure[], int position){
    if(testStructure[position] == NULL){
        printf("Unexpected Error");
        exit(0);
    }
}

void isNull(wordStruct *testStructure){
    if(testStructure == NULL){
        printf("Unexpected Error");
        exit(0);
    }
}

int countWords(char *string){

    char *cpyString = strdup(string);
    int count = 0;   
    char *words = NULL;
    
    words = strtok(cpyString, " ?!.,:()-0123456789\"\n\t");
    while(words != NULL){
        if(strlen(words) <= 20){
            count++;
        }
            words = strtok(NULL, " ?!.,:()-0123456789\"\n\t");
    }

    free(cpyString);
    cpyString = NULL;
    free(words);
    words = NULL;
    
    return count;
}