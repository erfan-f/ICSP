
void get_input(char *str)
{
    int i=0;
    while(1)
    {
        str[i] = getchar();
        str = (char *)realloc( str ,(i + 2) * sizeof(char));
      
        if(str[i] == '\n') 
        {
            str[i] = '\0';
            break;
        }
          i++;
    }
    fflush(stdin);
}