#ifndef LINKEDLIST
#define LINKEDLIST

#include "process.h"
#include "defines.h"

typedef struct node {
    process_t *data;
    node_t *next;
} node_t;

typedef struct linked_list {
    int sz;
    node_t *head, *last;
} linked_list_t;

// acho que nao vou precisar apagar processos, posso so ignorar os que acabarem

node_t* create_node(process_t* p);
linked_list_t* create_linked_list();
void erase_linked_list(linked_list_t* list);
void add_process_to_list(linked_list_t* list, process_t* p);

#endif