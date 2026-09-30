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
void display_at(Node* list, int index);
int length(Node* list);

void insert_end(Node** n, int value);

int main()
{
    Node* list = NULL;

    insert_end(&list, 10);    
    insert_end(&list, 15);
    insert_end(&list, 20);
    
    display_at(list, 3);
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


