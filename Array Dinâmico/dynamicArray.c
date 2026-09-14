#include <stdio.h>
#include <stdlib.h>


typedef struct 
{ 
    int* fixed_arr;
    int size;
    int capacity;
} vector ;


vector vector_init(int size);

int main()
{
    
    return 0;
};

vector vector_init(int size){
    
    vector v;
    v.capacity = size * 2;
    v.size = size;
    v.fixed_arr = malloc(size * sizeof(*v.fixed_arr));
}