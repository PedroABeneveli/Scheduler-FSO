#include "scheduler.h"

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
        int idx = -1;
        while (curr != NULL) {
            idx++;
            if (no == NULL) {
                no = curr;
                curr_process_index = 0;
            } else {
                if (!process_comp(no->data, curr->data, type)) {
                    no = curr;
                    curr_process_index = idx;
                }
            }
        }

        return no;
    } else if (type == 2) {
        if (curr_process_index + 1 >= list->sz) {
            no = list->head;
        } else {
            no = curr_process->next;
        }

        curr_process_index = (curr_process_index + 1) % list->sz;

        return no;
    }

    return NULL;
}

// type == 0 => FIFO
// type == 1 => SJF
// type == 2 => RR
void scheduler(int type) {
    // check to see if there is any process
    if (process_list->sz <= 0) return;

    if (type == 0 || type == 1) {
        if (curr_process == NULL) {
            curr_process = get_next_process_node(process_list, type);   
        } else {
            if (curr_process->data->time_left > 0) return;

            erase_node(process_list, curr_process_index);

            if (process_list->sz <= 0) {
                curr_process = NULL;
                return;
            }

            curr_process = get_next_process_node(process_list, type);
        }
    } else if (type == 2) {
        if (curr_process == NULL) {
            curr_process = process_list->head;
            curr_process_index = 0;
        } else {
            if (curr_process->data->time_running < quantum && curr_process->data->time_left > 0) return;

            node_t *prev_node = curr_process;
            curr_process = get_next_process_node(process_list, type);
            if (prev_node->data->time_left <= 0) {
                erase_node(process_list, (curr_process_index-1 + process_list->sz) % process_list->sz);
                
                if (process_list->sz <= 0) {
                    curr_process = NULL;
                    return;
                }

                // fixing the current index since we removed a node
                if (curr_process_index != 0)
                    curr_process_index--;
                
            } else {
                prev_node->data->state = READY;

                // context switch, saving previous data in the previous process context
                prev_node->data->context.eax = eax;
                prev_node->data->context.ecx = ecx;
                prev_node->data->context.edx = edx;
                prev_node->data->context.ebx = ebx;
                prev_node->data->context.esp = esp;
                prev_node->data->context.ebp = ebp;
                prev_node->data->context.esi = esi;
                prev_node->data->context.edi = edi;
                prev_node->data->context.eip = eip;
            }
        }
    }

    // context switch
    eax = curr_process->data->context.eax;
    ecx = curr_process->data->context.ecx;
    edx = curr_process->data->context.edx;
    ebx = curr_process->data->context.ebx;
    esp = curr_process->data->context.esp;
    ebp = curr_process->data->context.ebp;
    esi = curr_process->data->context.esi;
    edi = curr_process->data->context.edi;
    eip = curr_process->data->context.eip;

    curr_process->data->state = RUNNING;
}