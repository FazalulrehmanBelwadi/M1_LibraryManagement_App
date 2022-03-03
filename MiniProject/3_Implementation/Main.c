#include "library_management_system.h"
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

