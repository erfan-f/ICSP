// print function for print playground array and the page

void print(char playground[20][20],int*score,int nextshape,int speed)
{
    if(nextshape == 0)
    {
        if(speed == 350) printf("\n\n\t\t     speed : Slow\n");                    //print speed
        else if(speed == 200) printf("\n\n\t\t     speed : Middle\n");
        else if(speed == 50) printf("\n\n\t\t     speed : Fast\n");
        printf("\t\t---------------------\n");
        for(int i=0;i<20;i++)                                                     // print the playground array and the edges
        {
            printf("\t\t|");
            for(int j=0;j<20;j++)
            {
                printf("%c",playground[i][j]);
            }
            printf("|\n");
        }
        printf("\t\t---------------------\n\n");
        printf("                                                                                       []\n");
        printf("\t\t\tscore = %d",*score);                                         //print score
        printf("                                       next shape:  [][][]");
    }
    else if(nextshape == 1)                                                         //print next shape  depend on number of next shape
    {
        if(speed == 350) printf("\n\n\t\t     speed : Slow\n");
        else if(speed == 200) printf("\n\n\t\t     speed : Middle\n");
        else if(speed == 50) printf("\n\n\t\t     speed : Fast\n");
        printf("\t\t---------------------\n");
        for(int i=0;i<20;i++)
        {
            printf("\t\t|");
            for(int j=0;j<20;j++)
            {
                printf("%c",playground[i][j]);
            }
            printf("|\n");
        }
        printf("\t\t---------------------\n\n");
        printf("                                                                                     [][]\n");
        printf("\t\t\tscore = %d",*score);
        printf("                                       next shape:  [][]");

    }
    else if(nextshape == 2)
    {
        if(speed == 350) printf("\n\n\t\t     speed : Slow\n");
        else if(speed == 200) printf("\n\n\t\t     speed : Middle\n");
        else if(speed == 50) printf("\n\n\t\t     speed : Fast\n");
        printf("\t\t---------------------\n");
        for(int i=0;i<20;i++)
        {
            printf("\t\t|");
            for(int j=0;j<20;j++)
            {
                printf("%c",playground[i][j]);
            }
            printf("|\n");
        }
        printf("\t\t---------------------\n\n");
        printf("                                                                                     [][]\n");
        printf("\t\t\tscore = %d",*score);
        printf("                                       next shape:    [][]");
    }
    else if(nextshape == 3)
    {
        if(speed == 350) printf("\n\n\t\t     speed : Slow\n");
        else if(speed == 200) printf("\n\n\t\t     speed : Middle\n");
        else if(speed == 50) printf("\n\n\t\t     speed : Fast\n");
        printf("\t\t---------------------\n");
        for(int i=0;i<20;i++)
        {
            printf("\t\t|");
            for(int j=0;j<20;j++)
            {
                printf("%c",playground[i][j]);
            }
            printf("|\n");
        }
        printf("\t\t---------------------\n\n");
        printf("\n\t\t\tscore = %d",*score);
        printf("                                               next shape:    [][][][]");
    }

}