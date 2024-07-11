void Sort_Time(Task *head,char path[40])
{
    Task *current;
    current = head;

    int nT = 0;
    while(current->next != NULL)
    {
        current = current->next;
        nT++;
    }
    char * TempTask;
    char TempPriority[7];
    int TempYear , TempMonth , TempDay;


    Task *current2;
    int flag;
    for(int i=0;i<nT;i++)
    {
        current2 = head;
        while((current2->next != NULL) && (current2->next->next != NULL))
        {
            current2 = current2->next;
            flag = 0;
            if(current2->year > current2->next->year) flag =1;
            else if(current2->month > current2->next->month) flag =1;
            else if(current2->day > current2->next->day) flag=1;

            if(flag == 1)
            {
                TempTask = (char *) malloc(sizeof(current2->Task));
                strcpy(TempTask,current2->Task);
                strcpy(TempPriority,current2->priority);
                TempYear = current2->year;
                TempMonth = current2->month;
                TempDay = current2->day;
                strcpy(current2->Task,current2->next->Task);
                strcpy(current2->priority,current2->next->priority);
                current2->year = current2->next->year;
                current2->month = current2->next->month;
                current2->day = current2->next->day;
                strcpy(current2->next->Task,TempTask);
                strcpy(current2->next->priority,TempPriority);
                current2->next->year = TempYear;
                current2->next->month = TempMonth;
                current2->next->day = TempDay;
            }
        }
    }
    FILE *fptr = fopen(path,"w");

    if(fptr == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    fprintf(fptr," ");
    fclose(fptr); 
    Task *current3;
    current3 = head;
    FILE *fptr2 = fopen(path,"a+");
    if(fptr2 == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    while(current3->next != NULL)
    {   
        current3 = current3->next;
        fprintf(fptr2,"\n%s,%s,%d,%d,%d",current3->Task,current3->priority,current3->year,current3->month,current3->day);
        free(current3->Task);
    }
    fclose(fptr2);
    printf("\nSorted successfully ! ");
    getch();
    fflush(stdin);
}


