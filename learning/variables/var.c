#include<stdio.h>

int main() {

    // integer values
    int age = 19;
    int year = 2025;

    // default adding 6-7 digits  
    float gpa = 2.5;
    float price = 19.99;

    // double constants for more precision (6-7)+
    double pi = 3.14159265358; 

    // euler's number
    double e = 2.718281828;

    // characters, look @ unicode.c
    char grade = 'A';
    char symbol = '!';

    // usually doubles take more memory than floats

    printf("The year I learn this language is %d\n", year);
    printf("My age is %d\n", age);

    printf("Your GPA is a %.2f\n", gpa);
    printf("The price of apple earpods are $%.2f\n", price);

    // long float = lf (default prints 6 digits after decimal pt.)
    printf("Pi's value is %.15lf\n", pi);

    printf("Euler's value is %.15lf\n", e);

    // printing characters
    printf("Your grade on the exam is %c\n", grade);
    printf("Your favourite symbol is %c\n", symbol);


    return 0;
}