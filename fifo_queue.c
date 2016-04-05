#include <stdlib.h>
#include "fifo_queue.h"

typedef struct node {
    PCB_p pcb;
    struct node* next;
} Node;

FIFOq_p FIFOq_construct() {
    return (FIFOq_p) malloc(sizeof(FIFOq));
}

int FIFOq_init(FIFOq_p queue) {
    if(queue == NULL) {
        return NULL_OBJECT;
    }

    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return SUCCESS;
}

int FIFOq_is_empty(FIFOq_p queue) {
    if(queue == NULL) {
        return NULL_OBJECT;
    }
    return queue->size == 0;
}

int FIFOq_enqueue(FIFOq_p queue, PCB_p pcb) {
    if(queue == NULL || pcb == NULL) {
        return NULL_OBJECT;
    }

    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->pcb = pcb;
    new_node->next = NULL;

    if(FIFOq_is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
    return SUCCESS;
}

PCB_p FIFOq_dequeue(FIFOq_p queue) {
    if(queue == NULL || FIFOq_is_empty(queue)) {
        return NULL;
    }

    Node* old_front = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    PCB_p result = old_front->pcb;
    free(old_front);
    return queue->front->pcb;
}