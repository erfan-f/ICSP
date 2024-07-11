
#include "get_input.h"
#include "board_menu.h"
#include "compare_str.h"



void Sign_in()
{
    FILE *fptr = fopen("MyFile.csv","r");                                 // open MYFile for reading information(usernames and passwords)
    char *buffer = (char *) malloc(sizeof(char));
    char *buffer2 = (char *) malloc(sizeof(char));
    char buff[30];
    printf("Enter username: ");                                             // getting username and password from user
    get_input(buffer);
    printf("Enter password: ");
    get_input(buffer2);
    int flag = 1;
    char *data;                                                 // string for strtok
    char *data2 ;                                               // string for strtok
    int length = strlen(buffer);
    int length2 = strlen(buffer2);
    int length3 ;
    int length4 ;

    while(fgets(buff,sizeof(buff),fptr))              // getting username and password line by line for compare with input
    {
        data = strtok(buff,",");
        data2 = strtok(NULL,",");
        length3 = strlen(data2);
        length4 = strlen(data);
       
        if((compare_str(buffer,data,length,length4) == 1) && (compare_str(buffer2,data2,length2 ,length3) == 1)) 
        {
            flag = 0;
        }
    }
    if(flag == 1 )
    {
        printf("incorrect password or username !");
        getch();
        system("cls");
        main_menu();
    }
    else
    {
        int year_now,month_now,day_now;
        system("cls");
        printf("Please Enter the current Date  (YYYY/MM/DD) : ");                    // get date for reminder
        scanf("%d/%d/%d",&year_now,&month_now,&day_now);
        board_menu(buffer,year_now,month_now,day_now);
    }
}