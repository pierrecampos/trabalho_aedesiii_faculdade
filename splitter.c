#include "splitter.h"   

//Variáveis Globais
int insertedWords = 0;
int totalWords = 0;

//Função responsável por separar as palavras, e logo as enviará para a função de controle de estruturas
void split(char *string, int typeOfResearch){   
    
    //Variável para controle do total de palavras (inclusive duplicatas)
    totalWords = countWords(string);
    char *split = NULL;
    char *compareNextWord = NULL;
    
    //Separa as palavras já tratadas pela função sort
    split = strtok(string, " ");        
    while(split != NULL){
        /*Este teste verifica a quantidade de palavras únicas já inseridas,
         porém testa também se a próxima palavra é uma duplicata*/
        if(insertedWords < MAXWORDS || strcmp(split, compareNextWord) == 0){
            compareNextWord = strdup(split);
            //A palavra agora separada é enviada para o controle de estrutura
            insertedWords += structureCtrol(split, typeOfResearch, insertedWords);        
        }
            split = strtok(NULL, " ");
    }

    //Função responsável por imprimir as palavras já separadas
    printCall(typeOfResearch, insertedWords);
        
    free(split);
    split = NULL;
    free(compareNextWord);
    compareNextWord = NULL;
}

//Função responsável por retorna o número total de palavras únicas inseridas
int getInsertedWords(){
    return insertedWords;
}

//Função responsável por retornar o número total de palavras
int getTotalWords(){
    return totalWords;
}

