#include "fifo_queue.h"
#include "pcb.h"
#include <stdlib.h>

typedef struct node Node;
typedef Node * Node_p;

struct node {
    PCB_p pcb;
    Node_p next;
};

Node_p NODE_construct(void) {
    return (Node_p) malloc(sizeof(Node));
}

int NODE_init(Node_p node, PCB_p pcb) {
    node->pcb = pcb;
    node->next = NULL;
}
FIFOq_p FIFOq_construct() {
    return (FIFOq_p) malloc(sizeof(FIFOq));
}

int FIFOq_init(FIFOq_p queue) {
    if (queue == NULL) {
        return NULL_OBJECT;
    }
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
}

int FIFOq_is_empty(FIFOq_p queue) {
//    return queue->front == queue->rear;
    return queue->front == NULL;
}

int FIFOq_enqueue(FIFOq_p queue, PCB_p pcb) {
    if (pcb == NULL) {
        return NULL_OBJECT;
    }
    Node_p newNode = NODE_construct();
    NODE_init(newNode, pcb);
    queue->rear->next = newNode;
}

PCB_p FIFOq_dequeue(FIFOq_p queue) {
    return NULL;
}