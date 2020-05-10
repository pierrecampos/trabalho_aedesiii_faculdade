#include "hashLinkedList.h"

hash *linkedHash = NULL;
wordStruct *auxInsert = NULL;
int useLH = 0;

int prepareInsertionLH(char *word){
    if(linkedHash == NULL) linkedHash = createLH(getTotalWords());    

    wordStruct *tempWS = (wordStruct*)malloc(sizeof(wordStruct));
    isNull(tempWS);
    strcpy(tempWS->word, word);
    tempWS->frequency = 1;
    tempWS->next = NULL;

    // genPosition gera o Hashing, a função está presente no arquivo reHash.c e é reutilizado
    int position = genPosition(tempWS->word); 
    int result = insertlinkedHash(tempWS, position);
        
    return result;
}

hash* createLH(int tableSize){
    hash* linkedHash = (hash*)malloc(sizeof(hash));
    
    if(linkedHash != NULL){        
        int i;
        linkedHash->tableSize = tableSize;
        linkedHash->tableHash = (wordStruct**)malloc(tableSize * sizeof(wordStruct*));
        if(linkedHash->tableHash == NULL){
            free(linkedHash);
            return NULL;
        }       
        
        for(i = 0; i < linkedHash->tableSize; i++){
            linkedHash->tableHash[i] = NULL;            
        }
    }
    return linkedHash;
}

int insertlinkedHash(wordStruct *tempWS, int position){
    if(linkedHash == NULL) return 0;                
    int i;   
        
    if(linkedHash->tableHash[position] == NULL){
        linkedHash->tableHash[position] = tempWS;        
        return 1;
    }
    else if(strcmp(linkedHash->tableHash[position]->word, tempWS->word) == 0){
        useLH++;
        linkedHash->tableHash[position]->frequency++;                       
        return 0;
    }
    else if(linkedHash->tableHash[position]->next == NULL){
        linkedHash->tableHash[position]->next = tempWS;         
        return 1;        
    }
    else{
        auxInsert = linkedHash->tableHash[position]->next;            
        while(auxInsert != NULL){
            useLH++;                
            if(strcmp(auxInsert->word, tempWS->word) == 0){
                auxInsert->frequency++;                
                return 0;
            }                
            auxInsert = auxInsert->next;
        }
        tempWS->next = linkedHash->tableHash[position]->next;
        linkedHash->tableHash[position]->next = tempWS;
        
        return 1;
    }
} 

void printLH(wordStruct *tempS[]){    
    int i;

    for(i = 0; i < getInsertedWords(); i++){
        printf("%-20s\t->\t %d\n", tempS[i]->word, tempS[i]->frequency);
    } 
    
}

void preparePrintLH(){    
    int i;
    int j = 0;       
    wordStruct *tempS[getInsertedWords()];
    wordStruct *aux;

    for(i = 0; i < getTotalWords(); i++){
        if(linkedHash->tableHash[i] != NULL){
            if(linkedHash->tableHash[i]->next != NULL){
                aux = linkedHash->tableHash[i]->next;
                while(aux != NULL){
                    tempS[j] = aux;
                    aux = aux->next;
                    j++;
                }                
            }
            tempS[j] = linkedHash->tableHash[i];            
            j++;
        }
    }
    sortLH(tempS);
    printLH(tempS);

    for(i = 0; i < getInsertedWords(); i++){
        free(tempS[i]);
        tempS[i] = NULL;
    }
    free(tempS);
    free(aux);
    aux = NULL;
}

void sortLH(wordStruct *tempWS[]){
    int i, j;
    wordStruct *aux = NULL;

    for(i = 0; i < getInsertedWords(); i++){        
        for(j = i + 1; j < getInsertedWords(); j++){                
            if(strcmp(tempWS[i]->word, tempWS[j]->word) > 0){
                aux = tempWS[i];
                tempWS[i] = tempWS[j];
                tempWS[j] = aux;
            }
        }
    }
    free(aux);
    aux = NULL;
}

int getUseLH(){
    return useLH;
}

void deallocateLH(){
    int i;
    wordStruct *aux = NULL;
    wordStruct *trash = NULL;

    for(i = 0; i < getTotalWords(); i++){
        if(linkedHash->tableHash[i] != NULL){
            if(linkedHash->tableHash[i]->next != NULL){
                aux = linkedHash->tableHash[i]->next;
                while(aux != NULL){
                    trash = aux;
                    aux = aux->next;
                    free(trash);
                    trash = NULL;
                }
            }
            free(linkedHash->tableHash[i]);
            linkedHash->tableHash[i] = NULL;            
        }
    }    
    free(aux);
    aux = NULL;    
    free(trash);
    trash = NULL;
    free(linkedHash);
    linkedHash = NULL;
    free(auxInsert);
    auxInsert = NULL;
}





