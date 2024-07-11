
// for delete previous shape

// this function is so simular to shape function and the comments are same (exept the result part)

void clear(char playground[20][20],int h,int x,int randnum,int status)
{
    if(randnum==0)
    {
        int temp =9;
        if(status == 1)
        {
            int shape[8] = {temp,temp+1,temp-2,temp-1,temp,temp+1,temp+2,temp+3};
            for(int i=0;i<8;i+=2)
            {

                if(i==0) temp = shape[i];
                if(i==2)
                    h++;
                playground[h][shape[i] + x] = ' ';
                playground[h][shape[i+1] + x] = ' ';
            }
        }
        if(status == 2)
        {
            int shape[8] = {temp,temp+1,temp,temp+1,temp+2,temp+3,temp,temp+1};
            for(int i=0;i<8;i+=2)
            {
                playground[h][shape[i]+x] = ' ';
                playground[h][shape[i+1]+x] = ' ';
                if(i==0) temp = shape[i];
                if(i==0 || i==4) h++;
            }

        }
        else if(status == 3)
        {
            int shape[8] = {temp,temp+1,temp+2,temp+3,temp+4,temp+5,temp+2,temp+3};
            for(int i=0;i<8;i+=2)
            {
                playground[h][shape[i]+x] = ' ';
                playground[h][shape[i+1]+x] = ' ';
                if(i==0) temp = shape[i];
                if(i==4) h++;
            }
        }
        else if(status ==4)
        {
            int shape[8] = {temp,temp+1,temp-2,temp-1,temp,temp+1,temp,temp+1};
            for(int i=0;i<8;i+=2)
            {
                playground[h][shape[i]+x] = ' ';
                playground[h][shape[i+1]+x] = ' ';
                if(i==0) temp = shape[i];
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
            playground[h][shape[i] + x] = ' ';
            playground[h][shape[i+1] + x] = ' ';
        }
    }
    else if(randnum==2)
    {
        int temp = 7;
        if(status == 1 || status == 3)
        {
            for(int i=0 ; i<8;i+=2)
            {
                int shape[8] = {temp,temp+1,temp+2,temp+3,temp+2,temp+3,temp+4,temp+5};
                playground[h][shape[i] + x] = ' ';
                playground[h][shape[i+1] + x] = ' ';
                if(i==2) h++;
                if(i==0) temp =shape[i];
            }
        }
        else if(status == 2 || status == 4)
        {
            for(int i=0 ; i<8;i+=2)
            {
                int shape[8] = {temp,temp+1,temp-2,temp-1,temp,temp+1,temp-2,temp-1};
                playground[h][shape[i] + x] = ' ';
                playground[h][shape[i+1] + x] = ' ';
                if(i==0 || i==4) h++;
                if(i==0) temp =shape[i];
            }
        }
    }
    else if(randnum==3)
    {
        int temp =6;
        if(status == 1 || status ==3)
        {
            int shape[8] = {temp,temp+1,temp+2,temp+3,temp+4,temp+5,temp+6,temp+7};
            for(int i=0 ; i<8;i+=2)
            {
                playground[h][shape[i] + x] = ' ';
                if(i== 0) temp = shape[i];
                playground[h][shape[i+1] + x] = ' ';
            }
        }
        else if(status ==2 || status ==4)
        {
            int shape[8] = {temp,temp +1,temp,temp +1,temp,temp +1,temp,temp +1};
            for(int i=0 ; i<8;i+=2)
            {
                playground[h][shape[i] + x] = ' ';
                if(i == 0) temp = shape[i];
                playground[h][shape[i+1] + x] = ' ';
                h++;
            }
        }
    }
}