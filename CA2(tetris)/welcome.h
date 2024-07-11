int Welcome()
{
    printf("\t\t\t\t ---------------------------------------------");                   // print the menu of the game 
    for(int i=0;i<25;i++)
    {
        if(i==5) printf("\n\t\t\t\t|              welcome to Tetris              |");
        if(i==10) printf("\n\t\t\t\t|                  1. Start                   |");
        if(i==14) printf("\n\t\t\t\t|                  2. Exit                    |");
        if(i==23) printf("\n\t\t\t\t|   Erfan Falahati                            |");
        else printf("\n\t\t\t\t|                                             |");
    }
    printf("\n\t\t\t\t --------------------------------------------\n");

    int starter;
    scanf("%d",&starter);
    if(starter == 1) return 1;
    else if(starter == 2) return 2;
    else return 3;
}