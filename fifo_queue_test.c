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
    FIFOq_p fq = FIFOq_construct();
    FIFOq_init(fq);
    if (FIFOq_enqueue(fq, testPCB) == 1) {
        puts("enqueued");
    }

    if (FIFOq_is_empty(fq) == 0) {
        int stringtest = strcmp(PCB_toString(testPCB, pcbteststring), PCB_toString(FIFOq_dequeue(fq), pcbqstring));
        if (stringtest == 0) {
            puts("FIFOq_enqueue passed");
        } else {
            puts("FIFOq_enqueue failed");
        }
    } else {
        puts("FIFOq_enqueue failed");
    }
    FIFOq_destruct(fq);
}

void testDequeue(PCB_p testPCB) {
    char pcbteststring[100];
    char pcbqstring[100];
    PCB_toString(testPCB, pcbqstring);
    FIFOq_p fq = FIFOq_construct();
    FIFOq_init(fq);
    FIFOq_enqueue(fq, testPCB);

    PCB_p dqPCB = FIFOq_dequeue(fq);
    PCB_toString(dqPCB, pcbqstring);

    if (strcmp(pcbqstring, pcbteststring) == 0) {
        puts("FIFO_dequeue passed");
    } else {
        puts("FIFO_dequeue failed");
    }
    puts(pcbqstring);
    puts(pcbteststring);
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
    puts("End Test");
}