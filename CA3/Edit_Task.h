

void Edit_Task(Task *head,int Tasknum,char path[40],char *Board_Name,char *Listname,char *USER_name)
{

    Task *current;
    current = head;

    for(int i=0;i<Tasknum;i++)                                          // reach the Task that should be edited on link list
    {
        current = current->next;
    }
    
    char *temp_Task = (char *) malloc( sizeof(current->Task));
    strcpy(temp_Task,current->Task);


    printf("Edit Task Name: ");                                          // getting new name,priority and deadline 
    scanf("%s",current->Task);
    printf("Edit Task Priority: ");
    scanf("%7s",current->priority);
    printf("Edit Task Deadline (yyyy/mm/dd): ");
    scanf("%d/%d/%d",&current->year,&current->month,&current->day);

   

    Task *current2;
    current2 = head;

    FILE *fptr = fopen(path,"w");                      //open file to clear it                

    if(fptr == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    fprintf(fptr," ");
    fclose(fptr);    
    FILE *fptr2 = fopen(path,"a+");                              // open file for write new link lsit in it
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

    char buffer[200];                                // open reminder file for edit the task in reminder
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
        current3->next->Task = (char *) malloc(100 * sizeof(char));
        strcpy(current3->next->USER__NAME,strtok(buffer,","));
        strcpy(current3->next->Task,strtok(NULL,","));
        strcpy(current3->next->priority,strtok(NULL,","));
        current3->next->year = atoi(strtok(NULL,","));
        current3->next->month = atoi(strtok(NULL,","));
        current3->next->day =atoi(strtok(NULL,","));
        current3->next->Board_NAME = (char *) malloc(100 * sizeof(char));
        current3->next->List_NAME = (char *) malloc(100 * sizeof(char));
        strcpy(current3->next->Board_NAME,strtok(NULL,","));
        strcpy(current3->next->List_NAME,strtok(NULL,","));
        strtok(NULL,",");
        int x = atoi(strtok(NULL,","));
        if(x == 1) current3->next->Delete_status = 1;  

        if( (strcmp(current3->next->USER__NAME,USER_name) == 0) && (strcmp(current3->next->Task,temp_Task) == 0) && (strcmp(current3->next->Board_NAME,Board_Name) == 0) && (strcmp(current3->next->List_NAME,Listname) == 0))
        {
            strcpy(current3->next->Task,current->Task);
            strcpy(current3->next->priority,current->priority);                                        // replacement 
            current3->next->year = current->year;
            current3->next->month = current->month;
            current3->next->day = current->day;            
        }
        current3->next->next = NULL;
        current3 = current3->next;
    }
    fclose(fptr3);

    FILE *fptr4 = fopen("Reminder.csv","w");                 // clear the reminder file
    if(fptr4 == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    fprintf(fptr4," ");
    fclose(fptr4);

    FILE *fptr5 = fopen("Reminder.csv","a+");          // open reminder for write new link list in it
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
        if(current4->Delete_status == 1)
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
    printf("Task Edited successfully ! ");
    getch();
    fflush(stdin);
}



