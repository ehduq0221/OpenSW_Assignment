#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){

    pid_t child_pid;

    child_pid = fork();

    if (child_pid == 0){
        printf("Child process PID : %lu\n", (unsigned long)getpid());
        printf("Child process PPID : %lu\n", (unsigned long)getppid());
        sleep(1);
        return 7;
    }

    else {
        printf("Parent process PID : %lu\n", (unsigned long)getpid());
        printf("Parent process PPID : %lu\n", (unsigned long)getppid());
    }

    return 0;
}