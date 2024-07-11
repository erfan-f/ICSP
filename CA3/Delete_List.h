
void Delete_List(int Listnum, char *Board_Name,char *USER_name)
{
    char path[40] , path2[40];
    char buffer[50];

    strcpy(path,USER_name);
    strcat(path,"\\");
    strcat(path,Board_Name);
    strcpy(path2,path);
    strcat(path,"\\List_Name.csv");
   

    FILE *fptr = fopen(path,"r");
    if(fptr == NULL)
    {
        system("cls");
        printf("Error Could not read the File ! ");
        exit(-1);
    }
    
    list_NAME *dummy = (list_NAME *) malloc(sizeof(list_NAME));
    list_NAME *current;
    current = dummy;
    fgets(buffer,sizeof(buffer),fptr);

    while(fgets(buffer,sizeof(buffer),fptr))
    {
        current->next = (list_NAME *) malloc(sizeof(list_NAME));
        current->next->L_NAME = (char *) malloc ( 200 * sizeof(char));
        strcpy(current->next->L_NAME,strtok(buffer,","));
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
    fprintf(fptr2,"List Name");
    fclose(fptr2);
    

    list_NAME *current2 , *previous;
    current2 = dummy;

    for(int i=0;i<Listnum;i++)
    {
        previous = current2;
        current2 = current2->next ;
    }

    previous->next = current2->next ;

    FILE *fptr3 = fopen(path,"a+");
    list_NAME *current3;
    if(fptr2 == NULL)
    {
        system("cls");
        printf("Error Could not read the File ! ");
        exit(-1);
    }

    current3 = dummy;
    while(current3->next != NULL)
    {
        current3 = current3->next;
        fprintf(fptr3,"\n%s,.",current3->L_NAME);
    }
    fclose(fptr3);

    strcat(path2,"\\");
    strcat(path2,current2->L_NAME);
    strcat(path2,".csv");
    remove(path2);

    char buffer2[200];
    FILE *fptr4 = fopen("Reminder.csv","r");
    if(fptr4 == NULL)
    {
        system("cls");
        printf("Error ! could not read the file");
        exit(-1);
    }
    fgets(buffer2,sizeof(buffer2),fptr4);
    Task2 *dummy2 = (Task2 *) malloc(sizeof(Task2));
    Task2 *current4;
    current4 = dummy2;

    while(fgets(buffer2,sizeof(buffer2),fptr4))
    {
        current4->next = (Task2 *) malloc(sizeof(Task2));
        current4->next->USER__NAME = (char *) malloc(100 * sizeof(char));
        current4->next->Task  = (char *)  malloc(100 * sizeof(char));
        strcpy(current4->next->USER__NAME,strtok(buffer2,","));
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
    fclose(fptr4); 

    FILE *fptr5 = fopen("Reminder.csv","w");
    if(fptr5 == NULL)
    {
        system("cls");
        printf("Error ! could not edit the file");
        exit(-1);
    }
    fprintf(fptr5," ");
    fclose(fptr5);

    FILE *fptr6 = fopen("Reminder.csv","a+");
    if(fptr6 == NULL)
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
        if(((strcmp(current5->USER__NAME,USER_name) == 0) && (strcmp(current5->List_NAME,current2->L_NAME) == 0) ) || (current5->Delete_status == 1))
        {
            fprintf(fptr6,"\n%s,%s,%s,%d,%d,%d,%s,%s,.,1",current5->USER__NAME,current5->Task,current5->priority,current5->year,current5->month,current5->day,current5->Board_NAME,current5->List_NAME);
        }
        else
        {
            fprintf(fptr6,"\n%s,%s,%s,%d,%d,%d,%s,%s,.,0",current5->USER__NAME,current5->Task,current5->priority,current5->year,current5->month,current5->day,current5->Board_NAME,current5->List_NAME);
        }
    }
    fclose(fptr6);
    free(dummy);
    free(dummy2);
    printf("\nList Deleted successfully !");
    getch();
    fflush(stdin);

}
