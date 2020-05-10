#include "sortWords.h"

void sort(char* string){
           
    int i = 0, j;
    int count = countWords(string);    
    char vectWords[count][21];
    char *word = NULL;
    char aux[21];

    word = strtok(string, " ?!.,:()-0123456789\"\n\t");    
    while(word != NULL){
        strlwr(word);
        if(strlen(word) <= 20){
            strcpy(vectWords[i], word);
            i++;
        }
        word = strtok(NULL, " ?!.,:()-0123456789\"\n\t");
    }

    for(i = 0; i < count; i++){
        for(j = i + 1; j < count; j++){
            if(strcmp(vectWords[j], vectWords[i]) < 0){
                strcpy(aux, vectWords[i]);
                strcpy(vectWords[i], vectWords[j]);
                strcpy(vectWords[j], aux);
            }                
        }        
    }

    strcpy(string, "");
    for(i = 0; i < count; i++){        
        strcat(string, vectWords[i]);
        strcat(string, " ");
    }
    
    free(word);
}