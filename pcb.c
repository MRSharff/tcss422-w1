#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum state_type {
  new, ready, running, interrupted, waiting, halted
} State;

const int SUCCESS = 1;
const int NO_OBJECT = 2;

const unsigned long DEFAULT_PID = 0;
const State DEFAULT_STATE = new;
const unsigned long DEFAULT_PC = 0;



typedef struct pcb {
  unsigned long pid;
  State state;
  unsigned short priority;
  unsigned long pc;
} PCB;

typedef PCB * PCB_p;

//Used for generating random priority in init function
int generate_priority() {
  return (unsigned short) rand() % 32;
}

//Member Functions
PCB_p PCB_construct (void) {
  return (PCB_p) malloc(sizeof(PCB));
}

void PCB_destruct(PCB_p pcb) {
  free(pcb);
}

int PCB_init(PCB_p pcb) {
  if (pcb == NULL) {
    return NO_OBJECT;
  }
  pcb->pid = DEFAULT_PID;
  pcb->state = DEFAULT_STATE;
  pcb->priority = generate_priority();
  pcb->pc = DEFAULT_PC;
}

int PCB_set_pid(PCB_p pcb, unsigned long pid) {
  if (pcb == NULL) {
    return NO_OBJECT;
  }
  pcb->pid = pid;
  return SUCCESS;
}

unsigned long PCB_get_pid(PCB_p pcb) {
  //error checking in controller
  return pcb->pid;
}

int PCB_set_state(PCB_p pcb, State state) {
  if (pcb == NULL) {
    return NO_OBJECT;
  }
  pcb->state = state;
  return SUCCESS;
}

State PCB_get_state(PCB_p pcb) {
  return pcb->state;
}

char * PCB_toString(PCB_p pcb, char * string) {
  sprintf(string, "PID: %0x, State: %d, Priority: %0x, PC: %0x",
          pcb->pid, pcb->state, pcb->priority, pcb->pc);
  return string;
}
