/**
 * @file test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include"library_management_system.h"
#include"unity_internals.h"
#include"unity.h"
#include"AddTextbook.c"
#include"DeleteTextbook.c"
#include"IssueTextbook.c"
#include"ViewTextbook.c"
#include"SearchTextbook.c"

/**
 * @brief Set the Up object
 * 
 */
void setUp(){}

void tearDown(){}


void test_Textbook_Addon(void){
    TEST_ASSERT_EQUAL(pass,Textbook_Addon(125, "Travis", "Chalizard"));
}

void test_Textbook_view(void){
    TEST_ASSERT_EQUAL(pass,Textbook_view());
}

void test_Textbook_search(void){
    TEST_ASSERT_EQUAL(fail,searchbook(-2));
    TEST_ASSERT_EQUAL(pass,searchbook(125));
}



void test_Textbook_Delete(void){
    TEST_ASSERT_EQUAL(pass,Textbook_Delete(125));
}        

void test_Textbook_Issue(void){
    TEST_ASSERT_EQUAL(pass,Textbook_Issue(125));
}

int main(){
    UNITY_BEGIN();

    RUN_TEST(test_Textbook_Addon);
    RUN_TEST(test_Textbook_search);
    RUN_TEST(test_Textbook_Issue);
    RUN_TEST(test_Textbook_Delete);
    RUN_TEST(test_Textbook_view);
    
    return UNITY_END();
}