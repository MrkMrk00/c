#include <stddef.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

Node* node_create(void *data, size_t data_size);

void array_destroy(Node **head_ref);
int array_length(Node *head_ref);
void array_shift(Node **head_ref);
void array_unshift(Node **head_ref, void *data, size_t data_size);

void array_unshift_str(Node **head_ref, char *data);
void array_unshift_int(Node **head_ref, int data);