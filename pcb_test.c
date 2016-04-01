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
    
    //test set pid
    PCB_set_pid(test1, 123456789UL);
    if(test1->pid == 123456789UL){
        puts("Setting pid was suceesful");
    } else {
        puts("setting pid failed");
    }
 } 
