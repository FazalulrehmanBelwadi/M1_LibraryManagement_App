#include"library_management_system.h"
#include"unity_internals.h"
#include"unity.h"
#include"liberymanagement.c"

/*struct library lib[100];
char ar_nm[30], bk_nm[30];
int i=0;*/
int count=0;
void test_addbook(void)
{
     TEST_ASSERT_EQUAL(1,addbook(&count));
}

/*void test_searchbook(void)
{
    TEST_ASSERT_EQUAL(false,searchbook(-2));
    TEST_ASSERT_EQUAL(true,searchbook(125));
}*/