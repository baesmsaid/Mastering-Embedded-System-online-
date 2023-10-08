/*
 * Students.h
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)		{fflush(stdout) ; \
							fflush(stdin) ; \
							printf(__VA_ARGS__) ; \
							fflush(stdout) ; \
							fflush(stdin) ; }


//Effective Data
struct Sdata
{
	int ID ;
	char name [40] ;
	float height ;
};

//Linked List Node
struct SStudent
{
	struct Sdata student ;
	struct SStudent* PNextStudent ;   //Create Node to Next Data
};


// Create head of linked list and initialize it as NULL
struct SStudent* gpFirstStudent  ;


//APIs

void AddStudent () ;
int DeleteStudent () ;
void ViewStudent () ;
void DeleteAll () ;
void FillRecord (struct SStudent* NewStudent) ;
void GetNode () ;
void GetLength_Iterative () ;
int GetLength_Recursive (struct SStudent *pStudentNode) ;
void GetNode_From_End () ;
void GetMiddle_Student () ;
void DetectLoop () ;
void ReverseList () ;



#endif /* STUDENTS_H_ */
