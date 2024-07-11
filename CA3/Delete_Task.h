

void Delete_Task(Task *head,int Tasknum,char path[40],char *Board_Name,char *Listname, char *USER_name)
{
    Task *current, *previous;
    current = head;

    for(int i=0;i<Tasknum;i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;

    Task *current2;
    current2 = head;

    FILE *fptr = fopen(path,"w");

    if(fptr == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    fprintf(fptr," ");
    fclose(fptr);    
    FILE *fptr2 = fopen(path,"a+");
    if(fptr2 == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    while(current2->next != NULL)
    {   
        current2 = current2->next;
        fprintf(fptr2,"\n%s,%s,%d,%d,%d",current2->Task,current2->priority,current2->year,current2->month,current2->day);
    }
    fclose(fptr2);

    char buffer[200];
    FILE *fptr3 = fopen("Reminder.csv","r");
    if(fptr3 == NULL)
    {
        system("cls");
        printf("Error ! could not read the file");
        exit(-1);
    }
    fgets(buffer,sizeof(buffer),fptr3);
    Task2 *dummy = (Task2 *) malloc(sizeof(Task2));
    Task2 *current3;
    current3 = dummy;

    while(fgets(buffer,sizeof(buffer),fptr3))
    {
        current3->next = (Task2 *) malloc(sizeof(Task2));
        current3->next->USER__NAME = (char *) malloc(100 * sizeof(char));
        current3->next->Task  = (char *)  malloc(100 * sizeof(char));
        strcpy(current3->next->USER__NAME,strtok(buffer,","));
        strcpy(current3->next->Task,strtok(NULL,","));
        strcpy(current3->next->priority,strtok(NULL,","));
        current3->next->year = atoi(strtok(NULL,","));
        current3->next->month = atoi(strtok(NULL,","));
        current3->next->day =atoi(strtok(NULL,","));

        current3->next->Board_NAME = (char *) malloc(100 * sizeof(char));
        strcpy(current3->next->Board_NAME,strtok(NULL,","));
        current3->next->List_NAME = (char *) malloc(100 * sizeof(char));
        strcpy(current3->next->List_NAME,strtok(NULL,","));
        strtok(NULL,",");
        current3->next->Delete_status = atoi(strtok(NULL,","));
        current3->next->next = NULL;
        current3 = current3->next;
    }
    fclose(fptr3);

    FILE *fptr4 = fopen("Reminder.csv","w");
    if(fptr4 == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    fprintf(fptr4," ");
    fclose(fptr4);

    FILE *fptr5 = fopen("Reminder.csv","a+");
    if(fptr5 == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    Task2 *current4;
    current4 = dummy;
    while(current4->next != NULL)
    {   
        current4 = current4->next;
        if(((strcmp(current4->USER__NAME,USER_name) == 0) && (strcmp(current4->Task,current->Task) == 0) && (strcmp(current4->Board_NAME,Board_Name) == 0) && (strcmp(current4->List_NAME,Listname) == 0)) || (current4->Delete_status == 1))
        {
            fprintf(fptr5,"\n%s,%s,%s,%d,%d,%d,%s,%s,.,1",current4->USER__NAME,current4->Task,current4->priority,current4->year,current4->month,current4->day,current4->Board_NAME,current4->List_NAME);
        }
        else
        {
            fprintf(fptr5,"\n%s,%s,%s,%d,%d,%d,%s,%s,.,0",current4->USER__NAME,current4->Task,current4->priority,current4->year,current4->month,current4->day,current4->Board_NAME,current4->List_NAME);
        }
    }
    free(dummy);
    fclose(fptr5); 
    printf("Task Deleted successfully ! ");
    getch();
    fflush(stdin); 
}