#include <stdio.h>
#include <string.h>

int main(){

    //Shopping cart

    char item[50] = "";
    float price = 0.0f;
    int quantity = 0;
    char currency = '$';
    float total = 0.0f;

    printf("What item would you like to buy?: ");
    fgets(item, sizeof(item), stdin);
    item[strlen(item) - 1] = '\0';

    printf("What is the price of the item?: ");
    scanf("%f", &price);

    printf("How many of the item?: ");
    scanf("%d", &quantity);

    total = price * quantity;

    printf("\nYou have bought %d %s(s)\n", quantity, item);
    printf("%c%.2f", currency, total);

}