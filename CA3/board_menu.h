
void board_menu(char *USER_name,int year_now,int month_now,int day_now);
#include "Board.h"
#include "Reminder.h"
#include "Delete_Board.h"



void board_menu(char *USER_name,int year_now,int month_now,int day_now)
{
    
    system("cls");
    printf("Reminder:");
    Reminder(year_now,month_now,day_now,USER_name);                     // print all Task that need to me remind
    printf("\n\n");
    printf("-----------------------------------------\n");
    printf("1. View Boards\n");
    printf("2. Create a new Board\n");
    printf("3. Delete Board\n");
    printf("-----------------------------------------\n");
    char tempchar = getch();
    fflush(stdin);
    if(tempchar == '1')
    {   
        system("cls");
        char path[40];                                    // a string for save the path of File 
        char buffer[20];
        strcpy(path,USER_name);
        strcat(path,"\\Board_List.csv");
        FILE *fptr = fopen(path,"r");
        if(fptr == NULL) 
        {   
            system("cls");
            printf("Error in reading file !");
            exit(-1);
        }
        fgets(buffer,sizeof(buffer),fptr);
        int i=1;
        printf("-----------------------------------------");                  /// print All Board name
        while(fgets(buffer,sizeof(buffer),fptr))
        {
            printf("\n%d. %s",i,strtok(buffer,","));
            i++;
        }
        printf("\n-----------------------------------------\n");
        fclose(fptr); 
        if(i == 1)                                                     // in case of user not created any board
        {
            system("cls");
            printf("Your Board List is empty ! You have to create one first.\n");
            sleep(2);
            board_menu(USER_name,year_now,month_now,day_now);
        }
        int temp;
        scanf("%d",&temp);
        char buffer2[30];
        FILE *fptr2 = fopen(path,"r");                                  // open Board list for get board name and sent to the Board function
        if(fptr2 == NULL) 
        {   
            system("cls");
            printf("Error in reading file !");
            exit(-1);
        }
        fgets(buffer2,sizeof(buffer2),fptr2);
        if((temp <= i - 1) && (temp > 0))
        {
            for(int i=0; i<temp;i++) 
            {
                fgets(buffer2,sizeof(buffer2),fptr2);
            }
            if(buffer2[strlen(buffer2) - 1] == 10) buffer2[strlen(buffer2) - 1]  = 0;
            Board(strtok(buffer2,","),USER_name,year_now,month_now,day_now);
        }
        else 
        {
            printf("invalid input !\n");
            sleep(2);
            board_menu(USER_name,year_now,month_now,day_now);
        }
        fclose(fptr2);

    }
    else if(tempchar == '2')
    {
        system("cls");
        char *Board_name = (char *) malloc(sizeof(char));
        printf("Enter Board Name : ");
        get_input(Board_name);
        char buffer[30];
        char buffer2[30];
        strcpy(buffer,USER_name);
        strcat(buffer,"\\");
        strcat(buffer,Board_name);
        _mkdir(buffer);
        strcat(buffer,"\\List_Name.csv");
        FILE *fptr = fopen(buffer,"w");                                              // open board list file for wirte the name of the board in it
        if(fptr == NULL)
        {
            system("cls");
            printf("Error ! could not create the file.");
            exit(-1);
        }
        fprintf(fptr,"List Name");
        fclose(fptr);
        strcpy(buffer2,USER_name);
        strcat(buffer2,"\\Board_List.csv");
        FILE *fptr2 = fopen(buffer2,"a+");
        if(fptr2 == NULL)
        {
            system("cls");
            printf("Error ! could not write in the file.");
            exit(-1);
        }
        fprintf(fptr2,"\n%s,.",Board_name);
        fclose(fptr2);
        free(Board_name);
        printf("Board Created successfully");
        getch();
        board_menu(USER_name,year_now,month_now,day_now);
    }
    else if(tempchar == '3')
    {
        system("cls");
        char path[30];
        char buffer[20];
        strcpy(path,USER_name);
        strcat(path,"\\Board_List.csv");
        FILE *fptr = fopen(path,"r");
        if(fptr == NULL) 
        {   
            system("cls");
            printf("Error in reading file !");
            exit(-1);
        }
        fgets(buffer,sizeof(buffer),fptr);
        int i=1;
        printf("-----------------------------------------\n");

        while(fgets(buffer,sizeof(buffer),fptr))
        {
            printf("%d. %s\n",i,strtok(buffer,","));
            i++;
        }
        printf("\n-----------------------------------------\n");
        if(i == 1) 
        {
            system("cls");
            printf("Your Board List is empty !\n");
            sleep(2);
            board_menu(USER_name,year_now,month_now,day_now);
        }

        printf("Wich Board do you want to Delete ? ");
        int Boardnum;
        scanf("%d",&Boardnum);                                                    // select wich board should be deleted

        if(( Boardnum < 1) || (Boardnum > i-1))
        {
            printf("invalid input !");
            sleep(2);
            system("cls");
            board_menu(USER_name,year_now,month_now,day_now);
        }

        fclose(fptr); 
        Delete_Board(Boardnum,USER_name);
        board_menu(USER_name,year_now,month_now,day_now);
    }
    else
    {
        printf("invalid input !");
        sleep(2);
        system("cls");
        board_menu(USER_name,year_now,month_now,day_now);
    }
}