
void Add_Task(char path[40],Task *head,char *Board_Name,char *Listname, char *USER_name)
{
        Task *current;
        current = head;                                // current is a temp struct to move through the link list 
        while(current->next != NULL)
        {
            current = current->next;                  // reach the end of the link list (last node for add the new task)
        }
    
        current->next = (Task *)malloc(sizeof(Task));             // allocating memory for new task
        current->next->Task = (char *)malloc(sizeof(char));       // allocating memory for task name
        
        printf("Enter Task Name: ");                              // get the name,priority,deadline for new task  
        get_input(current->next->Task);
        printf("Enter Task Priority (Low / Medium / High): ");
        gets(current->next->priority);
        printf("Enter Task Deadline (YYYY/MM/DD):  ");
        scanf("%d/%d/%d",&(current->next->year),&(current->next->month),&(current->next->day));
        FILE *fptr = fopen(path,"a+");       // open specified lsit file(that sent to the function as char *Listname)  and write new task in it
        if(fptr == NULL)                    
        {
            system("cls");
            printf("Error in Opening File ! ");
            exit(-1);
        }    
        fprintf(fptr,"\n%s,%s,%d,%d,%d",current->next->Task,current->next->priority,current->next->year,current->next->month,current->next->day);
        fclose(fptr); 

        FILE *fptr2 = fopen("Reminder.csv","a+");     // open reminder file for write the new task in it
        if(fptr2 == NULL)
        {
            system("cls");
            printf("Error in Opening File ! ");
            exit(-1);
        }    
        fprintf(fptr2,"\n%s,%s,%s,%d,%d,%d,%s,%s,.,0",USER_name,current->next->Task,current->next->priority,current->next->year,current->next->month,current->next->day,Board_Name,Listname);
        fclose(fptr2);
        printf("\nTask Added successfully !");
        getch();
        fflush(stdin);
}