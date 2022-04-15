#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* node_str_create(char *data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = malloc(strlen(data));
    strcpy(new_node->data, data);
    return new_node;
}

void array_unshift_str(Node **head_ref, char *data) {
    Node *new_node = node_str_create(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void array_unshift_int(Node **head_ref, int data) {
    array_unshift(head_ref, &data, sizeof(int));
}