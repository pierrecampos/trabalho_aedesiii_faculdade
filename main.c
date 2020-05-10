#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<locale.h>

//Custom library
#include "openFile.h"
#include "useful.h"
#include "splitter.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, NULL);

    if(argv[2] == NULL){
        printf("\n\aNecessário um arquivo -> Exemplo de chamada: \"./main pseq file.txt\"\n");
        exit(0);
    }

    clock_t runtime;
    runtime = clock();

    char typesOfStructures[][35] = {"Pesquisa Sequencial", "Pesquisa Binária", "Árvore Binária Sem Balanceamento",
                                     "Hash Endereçamento Aberto", "Hash Lista Encadeada"};
    
    int typeOfResearch = typesOfresearch(argv[1]);    


    if(typeOfResearch != -1){
        int sizeOfFile = sizeFile(argv[2]);
        char string[sizeOfFile];
        
        strcpy(string, openFile(argv[2], sizeOfFile));
        clearPointerOF();
        
        printf("\n\t\t-- CAÇA PALAVRAS --\n");
        printf("\n\tPALAVRAS \t-> \tFREQUÊNCIA\n\n");
        split(string, typeOfResearch);

        runtime = clock() - runtime;
        printf("\n\n\t\tINFORMAÇÕES:");
        printf("\n\nTotal de Palavras Únicas: %d",  getInsertedWords());
        printf("\nTipo de Pesquisa: %s", typesOfStructures[typeOfResearch]);      
        printf("\nTempo de Execução: %g ms", (double)runtime);
    }
    else{
        printf("Pesquisa Inválida");        
    }


}