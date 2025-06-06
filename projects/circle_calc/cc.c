#include<stdio.h>
#include<math.h>

int main() {

    // PI we get from math.h, do not reinvent the wheel with a const double implementation
    // const, is basically the same as final in java

    double radius, area, surfaceArea, volume;

    printf("Enter the radius: ");
    scanf("%lf", &radius);
    getchar();

    area = M_PI * pow(radius, 2);
    surfaceArea = 4 * M_PI * pow(radius, 2);
    volume = (4.00 / 3.00) * M_PI * pow(radius, 3);

    printf("Area: %.2lf\n", area);
    printf("Surface Area: %.2lf\n", surfaceArea);
    printf("Volume: %.2lf\n", volume);
    
}