#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main() {

    /*Format specifiers are special tokens beginning with the % symbol, 
    followed by a character, that specifies the data type and optional modifiers 
    (width, precision, flags). They control how data is displayed or interpreted. */

    // format specifiers modify output
    int age = 25;
    float price = 20.22;
    double pi = 3.14159265358;

    // multibyte character requires a character array to store bytes
    // 1 byte characters are (0-127 on ASCII)
    // yen = 165 -> char yen[] = "¥";
    char currency = '$';
    char name[] = "Archisman Nath";

    printf("Age is %d\n", age);
    printf("Price is %.2f\n", price);
    printf("Pi's value is %.2lf\n", pi);
    printf("The currency is set to %c\n", currency);
    printf("My name is %s\n", name);

    // for scanning user input, %lf is good for output/input for consistency
    
    // width
    int num1 = 1;
    int num2 = 12;
    int num3 = 122;

    // default = right justified
    printf("\nPrinting with width-spacing: \n");
    printf("%3d\n", num1);  // var_width = 1, therefore 3 - 1 = 2 spaces
    printf("%3d\n", num2);  // var_width = 2, therefore 3 - 2 = 1 space
    printf("%3d\n", num3);  // var_width = 3, therefore 3 - 3 = 0 spaces

    // left justified w/ leading zeroes
    printf("\nPrinting with left-justified width-spacing: \n");
    printf("%-3d\n", num1); // left justified 3 spaces after

    // leading zeros (instead of spaces)
    printf("\nPrinting with leading zeroes: \n");
    printf("%03d\n", num1);
    printf("%03d\n", num2);
    printf("%03d\n", num3);

    // precision (decimals are set to print 6 spaces after the point)
    float price1 = 19.99;
    float price2 = 20.22;
    float price3 = -18.23;

    printf("\n");
    printf("Floats\n");
    printf("%.2f\n", price1);
    printf("%.3f\n", price2);
    printf("%.4f\n", price3);

    // doing .1f rounds the amount

    // combining width and precision
    // don't choose a width less than the set-width of the variable
    // adding '+' tells C compiler to "show me the signs!!!"
    printf("\nFloats (width-precision modified w/ signs showing):\n");
    printf("%+8.2f\n", price1); 
    printf("%+8.3f\n", price2);
    printf("%+8.4f\n", price3);

    /* 
    Escaping characters:

    -> use backslash "\" to escape any character
    -> use %% for SPECIFICALLY escaping the % character
    
    */
    printf("I am printing a %% right now\n");
    printf("Here is a normal \" escaped character\n");

    return 0;
}