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

    //Verifica se há argumento no argv[2]
    if(argv[2] == NULL){
        printf("\n\aNecessário um arquivo -> Exemplo de chamada: \"./main pseq file.txt\"\n");
        exit(0);
    }

    //Variável para calcular tempo de execução
    clock_t runtime;
    //Atribui o valor inicial de execução
    runtime = clock();

    //Array para guardar nomes de estruturas, útil para impressão de informações
    char typesOfStructures[][35] = {"Pesquisa Sequencial", "Pesquisa Binária", "Árvore Binária Sem Balanceamento",
                                     "Hash Endereçamento Aberto", "Hash Lista Encadeada"};
    
    //Define o tipo de Pesquisa atráves de uma função que faz o tratamento do dado passado por argumento
    int typeOfResearch = typesOfResearch(argv[1]);    

    //Executa o bloco abaixo caso o valor de typeOfResearch seja diferente de -1
    if(typeOfResearch != -1){

        //Coleta o número de bytes do arquivo
        int sizeOfFile = sizeFile(argv[2]);
        //Define uma variável com o tamanho de bytes do arquivo
        char string[sizeOfFile];
        
        //Através da função openFile é copiado para a var. string todo o conteúdo do arquivo
        openFile("file.txt", sizeOfFile, string);        
                
        printf("\n\t\t-- CAÇA PALAVRAS --\n");
        printf("\n\tPALAVRAS \t-> \tFREQUÊNCIA\n\n");

        //Através da função split, é separado as palavras, que passam por tratamento e por sua devida estrutura
        split(string, typeOfResearch);

        //Encerra o tempo de execução
        runtime = clock() - runtime;
        
        //Exibe informações na tela
        printf("\n\n\t\tINFORMAÇÕES:");
        printf("\n\nTotal de Palavras Únicas: %d",  getInsertedWords());
        printf("\nTipo de Pesquisa: %s", typesOfStructures[typeOfResearch]);      
        printf("\nTempo de Execução: %g ms", (double)runtime);
    }
    //Caso o tipo de pesquisa seja inválido
    else{
        printf("Pesquisa Inválida");        
    }


}