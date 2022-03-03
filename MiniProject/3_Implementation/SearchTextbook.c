/**
 * @file SearchTextbook.c
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
check_variable Textbook_search(int id)
{

    FILE *fp=NULL;
    fp = fopen("bookLibrary.dat","rb");
    if(fp==NULL)
    {
        printf("\nError while opening file in search area\n");
        return fail;
    }
    else
    {

        book *book_to_find=(book*)malloc(sizeof(book));
        while(fread(book_to_find,sizeof(book),1,fp))
    {
        if(book_to_find->Textbook_id==id)
        {

            printf("\nTextbook Id: %d\t\tTextbook Name: %s\t\tAuthor Name: %s",book_to_find->Textbook_id,book_to_find->Textbook_name,book_to_find->Author_name);
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