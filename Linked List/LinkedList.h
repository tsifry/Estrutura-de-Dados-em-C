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

//Inserção
void insert_head(Node** n, int value);
void insert_end(Node** n, int value);
void insert_at(Node** n, int position, int value);

//Delete
void delete_head(Node** n);
void delete_tail(Node* n);

//Search
Node* searchVal(Node* n, int value);