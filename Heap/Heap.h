#include "../ArrayDinamico/DynamicArray.h"

typedef struct{
    vector* array;
} Heap ;


Heap* createHeap();
int heap_getMin(Heap* h);
void heap_extractMin(Heap* h);
void heap_decreaseKey(Heap* h, int index, int value);

void heap_insert(Heap* h, int value);
void heap_delete(Heap* h, int index);
Heap* heapify(vector* vec);
