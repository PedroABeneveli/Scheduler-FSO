#include "linkedList.h"

// registers
int eax, ecx, edx, ebx, esp, ebp, esi, edi, eip;

// scheduler globals
int quantum, curr_process_index;
node_t *curr_process;
linked_list_t *process_list;

// process globals
int curr_pid, process_count;
