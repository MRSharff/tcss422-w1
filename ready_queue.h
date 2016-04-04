#ifndef READY_QUEUE_H
#define READY_QUEUE_H

#include "pcb.h"
#include "fifo_queue.h"

typedef struct ready_queue {
    FIFOq_p fifo_queues[16];
} READYq;

typedef READYq * READYq_p;


void enqueue(READYq_p queue, PCB_p pcb);

PCB_p dequeue(READYq_p queue);

#endif
