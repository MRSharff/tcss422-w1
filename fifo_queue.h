#ifndef FIFO_QUEUE_H
#define FIFO_QUEUE_H

#include "pcb.h"

typedef struct FIFO_q {
    int size;
    struct node* front;
    struct node* rear;
} FIFOq;
typedef FIFOq* FIFOq_p;

FIFOq_p FIFOq_construct(void);
int FIFOq_destruct(FIFOq_p fqueue);
int FIFOq_init(FIFOq_p queue);
int FIFOq_is_empty(FIFOq_p queue);
int FIFOq_enqueue(FIFOq_p queue, PCB_p pcb);
PCB_p FIFOq_dequeue(FIFOq_p queue);

#endif