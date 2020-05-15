#include "rehash.h"

//Variáveis, Estruturas Globais
hash *reHash = NULL;
int useReHash = 0;

//Prepara inserção da palavra(dentro de uma estrurura)
int prepareInsertionReHash(char *word){
    if(reHash == NULL) reHash = createHash(getTotalWords());    

    wordStruct *tempWS = (wordStruct*)malloc(sizeof(wordStruct));
    //Verifica alocação
    isNull(tempWS);
    strcpy(tempWS->word, word);
    tempWS->frequency = 1;
    tempWS->next = NULL;

    //genPosition é responsável por transformar a palavra em valor chave e aplicar em uma função hashing - "h(chave)"
    int position = genPosition(tempWS->word);

    //Função responsável por inserir uma palavra na estrura (Retorna 1 Inseriu, Retorna 0 Duplicata)
    int result = insertReHash(tempWS, position);
    
    return result;
}

//Aloca uma estrutura ** (tabela hash)
hash* createHash(int tableSize){
    hash* reHash = (hash*)malloc(sizeof(hash));
    
    if(reHash != NULL){
        int i;
        reHash->tableSize = tableSize;
        reHash->tableHash = (wordStruct**)malloc(tableSize * sizeof(wordStruct*));
        //Teste de alocação
        if(reHash->tableHash == NULL){
            free(reHash);
            return NULL;
        }
        //Inicializa cada estrutura * para NULL
        for(i = 0; i < reHash->tableSize; i++){
            reHash->tableHash[i] = NULL;
        }
    }
    return reHash;
}

//Pesquisa e insere uma palavra(dentro de uma estrutura) ou aumenta sua frequência (duplicata)
int insertReHash(wordStruct *tempWS, int position){
    if(reHash == NULL) return 0;

    int i, newPosition;

    for(i = 0; i < reHash->tableSize; i++){
        /*Se aquela posição estiver nula, insere, se não, verifica duplicata, se os dois casos forem negativos
        então é utilizado o método de Pesquisa Linear para tratar a colisão*/
        newPosition = linearPolling(position, i);        
        if(reHash->tableHash[newPosition] == NULL){
            reHash->tableHash[newPosition] = tempWS;            
            return 1;
        }
        else if(strcmp(reHash->tableHash[newPosition]->word, tempWS->word) == 0){
            reHash->tableHash[newPosition]->frequency++;
            free(tempWS);       
            useReHash++;
            return 0;
        }
        useReHash++;
    }
    
}

//Função responsável por criar uma chave, esta chave é a posição onde será inserido os dados na Tabela Hash
int genPosition(char *word){
    //A palavra se torna um valor inteiro
    int key = valueString(word);
    //Aplica essa key em uma função Hashing
    int position = hashingDivision(key);

    //Retorna a posição para inserção na Tabela Hash
    return position;
}

//Função Hashing
int hashingDivision(int key){    
    return (key & 0x7FFFFFFF) % getTotalWords();
}

//Função responsável por transformar caracter em um valor inteiro
int valueString(char *string){
    int i, value = 7;
    int length = strlen(string);
    for(i = 0; i < length; i++){
        value = 31 * value + (int) string[i];
    }
    return value;
}

//Função para tratar colisão, utiliza Bit E Bit para tratar possível overflow de sinal
int linearPolling(int position, int attempt){    
    return ((position + attempt) & 0x7FFFFFFF) % getTotalWords();
}

//Função para ordenar de forma alfabética as palavras
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

    aux = NULL;
}

//Função que imprime de forma formatada as palavras presente na estrutura
void printReHash(){
    sortReHash();
    int i;
    for(i = 0; i < getTotalWords(); i++){
        if(reHash->tableHash[i] != NULL){
            printf("%-20s\t->\t %d\n", (reHash->tableHash[i])->word, (reHash->tableHash[i])->frequency);
        }
    }   
}

//Função responsável por retornar o uso da estrutura
int getUseReHash(){
    return useReHash;
}

//Função responsável por desalocar os ponteiros
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
