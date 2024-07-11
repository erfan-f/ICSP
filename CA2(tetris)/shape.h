
// shape function for intializing the playground array

void shape(char playground[20][20],int h,int x,int randnum,int *result,int status)
{

    if(randnum==0)                          /*intializing playground array depends on randnum(which shape is on board currently) 
                                             and rotate_status   */
    {
        int temp =9;                         /* temp is for saving the position of the first block in teh case of rotate */
        if(status == 1)                      /*checking which rotate_status is currently on the board */
        {
            *result = 0;
            int shape[8] = {temp,temp+1,temp-2,temp-1,temp,temp+1,temp+2,temp+3};
            for(int i=0;i<8;i+=2)
            {
                if(i==0) temp = shape[i];
                if(i==2) h++;
                playground[h][shape[i] + x] = '[';
                playground[h][shape[i+1] + x] = ']';

                if(i>=2)                       /* this if check the bottom of the shape is empty or not for falling and if its a block there it wil be
                                                return result 1 and in the main function while will be break and next shape will be generated*/  
                {
                    if(playground[h+1][shape[i]+x] != ' '  || playground[h+1][shape[i+1 ]+x] != ' ') *result = 1;
                }
            }
        }
        else if(status == 2)
        {
            *result = 0;
            int shape[8] = {temp,temp+1,temp,temp+1,temp+2,temp+3,temp,temp+1};
            for(int i=0;i<8;i+=2)
            {
                playground[h][shape[i]+x] = '[';
                playground[h][shape[i+1]+x] = ']';
                if(i==0)temp = shape[i];
                if(i==4  || i==6)
                {
                    if(playground[h+1][shape[i]+x] != ' ' || playground[h+1][shape[i+1]+x] != ' ')
                    {
                        *result = 1;
                    }
                }
                if(i==0 || i==4) h++;
            }

        }
        else if(status == 3)
        {
            *result =0;
            int shape[8] = {temp,temp+1,temp+2,temp+3,temp+4,temp+5,temp+2,temp+3};
            for(int i=0;i<8;i+=2)
            {
                playground[h][shape[i]+x] = '[';
                playground[h][shape[i+1]+x] = ']';
                if(i==0) temp = shape[i];
                if(i==0 || i==4 || i==6)
                {
                    if(playground[h+1][shape[i]+x] != ' ' || playground[h+1][shape[i+1]+x] != ' ') *result=1;
                }
                if(i==4) h++;

            }
        }
        else if(status ==4)
        {
            *result =0;
            int shape[8] = {temp,temp+1,temp-2,temp-1,temp,temp+1,temp,temp+1};
            for(int i=0;i<8;i+=2)
            {
                playground[h][shape[i]+x] = '[';
                playground[h][shape[i+1]+x] = ']';
                if(i==0) temp = shape[i];
                if(i==0 || i==6)
                {
                    if(playground[h+1][shape[i]+x] != ' ' || playground[h+1][shape[i+1]+x] != ' ') *result=1;
                }
                if(i==0 ||i==4) h++;
            }
        }
    }
    else if(randnum==1)
    {
        int shape[8] = {8,9,10,11,8,9,10,11};
        for(int i=0 ; i<8;i+=2)
        {
            if(i==4) h++;
            playground[h][shape[i] + x] = '[';
            playground[h][shape[i+1] + x] = ']';
            if(i==4 || i==6)
            {
                if(playground[h+1][shape[i]+x] != ' '  || playground[h+1][shape[i+1 ]+x] != ' ') *result = 1;
            }
        }
    }
    else if(randnum==2)
    {
        int temp = 7;
        if(status == 1 || status == 3)
        {
            *result =0;
            for(int i=0 ; i<8;i+=2)
            {
                int shape[8] = {temp,temp+1,temp+2,temp+3,temp+2,temp+3,temp+4,temp+5};
                playground[h][shape[i] + x] = '[';
                playground[h][shape[i+1] + x] = ']';
                if(i==2) h++;
                if(i==0) temp =shape[i];
                if(i ==0 || i==4 || i==6)
                {
                    if(playground[h+1][shape[i]+x] != ' '  || playground[h+1][shape[i+1 ]+x] != ' ') *result = 1;
                }
            }
        }
        else if(status == 2 || status == 4)
        {
            *result =0;
            for(int i=0 ; i<8;i+=2)
            {
                int shape[8] = {temp,temp+1,temp-2,temp-1,temp,temp+1,temp-2,temp-1};
                playground[h][shape[i] + x] = '[';
                playground[h][shape[i+1] + x] = ']';
                if(i==0) temp =shape[i];
                if(i==4 || i==6)
                {
                    if(playground[h+1][shape[i]+x] != ' '  || playground[h+1][shape[i+1]+x] != ' ') *result = 1;
                }
                if(i==0 || i==4) h++;

            }
        }
    }
    else if(randnum==3)
    {
        int temp =6;
        if(status == 1 || status ==3)
        {
            *result = 0;
            int shape[8] = {temp,temp+1,temp+2,temp+3,temp+4,temp+5,temp+6,temp+7};
            for(int i=0 ; i<8;i+=2)
            {

                playground[h][shape[i] + x] = '[';
                if(i== 0) temp = shape[i];
                playground[h][shape[i+1] + x] = ']';
                if(playground[h+1][shape[i] + x] != ' ' || playground[h+1][shape[i+1]+x] != ' ') *result = 1;
            }
        }
        else if(status ==2|| status == 4)
        {
            int shape[8] = {temp,temp +1,temp,temp +1,temp,temp +1,temp,temp +1};
            for(int i=0 ; i<8;i+=2)
            {
                *result = 0;
                playground[h][shape[i] + x] = '[';
                if(i == 0) temp = shape[i];
                playground[h][shape[i+1] + x] = ']';
                if(i == 6)
                {
                    if(playground[h+1][shape[i] + x] != ' ' || playground[h+1][shape[i+1] +x] != ' ')
                    {
                        *result = 1;
                    }
                }
                h++;                                         
            }
        }
    }
}