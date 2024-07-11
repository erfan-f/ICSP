#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>



int random1()
{
    srand(time(0)+ 2) ;                               //for generate random number
    return rand() % 4;
}

