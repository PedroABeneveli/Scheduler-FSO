#include "scheduler.h"

extern int eax, ecx, edx, ebx, esp, ebp, esi, edi, eip;

// initializes scheduler variables
// call this function before inserting processes into the linked list
void init_scheduler(int quan) {
    quantum = quan;
    process_list = create_linked_list();
    curr_process = NULL;
    curr_process_index = 0;
}

// type == 0 => FIFO
// type == 1 => SJF
// type == 2 => RR, assumes that curr_process != NULL and curr_process_index is valid
node_t* get_next_process_node(linked_list_t *list, int type) {
    node_t *no= NULL, *curr = list->head;

    if (type == 0 || type == 1) {
        while (curr != NULL) {
            if (no == NULL)
                no = curr;
            else
                if (!process_comp(no->data, curr->data, type)) {
                    no = curr;
                }
        }

        return no;
    } else if (type == 2) {
        if (curr_process_index + 1 >= list->sz) {
            no = list->head;
        } else {
            no = curr_process->next;
        }
    }

    return NULL;
}