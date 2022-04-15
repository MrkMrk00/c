#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array_length(Node *head_ref) {
    if (head_ref == NULL) return 0;

    uint len = 1;
    Node *pom = head_ref;
    while (pom->next != NULL) {
        pom = pom->next;
        len++;
    }
    return len;
}

void node_destroy(Node **node) {
    free((*node)->data);
    free(*node);
}

Node* node_create(void *data, size_t data_size) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = malloc(data_size);
    memcpy(new_node->data, data, data_size);
    return new_node;
}

void array_destroy(Node **head_ref) {
    uint len = array_length(*head_ref);
    Node *nodes[len];
    uint cur_index = 0;
    
    if ((*head_ref)->next == NULL) {
        node_destroy(head_ref);
        *head_ref = NULL;
        return;
    }

    Node *pom = *head_ref;
    while (pom->next != NULL) {
        nodes[cur_index] = pom;
        cur_index++;
        pom = pom->next;
    }

    for (int i = 0; i < len; i++) {
        node_destroy(&nodes[i]);
    }

    *head_ref = NULL;
}

void array_unshift(Node **head_ref, void *data, size_t data_size) {
    Node *new_node = node_create(data, data_size);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void array_shift(Node **head_ref) {
    if (*head_ref == NULL) return;
    Node *to_destroy = *head_ref;
    *head_ref = (*head_ref)->next;

    node_destroy(&to_destroy);
}