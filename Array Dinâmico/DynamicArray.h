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