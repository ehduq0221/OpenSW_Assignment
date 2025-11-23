#include <stdio.h>
#include <unistd.h>

int main(void){
    pid_t mypid = getpid();
    pid_t myppid = getppid();

    printf("My pid : %lu\n", (unsigned long)mypid);
    printf("My ppid : %lu\n", (unsigned long)myppid);

    return 0;
}