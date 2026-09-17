#include <stdio.h>
#include <stdlib.h>


typedef struct 
{ 
    int* data;
    int size;
    int capacity;
} vector;


vector vector_init(int initial_capacity); //Initialize array

void vector_push_back(vector* v, int value); //Inserção
void vector_pop_back(vector* v); //Remoção

//Helpers
int vector_front(vector* v); //Primeiro elemento
int vector_back(vector* v); //Ultimo elemento
int vector_at(vector* v, int index); //Elemento em certo índice (com error handling)
int vector_size(vector* v); //Retorna tamanho do array atual.

int main()
{
    
    return 0;
};

vector vector_init(int initial_capacity){
    vector v;

    v.size = 0;
    v.capacity = initial_capacity;
    v.data = malloc(v.capacity * sizeof(*v.data));

    return v;
}

int vector_size(vector* v){
    return v->size;
}

int vector_front(vector* v){
    return v->data[0];
}

int vector_back(vector* v){
    return v->data[v->size];
}