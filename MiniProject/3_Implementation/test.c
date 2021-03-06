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

/**
 * @brief Set the Up object
 * 
 */
void setUp(){}

void tearDown(){}
/**
 * @brief 
 * 
 */

void test_Textbook_Addon(void){
    TEST_ASSERT_EQUAL(pass,Textbook_Addon(125, "Travis", "Chalizard"));
}
/**
 * @brief 
 * 
 */
void test_Textbook_view(void){
    TEST_ASSERT_EQUAL(pass,Textbook_view());
}
/**
 * @brief 
 * 
 */
void test_Textbook_search(void){
    TEST_ASSERT_EQUAL(fail,searchbook(-2));
    TEST_ASSERT_EQUAL(pass,searchbook(125));
}
/**
 * @brief 
 * 
 */



void test_Textbook_Delete(void){
    TEST_ASSERT_EQUAL(pass,Textbook_Delete(125));
}        
/**
 * @brief 
 * 
 */
void test_Textbook_Issue(void){
    TEST_ASSERT_EQUAL(pass,Textbook_Issue(125));
}
/**
 * @brief 
 * 
 * @return int 
 */
int main(){
    UNITY_BEGIN();

    RUN_TEST(test_Textbook_Addon);
    RUN_TEST(test_Textbook_search);
    RUN_TEST(test_Textbook_Issue);
    RUN_TEST(test_Textbook_Delete);
    RUN_TEST(test_Textbook_view);
    
    return UNITY_END();
}