#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    // 5 -> 5 * 4 = 20 -> 20
    int p1[2];
    if (pipe(p1) == -1){
        return 1;
    }
    int pid = fork();
    if (pid == -1){
        return 2;
    }
    if (pid == 0){
        //child process

    }
    return 0;

}
