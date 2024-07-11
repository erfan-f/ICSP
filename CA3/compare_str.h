

int compare_str(char *a,char *b,int length,int length2)
{
    int x=0;
    if(length != length2) return 0; 
    for(int i=0;i<length;i++)                                                  
    {

        if( *(a + i) == *(b + i) ) x++;
    }
    if(x == length) return 1;
    else return 0;
}
