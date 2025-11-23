#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUF_SIZE 32

int main(int argc, char* argv[]){

    if (argc < 3){
        printf("Usage : 06_mycp / source / dest1 ...\n");
        exit(1);
    }

    int file_num = argc - 2;

    int fd_src;
    fd_src = open(argv[1], O_RDONLY);

    if(fd_src == -1){
        printf("%s : file open error\n", argv[1]);
        perror(argv[1]);
        exit(1);
    }
    else {
        printf("%s : file open successful\n", argv[1]);
    }

    int* fd_dst_list = (int*)malloc(sizeof(int) * file_num);

    for(int i = 0; i < file_num; i++){
        fd_dst_list[i] = open(argv[2+i], O_WRONLY | O_CREAT, 0644);
        if(fd_dst_list[i] == -1){
            printf("%s : file open error\n", argv[2+i]);
        }
        else {
            printf("%s : file open successful\n", argv[2+i]);
        }
    }

    int read_result;
    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);

    while(1){
        read_result = read(fd_src, readStr, BUF_SIZE);

        if (read_result < 0){
            perror("read");
            exit(1);
        }
        if(read_result == 0){
            break;
        }
        write(STDOUT_FILENO, readStr, read_result);
        for (int i = 0; i < file_num; i++){
            if(fd_dst_list[i] != -1){
                write(fd_dst_list[i], readStr, read_result);
            }
            else {
                printf("%s : This file has not been opened\n", argv[2+i]);
            }
        }
    }

    close(fd_src);
    for (int i = 0; i < file_num; i++){
        close(fd_dst_list[i]);
    }

    free(fd_dst_list);
    free(readStr);
}