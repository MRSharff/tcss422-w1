#include "pcb.h"
/** Driver for testing all methods for pcb.
  */
int main(int theArgC, char* theArgV[]){
    //test pcb constructor
    PCB_p test1 = NULL;
    test1 = PCB_construct();
    if(test1 == NULL){
        puts("Constructor failed");
    } else {
        puts("Constructor passed");
    }

    //test initializer
    PCB_init(test1);
    if(tes1->pid == DEFAULT_PID
        && test->state == NEW
        && test->priority == DEFAULT_PRIORITY
        && test->pc == DEFAULT_PC
      ) {
        puts("intitializer passed test");
    }
        
 } 
