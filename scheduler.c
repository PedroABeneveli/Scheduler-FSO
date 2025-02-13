#include "scheduler.h"

extern int eax, ecx, edx, ebx, esp, ebp, esi, edi, eip;

// initializes scheduler variables
// call this function before inserting processes into the linked list
void init_scheduler(int quan) {
    quantum = quan;
    process_list = malloc(sizeof(linked_list_t));
    curr_process = NULL;
    curr_process_index = 0;
}

process_t* get_next_process(int type) {
    //TODO
}