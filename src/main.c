#include <stdio.h>
#include "global.h"
#include "defines.h"
#include "linkedList.h"
#include "process.h"
#include "scheduler.h"

extern linked_list_t* process_list;
extern node_t* curr_process;

// not really random, it repeats values on different executions
int gen_random(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main(int argc, char* argv[]) {
    if (argc > 4) {
        printf("Muitos argumentos fornecidos\n");
        return 0;
    }

    if (argc < 3) {
        printf("Eh necessario que seja fornecido o tipo de escalonamento e o numero de processos\n");
        return 0;
    }

    int type = atoi(argv[2]), num_processes = atoi(argv[1]);
    if (type < 0 || type > 2) {
        printf("Tipo de escalonamento invalido. O tipo pode ser:\n  0: First In First Out (FIFO)\n  1: Shortest Job First (SJF)\n  2: Round Robin, em que tambem deve ser fornecido o quantum\n");
        return 0;
    }
    if (num_processes <= 0) {
        printf("Eh necessario que seja instanciado pelo menos 1 processo\n");
        return 0;
    }

    if (type == 2 && argc < 4) {
        printf("Eh necessario que seja fornecido o quantum para o escalonamento Round Robin\n");
        return 0;
    }

    int quan = type == 2 ? atoi(argv[3]) : 0;

    init_scheduler(quan);

    // instanciando os processos
    process_t* proc;

    for (int i = 1 ; i <= num_processes ; i++) {
        proc = create_process(gen_random(1, 15), gen_random(1, 20*num_processes));
        add_process_to_list(process_list, proc);
        printf("Processo %d: pid = %d, duracao = %d, chegada = %d\n", i, proc->pid, proc->duration, proc->arrival);
    }

    printf("\n");

    // Simulando ate a lista ficar vazia
    for (int t = 0 ; process_list->sz > 0 ; t++) {
        scheduler(type);

        if (process_list->sz == 0) break;

        printf("Tempo %d: esta rodando o processo de pid igual a %d\n", t, curr_process->data->pid);
        curr_process->data->time_left--;
        curr_process->data->time_running++;
    }

    erase_linked_list(process_list);
    printf("Fim da lista de processos\n");
}