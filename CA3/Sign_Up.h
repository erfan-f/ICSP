


void Sign_Up()
{
    char *username = (char *) malloc(sizeof(char));                  //getting username and password from User
    char *password = (char *) malloc(sizeof(char));
    printf("Please enter your username: ");
    get_input(username);
    printf("Please enter your password: ");
    get_input(password);

    char buffer[100];                                                  
    FILE *fptr = fopen("MyFile.csv","r");                          // open My_File for checking the username is not used before by another user 
    if(fptr == NULL) 
    {
        system("cls");
        printf("Error ! could not open the file !");
        exit(-1);
    }
    fgets(buffer,sizeof(buffer),fptr);
    while(fgets(buffer,sizeof(buffer),fptr));
    {
        if(strcmp(strtok(buffer,","),username) == 0)                 // checking process
        {
            printf("\nThis username is used by Another User !\n");
            printf("Press any key to back to main menu.\n");
            getch();
            fflush(stdin);
            system("cls");
            main_menu();                              
        }
    }
    fclose(fptr);

    FILE *fptr2 = fopen("MyFile.csv","a+");                     // open My_File for write username and password in it

    if(fptr2 == NULL) 
    {
        system("cls");
        printf("Error ! could not open the file !");
        exit(-1);
    }

    char path[40];                                              // a string for save the path of File 
    fprintf(fptr2,"\n%s,%s,.",username,password);
    fclose(fptr2);
    _mkdir(username);                                           // create a folder for user 
    strcpy(path,username);
    strcat(path,"\\");
    strcat(path,"Board_List.csv");                              // create a board list in the folder for write created board name from user in future

    FILE *fptr3 = fopen(path,"w");
    if(fptr3 == NULL) 
    {
        system("cls");
        printf("Error ! could not open the file !");
        exit(-1);
    }
    fprintf(fptr3,"Board Name");
    fclose(fptr3);
    free(username);
    free(password);
    printf("You sign up successfully !");
    printf("\nfor back to main menu press any key.");
    getch();
}
