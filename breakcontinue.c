#include <stdio.h>

int main(){

//break will break out of a loop, continue will skip the current cycle
    for (int i =  0; i < 10; i++){
        if (i == 4){
            continue;
        }
        printf("%d\n", i);
    }

    return 0;
}