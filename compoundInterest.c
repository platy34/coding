#include <stdio.h>
#include <math.h>

int main(){

    double principal = 0.0;
    double rate = 0.0;
    int years = 0;
    int numCompoundedPerYear = 0;
    double total = 0.0;

    printf("Enter the principal: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate: ");
    scanf("%lf", &rate);
    rate = rate/100;

    printf("Enter the number of years: ");
    scanf("%d", &years);

    printf("Enter the number of times compounded per year (n): ");
    scanf("%d", &numCompoundedPerYear);

    total = principal * pow(1 + rate / numCompoundedPerYear, numCompoundedPerYear * years);
    printf("After %d years, the total will be $%.2lf", years, total);


    return 0;
}