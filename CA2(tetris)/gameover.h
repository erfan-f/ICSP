
//for checking the gameover conditon

int gameover(char playground[][20])
{
    int count;
   for(int j=0;j<20;j++)                       // this for loop check for complete coloumn
    {
        count =0;
        for(int i=0;i<20;i++)
        {
            if(playground[i][j] != ' ') count++;
        }
        if(count ==20) return 1;
    }
    return 0;
}