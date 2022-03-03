/**
 * @file library_management_system.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __LIBRARY_MANAGEMENT_SYSTEM_H__
#define __LIBRARY_MANAGEMENT_SYSTEM_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * @brief 
 * 
 */

typedef struct Library_management
{
    int Textbook_id;
    char Textbook_name[20];
    char Author_name[20];
}book;

/**
 * @brief 
 * 
 */


typedef enum check_variable {
    pass = 1,
    fail = 0
}check_variable;

/**
 * @brief 
 * 
 * @param id 
 * @return check_variable 
 */


check_variable Textbook_search(int id);
/**
 * @brief 
 * 
 * @param id 
 * @param name 
 * @param author 
 * @return check_variable 
 */


check_variable Textbook_Addon(int id,char name[],char author[]);
/**
 * @brief 
 * 
 * @param id 
 * @return check_variable 
 */


check_variable Textbook_Delete(int id);
/**
 * @brief 
 * 
 * @param id 
 * @return check_variable 
 */


check_variable Textbook_Issue(int id);
/**
 * @brief 
 * 
 * @return check_variable 
 */


check_variable Textbook_view(void);
/**
 * @brief 
 * 
 */

#endif
