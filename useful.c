#include "useful.h"

//Implementação da biblioteca useful, destinada a oferecer pequenas funções para todo o programa

//Define o tamanho do arquivo em bytes
int sizeFile(char *urlFile){
    
    int len;
    FILE *fp = fopen(urlFile, "r");

    if(fp == NULL){
        perror("\n\aError");
        exit(0);
    }
    //Reposiciona o indicador de posição de fluxo ao *fim do arquivo (*SEEK_END) 
    fseek(fp, 0, SEEK_END);
    //Retorna o valor atual do indicador de posição do fluxo através da função ftell
    len = ftell(fp);
    fclose(fp);

    return len;
}

//Converte o argumento de pesquisa de char para um valor inteiro
int typesOfResearch(char *type){
    int typeOfResearch = -1;
    if(strcmp(type, "pseq") == 0) typeOfResearch = 0;    
    if(strcmp(type, "pbinaria") == 0) typeOfResearch = 1;    
    if(strcmp(type, "arvore") == 0) typeOfResearch = 2;    
    if(strcmp(type, "haberto") == 0) typeOfResearch = 3;    
    if(strcmp(type, "hlista") == 0) typeOfResearch = 4;
    
    return typeOfResearch;
}

//Verifica se o vetor de ponteiro do tipo wordStruct é nulo
void isNullVector(wordStruct *testStructure[], int position){
    if(testStructure[position] == NULL){
        printf("Unexpected Error");
        exit(0);
    }
}
//Verifica se o ponteiro do tipo wordStruct é nulo
void isNull(wordStruct *testStructure){
    if(testStructure == NULL){
        printf("Unexpected Error");
        exit(0);
    }
}
//Faz a contagem do número de palavras válidas
int countWords(char *string){

    //É utilizado uma cópia da string original para evitar bugs quando se utiliza strtok
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