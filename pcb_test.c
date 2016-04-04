#include "pcb.h"
#include <stdio.h>
#include <stdlib.h>
/** Checks if construction is successful.*/
void testConstructor(){
	PCB_p t1 = PCB_construct();
    if(t1){
		puts("Constructor passed");
		free(t1);
    } else {
        puts("Constructor failed");
    }
}
/** Checks if initialized correctly. */
void testInitializer() {
	PCB_p t1 = PCB_construct();
	PCB_init(t1);
    if(t1->pid == DEFAULT_PID
        && t1->state == DEFAULT_STATE
        && t1->priority == DEFAULT_PRIORITY
        && t1->pc == DEFAULT_PC
      ) {
        puts("initializer passed test");
    } else {
		puts("initializer failed");
	}
	free(t1);
}
/** Checks if setting pid works. */
void testSetPid() {
	PCB_p t1 = PCB_construct();
	PCB_init(t1);
	PCB_set_pid(t1, 123456789UL);
    if(t1->pid == 123456789UL){
        puts("Setting pid was successful");
    } else {
        puts("setting pid failed");
    }
	free(t1);
}
/** Test if the get_pid retrieves correct pid. */
void testGetPid() {
	PCB_p t1 = PCB_construct();
	PCB_init(t1);
	PCB_set_pid(t1, 123456789UL);
	unsigned long temp_pid = PCB_get_pid(t1);
	if(temp_pid == 123456789UL){
		puts("get pid worked");
	} else {
		puts("get pid failed");
	}
	free(t1);
}
/** Checks if toString correctly represents
	the pcb state*/
void testToString(char * theStr){
	PCB_p t1 = PCB_construct();
	PCB_init(t1);
	PCB_set_pid(t1, 123456789UL);
	PCB_toString(t1, theStr);
	printf("%s\n",theStr);
	if (strcmp(theStr, "PID: 0x75BCD15, State: 0, Priority: 0, PC: 0")) {
		puts("toString failed");
	} else {
		
		puts("toString passed");
	}
	free(t1);	
}
/** Driver for testing all methods of pcb.*/
int main(int theArgC, char* theArgV[]){
    char str[100];
	testConstructor();
    testInitializer();
	testSetPid();
	testGetPid();
	testToString(str);
} 
