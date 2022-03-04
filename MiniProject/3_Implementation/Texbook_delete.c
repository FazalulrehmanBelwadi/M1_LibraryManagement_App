/**
 * @file Texbook_delete.c
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
 * @return check_variable 
 */
check_variable Textbook_Delete(int id)
{



    FILE *fp=NULL;
    FILE *ft=NULL;
    fp = fopen("bookLibrary.dat","rb");
    ft = fopen("temp.dat","wb");

    if(fp==NULL || ft==NULL)
        {
            printf("\nError: While opening file:\n");
            return fail;
        }
    else
    {
        rewind(fp);
        book *discarded_book = (book*)malloc(sizeof(book));
    while(fread(discarded_book,sizeof(book),1,fp)==1)
    {
        if(id != discarded_book->Textbook_id)
        {

            fwrite(discarded_book,sizeof(book),1,ft);


        }




    }
    fclose(fp);
    fclose(ft);
    free(discarded_book);

    remove("bookLibrary.dat");
    rename("temp.dat","bookLibrary.dat");

    return pass;


        }

}