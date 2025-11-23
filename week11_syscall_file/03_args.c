#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    
    if(argc != 4){
        printf("Usage 03_args file name\n");
        return 0;
    }

    // printf("argc %d\n", argc);

    for (int i = 0; i < argc; i++){
        printf("argc[%d] : %s\n", i, argv[i]);
    }

    return 0;
}