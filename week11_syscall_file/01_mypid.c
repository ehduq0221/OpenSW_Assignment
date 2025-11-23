#include <stdio.h>
#include <unistd.h>

int main(void){
    pid_t mypid = getpid();

    printf("My pid : %lu\n", (unsigned long)mypid);

    return 0;
}