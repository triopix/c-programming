#include<stdio.h>

int main() {

    // arithmetic operators, +, -, /, *, ...
    int x = 10;
    int y = 3;
    int z = 0;

    // addition 
    z = x + y;
    printf("%d + %d = %d\n", x, y, z);

    // subtraction
    z = x - y;
    printf("%d - %d = %d\n", x, y, z);
    
    // multiplication
    z = x * y;
    printf("%d * %d = %d\n", x, y, z);

    // integer division (2/3 = 0.6666)
    z = x / y;
    // using "//" to represent integer division
    printf("%d // %d = %d\n", x, y, z);

    // typecasting our variables (earlier ones)
    float xx = (float) x; 
    float yy = (float) y;
    float zz = (float) z;

    // floating point division
    zz = xx / yy;
    printf("%.1f / %.1f = %f\n", xx, yy, zz);

    // modulus operator (remainder of division)
    z = x % y;
    printf("%d %% %d = %d\n", x, y, z);

    // increment operator
    x++;
    printf("X++ = %d\n", x);

    // decrement operator
    y--;
    printf("Y-- = %d\n", y);

    /*
    Side note: (pre-increment / pre-decrement) vs. (post-increment / post-decrement)
    
    pre-increment: ++x (increments x before USING it)
    post-increment: x++ (increments x after USING it)

    pre-decrement: --x (decrements x before USING it)
    post-decrement: x-- (decrements x after USING it)

    Example:

    int a = 5
    int b = ++a; // a becomes 6, b is assigned 6

    Example:

    int a = 5
    int b = a++; // b is assigned 5, a becomes 6

    Note: The same applies to decrement operators.
    */

    // augmented assignment operators (you know these)

    return 0;
}