/**
 * @file Main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "library_management_system.h"
#include"AddTextbook.c"
#include"DeleteTextbook.c"
#include"IssueTextbook.c"
#include"ViewTextbook.c"
#include"SearchTextbook.c"

/**
 * @brief 
 * 
 * @return int 
 */

int main()
{

    int id,choice,success;

    char title[20],Author_Name[20];


    printf("\n\t\t\t--------------- WELCOME TO LIBRARY MANAGEMENT SYSTEM-----------------\n");
    printf("\n\t\t\t-------------------------- MAIN MENU --------------------------------\n");
    printf("\n\t\t\t1. Add TextBooks");
    printf("\n\t\t\t2. Delete Textbooks");
    printf("\n\t\t\t3. View TextBooks");
    printf("\n\t\t\t4. Search Textbook");
    printf("\n\t\t\t5. Issue Textbooks");
    printf("\n\t\t\t6. Close Management System");
    printf("\n\t\t\t-----------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\nTextbook ID: ");
        scanf("%d",&id);
        fflush(stdin);
        printf("\nTextbook Name:");

	scanf("%19s",title);
       printf("Author Name: ");
        fflush(stdin);
        //gets(author);
	scanf("%19s",Author_Name);
        success=Textbook_Addon(id,title,Author_Name);
        break;
        case 2:
        printf("\nTextbook ID: ");
        scanf("%d\n",&id);
        success=Textbook_Delete(id);
        break;
        case 3:
        success=Textbook_view();
        break;
        case 4:
        printf("\nTextbook ID:");
        scanf("%d\n",&id);
        success=Textbook_search(id);
        break;
        case 5:
        printf("\nTextbook ID: ");
        scanf("%d\n",&id);
        success=Textbook_Issue(id);
        break;
        case 6:
        printf("\n\n\n");
        exit(1);
        default:
        printf("\n\t\t\t\t\t\t Invalid Input Entered");
        break;
     }
    if(success == pass)
    {
        printf("\nSuccessful\n");
    }
    else if(success==fail)
    {
        printf("\nUnsuccessful\n");
    }
    else{
        printf("\nError\n");
    }
return 0;
}

