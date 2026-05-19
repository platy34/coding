#include <stdio.h>
#include <stdbool.h>

int getMax(int x, int y){

    if (x >= y){
        return x;
    }else{
        return y;
    }
}

bool ageCheck(int age){
    if (age >= 18){
        return true;
    }else{
        return false;
    }
}

double cube(double num){
    return num * num * num;
}

double square(double num){

    return num * num;
}

int main(){

    double x = cube(2.43);
    double y = square(3.2);
    double z = square(4.4);
    int a  = 4;
    int b = 7;

    int age = 78;
    if (ageCheck(age)){
        printf("You may sign up.\n");
    }else{
        printf("You must be 18+ to sign up.\n");
    }
    printf("%d\n", getMax(a,b));

    printf("%lf\n", x);
    printf("%lf\n", y);
    printf("%lf\n", z);

    return 0;
}