#include "sequentialSearch.h"

//Variáveis, Estruturas Globais
wordStruct *seqStructure[MAXWORDS];
wordStruct *aux;
int useSeq = 0;

//Função responsável por pesquisar uma palavra na estrutura, se houver duplicatas aumenta a frequência daquela palavra
int seqSearch(char *word, int totalWords){        
    int i;
    if(totalWords == 0) return insertSeq(word);

    for(i = 0; i < totalWords; i++){
        useSeq++;        
        if(strcmp(word, seqStructure[i]->word) == 0){
            seqStructure[i]->frequency++;
            return 0;
        }
    }    
    return insertSeq(word);  
}

//Função que insere uma nova palavra para a estrutura
int insertSeq(char *word){
    
    int position = getInsertedWords();
    seqStructure[position] = (wordStruct *)malloc(sizeof(wordStruct));
    isNullVector(seqStructure, position);
    
    strcpy(seqStructure[position]->word, word);
    seqStructure[position]->frequency = 1;
    
    return 1;
}

//Função que imprime de forma formatada as palavras presente na estrutura
void printSequential(int totalWords){   
  
    int i;
    for(i = 0; i < totalWords; i++){
        printf("%-20s\t->\t %d\n", seqStructure[i]->word, seqStructure[i]->frequency);
    }
}

//Função responsável por retornar o uso da estrutura
int getUseSeq(){
    return useSeq;
}

//Função responsável por desalocar os ponteiros
void deallocateSeq(int totalWords){
    int i;
    for(i = totalWords; i >= 0; i--){
        free(seqStructure[i]);
        seqStructure[i] = NULL;
    }
    free(aux);
    aux = NULL;
    free(*seqStructure);
    *seqStructure = NULL;
}


