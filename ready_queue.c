#include <stdlib.h>
#include "ready_queue.h"

READYq_p READYq_construct(void) {
    return (READYq_p) malloc(sizeof(READYq));
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
