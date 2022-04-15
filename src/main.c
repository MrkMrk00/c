#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list/types.h"

int main() {
    Node *list = NULL;
    char *strings[] = {
        "Tvoje mama",
        "Jeho mama",
        "Nejaka jina mama"
    };

    array_unshift_str(&list, strings[0]);
    array_unshift_str(&list, strings[1]);
    array_unshift_int(&list, 5);

    printf("%s\n", strings[0]);
    printf("%i\n", *(int *)list->data);

    return 0;
}