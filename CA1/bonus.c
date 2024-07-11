#include <stdio.h>

int main()
{
    int n500,n1000,n2000,n5000,n10000,n50000;

    printf("Enter the number of 500: ");                   /*getting number of banknote*/
    scanf("%d",&n500);
    printf("Enter the number of 1000: ");
    scanf("%d",&n1000);
    printf("Enter the number of 2000: ");
    scanf("%d",&n2000);
    printf("Enter the number of 5000: ");
    scanf("%d",&n5000);
    printf("Enter the number of 10000: ");
    scanf("%d",&n10000);
    printf("Enter the number of 50000: ");
    scanf("%d",&n50000);

    int inventory = n500*500+n1000*1000+n2000*2000+n5000*5000+n10000*10000+n50000*50000;    /*calculating inventory*/

    printf("\nYour inventory is: %d\n",inventory); 

    int n;                                                          /*getting number of goods*/
    printf("\nPlease enter number of goods: ");
    scanf("%d",&n);

    int n1,n2,n3,n4,n5,n6;                                         /*declaration for calculating banknote*/


    int i=0;
    for(i=0 ; i<n;i++)                                       /*for  loop for calculating the number of banknote for each commodity*/
   {
            int value;                                      /*get the value of commodity*/
            printf("\nEnter value: ");
            scanf("%d",&value);

            inventory = inventory -value;                              /*update the inventory*/

            if(inventory<0)                                       /*check for enough value in account for buying the commodity*/
            {
                printf("\nNot Enough Money !\n");
                inventory = inventory +value;
                continue;
            }
            n1 = value/50000;                              /*calculating the first number of banknotes (this will be updated in if condition a few lines down)*/
            n2 = (value%50000)/10000;
            n3 = ((value%50000)%10000)/5000;
            n4 = (((value%50000)%10000)%5000)/2000;
            n5 = (((((value%50000)%10000)%5000)%2000))/1000;
            n6 = (((((value%50000)%10000)%5000)%2000)%1000)/500;

            int nn500 = n500,nn1000 = n1000,nn2000 = n2000,nn5000 =n5000,nn10000 = n10000,nn50000 = n50000;  /*temporary variables for if condition a few lines down*/

            int val;    /*/*temporary variable  for if condition a few lines down*/
            
            if(nn50000 * 50000 < n1*50000)    /*this if conditions update the number of banknote according to the number of  user banknotes*/
            {
                 if(value < nn50000 *50000) nn50000=0;
                 n1 = nn50000;
                 val = value - (nn50000*50000);
                 n2 = val/10000;
                 n3 = (val%10000)/5000;
                 n4 = ((val%10000)%5000)/2000;
                 n5 = ((((val%10000)%5000)%2000))/1000;
                 n6 = ((((val%10000)%5000)%2000)%1000)/500;
                 if(nn10000 * 10000 < n2 *10000)
                 {
                     if(value < nn50000 *50000) nn50000=0;
                     if(value < nn10000 *10000) nn10000=0;
                     n1 = nn50000;
                     n2 = nn10000;
                     val = value - (nn50000*50000 + nn10000 *10000);
                     n3 = val/5000;
                     n4 = (val%5000)/2000;
                     n5 = ((val%5000)%2000)/1000;
                     n6 = (((val%5000)%2000)%1000)/500;

                     if(nn5000 *5000 < n3 *5000)
                     {
                            if(value < nn50000 *50000) nn50000=0;
                            if(value < nn10000 *10000) nn10000=0;
                            if(value < nn5000 *5000) nn5000=0;
                            n1 = nn50000;
                            n2 = nn10000;
                            n3 = nn5000;
                            val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000);
                            n4 = val/2000;
                            n5 = (val%2000)/1000;
                            n6 = ((val%2000)%1000)/500;
                            if(nn2000 * 2000 < n4 * 2000)
                            {
                                if(value < nn50000 *50000) nn50000=0;
                                if(value < nn10000 *10000) nn10000=0;
                                if(value < nn5000 *5000) nn5000=0;
                                if(value < nn2000 *2000) nn2000=0;
                                n1 = nn50000;
                                n2 = nn10000;
                                n3 = nn5000;
                                n4 = nn2000;
                                val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000);
                                n5 = val/1000;
                                n6 = (val%1000)/500;
                                if(nn1000 * 1000 <n5*1000)
                                {
                                    if(value < nn50000 *50000) nn50000=0;
                                    if(value < nn10000 *10000) nn10000=0;
                                    if(value < nn5000 *5000) nn5000=0;
                                    if(value < nn2000 *2000) nn2000=0;
                                    if(value < nn1000 *1000) nn1000=0;
                                    n1 = nn50000;
                                    n2 = nn10000;
                                    n3 = nn5000;
                                    n4 = nn2000;
                                    n5 = nn1000;
                                    val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000 + nn1000 *1000);
                                    n6 = val/500;
                                    if(nn500 * 500 < n6 *500)
                                    {
                                        printf("Error!");
                                        inventory = inventory + value;
                                        continue;
                                    }
                                }
                            }
                     }
                 }

            }
            if(nn10000 * 10000 < n2 *10000)
            {
                if(value < nn50000 *50000) nn50000=0;
                if(value < nn10000 *10000) nn10000=0;
                n1 = nn50000;
                n2 = nn10000;
                val = value - (nn50000*50000 + nn10000 *10000);
                n3 = val/5000;
                n4 = (val%5000)/2000;
                n5 = ((val%5000)%2000)/1000;
                n6 = (((val%5000)%2000)%1000)/500;

                if(nn5000 *5000 < n3 *5000)
                {
                    if(value < nn50000 *50000) nn50000=0;
                    if(value < nn10000 *10000) nn10000=0;
                    if(value < nn5000 *5000) nn5000=0;
                    n1 = nn50000;
                    n2 = nn10000;
                    n3 = nn5000;
                    val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000);
                    n4 = val/2000;
                    n5 = (val%2000)/1000;
                    n6 = ((val%2000)%1000)/500;
                    if(nn2000 * 2000 < n4 * 2000)
                    {
                        if(value < nn50000 *50000) nn50000=0;
                        if(value < nn10000 *10000) nn10000=0;
                        if(value < nn5000 *5000) nn5000=0;
                        if(value < nn2000 *2000) nn2000=0;
                        n1 = nn50000;
                        n2 = nn10000;
                        n3 = nn5000;
                        n4 = nn2000;
                        val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000);
                        n5 = val/1000;
                        n6 = (val%1000)/500;
                        if(nn1000 * 1000 <n5*1000)
                        {
                            if(value < nn50000 *50000) nn50000=0;
                            if(value < nn10000 *10000) nn10000=0;
                            if(value < nn5000 *5000) nn5000=0;
                            if(value < nn2000 *2000) nn2000=0;
                            if(value < nn1000 *1000) nn1000=0;
                            n1 = nn50000;
                            n2 = nn10000;
                            n3 = nn5000;
                            n4 = nn2000;
                            n5 = nn1000;
                            val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000 + nn1000 *1000);
                            n6 = val/500;
                            if(nn500 * 500 < n6 *500)
                            {
                                printf("Error!");
                                inventory = inventory + value;
                                continue;
                            }
                        }
                    }
                }
            }
            if(nn5000 *5000 < n3 *5000)
            {
                    if(value < nn50000 *50000) nn50000=0;
                    if(value < nn10000 *10000) nn10000=0;
                    if(value < nn5000 *5000) nn5000=0;
                    n1 = nn50000;
                    n2 = nn10000;
                    n3 = nn5000;
                    val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000);
                    n4 = val/2000;
                    n5 = (val%2000)/1000;
                    n6 = ((val%2000)%1000)/500;
                    if(nn2000 * 2000 < n4 * 2000)
                    {
                        if(value < nn50000 *50000) nn50000=0;
                        if(value < nn10000 *10000) nn10000=0;
                        if(value < nn5000 *5000) nn5000=0;
                        if(value < nn2000 *2000) nn2000=0;
                        n1 = nn50000;
                        n2 = nn10000;
                        n3 = nn5000;
                        n4 = nn2000;
                        val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000);
                        n5 = val/1000;
                        n6 = (val%1000)/500;
                        if(nn1000 * 1000 <n5*1000)
                        {
                            if(value < nn50000 *50000) nn50000=0;
                            if(value < nn10000 *10000) nn10000=0;
                            if(value < nn5000 *5000) nn5000=0;
                            if(value < nn2000 *2000) nn2000=0;
                            if(value < nn1000 *1000) nn1000=0;
                            n1 = nn50000;
                            n2 = nn10000;
                            n3 = nn5000;
                            n4 = nn2000;
                            n5 = nn1000;
                            val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000 + nn1000 *1000);
                            n6 = val/500;
                            if(nn500 * 500 < n6 *500)
                            {
                                printf("Error!");
                                inventory = inventory + value;
                                continue;
                            }
                        }
                    }
            }
            if(nn2000 * 2000 < n4 * 2000)
            {
                if(value < nn50000 *50000) nn50000=0;
                if(value < nn10000 *10000) nn10000=0;
                if(value < nn5000 *5000) nn5000=0;
                if(value < nn2000 *2000) nn2000=0;
                n1 = nn50000;
                n2 = nn10000;
                n3 = nn5000;
                n4 = nn2000;
                val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000);
                n5 = val/1000;
                n6 = (val%1000)/500;
                if(nn1000 * 1000 <n5*1000)
                {
                        if(value < nn50000 *50000) nn50000=0;
                        if(value < nn10000 *10000) nn10000=0;
                        if(value < nn5000 *5000) nn5000=0;
                        if(value < nn2000 *2000) nn2000=0;
                        if(value < nn1000 *1000) nn1000=0;
                        n1 = nn50000;
                        n2 = nn10000;
                        n3 = nn5000;
                        n4 = nn2000;
                        n5 = nn1000;
                        val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000 + nn1000 *1000);
                        n6 = val/500;
                        if(nn500 * 500 < n6 *500)
                        {
                            printf("Error!");
                            inventory = inventory + value;
                            continue;
                        }
                }
            }
            if(nn1000 * 1000 <n5*1000)
            {
                    if(value < nn50000 *50000) nn50000=0;
                    if(value < nn10000 *10000) nn10000=0;
                    if(value < nn5000 *5000) nn5000=0;
                    if(value < nn2000 *2000) nn2000=0;
                    if(value < nn1000 *1000) nn1000=0;
                    n1 = nn50000;
                    n2 = nn10000;
                    n3 = nn5000;
                    n4 = nn2000;
                    n5 = nn1000;
                    val = value - (nn50000*50000 + nn10000 *10000 + nn5000 *5000 + nn2000 *2000 + nn1000 *1000);
                    n6 = val/500;
                    if(nn500 * 500 < n6 *500)
                    {
                        printf("Error!");
                        inventory = inventory + value;
                        continue;
                    }
            }


            int spend = n1*50000 + n2*10000 + n3 *5000 + n4*2000 + n5*1000 + n6*500;
            if(value -spend>0 && value -spend<500) n6++;                 /*calculating for overpaid situation*/

            n500 = n500 - n6;                        /*update the number of banknote for next time*/
            n1000 = n1000 -n5;
            n2000 = n2000 -n4;
            n5000 = n5000 -n3;
            n10000 = n10000-n2;
            n50000 = n50000-n1;

            printf("n500\t\tn1000\t\tn2000\t\tn5000\t\tn10000\t\tn50000");              /*print the number of bank note for commodity*/
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",n6,n5,n4,n3,n2,n1);

            printf("\nRemaining inventory: %d\n",inventory);                                /*print remmaining money*/

            printf("\nnumber of 500: %d\n",n500);                                    /*print the number of remaining banknote */
            printf("number of 1000: %d\n",n1000);
            printf("number of 2000: %d\n",n2000);
            printf("number of 5000: %d\n",n5000);
            printf("number of 10000: %d\n",n10000);
            printf("number of 50000: %d\n",n50000);
    }
    return 0;
}