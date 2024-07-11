#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <direct.h>
#include <windows.h>


void Reminder(int y,int m,int d,char *USER_name)
{
    char buffer[200];
    char *board_name = (char *) malloc ( 200 * sizeof(char));;
    int year,month,day,Delete_chek;
    FILE *fptr = fopen("Reminder.csv","r");
    if(fptr == NULL)
    {
        system("cls");
        printf("Error ! could not read the file");
        exit(-1);
    }
    fgets(buffer,sizeof(buffer),fptr);

    Task *dummy = (Task *) malloc(sizeof(Task));
    Task *current;
    current = dummy;

    char *temp_username = (char *) malloc(200 * sizeof(char));

    int flag;
    int i = 1;
    while(fgets(buffer,sizeof(buffer),fptr))
    {
        strcpy(temp_username,strtok(buffer,","));
        flag =0;
        current->next = (Task *) malloc(sizeof(Task));
        current->next->Task = (char *) malloc(200 * sizeof(char));
        strcpy(current->next->Task,strtok(NULL,","));
        strcpy(current->next->priority,strtok(NULL,","));
        year = atoi(strtok(NULL,","));
        month = atoi(strtok(NULL,","));
        day = atoi(strtok(NULL,","));
        current->next->year = year;
        current->next->month = month;
        current->next->day = day;
        strcpy(board_name,strtok(NULL,","));
        strtok(NULL,",");
        strtok(NULL,",");
        Delete_chek = atoi(strtok(NULL,","));


        if(y == year)
        {
            if(m == month)
            {
                if((day - d >= 0) && (day -d <=3)) flag = 1;
            }
        }
        if(flag == 1 && Delete_chek != 1 && (strcmp(temp_username,USER_name) == 0))
        {
            printf("\n%d. Task: %s , Priority: %s , Deadline : %d/%d/%d , Board : %s",i,current->next->Task,current->next->priority,current->next->year,current->next->month,current->next->day,board_name);
            i++;
            //free(current->next->Task);
        }
        current->next->next = NULL;
        current = current->next;
    }
    free(dummy);
    free(temp_username);
    fclose(fptr);
}
