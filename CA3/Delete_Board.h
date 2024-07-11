
void Delete_Board(int Boardnum,char *USER_name)
{
    char path[40] , board_path[40];
    char buffer[50];

    strcpy(path,USER_name);
    strcat(path,"\\Board_List.csv");
    FILE *fptr = fopen(path,"r");
    if(fptr == NULL)
    {
        system("cls");
        printf("Error Could not read the File ! ");
        exit(-1);
    }
    
    board_NAME *dummy = (board_NAME *) malloc(sizeof(board_NAME));
    board_NAME *current;
    current = dummy;
    fgets(buffer,sizeof(buffer),fptr);

    while(fgets(buffer,sizeof(buffer),fptr))
    {
        current->next = (board_NAME *) malloc(sizeof(board_NAME));
        current->next->B_NAME = (char *) malloc ( 200 * sizeof(char));
        strcpy(current->next->B_NAME,strtok(buffer,","));
        current->next->next = NULL;
        current = current->next;
    }
    fclose(fptr);


    FILE *fptr2 = fopen(path,"w");
    if(fptr2 == NULL)
    {
        system("cls");
        printf("Error Could not read the File ! ");
        exit(-1);
    }
    fprintf(fptr2,"Board Name");
    fclose(fptr2);
    

    board_NAME *current2 , *previous;
    current2 = dummy;

    for(int i=0;i<Boardnum;i++)
    {
        previous = current2;
        current2 = current2->next ;
    }

    previous->next = current2->next ;

    FILE *fptr3 = fopen(path,"a+");
    board_NAME *current3;
    if(fptr3 == NULL)
    {
        system("cls");
        printf("Error Could not read the File ! ");
        exit(-1);
    }

    current3 = dummy;
    while(current3->next != NULL)
    {
        current3 = current3->next;
        fprintf(fptr3,"\n%s,.",current3->B_NAME);
    }
    fclose(fptr3);

    char path2[40] , path3[40], path4[40];
    strcpy(path2,USER_name);
    strcat(path2,"\\");
    strcat(path2,current2->B_NAME);
    strcpy(board_path,path2);
    strcat(path2,"\\");
    strcpy(path3,path2);
    strcat(path2,"List_Name.csv");
    
    char buffer2[50];
    FILE *fptr4 = fopen(path2,"r");
    if(fptr4 == NULL)
    {
        system("cls");
        printf("Error Could not read the File ! ");
        exit(-1);
    }
    fgets(buffer2,sizeof(buffer2),fptr4);
    while(fgets(buffer2,sizeof(buffer2),fptr4))
    {
        strcpy(path4,path3);
        strcat(path4,strtok(buffer2,","));
        strcat(path4,".csv");
        remove(path4);
    }
    fclose(fptr4);
    remove(path2);
    _rmdir(board_path);

    char buffer3[200];
    FILE *fptr5 = fopen("Reminder.csv","r");
    if(fptr5 == NULL)
    {
        system("cls");
        printf("Error ! could not read the file");
        exit(-1);
    }
    fgets(buffer3,sizeof(buffer3),fptr5);
    Task2 *dummy2 = (Task2 *) malloc(sizeof(Task2));
    Task2 *current4;
    current4 = dummy2;

    while(fgets(buffer3,sizeof(buffer3),fptr5))
    {
        current4->next = (Task2 *) malloc(sizeof(Task2));
        current4->next->USER__NAME = (char *) malloc(100 * sizeof(char));
        current4->next->Task  = (char *)  malloc(100 * sizeof(char));
        strcpy(current4->next->USER__NAME,strtok(buffer3,","));
        strcpy(current4->next->Task,strtok(NULL,","));
        strcpy(current4->next->priority,strtok(NULL,","));
        current4->next->year = atoi(strtok(NULL,","));
        current4->next->month = atoi(strtok(NULL,","));
        current4->next->day =atoi(strtok(NULL,","));

        current4->next->Board_NAME = (char *) malloc(100 * sizeof(char));
        strcpy(current4->next->Board_NAME,strtok(NULL,","));
        current4->next->List_NAME = (char *) malloc(100 * sizeof(char));
        strcpy(current4->next->List_NAME,strtok(NULL,","));
        strtok(NULL,",");
        current4->next->Delete_status = atoi(strtok(NULL,","));
        current4->next->next = NULL;
        current4 = current4->next;
    }
    fclose(fptr5); 

    FILE *fptr6 = fopen("Reminder.csv","w");
    if(fptr6 == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    fprintf(fptr6," ");
    fclose(fptr6);

    FILE *fptr7 = fopen("Reminder.csv","a+");
    if(fptr7 == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    Task2 *current5;
    current5 = dummy2;
    while(current5->next != NULL)
    {   
        current5 = current5->next;
        if(((strcmp(current5->USER__NAME,USER_name) == 0) && (strcmp(current5->Board_NAME,current2->B_NAME) == 0) ) || (current5->Delete_status == 1))
        {
            fprintf(fptr7,"\n%s,%s,%s,%d,%d,%d,%s,%s,.,1",current5->USER__NAME,current5->Task,current5->priority,current5->year,current5->month,current5->day,current5->Board_NAME,current5->List_NAME);
        }
        else
        {
            fprintf(fptr7,"\n%s,%s,%s,%d,%d,%d,%s,%s,.,0",current5->USER__NAME,current5->Task,current5->priority,current5->year,current5->month,current5->day,current5->Board_NAME,current5->List_NAME);
        }
    }
    fclose(fptr7);
    free(dummy);
    free(dummy2);
    printf("\nDeleted successfully !\n");
    sleep(2);
}


