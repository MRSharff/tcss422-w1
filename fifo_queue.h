#ifndef FIFO_QUEUE_H
#define FIFO_QUEUE_H

#include "pcb.h"

typedef struct node Node;
typedef Node * Node_p;

struct node {
    PCB_p pcb;
    Node_p next;
};

#include "pcb.h"

// Error Handling Values
#define SUCCESS 0
#define NULL_OBJECT -1

typedef struct node {
    PCB_p pcb;
    struct node* next;
} Node;
typedef Node* Node_p;

typedef struct FIFO_q {
    int size;
    Node_p front;
    Node_p rear;
} FIFOq;
typedef FIFOq * FIFOq_p;

FIFOq_p FIFOq_construct(void);
int FIFOq_destruct(FIFOq_p fqueue);
int FIFOq_init(FIFOq_p queue);
int FIFOq_is_empty(FIFOq_p queue);
int FIFOq_enqueue(FIFOq_p queue, PCB_p pcb);
PCB_p FIFOq_dequeue(FIFOq_p queue);

#endif