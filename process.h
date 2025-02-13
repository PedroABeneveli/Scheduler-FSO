#ifndef PROCESS
#define PROCESS

typedef enum process_state {READY, RUNNING, BLOCKED} process_state_t;

typedef struct process_context {
    int eax, ecx, edx, ebx, esp, ebp, esi, edi, eip;
} process_context_t;

typedef struct process {
    process_context_t context;
    process_state_t state;
    int duration;   // for SJF
    int arrival;    // relative arrival time used for FIFO
    int time_left, in_processor;    // data needed for RR
} process_t;

#endif