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

void FIFOq_enqueue(FIFOq_p queue) {

}

int FIFOq_dequeue(FIFOq_p queue) {
    return -1;
}