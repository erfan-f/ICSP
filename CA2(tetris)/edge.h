
//edge function for displacement limits

void  edge(char playground[][20],int *edge1,int *edge2,int randnum,int status,int h)  
{                                                                                                   
    if(randnum == 0)                            // check for which shape is currentlyy on the board
    {
            if(status == 1)                            // check the rotate_status of the shape
            {
                if(playground[h+1][19] == ']') *edge2=1;
                if(playground[h+1][0] == '[') *edge1=1;
            }
            if(status == 2)
            {
                if(playground[h+1][19] == ']') *edge2=1;
                if(playground[h][0] == '[') *edge1=1;
            }
            if(status == 3)
            {
                if(playground[h][19] == ']') *edge2 = 1;
                if(playground[h][0] == '[') *edge1 = 1;
            }
            if(status == 4)
            {
                if(playground[h][19] == ']') *edge2=1;
                if(playground[h+1][0] == '[') *edge1=1;
            }
    }
    else if(randnum == 1)
    {
        if(playground[h][19] == ']') *edge2=1;
        if(playground[h][0] == '[') *edge1=1;
    }
    else if(randnum == 2)
    {
        if(status == 1)
        {
            if(playground[h+1][19] == ']') *edge2=1;
            if(playground[h][0] == '[') *edge1=1;
        }
        if(status == 2)
        {
            if(playground[h+1][19] == ']') *edge2=1;
            if(playground[h+1][0] == '[') *edge1=1;
        }
        if(status == 3)
        {
            if(playground[h][19] == ']') *edge2 = 1;
            if(playground[h][0] == '[') *edge1 = 1;
        }
        if(status == 4)
        {
            if(playground[h][19] == ']') *edge2=1;
            if(playground[h+1][0] == '[') *edge1=1;
        }
    }
    else if(randnum == 3)
    {
        if(playground[h][19] == ']') *edge2 = 1;
        if(playground[h][0] == '[') *edge1 = 1;
    }
}