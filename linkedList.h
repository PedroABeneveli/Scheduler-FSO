#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdlib.h>

#include "process.h"
#include "defines.h"

typedef struct node node_t;

struct node {
    process_t *data;
    node_t *next;
};

typedef struct linked_list {
    int sz;
    node_t *head, *last;
} linked_list_t;

node_t* create_node(process_t* p);
int erase_node(linked_list_t* list, int idx);
linked_list_t* create_linked_list();
void erase_linked_list(linked_list_t* list);
void add_process_to_list(linked_list_t* list, process_t* p);

#endif