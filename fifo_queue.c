#include "fifo_queue.h"
#include <stdlib.h>
#include <stdio.h>

FIFOq_p FIFOq_construct() {
    return (FIFOq_p) malloc(sizeof(FIFOq));
}

int FIFOq_init(FIFOq_p queue) {
    if(queue == NULL) {
        return NULL_OBJECT;
    }

    queue->size = 0;
    free(queue->front);     // In case an old node was previously allocated here.
    queue->front = NULL;
    free(queue->rear);      // In case an old node was previously allocated here.
    queue->rear = NULL;
    return SUCCESS;
}

int FIFOq_destruct(FIFOq_p fqueue) {
    // Free all of the nodes in memory.
    while(fqueue->front != NULL) {
        Node_p temp = fqueue->front;
        fqueue->front = fqueue->front->next;
        free(temp);
    }
    free(fqueue);
}

int FIFOq_is_empty(FIFOq_p queue) {
    if (queue->size == 0) {
        return 1;
    }
    return 0;
}

int FIFOq_enqueue(FIFOq_p queue, PCB_p pcb) {
    if(queue == NULL || pcb == NULL) {
        return NULL_OBJECT;
    }

    Node_p new_node = (Node_p) malloc(sizeof(Node));
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

    Node_p old_front = queue->front;
    queue->front = queue->front->next;
    queue->size--;

    PCB_p result = old_front->pcb;
    free(old_front);

    return result;
}