#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int my_system(char *const cmd){
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == 0){
        int code_execl = execl("/bin/sh", "sh", "-c", cmd, NULL);

        if (code_execl == -1){
            perror("execl");
            return 1;
        }
        return 7;
    }
    
    else {
        if(child_pid == -1){
            printf("fork failed");
            return 0;
        }
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Exit with Code : %d\n", WEXITSTATUS(wstatus));
        }
    }

    return 0;
}

int main(void){

    //system("ls -l | wc -l");
    //system("find . -name '*.c'");

    my_system("ls -l | wc -l");
    my_system("find . -name '*.c'");

    printf("good bye\n");

    return 0;

}