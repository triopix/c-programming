#include<stdio.h>
#include<string.h>

int main() {

    // SHOPPING CART PROGRAM 

    char item[50];
    char currency[10];
    int quantity;
    float price, total;

    // expect string input 
    printf("What item would you like to buy?: ");

    // strlen() counts # of chars, excluding '\0'
    fgets(item, sizeof(item), stdin);
    item[strcspn(item, "\n")] = '\0'; // safer newline replacement

    printf("What is the price for each?: ");
    scanf("%f", &price);
    
    getchar(); // consumes any newline character
    printf("What currency are you paying in? (type a character): ");
    fgets(currency, sizeof(currency), stdin);
    currency[strcspn(currency, "\n")] = '\0'; // safer newline replacement

    printf("How many would you like?: ");
    scanf("%d", &quantity);

    // grammatical correction logic
    // if(quantity > 1) {
    //     printf("You have bought %d %s/s\n", quantity, item);
    // } else {
    //     printf("You have bought %d %s\n", quantity, item);
    // }
    
    // handling plurarity logic
    char lst = item[strlen(item) - 1];

    printf("You have bought %d %s%s\n", quantity, item, 
        (lst != 's') ? (quantity > 1) ? "s" : "" : "");
    printf("The total is: %s%.2f\n", currency, total = price * quantity);

}