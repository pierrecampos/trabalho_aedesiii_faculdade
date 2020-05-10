#include "sortWords.h"

//Função responsável por coletar apenas palavras válidas e ordernar em ordem alfábetica
void sort(char* string){
           
    int i = 0, j;
    int count = countWords(string);    
    char vectWords[count][21];
    char *word = NULL;
    char aux[21];

    //Separa as palavras e as insere em uma matriz para que logo seja possível ordenalas
    word = strtok(string, " ?!.,:()-0123456789\"\n\t");    
    while(word != NULL){
        //Transforma palavras em minúsculas
        strlwr(word);
        if(strlen(word) <= 20){
            strcpy(vectWords[i], word);
            i++;
        }
        word = strtok(NULL, " ?!.,:()-0123456789\"\n\t");
    }
    
    //Faz a ordenação do vetor em ordem alfábetica
    for(i = 0; i < count; i++){
        for(j = i + 1; j < count; j++){
            if(strcmp(vectWords[j], vectWords[i]) < 0){
                strcpy(aux, vectWords[i]);
                strcpy(vectWords[i], vectWords[j]);
                strcpy(vectWords[j], aux);
            }                
        }        
    }

    //Cópia as palavras já ordenadas novamente para a string
    strcpy(string, "");
    for(i = 0; i < count; i++){        
        strcat(string, vectWords[i]);
        strcat(string, " ");
    }
    
    free(word);
    word = NULL;
}