#include <stdio.h>

int main()
{
    int g_wide;
    int x0;
    float displacement;

    printf("Please enter wide of glass: ");
    scanf("%d",&g_wide);                                                   /*getting wide of glass*/

    printf("Please enter primary position of fly on x: ");
    scanf("%d",&x0);                                                       /*getting x0*/
    
    printf("Plese enter delta_x: ");
    scanf("%f",&displacement);                                                  /*getting delta x*/

    int n = (g_wide - x0)/displacement;                                         /*calculating the number of hits*/

    printf("The number of hits to the glass is: %d\n",n);                  /*print number of hits*/

    return 0;
}
