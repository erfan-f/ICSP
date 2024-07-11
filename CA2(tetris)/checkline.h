
 // checkline function for checking complete line and plus 10 to score 

void checkline(char playground[][20],int *score)
{

    for(int i=0;i<20;i++)                                    // checking wich line is filled with '[' or ']'
    {
        int count1=0;
        for(int j=0;j<20;j++)
        {
            if(playground[i][j] != ' ')
            {
                count1++;
            }
        }
        int fill_line = i;
        if(count1 == 20)
        {
            *score += 10;                                                          // plus 10 to score
            for(int j=0;j<20;j++) playground[i][j] = ' ';
            for(int k=fill_line ; k>0 ;k--)                                                // move the shape up to down
            {
                for(int j=0;j<20;j++)                                    
                {
                    playground[k][j] = playground[k-1][j];
                }
            }
        }
    }
}