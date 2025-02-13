#ifndef SCHEDULER
#define SCHEDULER

#include "process.h"
#include "linkedList.h"

int quantum, curr_process_index;
process_t *curr_process;
linked_list_t *process_list;

void init_scheduler();
process_t* get_next_process(int type);

#endif