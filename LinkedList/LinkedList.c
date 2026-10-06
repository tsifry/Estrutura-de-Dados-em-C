#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void free_list(Node* head){
    Node* next;

    while(head != NULL){
        next = head->next;
        free(head);

        head = next;
    }
}

void insert_end(Node** n, int value){

    //Cria nova Tail
    Node* tail = malloc(sizeof(Node));
    tail->data = value;
    tail->next = NULL;
    
    //Caso seja a Head
    if(*n == NULL){
        *n = tail;
        return;
    }
    
    Node* curr = (*n);
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = tail;
}

void insert_head(Node** n, int value){

    //Cria nova Tail
    Node* tail = malloc(sizeof(Node));
    tail->data = value;
    tail->next = *n;
    
    *n = tail;
}

void insert_at(Node** n, int position, int value){

    int len = length(*n);

    if(position >= len || position < 0) return;

    if(position == 1)
    {
        insert_head(n, value);
        return;
    } 

    int counter = 1;
    Node* current = (*n);

    while(counter < (position - 1)){
        current = current->next;
        counter++;
    }

    Node* prox = current->next;

    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;

    current->next = newNode;
    newNode->next = prox;
}

void display(Node* list){

    if(list == NULL) return;

    Node* curr = list;
    while(curr != NULL){
        printf("Data: %d \n", curr->data);
        curr = curr->next;
    }
}

void display_at(Node* list, int index){

    if(list == NULL || index >= length(list)){
        printf("Out of bounds.");
        return;
    };

    int counter = 0;

    Node* curr = list;
    for(int i = 0; i < index; i++){
        curr = curr->next;
    }

    printf("%d", curr->data);
}

int length(Node* list){

    if(list == NULL) return 0;
    int length = 0;

    Node* curr = list;
    while(curr != NULL){
        curr = curr->next;
        length++;
    }

    return length;
}

void delete_tail(Node* n){

    if(n == NULL) return;

    Node* curr = n;

    while(curr->next->next != NULL){
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;
}

void delete_head(Node** n){

    if(n == NULL) return;

    Node* curr = *n;
    (*n) = curr->next;

    free(curr);
}

Node* searchVal(Node* n, int value){

    if(n == NULL) return NULL;

    Node* curr = n;
    while(curr != NULL){
        
        if(curr->data == value){
            return curr;
        };

        curr = curr->next;
    }

    return NULL;
}