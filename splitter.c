#include "splitter.h"   

int insertedWords = 0;
int totalWords = 0;

void split(char *string, int typeOfResearch){   
    
    totalWords = countWords(string);
    char *split = NULL;
    char *compareNextWord = NULL;
    
    split = strtok(string, " ");        
    while(split != NULL){
        if(insertedWords < MAXWORDS || strcmp(split, compareNextWord) == 0){
            compareNextWord = strdup(split);
            insertedWords += structureCtrol(split, typeOfResearch, insertedWords);        
        }
            split = strtok(NULL, " ");
    }

    printCall(typeOfResearch, insertedWords);
        
    free(split);
    split = NULL;
    free(compareNextWord);
    compareNextWord = NULL;
}

int getInsertedWords(){
    return insertedWords;
}

int getTotalWords(){
    return totalWords;
}

