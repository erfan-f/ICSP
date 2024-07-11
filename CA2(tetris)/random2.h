int random2()
{
    srand(time(0)+1);                     //for generate random number
    return rand() % 4;
}
