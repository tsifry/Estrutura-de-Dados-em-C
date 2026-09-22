#include <stdio.h>
#include <stdlib.h>


typedef struct 
{ 
    int* data;
    size_t size;
    size_t capacity;
} vector;


vector vector_init(size_t initial_capacity); //Initialize array

void vector_push_back(vector* v, int value); //Inserção
void vector_pop_back(vector* v); //Remoção
void vector_free(vector* v); //Limpa memória após uso

//Helpers
int vector_front(vector* v); //Primeiro elemento
int vector_back(vector* v); //Ultimo elemento
int vector_at(vector* v, int index); //Elemento em certo índice (com error handling)
size_t vector_size(vector* v); //Retorna tamanho do array atual.

//Inicialização
vector vector_init(size_t initial_capacity){
    vector v;

    v.size = 0;
    v.capacity = initial_capacity;
    v.data = malloc(v.capacity * sizeof(*v.data));

    return v;
}

//Adiciona elemento
void vector_push_back(vector* v, int value)
{
    if(v->size == v->capacity){
        int *temp;
        size_t newCapacity = v->capacity * 2;

        temp = realloc(v->data, newCapacity * sizeof(int));

        if(temp == NULL){
            printf("Não foi possível adicionar elemento.\n");
            printf("Erro ao realocar memória.\n");
            return;
        }

        v->capacity = newCapacity;
        v->data = temp;

        printf("Size was reallocated from %zu to %zu\n", v->size, v->capacity);
    }

    v->data[v->size] = value;
    v->size++;
}

//Remove Ultimo
void vector_pop_back(vector* v){
    if(v->size == 0)
    {
        printf("Array ja esta vazio.");
        exit(EXIT_FAILURE);
    }
    
    v->size--;
}

//Tamanho lógico
size_t vector_size(vector* v){
    return v->size;
}

//Retorna primeiro elemento
int vector_front(vector* v){
    if(v->size == 0)
    {
        printf("Array Vazio.");
        exit(EXIT_FAILURE);
    }

    return v->data[0];
}

//Retorna ultimo elemento
int vector_back(vector* v){
    if(v->size == 0)
    {
        printf("Array Vazio.");
        exit(EXIT_FAILURE);
    }

    return v->data[v->size - 1];
}

//Retorna elemento no index X
int vector_at(vector* v, int index){
    if(index > v->size || index < 0)
    {
        printf("Tentativa de acesso out of bound.\n");
        exit(EXIT_FAILURE);
    }

    return v->data[index];
}

//Libera memória após uso
void vector_free(vector* v){
    free(v->data); 
}
