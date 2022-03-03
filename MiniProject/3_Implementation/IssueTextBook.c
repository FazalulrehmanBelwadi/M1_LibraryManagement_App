/**
 * @file IssueTextBook.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "library_management_system.h"
/**
 * @brief 
 * 
 * @param id 
 * @return check_variable 
 */

check_variable Textbook_Issue(int id)
{
    char title1[20];
    FILE *fp=NULL;
    fp = fopen("bookLibrary.dat","rb");
    if(fp==NULL)
    {
        printf("\nError while opening file in issuing book\\n");
        return fail;
    }
    else
    {    
        scanf("%19s student name",title1);
        book *book_to_find=(book*)malloc(sizeof(book));
        while(fread(book_to_find,sizeof(book),1,fp))
    {
        if(book_to_find->Textbook_id==id)
        {

            printf("\nTextbook id: %d\t\tTextbook Name: %s\t\tAuthor Name: %s",book_to_find->Textbook_id,book_to_find->Textbook_name,book_to_find->Author_name);
            printf("\n Book is issued to %s \n",title1);
            fclose(fp);
            free(book_to_find);
            return pass;
        }
    }

    fclose(fp);
    free(book_to_find);
    printf("\nSpecified book is not present\n");

    return fail;
    }
}