#include <stdio.h>
#include <math.h>

int main(){

    double radius = 0.0;
    double area = 0.0;
    double surfaceArea = 0.0;
    double volume = 0.0;
    const double PI = 3.14159;

    printf("Enter a radius: ");
    scanf("%lf", &radius);
    
    area = PI * pow(radius, 2); // for circle
    surfaceArea = 4 * PI * pow(radius, 2); // for sphere
    volume = (4.0/3.0) * PI * pow(radius, 3);

    printf("Area: %.2lf\n", area);
    printf("Surface Area: %.2lf\n", surfaceArea);
    printf("Volume: %.2f\n", volume);

    return 0;
}