#include "Add_Task.h"
#include "print_Task.h"
#include "Edit_Task.h"
#include "Delete_Task.h"
#include "Move_Task.h"
#include "Sort_Time.h"
#include "Sort_Priority.h"

void List_menu(char *Board_Name ,char *Listname,char *USER_name,int year_now,int month_now,int day_now)
{
    system("cls");
    char path[40];                                       //create the address of directory for open the lsit name
    strcpy(path,USER_name);
    strcat(path,"\\");
    strcat(path,Board_Name);
    strcat(path,"\\");
    strcat(path,Listname);
    strcat(path,".csv");

    Task *head = (Task *) malloc(sizeof(Task));                 // allocate the head of the linl list (this link list save the Task for edit,move and delete) 
    print_Task(path,head);

    printf("\nOptions : \n");                                    // print options for user
    printf("1. Add Task\n");
    printf("2. Edit Task\n");
    printf("3. Delete Task\n");
    printf("4. Move Task to Another List\n");
    printf("5. Sort option\n");
    printf("6. Go Back\n");
    char tempchar = getch();
    fflush(stdin);
    if(tempchar == '1')
    {
        system("cls");
        Add_Task(path,head,Board_Name,Listname,USER_name);
        free(head);
        system("cls");
        List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
    }
    else if(tempchar == '2')
    {
        system("cls");    
        char buff[200];                              
        FILE *fptr = fopen(path,"r");
        if(fptr == NULL)
        {
            system("cls");
            printf("Error ! could not read the file");
            exit(-1);
        }
        fgets(buff,sizeof(buff),fptr);
        int i = 0;
        while(fgets(buff,sizeof(buff),fptr))                      
        {
            i++;
        }
        fclose(fptr);
        if(i == 0) 
        {
            system("cls");
            printf("You have not any Task in current List !");
            sleep(3);
            List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
        }    
        print_Task(path,head);                                       // print all task for selection
        printf("\nWich Task Do You Want to Edit ? ");                // select which task should be edited
        int Tasknum;
        scanf("%d",&Tasknum);
        if(( Tasknum< 1) || (Tasknum > i))
        {
            printf("invalid input !");
            sleep(2);
            List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
        } 
        Edit_Task(head,Tasknum,path,Board_Name,Listname,USER_name);
        free(head);
        List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
    }
    else if(tempchar == '3')
    {
        system("cls");
        char buff[200];                              
        FILE *fptr = fopen(path,"r");
        if(fptr == NULL)
        {
            system("cls");
            printf("Error ! could not read the file");
            exit(-1);
        }
        fgets(buff,sizeof(buff),fptr);
        int i = 0;
        while(fgets(buff,sizeof(buff),fptr))                      
        {
            i++;
        }
        fclose(fptr);
        if(i == 0) 
        {
            system("cls");
            printf("You have not any Task in current List !");
            sleep(3);
            List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
        }    
        print_Task(path,head);                                      // print all task for selection
        printf("\nWich Task Do You Want to Delete ? ");             // select which task should be deleted
        int Tasknum;
        scanf("%d",&Tasknum);

        if(( Tasknum< 1) || (Tasknum > i))
        {
            printf("invalid input !");
            sleep(2);
            List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
        }   
        Delete_Task(head,Tasknum,path,Board_Name,Listname,USER_name);
        free(head);
        List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
    }
    else if(tempchar == '4')
    {
    system("cls");    
    char buff[200];                              
    FILE *fptr = fopen(path,"r");
    if(fptr == NULL)
    {
        system("cls");
        printf("Error ! could not read the file");
        exit(-1);
    }
    fgets(buff,sizeof(buff),fptr);
    int i = 0;
    while(fgets(buff,sizeof(buff),fptr))                      
    {
        i++;
    }
    fclose(fptr);
    if(i == 0) 
    {
        system("cls");
        printf("You have not any Task in current List !");
        sleep(3);
        List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
    }
    print_Task(path,head);                                          // print all task for selection
    printf("\nWich Task Do You Want to move ? ");                   // select which task should be deleted
    int Tasknum;
    scanf("%d",&Tasknum);

    if(( Tasknum< 1) || (Tasknum > i))
    {
        printf("invalid input !");
        sleep(2);
        List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
    }
    
    system("cls"); 
    char path2[50];
    char buffer[20];
    strcpy(path2,USER_name);
    strcat(path2,"\\");
    strcat(path2,Board_Name);
    strcat(path2,"\\List_Name.csv");
    FILE *fptr2 = fopen(path2,"r");                                      //open List_namefile for reading all list name
    if(fptr2 == NULL) 
    {   
        system("cls");
        printf("Error in reading file !");
        exit(-1);
    }
    fgets(buffer,sizeof(buffer),fptr2);
    int j=1;

    while(fgets(buffer,sizeof(buffer),fptr2))
    {
        printf("%d. %s\n",j,strtok(buffer,","));
        j++;
    }
    fclose(fptr2); 
    printf("\nWich list to you want select as destination ? ");          // destination selection by the user
    int Listnum;
    scanf("%d",&Listnum);
    if(( Listnum < 1) || (Listnum > j-1))
    {
        printf("invalid input !");
        sleep(2);
        system("cls");
        List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
    }
    Move_Task(head,Tasknum,Listnum,path,Board_Name,Listname,USER_name);
    free(head);
    List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);

    }
    else if(tempchar == '5')
    {
        system("cls");
        printf("1. Sort by Time\n");
        printf("2. Sort by Priority\n");
        char tempchar2 = getch();
        fflush(stdin);
        if(tempchar2 == '1')
        {
            system("cls");
            Sort_Time(head,path);
            free(head);
            List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
        }
        if(tempchar2 == '2')
        {
            system("cls");
            Sort_Priority(head,path);
            free(head);
            List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
        }
        else
        {
            printf("\ninvalid input !");
            sleep(2);
            system("cls");
            List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
        }
    }
    else if(tempchar == '6')
    {
        Board(Board_Name,USER_name,year_now,month_now,day_now);
        free(head);
    }
    else
    {
        printf("invalid input !");
        sleep(2);
        system("cls");
        List_menu(Board_Name,Listname,USER_name,year_now,month_now,day_now);
    }
}