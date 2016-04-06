#include <stdlib.h>
#include <stdio.h>
#include "ready_queue.h"

READYq_p READYq_construct(void) {
    READYq_p newRQueue = malloc(sizeof(READYq));
//    newRQueue->fifo_queues = malloc(PRIORITYRANGE * sizeof(FIFOq_p));
    int i;
    for (i = 0; i < PRIORITYRANGE; i++) {
        newRQueue->fifo_queues[i] = FIFOq_construct();
        FIFOq_init(newRQueue->fifo_queues[i]);
    }
    return newRQueue;
}

void READYq_destruct(READYq_p readyqueue) {
    int i;
    for (i = 0; i < PRIORITYRANGE; i++) {
        FIFOq_destruct(readyqueue->fifo_queues[i]);
    }
    free(readyqueue);
}

void READYq_enqueue(READYq_p readyqueue, PCB_p pcb) {
    FIFOq_enqueue(readyqueue->fifo_queues[pcb->priority], pcb);
}

PCB_p READYq_dequeue(READYq_p readyqueue) {
    int priority;
    for (priority = 0; priority < 16; priority++) {
        if (FIFOq_is_empty(readyqueue->fifo_queues[priority]) == 0) {
            return FIFOq_dequeue(readyqueue->fifo_queues[priority]);
        }
    }
    return NULL;
}

char * READYq_toString(READYq_p readyqueue, char * string, int size) {
    int offset = 0;
    int consumption = 0;

    int priority;
    for (priority = 0; priority < PRIORITYRANGE; priority++) {
        if (FIFOq_is_empty(readyqueue->fifo_queues[priority]) != 1) {
            int string_size = 32 + (4 * FIFOq_size(readyqueue->fifo_queues[priority])) + 1;    // 11 for header, 4 for each node, 1 for \0
            char* fq_string = (char*) malloc(string_size);
            FIFOq_toString(readyqueue->fifo_queues[priority], fq_string, string_size);

            consumption = snprintf(string + offset, size, "Q%d: %s\n", priority, fq_string);
            offset+= consumption;
            size-= consumption;
        }
    }
}
