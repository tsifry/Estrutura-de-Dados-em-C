#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node* next;
};

//Life Cycle
void free_list(Node* head);

//Traversal
void display(Node* list);

void insert_end(Node** n, int value);

int main()
{
    Node* list = NULL;
    insert_end(&list, 10);
    insert_end(&list, 15);
    insert_end(&list, 20);
    display(list);
};

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
    Node* tail = malloc(sizeof(Node));;
    
    //Caso seja a Head
    if(*n == NULL){
        tail->data = value;
        tail->next = NULL;
        
        *n = tail;
        return;
    }

    while((*n)->next != NULL){
        (*n) = (*n)->next;
    }

    tail->data = value;
    tail->next = NULL;

    (*n)->next = tail;

}

void display(Node* list){

    if(list == NULL) return;
    Node* current = list;

    while(current != NULL){
        printf("Data: %d \n", current->data);
        current = current->next;
    }

}