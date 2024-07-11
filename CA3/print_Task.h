void print_Task(char path[40] ,Task *head)
{

    char buffer[200];                               // a buffer for fgets (read each line from csv file)
    FILE *fptr = fopen(path,"r");                   // open file for reading all task and save them as a link list
    if(fptr == NULL)
    {
        system("cls");
        printf("Error ! could not read the file");
        exit(-1);
    }
    fgets(buffer,sizeof(buffer),fptr);
    Task *current;
    current = head;
    int i = 1;
    while(fgets(buffer,sizeof(buffer),fptr))                         // create a link list and print all of them 
    {
        current->next = (Task *) malloc(sizeof(Task));
        current->next->Task = (char *) malloc(sizeof(strtok(buffer,",")));
        strcpy(current->next->Task,strtok(buffer,","));
        strcpy(current->next->priority,strtok(NULL,","));
        int year = atoi(strtok(NULL,","));
        int month = atoi(strtok(NULL,","));
        int day = atoi(strtok(NULL,","));
        current->next->year = year;
        current->next->month = month;
        current->next->day = day;

        printf("%d. Task: %s , Priority: %s , Deadline : %d/%d/%d\n",i,current->next->Task,current->next->priority,current->next->year,current->next->month,current->next->day);
        current->next->next = NULL;
        current = current->next;
        i++;
    }
    fclose(fptr);
}