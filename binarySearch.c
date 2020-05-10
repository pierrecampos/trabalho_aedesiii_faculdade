#include "binarySearch.h"

//Variáveis, Estruturas Globais
wordStruct *binStructure[MAXWORDS];
wordStruct *aux;
int useBinSearch = 0;

//Função que realiza uma pesquisa utilizando conceito de Pesquisa Binária
int binSearch(int left, int right, char *word){   
        
    int middle = (left + right - 1) / 2;
        
        if(right == 0) return insertBin(word);

        if(left < right){
            
            if(strcmp(binStructure[middle]->word, word) == 0){
                binStructure[middle]->frequency++;
                return 0;
            }
            else if(strcmp(binStructure[middle]->word, word) > 0){ 
                useBinSearch++;               
                return binSearch(left, middle, word);
            }
            else if(strcmp(binStructure[middle]->word, word ) < 0){
                useBinSearch++;
                return binSearch(middle + 1, right, word);
            }
        }    
    return  insertBin(word);
}

//Função para inserir uma palavra na estrutura
int insertBin(char *word){

    int position = getInsertedWords();

    binStructure[position] = (wordStruct *)malloc(sizeof(wordStruct));
    isNullVector(binStructure, position);
        
    strcpy(binStructure[position]->word, word);
    binStructure[position]->frequency = 1;
    binStructure[position]->next = NULL;

    return 1;
}
//Função que imprime de forma formatada as palavras presente na estrutura
void printBinary(int totalWords){      
    int i;
    for(i = 0; i < totalWords; i++){
        printf("%-20s\t->\t %d\n", binStructure[i]->word, binStructure[i]->frequency);
    }    
}

//Função responsável por retornar o uso da estrutura
int getUseBinSearch(){
    return useBinSearch;
}

//Função responsável por desalocar os ponteiros
void deallocateBin(int totalWords){
    int i;
    for(i = totalWords - 1; i >= 0; i--){
        free(binStructure[i]);
        binStructure[i] = NULL;
    }    
    free(aux);
    aux = NULL;
    free(*binStructure);
    *binStructure = NULL;
}