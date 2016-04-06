#include <stdlib.h>
#include "ready_queue.h"

READYq_p READYq_construct(void) {
    READYq_p newRQueue = malloc(sizeof(READYq));
//    newRQueue->fifo_queues = malloc(PRIORITYRANGE * sizeof(FIFOq_p));
    int i;
    for (i = 0; i < PRIORITYRANGE; i++) {
        newRQueue->fifo_queues[i] = FIFOq_construct();
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
