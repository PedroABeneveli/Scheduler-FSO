#include "linkedList.h"
#include "process.h"

#define NULL 0  

node_t* create_node(process_t *p) {
    node_t *no = malloc(sizeof(node_t));
    no->data = p;
    no->next = NULL;
    return no;
}

// returns true if the node was removed successfully, and false otherwise
int erase_node(linked_list_t* list, int idx) {
    if (idx >= list->sz || idx < 0)
        return false;

    if (idx == 0) {
        if (list->sz == 1) {
            list->head = NULL;
            list->last = NULL;
        } else {
            node_t *no = list->head;
            list->head = no->next;
            free(no->data);
            free(no);
        }
    } else {
        int curr = 0, next = 1;
        node_t *curr_no = list->head;
        while (next != idx) {
            curr_no = curr_no->next;
            curr++;
            next++;
        }

        node_t *next_no = curr_no->next;

        curr_no->next = next_no->next;
        free(next_no->data);
        free(next_no);

        if (idx == list->sz - 1) {
            list->last = curr_no;
        }
    }

    list->sz--;
    return true;
}

linked_list_t* create_linked_list() {
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->sz = 0;
    list->head = NULL;
    list->last = NULL;
    return list;
}

// Erases all nodes and data present in the linked_list
void erase_linked_list(linked_list_t *list) {
    node_t *no, *next;
    while (list->head != NULL) {
        no = list->head;
        next = no->next;

        if (no->next == NULL) {
            free(no->data);
            free(no);
            break;
        }

        while (next->next != NULL) {
            no = no->next;
            next = next->next;
        }

        free(next->data);
        free(next);
        no->next = NULL;
    }

    free(list);
}

void add_process_to_list(linked_list_t *list, process_t *p) {
    node_t *new_no = create_node(p);

    if (list->sz == 0) {
        list->head = new_no;
        list->last = new_no;
    } else {
        list->last->next = new_no;
        list->last = new_no;
    }

    list->sz++;
}