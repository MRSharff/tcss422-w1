#include "fifo_queue.h"
#include <stdlib.h>

typedef struct node {
    PCB_p pcb;
    struct Node* next;
} Node;

FIFOq_p construct() {
    return (FIFOq_p) malloc(sizeof(FIFOq));
}

FIFOq_p init(FIFOq_p queue) {
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
}

int FIFOq_is_empty(FIFOq_p queue) {
    return queue->front == queue->rear;
}

void FIFOq_enqueue(FIFOq_p queue, PCB_p pcb) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->pcb = pcb;

    if(FIFOq_is_empty(queue)) {

    }
}

FIFOq_p FIFOq_dequeue() {
    return NULL;
}