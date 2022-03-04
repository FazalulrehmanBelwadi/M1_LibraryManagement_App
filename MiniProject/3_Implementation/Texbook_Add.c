/**
 * @file Texbook_Add.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "library_management_system.h"
/**
 * @brief 
 * 
 * @param id 
 * @param title 
 * @param author 
 * @return check_variable 
 */
check_variable Textbook_Addon(int id,char title[],char author[])
{

    FILE *fp=NULL;
    fp=fopen("bookLibrary.dat","ab+");

    if(fp == NULL)
    {
        printf("\nError: while opening file\n");
        return fail;
    }
    else
    {

        book *newBook = NULL;
        newBook = malloc(sizeof(book));

        newBook->Textbook_id = id;
        strcpy(newBook->Textbook_name,title);

         strcpy(newBook->Author_name,author);

        fwrite(newBook,sizeof(book),1,fp);
        fclose(fp);
        free(newBook);
    return pass;
    }

}