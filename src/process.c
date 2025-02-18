#include "process.h"

void process_init() {
    curr_pid = 0;
    process_count = 0;
}

process_t* create_process(int duration, int arrival) {
    process_t *process = malloc(sizeof(process_t));

    process->pid = curr_pid++;

    // data for scheduling
    process->arrival = arrival;
    process->duration = duration;
    process->time_left = duration;
    process->time_running = 0;

    process->context.eax = 0;
    process->context.ebx = 0;
    process->context.ecx = 0;
    process->context.edx = 0;
    process->context.esp = 0;
    process->context.ebp = 0;
    process->context.esi = 0;
    process->context.edi = 0;
    process->context.eip = 0;   // in the original code this is the base_address, but we wont use base address here

    process->state = READY;

    process_count++;

    return process;
}

// type == 0 => FIFO
// type == 1 => SJF
// RR doesn't compare processes, it just goes to the next element in the list
// returns true if p1 is going to be executed before p2
int process_comp(process_t *p1, process_t *p2, int type) {
    if (type == 0) {
        if (p1->arrival < p2->arrival)
            return true;
        return false;
    } else if (type == 1) {
        if (p1->duration < p2->duration)
            return true;
        return false;
    }

    // invalid scheduling type
    return -1;
}