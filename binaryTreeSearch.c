#include "binaryTreeSearch.h"

node *root = NULL;
int useBinTree = 0;

int prepareInsertionBTree(char *word){
    wordStruct tempWS;
    strcpy(tempWS.word, word);
    tempWS.frequency = 1;
    
    return insertNode(&root, tempWS);
}

int insertNode(node** root, wordStruct wS){
    
    if(*root == NULL){          
        *root = (node*)malloc(sizeof(node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->data = wS;
        return 1;               
    }
    else if(strcmp(wS.word, (*root)->data.word) == 0){        
        (*root)->data.frequency++;
        return 0;
    }
    else if(strcmp(wS.word, (*root)->data.word) < 0){
        useBinTree++;
        insertNode(&(*root)->left, wS);
    }
    else{
        useBinTree++;
        insertNode(&(*root)->right, wS);
    }
}

void printTree(node* root){
    if(root != NULL){    
        printf("%-20s\t->\t %d\n", root->data.word, root->data.frequency);
        printTree(root->left);
        printTree(root->right);        
    }
}

node* getRoot(){
    return root;
}

int getUseBinTree(){
    return useBinTree;
}

void deallocateTree(node* root){    
    if(root != NULL){
        deallocateTree(root->left);       
        deallocateTree(root->right);        
        free(root);
        root = NULL;
    }    
}