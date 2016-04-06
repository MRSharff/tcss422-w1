
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ready_queue.h"
#include "fifo_queue.h"
#define LOOPS 10
#define NUM_OF_PRIORITIES

int main(int theArgC, char * theArgV[]) {
	char str[200];
	READYq_p t1 = READYq_construct();
	int i;
	int j;
	int pcb_cnt = 0;
	PCB_p tmp_pcb;
	int rand_dequeue;
	
	for(i = 0; i < LOOPS; i++){
		
		for(j = 0; j < LOOPS; j++){
			tmp_pcb = PCB_construct();
			PCB_init(tmp_pcb);
			PCB_set_pid(tmp_pcb, pcb_cnt);
			PCB_set_state(tmp_pcb, ready);
			PCB_set_priority(tmp_pcb, rand() % NUM_OF_PRIORITIES);
			
			READYq_enqueue(t1,tmp_pcb);
		}
		printf("State after %d enqueues:", LOOPS);
		READYq_toString(t1, str);
		printf("%s\n", str);
		rand_dequeue = 4 + rand() % 3;
		printf("Dequeue %d pcbs:\n", rand_dequeue);
		for(j = 0; j < rand_dequeue; j++){
			tmp_pcb = READYq_dequeue(t1);
			PCB_toString(tmp_pcb, str);
			printf("%s\n", str);
			PCB_destruct(tmp_pcb);
		}
		puts("State After Dequeue:");
		READYq_toString(t1, str);
		printf("%s\n\n\n", str);
	}
	
	READYq_destruct(t1);
	return 0;

}