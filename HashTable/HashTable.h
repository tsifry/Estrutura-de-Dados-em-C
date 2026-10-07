
typedef struct HashEntry HashEntry;
struct HashEntry {
    int data;
    char* key;
    HashEntry* next;
};

typedef struct
{
    HashEntry** bucket;
    int bucketSize;
} HashTable ;


//Hash table specifics
HashTable* initializeHashTable(int size);
int hashFunction(char* key, int size);
void append(HashTable* ht, char* key, int value);
void delete(HashTable* ht, char* key);
int lookup(HashTable* ht, char* key);

//Linked list of HashEntry operations
void hashE_insert_end(HashEntry** n, char* key, int value);
void hashE_delete_key(HashEntry* n, char* key);
void hashE_display(HashEntry* list);
int hashE_searchVal(HashEntry* n, char* key);
