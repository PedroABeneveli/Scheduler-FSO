#ifndef SCHEDULER
#define SCHEDULER

#include "process.h"
#include "linkedList.h"
#include "defines.h"

extern int eax, ecx, edx, ebx, esp, ebp, esi, edi, eip;

int quantum, curr_process_index;
node_t *curr_process;
linked_list_t *process_list;

void init_scheduler(int quan);
node_t* get_next_process_node(linked_list_t *list, int type);
void scheduler(int type);

#endif