#ifndef PROCESS
#define PROCESS

#define true 1
#define false 0

int curr_pid, process_count;

typedef enum process_state {READY, RUNNING, BLOCKED} process_state_t;

typedef struct process_context {
    int eax, ecx, edx, ebx, esp, ebp, esi, edi, eip;
} process_context_t;

typedef struct process {
    int pid;
    process_context_t context;
    process_state_t state;
    int duration;   // for SJF
    int arrival;    // relative arrival time used for FIFO
    int time_left;  // how much time left this process needs to use the processor, used in RR
    int time_running;    // time this process has been using the processor for RR
} process_t;

void process_init();
process_t* create_process(int duration, int arrival);
int process_comp(process_t p1, process_t p2, int type);

#endif