

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler_function(int sig){
    printf("\nInterrupt signal (%d) received.\n", sig);
    exit(sig);
}

int main(){
    struct sigaction sa;

    printf("Program starting.\n");

    // register signal handler
    sa.sa_handler = handler_function;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGINT");
        exit(1);
    }

    // do some work
    int count = 0;
    while(1) {
        printf("Working...\n");
        sleep(1);
        count++;
        if (count > 10) {
            printf("Done!\n");
            break;
        }
    }

    return 0;
}