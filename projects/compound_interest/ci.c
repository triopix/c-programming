#include<stdio.h>
#include<math.h>

int main() {

    /*
    Compound Interest Calculator

    This program calculates the compound interest based on user input for principal amount, rate of interest, time period, and number of times interest is compounded per year.

    Formula used: 
    A = P * (1 + r/n)^(nt)

    Where:
    A = the future value of the investment/loan, including interest
    P = the principal investment amount (the initial deposit or loan amount)
    r = the annual interest rate (decimal)
    n = the number of times that interest is compounded per year
    t = the number of years the money is invested or borrowed for
    */

    double A, P, r, n, t;

    printf("Compound Interest Calculator\n");

    // copilot did some magic here lmao (fixed trying to type prompts w/ scanf)
    printf("Enter the principal (P): ");
    scanf("%lf", &P);
    printf("Enter the interest rate %% (r): ");
    scanf("%lf", &r);
    printf("Enter the # of years (t): ");
    scanf("%lf", &t);
    printf("Enter the # of times compounded per year (n): ");
    scanf("%lf", &n);

    A = P * pow((1.00 + ((r/100.0)/n)), (n*t));

    // Print double: %g conveniently omits trailing .00 for whole numbers.
    printf("After %g years, the total will be $%.2lf\n", t, A);
}