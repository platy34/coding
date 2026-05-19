#include <stdio.h>
#include <windows.h>
// #include <unistd.h> sleep function on linux/mac

int main(){

    for (int i = 10; i >= 0; i--){
        Sleep(1000);
        printf("%d\n", i);
    }

    printf("Happy new year");

    return 0;
}