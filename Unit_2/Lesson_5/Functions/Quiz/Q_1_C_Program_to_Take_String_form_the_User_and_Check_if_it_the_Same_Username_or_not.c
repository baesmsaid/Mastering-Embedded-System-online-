/*
 *    C_Program_to_Take_String_form_the_User_and_Check_if_it_the_Same_Username_or_not.c
 *
 *  Created on: june 16, 2023
 *      Author: Basem Said
 *
 *   Description: A c program to take string from the user and compare it with the user-name which inputed by the user to give him a check that the use is correct.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char UserEntry[20];
    char USERNAME[20]="Bassem";
    int compare;
    
    printf("Enter User Name : \n");
    scanf("%s",UserEntry);
    
    compare = strcmp(UserEntry,USERNAME);
    
    if(compare==0)
    printf("Identical");
    else
    printf("Not Identical");
    
    return 0;
}