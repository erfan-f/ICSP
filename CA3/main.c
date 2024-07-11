/* This programm work with two constant File (MyFile.csv and Reminder.csv) and create  a folder for each USER.
   inside the folder is a Board_List.csv that contain all board name user created.every board have a folder.
   inside this folder is List_Name file that contain all List name user created.every list have csv file.   */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <direct.h>
#include <windows.h>
#include <unistd.h>

typedef struct task                                               // Structure for task
{
    
    char *Task;
    char priority[7];
    int year ;
    int month;
    int day ;
    struct task *next;
}Task; 

typedef struct task2                                              // Structure for task (For reminder) 
{
    
    char *Task;
    char *USER__NAME;
    char priority[7];
    char *Board_NAME;
    char *List_NAME;
    int year ;
    int month;
    int day ;
    int Delete_status;
    struct task2 *next;
}Task2; 

typedef struct board_name                                        //structure  for delete board
{
    char *B_NAME;
    struct board_name *next;
}board_NAME;

typedef struct list_name                                        //structure  for delete list
{
    char *L_NAME;
    struct list_name *next;
}list_NAME;







#include "main_menu.h"


/*
void get_input(char *str);                                              // function for get input (with malloc  and realloc)
void main_menu();                                                       // main_menu function (include sign in and sign Up functions)
void Sign_Up();                                                         // sign up function (include main_menu,compare_str and get input functions)
void Sign_in();                                                         // sign in function (include board_menu , main_menu and get input functions)
void board_menu(char *USER_name);                                       // board menu function (include reminder,Board,Delete_board and get input functions) 
void Board(char *Board_name,char *USER_name);                           // Board for list function (incldue List_menu,get input,Delete_list and bord_menu functions)
void List_menu(char *Board_Name ,char *Listname,char *USER_name);       // list menu function (include Add_task,print_Task,Edit_Task,Delete_Task,Move_Task,Sort_priority,Sort_priority and Board functions)
void Add_Task(char path[40],Task *head,char *Board_Name,char *Listname, char *USER_name);                                   // this function use for add task to a lsit (include get input function)
int  compare_str(char *a,char *b,int length,int lenght2);                                                                  // this function use for compare string in some part of the programm in case of problem in strcmp function(strcmp use in other part of programm)
void print_Task(char path[40] ,Task *head);                                                                                // this function print task in top of the List menu 
void Edit_Task(Task *head,int Tasknum,char path[40],char *Board_Name,char *Listname , char *USER_name);                    //function for edit Task
void Delete_Task(Task *head,int Tasknum,char path[40],char *Board_Name,char *Listname,char *USER_name);                     //  function for Delete Task
void Move_Task(Task *head,int Tasknum,int Listnum,char path[40],char *Board_Name ,char *Listname,char *USER_name);         //function for move a Task
void Sort_Time(Task *head,char path[40]);                                                                                // This function sort the Task by time 
void Sort_Priority(Task *head,char path[40]);                        // This function sort the Task by priority (1.high  2.medium  3.low)
void Reminder(int y,int m,int d,char *USER_name);                    // This function reminde  deadline for user (3 days further) 
void Delete_Board(int Boardnum,char *USER_name);                     // function for Delete each Board 
void Delete_List(int Listnum, char *Board_Name,char *USER_name);     //function for Delete each List  
*/


int main()
{  
   main_menu();

   return 0;
}

