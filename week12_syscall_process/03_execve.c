#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *const argv[]){

    if(argc < 2){
        printf("Usage : 03_execve, program_path, option_1 ...\n");
        return 0;
    }
    
    // child의 pid
    pid_t child_pid;

    // child 생성
    child_pid = fork();

    if (child_pid == 0) {
        int code_execve = execve(argv[1], &argv[1], NULL);
        if (code_execve == -1){
            perror("execve");
            return 1;
        }
        return 7;
    }
    else {
        if(child_pid == -1){
            printf("fork failed\n");
            return 0;
        }
        // execve가 만약 실패했다면 exit code 1로 종료한다는 것을 체크하는 부분
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Exit with Code %d\n", WEXITSTATUS(wstatus));
        }
    }

    return 0;
}