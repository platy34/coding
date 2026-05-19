#include <stdio.h>

int main(){

    int numbers[] = {10000, 20, 30, 40, 50, 32123};
    char grades[] = {'A', 'B', 'C', 'D', 'F'};

    int size = sizeof(numbers)/sizeof(numbers[0]);

    for (int i = 0; i < size; i++){
        printf("%d\n", numbers[i]);
    }

    return 0;
}
