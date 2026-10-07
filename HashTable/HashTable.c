#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

HashTable* initializeHashTable(int size)
{
    HashTable* ht;
    ht->bucket = malloc(size * sizeof(int*));
    ht->bucketSize = size;

    for(int i = 0; i < ht->bucketSize; i++){
        ht->bucket[i] = NULL;
    }
    
    return ht;
};


int hashFunction(char* key, int size){
    return (strlen(key) * 10) % size;
};

void append(HashTable* ht, char* key, int value){

    if(ht == NULL) return;

    int index = hashFunction(key, ht->bucketSize);
    hashE_insert_end(&(ht->bucket[index]), key, value);
};

void delete(HashTable* ht, char* key){

    int index = hashFunction(key, ht->bucketSize);
    hashE_delete_key(&(ht->bucket[index]), key);
};

int lookup(HashTable* ht, char* key){

    int index = hashFunction(key, ht->bucketSize);
    int found = hashE_searchVal(ht->bucket[index], key)->data;

    if(found == -1){
        printf("Not found");
        return -1;
    }

    printf("Found key: %s\n", key);
    printf("Key Value: %d\n", found);
    return found;

};

////////////////////////////////////////////////////////////////////////
//Linked List operations especificamente para manipular as entries de um bucket.
////////////////////////////////////////////////////////////////////////

void hashE_insert_end(HashEntry** n, char* key, int value){

    //Cria nova Tail
    HashEntry* tail = malloc(sizeof(HashEntry));
    tail->data = value;
    tail->key = malloc(sizeof(char*));
    strcpy(tail->key, key);
    tail->next = NULL;
    
    //Caso seja a Head
    if(*n == NULL){
        *n = tail;
        return;
    }
    
    HashEntry* curr = (*n);
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = tail;
};


void hashE_delete_key(HashEntry** n, char* key)
{
    if(n == NULL) return;

    HashEntry* curr = (*n);
    HashEntry* prev = NULL;

    while(curr != NULL){
        
        if(strcmp(curr->key, key) == 0){

            if(prev != NULL)
            {
                prev->next = curr->next;
            }else
            {
                (*n) = curr->next;
            }

            free(curr->key);
            free(curr);

            return;
        };

        prev = curr;
        curr = curr->next;
    }
};

HashEntry* hashE_searchVal(HashEntry* n, char* key)
{
    if(n == NULL) return NULL;

    HashEntry* curr = n;
    while(curr != NULL){
        
        if(strcmp(curr->key, key) == 0){
            return curr;
        };

        curr = curr->next;
    }

    return NULL;
}

void hashE_display(HashEntry* list){

    if(list == NULL) return;

    HashEntry* curr = list;
    while(curr != NULL){
        printf("Key: %s\n", curr->key);
        printf("Value: %d \n\n", curr->data);
        curr = curr->next;
    }
}