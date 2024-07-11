#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


#include "welcome.h"                                       //welcome function for menu of the game
#include "checkline.h"                                     // checkline function for checking complete line and plus 10 to score 
#include "shape.h"                                         // shape function for intializing the playground array
#include "clear.h"                                         // for delete previous shape
#include "edge.h"                                         // edge function for displacement limits
#include "gameover.h"                                     // for checking the gameover conditon
#include "print.h"                                        // print function for print playground array and the page
#include "putspace.h"                                     // this function only put space character into all playground array in the first of the programm
#include "random1.h"                                     // this function generate random number 
#include "random2.h"                                     // this function generate random number for nextshape 
 
int main()
{
    int starter;

    starter = Welcome();    

    if(starter == 1)                                
    {
        int score =0;                                           // player score
        int randnum = random2() ,Rotate_status,h,x,n;                  // generate random number for draw the shape 
        int nextshape;                                          // an integer for save the number of next shape
        int speed;                                              // for speed of falling and chalenging the player
        int dead_counter = 0;                                   // for debugging the dead situation on the top of playground
        char playground[20][20];                                // playground array for saving the shape and then could print it
        putspace(playground);

        while(!gameover(playground))                           // while loop for generate the shape until gameover
        {
            speed = 350;                                      // default falling speed
            nextshape = random1();
            int result = 0;                                  // a variable for checking the bottom of the shape in the case of crash
            Rotate_status = 1;                               // fist status of rotation for shape 
            h=0;                                             // first shape height on the playground
            x=0;                                             // size of displacement on the playground
            n=0;                                             // just an integer for  while 
            shape(playground,h,x,randnum,&result,Rotate_status);  
            print(playground,&score,nextshape,speed);              

            while(n<500)       
            {
                int edge1 = 0,edge2 =0;                             //edge variable for displacement limits
                edge(playground,&edge1,&edge2,randnum,Rotate_status,h);
                while(!kbhit())                                            // until a key not press line below will be executed
                {
                    if(gameover(playground)) break;
                    system("cls");                                         // for cleaning the page every time
                    clear(playground,h,x,randnum,Rotate_status);
                    h++;                                                    // for falling shape
                    shape(playground,h,x,randnum,&result,Rotate_status);
                    print(playground,&score,nextshape,speed);
                    if(result == 1)
                    {
                        checkline(playground,&score);
                        break;
                    }
                    Sleep(speed);                                          // sleep for control the speed of falling
                }
                if(gameover(playground)) break;
                if(result == 1) break;
                char ch;
                ch = getch();                                    //get character for move and rotate the shape or boost the speed

                if((ch == 'D' || ch =='d') && edge2==0)
                {
                    system("cls");
                    clear(playground,h,x,randnum,Rotate_status);
                    x++;                                            // for displacement on the x(line) 
                    shape(playground,h,x,randnum,&result,Rotate_status);
                    if(result == 1) break;                              // break condition for check the below of the shape
                    print(playground,&score,nextshape,speed);
                }
                else if((ch == 'A' || ch =='a') && edge1==0)
                {
                    system("cls");
                    clear(playground,h,x,randnum,Rotate_status);
                    x--;                                                 // for displacement on the x(line) 
                    shape(playground,h,x,randnum,&result,Rotate_status);
                    if(result == 1) break;                               // break condition for check the below of the shape
                    print(playground,&score,nextshape,speed);
                }
                else if(ch == ' ')
                {
                    clear(playground,h,x,randnum,Rotate_status);
                    Rotate_status ++;                                    //for rotate the shape
                    if(Rotate_status == 5) Rotate_status =1;

                }
                else if(ch == 's' || ch == 'S')
                {
                    speed = speed - 150;                                    // for boost the speed
                    if(speed <50) speed = 350;

                }
                else if(ch != 's' && ch != 'S' && ch != ' ' && ch != 'd' && ch != 'D' && ch != 'a' && ch != 'A')
                {
                    printf("         invalid input !");                              //print invalid input if the user press wrong key
                    Sleep(2000);                    
                }
            }
         dead_counter++;
         if(dead_counter >70) break;                      // dead condition
         randnum = nextshape;                            // pass the value of next shape to current shape
        }
        system("cls");
        printf("You lost :(((");                         // print lost message
        getchar();
        return 0;
    }
    else if(starter == 2) return 0;

}










