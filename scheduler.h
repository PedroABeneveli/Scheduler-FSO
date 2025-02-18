#ifndef SCHEDULER
#define SCHEDULER

#include "process.h"
#include "linkedList.h"
#include "defines.h"

int quantum, curr_process_index;
node_t *curr_process;
linked_list_t *process_list;

void init_scheduler(int quan);
node_t* get_next_process_node(linked_list_t *list, int type);
void scheduler();

#endif