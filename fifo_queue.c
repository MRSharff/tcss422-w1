#include "fifo_queue.h"
#include <stdlib.h>
#include <stdio.h>



Node_p NODE_construct(void) {
    Node_p retNode = malloc(sizeof(Node));
    if (retNode == NULL) {
        return NULL;
    }
    retNode->pcb = malloc(sizeof(PCB));
    retNode->next = malloc(sizeof(Node));
    if (retNode->pcb == NULL || retNode->next == NULL) {
        free(retNode);
        return NULL;
    }
    return retNode;
}

int NODE_init(Node_p node, PCB_p pcb) {
    node->pcb = pcb;
    node->next = NULL;
}
FIFOq_p FIFOq_construct() {
    FIFOq_p returnqueue = malloc(sizeof(FIFOq));
    if (returnqueue == NULL) {
        return NULL;
    }
    returnqueue->front = malloc(sizeof(Node));
    returnqueue->rear = malloc(sizeof(Node));
    if (returnqueue->front == NULL || returnqueue->rear == NULL) {
        free(returnqueue);
        puts("front or rear was null");
        return NULL;
    }
    return returnqueue;
}

int FIFOq_destruct(FIFOq_p fqueue) {
    free(fqueue);
}

int FIFOq_init(FIFOq_p queue) {
    if (queue == NULL) {
        return NULL_OBJECT;
    }
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return SUCCESS;
}

int FIFOq_is_empty(FIFOq_p queue) {
//    return queue->front == queue->rear;
    if (queue->size == 0) {
        return 1;
    }
    return 0;
}

int FIFOq_enqueue(FIFOq_p queue, PCB_p pcb) {
    if (pcb == NULL) {
        return NULL_OBJECT;
    }
    Node_p newNode = NODE_construct();
    NODE_init(newNode, pcb);
    queue->rear->next = newNode;
    queue->size++;
    return SUCCESS;
}

PCB_p FIFOq_dequeue(FIFOq_p queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    Node_p temp = queue->front;
    queue->front = temp->next;
    return temp->pcb;
}

int main(void) {
    FIFOq_p fq = FIFOq_construct();
    FIFOq_init(fq);
    return 1;
}