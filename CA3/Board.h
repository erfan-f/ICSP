void Board(char *Board_Name,char *USER_name,int year_now,int month_now,int day_now);
#include "List_menu.h"
#include "Delete_List.h"

void Board(char *Board_Name,char *USER_name,int year_now,int month_now,int day_now)
{
    system("cls");
    printf("-----------------------------------------\n");
    printf("Board: %s \n",Board_Name);
    printf("1. View lists\n");
    printf("2. Create a New list\n");
    printf("3. Delete List\n");
    printf("4. Go Back\n");
    printf("-----------------------------------------\n");

    char tempchar = getch();
    fflush(stdin);

    if(tempchar == '1')
    {
        system("cls");
        char path[50];
        char buffer[20];
        strcpy(path,USER_name);
        strcat(path,"\\");
        strcat(path,Board_Name);
        strcat(path,"\\List_Name.csv");
        FILE *fptr = fopen(path,"r");
        if(fptr == NULL) 
        {   
            system("cls");
            printf("Error in reading file !");
            exit(-1);
        }
        fgets(buffer,sizeof(buffer),fptr);
        int i=1;
        printf("-----------------------------------------");

        while(fgets(buffer,sizeof(buffer),fptr))
        {
            printf("\n%d. %s",i,strtok(buffer,","));                                // print all list name to view
            i++;
        }
        printf("\n-----------------------------------------\n");
        fclose(fptr); 
        if(i == 1) 
        {
            system("cls");
            printf("Your  List is empty ! You have to create one first.\n");        // in case not any list created by the user
            sleep(2);
            Board(Board_Name,USER_name,year_now,month_now,day_now);
        }
        int temp;
        scanf("%d",&temp);
        char buffer2[15];
        FILE *fptr2 = fopen(path,"r");
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
                fgets(buffer2,sizeof(buffer2),fptr2);                                              // open list name for get list name and sent to the List_menu function
            }
            if(buffer2[strlen(buffer2) - 1] == 10) buffer2[strlen(buffer2) - 1]  = 0;
            List_menu(Board_Name,strtok(buffer2,","),USER_name,year_now,month_now,day_now);
        }
        else 
        {
            printf("invalid input !\n");
            getch();
            Board(Board_Name,USER_name,year_now,month_now,day_now);
        }
        fclose(fptr2);
    }
    else if(tempchar == '2')
    {
        system("cls");
        char path[40];
        printf("Enter List Name: ");
        char *listname = (char * ) malloc(sizeof(char));
        get_input(listname);                                           //get name of the new list
        strcpy(path,USER_name);
        strcat(path,"\\");
        strcat(path,Board_Name);
        strcat(path,"\\List_Name.csv");
        FILE *fptr = fopen(path,"a+");
        if(fptr == NULL)
        {
            system("cls");
            printf("error in reading FILE !");
            exit(-1);
        }
        fprintf(fptr,"\n%s,.",listname);
        fclose(fptr);
        char path2[40];
        strcpy(path2,USER_name);
        strcat(path2,"\\");
        strcat(path2,Board_Name);
        strcat(path2,"\\");
        strcat(path2,listname);
        strcat(path2,".csv");
        FILE *fptr2 = fopen(path2,"w");                   // open list_name file for write in to it name of the new list
        if(fptr == NULL)
        {
            system("cls");
            printf("Error in creating The  FILE !");
            exit(-1);
        }
        fclose(fptr2);
        printf("List created successfully !\n");
        getch();
        fflush(stdin);
        Board(Board_Name,USER_name,year_now,month_now,day_now);
    }
    else if(tempchar == '3')
    {
        system("cls");
        char path[50];
        char buffer[20];
        strcpy(path,USER_name);
        strcat(path,"\\");
        strcat(path,Board_Name);
        strcat(path,"\\List_Name.csv");
        FILE *fptr = fopen(path,"r");                           //open listname file for read name of all created list 
        if(fptr == NULL) 
        {   
            system("cls");
            printf("Error in reading file !");
            exit(-1);
        }
        fgets(buffer,sizeof(buffer),fptr);
        int i=1;

        while(fgets(buffer,sizeof(buffer),fptr))
        {
            printf("%d. %s\n",i,strtok(buffer,","));
            i++;
        }
        fclose(fptr);

        if(i == 1) 
        {
            system("cls");
            printf("Your  List is empty !\n");
            sleep(2);
            Board(Board_Name,USER_name,year_now,month_now,day_now);
        }

        int Listnum;
        printf("\nWich List Do tou want to Delete ? ");                    //select wich list should be deleted
        scanf("%d",&Listnum);

        if(( Listnum < 1) || (Listnum > i-1))
        {
            printf("invalid input !");
            sleep(2);
            system("cls");
            Board(Board_Name,USER_name,year_now,month_now,day_now);
        }
        Delete_List(Listnum,Board_Name,USER_name);
        Board(Board_Name,USER_name,year_now,month_now,day_now);

    }
    else if(tempchar == '4')         
    {
        system("cls");
        board_menu(USER_name,year_now,month_now,day_now);           
    }
    else 
    {
        printf("invalid input !");
        sleep(2);
        system("cls");
        Board(Board_Name,USER_name,year_now,month_now,day_now);
    }
}