#ifndef FIFO_QUEUE_H
#define FIFO_QUEUE_H

typedef struct fifoq {

} FIFOq;

typedef FIFOq * FIFOq_p;

/* Function Prototypes */
void FIFO_enqueue(FIFOq_p queue, PCB_p pcb);
PCB_p FIFO_dequeue(FIFOq_p queue);

#endif
