#include "openFile.h"

//Global Pointer
char *stringToMain; 

char* openFile(char *urlFile, int sizeOfFile){

    FILE *file;
    file = fopen(urlFile, "r");
    char textLine[sizeOfFile];
    char string[sizeOfFile];
    
    strcpy(string, "");

    if(file == NULL){
        perror("\n\aError");
        exit(0);
    }    
    
    while(fgets(textLine, sizeOfFile, file) != NULL){        
        strcat(string, textLine);        
    }    
    fclose(file);    

    sort(string);    
    stringToMain = string;
        
    return stringToMain;
}

void clearPointerOF(){
    free(stringToMain);
    stringToMain = NULL;   
}
