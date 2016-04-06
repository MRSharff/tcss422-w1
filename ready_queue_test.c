//
// Created by mat on 4/6/16.
//

#include <stdio.h>
#include "ready_queue_test.h"

void RQ_testConstruct() {
    READYq_p rq = READYq_construct();
    if (rq != NULL) {
        puts("READYq_construct passed");
    } else {
        puts("READYq_construct failed");
    }
    READYq_destruct(rq);
}

int main(void) {
    return 1;
}