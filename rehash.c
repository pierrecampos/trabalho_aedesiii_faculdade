#include "rehash.h"

hash *reHash = NULL;
int useReHash = 0;

int prepareInsertionReHash(char *word){
    if(reHash == NULL) reHash = createHash(getTotalWords());    

    wordStruct *tempWS = (wordStruct*)malloc(sizeof(wordStruct));
    isNull(tempWS);
    strcpy(tempWS->word, word);
    tempWS->frequency = 1;   

    int position = genPosition(tempWS->word);    
    int result = insertReHash(tempWS, position);
    
    return result;
}

hash* createHash(int tableSize){
    hash* reHash = (hash*)malloc(sizeof(hash));
    
    if(reHash != NULL){
        int i;
        reHash->tableSize = tableSize;
        reHash->tableHash = (wordStruct**)malloc(tableSize * sizeof(wordStruct*));
        if(reHash->tableHash == NULL){
            free(reHash);
            return NULL;
        }
                
        for(i = 0; i < reHash->tableSize; i++){
            reHash->tableHash[i] = NULL;
        }
    }
    return reHash;
}

int insertReHash(wordStruct *tempWS, int position){
    if(reHash == NULL) return 0;

    int i, newPosition;

    for(i = 0; i < reHash->tableSize; i++){
        newPosition = linearPolling(position, i);        
        if(reHash->tableHash[newPosition] == NULL){
            reHash->tableHash[newPosition] = tempWS;            
            return 1;
        }
        else if(strcmp(reHash->tableHash[newPosition]->word, tempWS->word) == 0){
            reHash->tableHash[newPosition]->frequency++;            
            useReHash++;
            return 0;
        }
        useReHash++;
    }
    
}

int genPosition(char *word){
    int key = valueString(word);
    int position = hashingDivision(key);

    return position;
}

int hashingDivision(int key){    
    return (key & 0x7FFFFFFF) % getTotalWords();
}

int valueString(char *string){
    int i, value = 7;
    int length = strlen(string);
    for(i = 0; i < length; i++){
        value = 31 * value + (int) string[i];
    }
    return value;
}

int linearPolling(int position, int attempt){    
    return ((position + attempt) & 0x7FFFFFFF) % getTotalWords();
}

void sortReHash(){
    int i, j;
    wordStruct *aux = NULL;    

    for(i = 0; i < getTotalWords(); i++){
        if(reHash->tableHash[i] != NULL){
            for(j = i + 1; j < getTotalWords(); j++){
                if(reHash->tableHash[j] != NULL){
                    if(strcmp((reHash->tableHash[i])->word, (reHash->tableHash[j])->word) > 0){
                        aux = reHash->tableHash[i];
                        reHash->tableHash[i] = reHash->tableHash[j];;
                        reHash->tableHash[j] = aux;
                    }
                }
            }                
        }
    }

    free(aux);
    aux = NULL;
}

void printReHash(){
    sortReHash();
    int i;
    for(i = 0; i < getTotalWords(); i++){
        if(reHash->tableHash[i] != NULL){
            printf("%-20s\t->\t %d\n", (reHash->tableHash[i])->word, (reHash->tableHash[i])->frequency);
        }
    }   
}

int getUseReHash(){
    return useReHash;
}

void deallocateReHash(){
    if(reHash != NULL){
        int i;
        for(i = 0; i < getTotalWords(); i++){
            if(reHash->tableHash[i] != NULL){
                free(reHash->tableHash[i]);
                reHash->tableHash[i] = NULL;
            }
        }
        free(reHash->tableHash);
        free(reHash);
        reHash = NULL;
    }
}
