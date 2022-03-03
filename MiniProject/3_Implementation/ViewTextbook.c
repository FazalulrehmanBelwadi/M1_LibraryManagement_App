/**
 * @file ViewTextbook.c
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
 * @return check_variable 
 */
check_variable Textbook_view()
{

    FILE *fp=NULL;
    fp=fopen("bookLibrary.dat","rb");

    if(fp==NULL)
    {
        printf("\nERROR:\n");
        return fail;
    }
    else{
        book *book_to_find=(book*)malloc(sizeof(book));
    while(fread(book_to_find,sizeof(book),1,fp)==1)
    {
        printf("\n%d\t\t\t%s\t\t\t%s",book_to_find->Textbook_id,book_to_find->Textbook_name,book_to_find->Author_name);
    }
    fclose(fp);
    free(book_to_find);

    return pass;
    }
}
