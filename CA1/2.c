#include <stdio.h>

 int main()
{
    int dec;
    printf("Please Enter a decimal number: ");    /*getting decimal number*/
    scanf("%d",&dec);

    int place=1,x=0;
    while(dec!=0)                    /*calculating bainary number*/            
    {   
        x = x + ((dec%2) * place);
        place = place * 10;        
        dec = dec/2;   
    }
    printf("%d",x);             /*print binary number*/
    return 0;
}
