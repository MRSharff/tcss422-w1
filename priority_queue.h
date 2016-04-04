#ifndef READY_QUEUE_H
#define READY_QUEUE_H

void enqueue(READYq_p queue, PCB_p pcb);

PCB_p dequeue(READYq_p queue);

#endif
