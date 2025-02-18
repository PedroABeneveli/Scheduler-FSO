#include <stdio.h>
#include "global.h"
#include "defines.h"
#include "linkedList.h"
#include "process.h"
#include "scheduler.h"

extern linked_list_t* process_list;
extern node_t* curr_process;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Eh necessario que seja fornecido o tipo de escalonamento\n");
        return 0;
    }

    int type = atoi(argv[1]);
    if (type < 0 || type > 2) {
        printf("Tipo de escalonamento invalido. O tipo pode ser:\n  0: First In First Out (FIFO)\n  1: Shortest Job First (SJF)\n  2: Round Robin, em que tambem deve ser fornecido o quantum\n");
        return 0;
    }

    if (type == 2 && argc < 3) {
        printf("Eh necessario que seja fornecido o quantum para o escalonamento Round Robin\n");
        return 0;
    }

    int quan = type == 2 ? atoi(argv[2]) : 0;

    init_scheduler(quan);

    // instanciando os processos
    process_t* proc;

    // Processo A
    proc = create_process(10, 6);
    add_process_to_list(process_list, proc);

    // Processo B
    proc = create_process(3, 8);
    add_process_to_list(process_list, proc);

    // Processo C
    proc = create_process(6, 2);
    add_process_to_list(process_list, proc);

    // Processo D
    proc = create_process(4, 3);
    add_process_to_list(process_list, proc);

    // Simulando ate a lista ficar vazia
    for (int t = 0 ; process_list->sz > 0 ; t++) {
        scheduler(type);

        if (process_list->sz == 0) break;

        printf("Tempo %d: esta rodando o processo de duracao inicial de %d tempo, e que chegou no instante %d\n", t, curr_process->data->duration, curr_process->data->arrival);
        curr_process->data->time_left--;
        curr_process->data->time_running++;
    }

    erase_linked_list(process_list);
    printf("Fim da lista de processos\n");
}