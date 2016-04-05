//
// Created by mat on 4/4/16.
//

#include <stdio.h>
#include <string.h>
#include "fifo_queue.h"

void testConstructor(void) {
    FIFOq_p fq = FIFOq_construct();
    if (fq) {
        puts("FIFOq_construct passed");
    } else {
        puts("FIFOq_construct failed");
    }
    FIFOq_destruct(fq);
}

void testInitializer() {
    FIFOq_p fq = FIFOq_construct();
    FIFOq_init(fq);
    if (fq->size == 0 && fq->front == NULL && fq->rear == NULL) {
        puts("FIFO_init passed");
    } else {
        puts("FIFO_init failed");
    }
    FIFOq_destruct(fq);
}

void testisEmpty() {
    FIFOq_p fq = FIFOq_construct();
    FIFOq_init(fq);
    if (FIFOq_is_empty(fq)) {
        puts("FIFO_is_empty passed");
    } else {
        puts("FIFO_is_empty failed");
    }
    FIFOq_destruct(fq);
}

void testEnqueue(PCB_p testPCB) {
    char pcbteststring[100];
    char pcbqstring[100];
    puts("Debug 0");
    FIFOq_p fq = FIFOq_construct();
    puts("debug 1");
    FIFOq_init(fq);
    puts("debug 2");
    if (FIFOq_enqueue(fq, testPCB) == 1) {
        puts("enqueued");
    }
    puts("Debug 3");
    if (FIFOq_is_empty(fq) == 0) {
        int stringtest = strcmp(PCB_toString(testPCB, pcbteststring), PCB_toString(FIFOq_dequeue(fq), pcbqstring));
        if (stringtest == 0) {
            puts("FIFOq_enqueue passed");
        }
    }
    puts("FIFOq_enqueue failed");
    FIFOq_destruct(fq);
}

void testDequeue(PCB_p testPCB) {
    FIFOq_p fq = FIFOq_construct();
    FIFOq_init(fq);
    FIFOq_enqueue(fq, testPCB);

    FIFOq_dequeue(fq);
    puts("End");
}

int main(void) {
    PCB_p testPCB = PCB_construct();
    PCB_init(testPCB);

    testConstructor();
    testInitializer();
    testisEmpty();
    testEnqueue(testPCB);
    testDequeue(testPCB);

    PCB_destruct(testPCB);
}