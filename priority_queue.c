#include "priority_queue.h"
#include "fifo_queue.h"
#include "pcb.h"

typedef struct ready_queue {
  FIFOq_p fifoques[16];
} READYq;

typedef READYq * READYq_p;

READYq_p READYq_construct(void) {
  return (READYq_p) malloc(sizeof(READYq));
}

void READYq_enqueue(READYq_p queue, PCB_p pcb) {
  FIFO_enqueue(queue->fifoques[pcb->priority], pcb);
}

PCB_p READYq_dequeue(READYq_p queue) {
  int i;
  for (i = 0; i < 16; i++) {
    if (!isEmpty(queue->fifoques[i])) {
      return FIFO_dequeue(queue->fifoques[i]);
    }
  }
  return NULL;
}
