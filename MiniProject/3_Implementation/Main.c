// C program for the library
// Management System
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/


/*struct library {
	char book_name[20];
	char author[20];
	int pages;
	float price;
};*/
#include "library_management_system.h"
// Driver Code
struct library lib[100];
char ar_nm[30], bk_nm[30];
int i=0;
bool addbook(int *count) {
	printf("Enter book name = ");
			scanf("%s", lib[i].book_name);

			printf("Enter author name = ");
			scanf("%s", lib[i].author);

			printf("Enter pages = ");
			scanf("%d", &lib[i].pages);
			if(lib[i].pages<0)
			{
				printf("you have entered invalid input = %d\n",lib[i].pages);
				return false;
			
			}
			printf("Enter price = ");
			scanf("%f", &lib[i].price);
			if(lib[i].price<0)
			{
				printf("you have entered invalid input =%f\n",lib[i].price);
				return false;
			}
			*count=*count+1;
			i++;
			return true;
}

bool search_authorname(int *count){
	printf("Enter author name : ");
			scanf("%s", ar_nm);
			for (i = 0; i < *count; i++) {

				if (strcmp(ar_nm,
						lib[i].author)
					== 0)
					printf("book name = %s",
					lib[i].book_name);

					printf("\t author name = %s",
					lib[i].author);
					
					printf("\t pages = %d",
					lib[i].pages);

					printf("\t price = %f",
					lib[i].price);


			}

}
int main()
{

	int input, count;

	input = count = 0;

	// Iterate the loop
	while (input != 5) {

		printf("\n\n********######"
			" WELCOME TO LIBRARY "
			"#####********\n");
		printf("\n\n1. Add book infor"
			"mation\n2. Display "
			"book information\n");
		printf("3. List all books of "
			"given author\n");
		printf(
			"4. List the count of book"
			"s in the library\n");
		printf("5. Exit");

		// Enter the book details
		printf("\n\nEnter one of "
			"the above: ");
		scanf("%d", &input);

		// Process the input
		switch (input) {

		// Add book
		case 1:
			addbook(&count);
			printf("%d",count);
			printf ("%d",i);
			break;

		// Print book information
		case 2:
			printf("you have entered"
				" the following "
				"information\n");
			for (int j = 0; j < count; j++) {

				printf("book name = %s",
					lib[j].book_name);

				printf("\t author name = %s",
					lib[j].author);

				printf("\t pages = %d",
					lib[j].pages);

				printf("\t price = %f",
					lib[j].price);
			}
			break;

		// Take the author name as input
		case 3:
			search_authorname(&count);
		
			
			break;

		// Print total count
		case 4:
			printf("\n No of books in "
				"library : %d",
				count);
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}
