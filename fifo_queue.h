#ifndef FIFO_QUEUE
#define FIFO_QUEUE

typedef struct FIFO_q {
    int size;
    struct node* front;
    struct node* rear;
} FIFOq;
typedef FIFOq* FIFOq_p;

FIFOq_p FIFOq_construct(void);
FIFOq_p FIFOq_init(FIFOq_p queue);
int FIFOq_is_empty(FIFOq_p queue);
void FIFOq_enqueue(FIFOq_p queue, PCB_p pcb);
int FIFOq_dequeue(FIFOq_p queue);

#endif