#include <stdio.h>

int main()
{
    char unit;                                    /*getting char for status of kelvin or Fahrenheit*/
    printf("Fahrenheit or kelvin: ");
    scanf("%c",&unit);


    float degree;                               

    if(unit == 'K' || unit == 'k')                 /*check condition for calculate degree(C) */
    {
        printf("Enter degree : ");
        scanf("%f",&degree);
        printf("%f(K) = %.2f(C)\n",degree,degree - 273.15);    /*calculate and print degree(C) if the case is Kelvin*/
    }
    else if(unit == 'F' || unit == 'f')
    {
        printf("Enter degree : ");
        scanf("%f",&degree);
        printf("%f(F) = %.2f(C)\n",degree,((float)5/9)*(degree -32));     /*calculate and print degree(C) if the case is Fahrenheit*/
    }
    else   printf("Error!");

    return 0;
}