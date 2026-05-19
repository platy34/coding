#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){

    int choice = 0;
    float pounds = 0.0f;
    float kilograms = 0.0f;

    printf("Weight Conversion Calculator\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice ==  1){
        //kg to lb
        printf("Enter the weight in kg: ");
        scanf("%f", &kilograms);
        pounds = kilograms * 2.20462;
        printf("%.2f kilograms is equal to %.2f pounds", kilograms, pounds);
    }
    else if (choice == 2){
        //lb to kg
        printf("Enter the weight in pounds: ");
        scanf("%f", &pounds);
        kilograms = pounds / 2.20462;
        printf("%.2f pounds is equal to %.2f kilograms", pounds, kilograms);
    }
    else{
        printf("Invalid choice! Please enter 1 or 2\n");
    }


    return 0;
}