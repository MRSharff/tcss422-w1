#include "fifo_queue.h"
#include <stdlib.h>
#include <stdio.h>

FIFOq_p FIFOq_construct() {
    FIFOq_p fq = (FIFOq_p) malloc(sizeof(FIFOq));

    // Sometimes we get segfaults if the OS tries to allocate the same memory location.
    if(fq != NULL) {
        fq->front = NULL;
        fq->rear = NULL;
    }

    return fq;
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
    if(fqueue == NULL) {
        return NULL_OBJECT;
    }

    // Free all of the nodes in memory.
    Node_p traverse = fqueue->front;
    while(traverse != NULL) {
        Node_p temp = traverse;
        traverse = traverse->next;
        free(temp);
    }
    free(fqueue);

    return SUCCESS;
}

int FIFOq_is_empty(FIFOq_p queue) {
    if (queue->size == 0) {
        return 1;
    }
    return 0;
}

int FIFOq_size(FIFOq_p queue) {
    if(queue == NULL) {
        return NULL_OBJECT;
    } else {
        return queue->size;
    }
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

char* FIFOq_toString(FIFOq_p queue, char* string, int size) {
    // Note: We assume that the controller has allocated a string of appropriate size (using FIFOq_size() function).
    int offset = 0;
    int consumption = snprintf(string, size, "Count=%d: ", FIFOq_size(queue));
    offset += consumption;
    size -= consumption;

    Node_p front = queue->front;
    while(front != NULL) {
        consumption = snprintf(string + offset, size, "P%lu-", PCB_get_pid(front->pcb));
        offset += consumption;
        size -= consumption;

        if(front->next == NULL) {
            consumption= snprintf(string + offset, size, "*");
            offset += consumption;
            size -= consumption;
        } else {
            consumption= snprintf(string + offset, size, ">");
            offset += consumption;
            size -= consumption;
        }

        front = front->next;
    }

    return string;
}