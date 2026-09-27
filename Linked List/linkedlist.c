#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node* next;
};

//Life Cycle
Node* create_list();
Node* create_node();
void free_list(Node* head);

void insert_end(Node* n, int value);

int main()
{
    Node* list = create_list();
    insert_end(list, 10);

};


//Cria um node vazio.
Node* create_node(){

    Node* n = (Node*) malloc(sizeof(Node));
    n->data = 0;
    n->next = NULL;

    return n;
}

Node* create_list()
{
    Node* head = create_node();
    return head;
}

void free_list(Node* head){
    Node* next;

    while(head != NULL){
        next = head->next;
        free(head);

        head = next;
    }
}

void insert_end(Node* n, int value){

    if(n == NULL) return;

    while(n->next != NULL){
        n = n->next;
    }

    //Cria nova Tail
    Node* tail = create_node();

    n->data = value;
    n->next = tail;

}