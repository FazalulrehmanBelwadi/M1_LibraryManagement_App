/**
 * @file library_management_system.h
 * @author FazalulrehmanBelwadi(you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//Header gaurd
#ifndef __LIBRARY_MANAGEMENT_SYSTEM_H__
#define __LIBRARY_MANAGEMENT_SYSTEM_H__
 
 // Include File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Structure Declaration
struct library {
	char book_name[20];
	char author[20];
	int pages;
	float price;
};


#endif