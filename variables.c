#include <stdio.h>
#include <stdbool.h>

int main(){

    int age = 25;
    int year = 2026;
    int quantity = 2;
    float gpa = 2.5;
    float price = 19.99;
    float temperature = -10.1;
    double pi = 3.14159265358;
    double e = 2.71828;
    char grade = 'A';
    char symbol = '!';
    char currency = '$';
    char name[] = "Awoogabooga"; //Can store more than one char, must be in double quotes
    char food[] = "pizza";
    char email[] = "fake123@gmail.com";
    bool isOnline = true;
    bool isStudent = false;
    if (isOnline){
        printf("You are online\n");
    }else{
        printf("You are offline\n");
    }
    if (isStudent){
        printf("You are a Student\n");
    }else{
        printf("You are not a Student\n");
    }

    printf("You are %d years old\n", age);
    printf("The year is %d\n", year);
    printf("Your have ordered %d x items\n", quantity);
    printf("Your gpa is %.1f\n", gpa);
    printf("The price is $%.2f\n", price);
    printf("The temperature is %.1f°C\n", temperature);
    printf("The value of pi is %.11lf\n", pi);
    printf("The value of e is %.5lf", e);
    printf("Your grade is %c\n", grade);
    printf("Your favourite symbol is %c\n", symbol);
    printf("The currency is %c\n", currency);
    printf("Hello %s\n", name);
    printf("Your favourite food is %s\n", food);
    printf("Your email is %s\n", email);
    printf("%d", isOnline);

    return 0;


}