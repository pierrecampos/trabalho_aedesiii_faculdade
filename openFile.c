#include "openFile.h"

//Abre o arquivo, faz uma cópia de toda sua informação para a variável string
void openFile(char *urlFile, int sizeOfFile, char *string){

    FILE *file;
    file = fopen(urlFile, "r");
    char textLine[sizeOfFile];
    
    if(file == NULL){
        perror("\n\aError");    
        exit(0);
    }    
    
    memset(string, '\0', sizeOfFile);
    while(fgets(textLine, sizeOfFile, file) != NULL){        
        strcat(string, textLine);        
    }    
    fclose(file);    

    //Função responsável por coletar apenas palavras válidas e ordernar em ordem alfábetica
    sort(string);
}
