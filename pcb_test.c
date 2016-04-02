#include "pcb.h"
/**
	Checks if construction is successful.
 */
void testConstructor(){
	PCB_p t1 = PCB_construct();
    if(t1){
		puts("Constructor passed");
		free(t1);
    } else {
        puts("Constructor failed");
    }
}

/** Driver for testing all methods for pcb.
 */
int main(int theArgC, char* theArgV[]){
    char str[100];
	//test pcb constructor
	testConstructor();
    //test initializer
    PCB_init(t1);
    if(tes1->pid == DEFAULT_PID
        && test->state == NEW
        && test->priority == DEFAULT_PRIORITY
        && test->pc == DEFAULT_PC
      ) {
        puts("initializer passed test");
    }
    
    //test set pid
    PCB_set_pid(t1, 123456789UL);
    if(t1->pid == 123456789UL){
        puts("Setting pid was successful");
    } else {
        puts("setting pid failed");
    }
	
	//test get pid
	unsigned long temp_pid = PCB_get_pid(t1);
	if(temp_pid == 123456789UL){
		puts("get pid worked");
	} else {
		puts("get pid failed");
	}
	
	//test pcb_toString
	PCB_toString(t1, str);
	if (strcmp(str, "pid: 123456789, state: 0, priority: 31, pc: 0")) {
		puts("toString passed");
	} else {
		puts("toString failed");
	}
 } 
