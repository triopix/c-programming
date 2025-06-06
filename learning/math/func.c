#include<stdio.h>
#include <stdlib.h> // For abs, labs, llabs
#include <math.h>   // For fabs, fabsf, fabsl

int main() {

    // changing x 
    double x;
    scanf("%lf", &x);   
    getchar();  // good practice (consumes newline)

    // x itself
    printf("\n%lf\n", x);

    // square root (usually needs output a double)
    printf("%lf\n", sqrt(x));

    // power function
    printf("%lf\n", pow(x, 4));

    // round (equivalent to floor(x))
    printf("%lf\n", round(x));
    
    // round up (ceiling)
    printf("%lf\n", ceil(x));
    
    // floor (rounding down)
    printf("%lf\n", floor(x));

    // absolute value (distance from 0, as a positive #)
    printf("%lf\n", fabs(x));

    // natural logarithm (ln(x)) -> base 'e'
    printf("%lf\n", log(x));

    // sin of x
    printf("%lf\n", sin(x));

    // cos of x
    printf("%lf", cos(x));

    // tan of x
    printf("%lf\n", tan(x));

    return 0;
}