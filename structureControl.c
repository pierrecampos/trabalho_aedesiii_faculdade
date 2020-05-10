#include "structureControl.h"

int totalStructUse = 0;

//Função responsável por chamar a estrutura escolhida ao executar o programa, esta função recebe uma palavra tratada como argumento
int structureCtrol(char *word, int typeOfResearch, int totalWords){   
    
    if(typeOfResearch == 0) return seqSearch(word, totalWords);
    if(typeOfResearch == 1) return binSearch(0, totalWords, word);
    if(typeOfResearch == 2) return prepareInsertionBTree(word);
    if(typeOfResearch == 3) return prepareInsertionReHash(word);
    if(typeOfResearch == 4) return prepareInsertionLH(word);
    
}

//Faz a impressão das palavras já separadas de sua devia estrutura, desaloca ponteiros e retorna o uso total daquela estrutura
void printCall(int typeOfResearch, int totalWords){    
    if(typeOfResearch == 0) {
        printSequential(totalWords);
        deallocateSeq(totalWords);
        totalStructUse = getUseSeq();   
    }
    if(typeOfResearch == 1){
        printBinary(totalWords);
        deallocateBin(totalWords);
        totalStructUse = getUseBinSearch();
    }
    if(typeOfResearch == 2){
        printTree(getRoot());
        deallocateTree(getRoot());  
        totalStructUse = getUseBinTree();      
    }
    if(typeOfResearch == 3){
        printReHash();
        deallocateReHash();
        totalStructUse = getUseReHash();
    }
    if(typeOfResearch == 4){
        preparePrintLH();
        deallocateLH();
        totalStructUse = getUseLH();
    }
}
//Retorna o uso total da devida estrutura
int getTotalStructUse(){
    return totalStructUse;
}