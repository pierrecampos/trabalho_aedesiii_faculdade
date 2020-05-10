#include "binarySearch.h"

wordStruct *binStructure[MAXWORDS];
wordStruct *aux;
int useBinSearch = 0;

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

int insertBin(char *word){

    int position = getInsertedWords();

    binStructure[position] = (wordStruct *)malloc(sizeof(wordStruct));
    isNullVector(binStructure, position);
        
    strcpy(binStructure[position]->word, word);
    binStructure[position]->frequency = 1;   

    return 1;
}

void printBinary(int totalWords){      
    int i;
    for(i = 0; i < totalWords; i++){
        printf("%-20s\t->\t %d\n", binStructure[i]->word, binStructure[i]->frequency);
    }    
}

int getUseBinSearch(){
    return useBinSearch;
}

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