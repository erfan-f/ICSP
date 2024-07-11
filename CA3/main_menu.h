void main_menu();
#include "Sign_in.h"
#include "Sign_Up.h"

void main_menu()
{
    printf("-----------------------------------------\n");
    printf("Welcome  to Programm Management ! \n\n");
    printf("1. Sign in\n");
    printf("2. Sign Up\n");
    printf("-----------------------------------------\n");

    char start = getch();
    fflush(stdin);
    if(start == '1')
    {
        system("cls");
        Sign_in();
    }
    else if(start == '2')
    {
        system("cls");
        Sign_Up();
        system("cls");
        main_menu();
    }
    else
    {
        printf("invalid input !");
        sleep(2);
        system("cls");
        main_menu();
    }
}