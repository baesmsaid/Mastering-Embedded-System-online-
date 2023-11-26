/*
 * Student_Sys_Queue.h
 *
 *  Created on: 26/11/2023
 *      Author: Basem Said
 */

#ifndef STUDENT_SYS_QUEUE_H_
#define STUDENT_SYS_QUEUE_H_

#include "stdio.h"
#include "string.h"

#define DPRINTF(...)		{fflush(stdout) ; \
							fflush(stdin) ; \
							printf(__VA_ARGS__) ; \
							fflush(stdout) ; \
							fflush(stdin) ; }

#define Name_Length    30
#define Courses_Number  5

// Student Info Structure
struct SStudent_Info {
	char First_Name[Name_Length] ;
	char Last_Name [Name_Length] ;
	int Roll_Number ;
	float GPA ;
	int Course_Id [Courses_Number] ;
};

//Data Type of Buffer
typedef struct SStudent_Info Item ;

// FIFO Data Type
typedef struct {
	int length ;
	int counter ;
	Item *base ;
	Item *head ;
	Item *tail ;
}FIFO_Buf_t;

typedef enum
{
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Not_Full,
	FIFO_Empty,
	FIFO_Not_Empty,
	FIFO_Null
}FIFO_Buf_Status;

// FIFO APIs
// Students Queue Initialization
FIFO_Buf_Status Students_Init(FIFO_Buf_t *students , Item *item , int length) ;

// Enter Data(item) in the FIFO
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t *fifo_buf , Item item) ;

// Is FIFO Full ?!
FIFO_Buf_Status FIFO_IS_Full(FIFO_Buf_t *fifo_buf) ;

// Is FIFO Empty ?!
FIFO_Buf_Status FIFO_IS_Empty(FIFO_Buf_t *fifo_buf) ;

// Enter Students Data from File
void Add_Student_From_File(FIFO_Buf_t *students) ;

// Enter Students Data From Update File
void Add_Student_From_Update_File(FIFO_Buf_t *students) ;

// Enter Student Data Manually
void Add_Student_Manually(FIFO_Buf_t *students) ;

// Get Student Data by Roll Number
void Get_Student_by_RollNum(FIFO_Buf_t *students) ;

// Get Student Data by First Name
void Get_Student_by_FirstName(FIFO_Buf_t *students) ;

// Get Student Data Who Register this Course
void Get_Student_by_CourseId(FIFO_Buf_t *students) ;

// View Students Number in Queue
void Print_StudentsNum(FIFO_Buf_t *students) ;

// Delete Student from Queue
void Delete_Student_by_RollNum(FIFO_Buf_t *students) ;

// Update Specific Data
void Update_Student_by_RollNum(FIFO_Buf_t *students) ;

// Update Students in File
void Update_Student_File(FIFO_Buf_t *students) ;

// View All Students in Queue
void Show_Students_Info(FIFO_Buf_t *students) ;


#endif /* STUDENT_SYS_QUEUE_H_ */
