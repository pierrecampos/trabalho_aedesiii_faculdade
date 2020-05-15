#include "hashLinkedList.h"

//Variáveis, Estruturas Globais
hash *linkedHash = NULL;
wordStruct *auxInsert = NULL;
int useLH = 0;

//Insere a palavra em uma estrutura, aloca uma estrutura **
int prepareInsertionLH(char *word){
    //Chama uma função para que inicialize uma tabela hash **
    if(linkedHash == NULL) linkedHash = createLH(getTotalWords());    

    wordStruct *tempWS = (wordStruct*)malloc(sizeof(wordStruct));
    isNull(tempWS);
    strcpy(tempWS->word, word);
    tempWS->frequency = 1;
    tempWS->next = NULL;

    // genPosition gera o Hashing, a função está presente no arquivo reHash.c (reutilização)
    int position = genPosition(tempWS->word);
    
    //Função responsável por inserir uma palavra na estrura (Retorna 1 Inseriu, Retorna 0 Duplicata)
    int result = insertlinkedHash(tempWS, position);
        
    return result;
}

//Aloca uma estrutura ** (tabela hash)
hash* createLH(int tableSize){
    hash* linkedHash = (hash*)malloc(sizeof(hash));
    
    if(linkedHash != NULL){        
        int i;
        linkedHash->tableSize = tableSize;
        linkedHash->tableHash = (wordStruct**)malloc(tableSize * sizeof(wordStruct*));
        //Teste de alocação
        if(linkedHash->tableHash == NULL){
            free(linkedHash);
            return NULL;
        }       
        
        //Inicializa cada estrutura * para NULL
        for(i = 0; i < linkedHash->tableSize; i++){
            linkedHash->tableHash[i] = NULL;            
        }
    }
    return linkedHash;
}

//Pesquisa e insere uma palavra(dentro de uma estrutura) ou aumenta sua frequência (duplicata)
int insertlinkedHash(wordStruct *tempWS, int position){
    if(linkedHash == NULL) return 0;                
    int i;   
    
    //Se aquela posição for NULA, então insere
    if(linkedHash->tableHash[position] == NULL){
        linkedHash->tableHash[position] = tempWS;        
        return 1;
    }
    //Se aquela posição houver uma palavra idêntica, aumenta sua frequência
    else if(strcmp(linkedHash->tableHash[position]->word, tempWS->word) == 0){
        useLH++;
        linkedHash->tableHash[position]->frequency++;
        free(tempWS);                       
        return 0;
    }
    //Se a palavra não for idêntica, então é verificiado se na lista encadeada há algum valor, em caso negativo, insere a palavra
    else if(linkedHash->tableHash[position]->next == NULL){
        linkedHash->tableHash[position]->next = tempWS;         
        return 1;        
    }
    //Se na primeira posição da lista encadeada daquela posição não for nulo, segue os testes:
    else{
        //Enquanto for diferente de nulo é percorrido a lista encadeada verificando possivél duplicata
        auxInsert = linkedHash->tableHash[position]->next;            
        while(auxInsert != NULL){
            useLH++;                
            if(strcmp(auxInsert->word, tempWS->word) == 0){
                auxInsert->frequency++;
                free(tempWS);                
                return 0;
            }                
            auxInsert = auxInsert->next;
        }
        //Se não houver duplicata, então é inserido no começo da lista encadeada um novo valor(Utiliza conceito de PUSH)
        tempWS->next = linkedHash->tableHash[position]->next;
        linkedHash->tableHash[position]->next = tempWS;
        
        return 1;
    }
} 

//Função que imprime de forma formatada as palavras presente na estrutura
void printLH(wordStruct *tempS[]){    
    int i;

    for(i = 0; i < getInsertedWords(); i++){
        printf("%-20s\t->\t %d\n", tempS[i]->word, tempS[i]->frequency);
    } 
    
}
//Prepara os dados antes da impressão, é coleta todas as palavras, inclusive na lista encadeada
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
    //Chama a função de ordenação alfabética desta estrutura
    sortLH(tempS);
    //Chama a função responsável por imprimir
    printLH(tempS);

    //Desvinculando Ponteiro
    for(i = 0; i < getInsertedWords(); i++){
        tempS[i] = NULL;
    }
    aux = NULL;
}

//Organiza de forma alfabética
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

    aux = NULL;
}

//Retorna o uso da estrutura
int getUseLH(){
    return useLH;
}

//Função responsável por desalocar os ponteiros
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
    aux = NULL;
    trash = NULL;
    free(linkedHash);
    linkedHash = NULL;
    free(auxInsert);
    auxInsert = NULL;
}





