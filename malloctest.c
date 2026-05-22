#include <stdio.h>
#include <stdlib.h>

int main(){
   
    int number = 0;

    //create an array to store n number of integers (n from user input)
    printf("Enter the number of integers in the array: ");
    scanf("%d", &number);
    
    int *ptr = (int *)malloc(number * sizeof(number));
    if (ptr == NULL){
        printf("malloc failed");
        return 1;
    }

    //populate the array
    for (int i = 0; i < number; i++){
        ptr[i] = i + 1;
    }

    //print the array
    for (int i = 0; i < number; i++){
        printf("%d ", ptr[i]);
    }
    
    free(ptr);
    ptr == NULL;

    return 0;
}
