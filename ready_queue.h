#ifndef READY_QUEUE_H
#define READY_QUEUE_H

#include "pcb.h"
#include "fifo_queue.h"

#define PRIORITYRANGE 16

typedef struct ready_queue {
    FIFOq_p fifo_queues[PRIORITYRANGE];
} READYq;

typedef READYq * READYq_p;

READYq_p READYq_construct(void);

void READYq_destruct(READYq_p readyqueue);

void enqueue(READYq_p queue, PCB_p pcb);

PCB_p dequeue(READYq_p queue);

#endif
