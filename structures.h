#ifndef STRUCTURES_
#define STRUCTURES_

#define MAXWORDS 1024

typedef struct wordStruct{
    char word[21];
    int frequency;
    struct wordStruct *next; // Utilizado apenas para Hash Linked List
}wordStruct;

typedef struct node{
    wordStruct data;
    struct node *left;
    struct node *right;
}node;

typedef struct hash{
    int tableSize;
    wordStruct **tableHash;    
}hash;

#endif

