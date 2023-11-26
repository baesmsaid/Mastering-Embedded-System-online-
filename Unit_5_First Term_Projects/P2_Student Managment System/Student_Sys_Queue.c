/*
 * Student_Sys_Queue.c
 *
 *  Created on: 26/11/2023
 *      Author: Basem Said
 */


#include "Student_Sys_Queue.h"

FILE *Students_file , *Update_Students_file ;

// Declaration static function
static void Print_Student_Info(struct SStudent_Info *student) ;

static struct SStudent_Info *Search_Studnent_by_RollNum(FIFO_Buf_t *students , int roll) ;

// Students Queue Initialization
FIFO_Buf_Status Students_Init(FIFO_Buf_t *students , Item *item , int length)
{
	// Check Parameters is exist
	if(!students || !item || !length)
	{
		DPRINTF("Student System Queue Initialization Failed \n") ;
		return FIFO_Null ;
	}

	// FIFO Initialization
	students->base    = item ;
	students->head    = students->base ;
	students->tail    = students->base ;
	students->length  = length ;
	students->counter = 0 ;

	DPRINTF("Student System Queue Initialization Successfully \n") ;
	return FIFO_No_Error ;
}

// Enter Data(item) in the FIFO
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t *fifo_buf , Item item)
{
	// Check Parameters is exist
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DPRINTF("FIFO Not Exist \n") ;
		return FIFO_Null ;
	}

	//Check if FIFO is Full
	if(FIFO_IS_Full(fifo_buf) == FIFO_Full)
	{
		DPRINTF("FIFO is Full:FIFO Enqueue is failed \n") ;
		return FIFO_Full ;
	}

	//Enqueue New Item
	*(fifo_buf->head) = item ;
	//Check if the head is in the End of Array
	if((fifo_buf->head + 1) == (fifo_buf->base + fifo_buf->length))
	{
		fifo_buf->head = fifo_buf->base ;
	}
	else
	{
		fifo_buf->head++ ;
	}

	fifo_buf->counter++;

	return FIFO_No_Error ;
}

//Is FIFO Full ?!
FIFO_Buf_Status FIFO_IS_Full(FIFO_Buf_t *fifo_buf)
{
	// Check Parameters is exist
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DPRINTF("FIFO Not Exist \n") ;
		return FIFO_Null ;
	}

	//Check If Number of Items Equal Buffer Length
	if(fifo_buf->counter == fifo_buf->length)
	{
		return FIFO_Full ;
	}

	return FIFO_Not_Full ;
}

// Is FIFO Empty ?!
FIFO_Buf_Status FIFO_IS_Empty(FIFO_Buf_t *fifo_buf)
{
	// Check Parameters is exist
	if(!fifo_buf || !fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		DPRINTF("FIFO Not Exist \n") ;
		return FIFO_Null ;
	}

	//Check If Number of Items is Equal Zero
	if(fifo_buf->counter == 0)
	{
		return FIFO_Empty ;
	}

	return FIFO_Not_Empty ;
}

// Enter Students Data from File
void Add_Student_From_File(FIFO_Buf_t *students)
{
	Item new_student ;
	int i ;

	//Opening Student.txt file and Read it
	Students_file = fopen("Students.txt","r") ;

	//Check if the file is exist and there is data in it
	if(Students_file == NULL)
	{
		DPRINTF("\n [ERROR]===> Student.txt File Not Found. \n") ;
		DPRINTF("\n [ERROR]===> Adding Students From File Failed \n") ;
		return ;
	}

	//While Loop for Reading Students Until the End of File by Using feof == Check end of file
	while(!feof(Students_file))
	{
		//Reading Roll Number of Student
		fscanf(Students_file , "%d" , &new_student.Roll_Number) ;

		//Check if Roll Number is exist
		if(Search_Studnent_by_RollNum(students , new_student.Roll_Number) != NULL)
		{
			DPRINTF("\n [ERROR]===> Roll Number  %d is Already Taken\n",new_student.Roll_Number) ;

			//Ignore the Rest of the Line
			fscanf(Students_file , "%*[^\n]") ;

			//Start over from next line in text file
			continue ;
		}

		//Reading Data (First_Name,Last_Name,GPA)
		fscanf(Students_file , "%s" , new_student.First_Name) ;
		fscanf(Students_file , "%s" , new_student.Last_Name) ;
		fscanf(Students_file , "%f" , &new_student.GPA) ;

		//Reading Course ID
		for (i=0 ; i<Courses_Number ; ++i)
		{
			fscanf(Students_file , "%d" , &new_student.Course_Id[i]) ;
		}

		// Enqueue New Student
		if((FIFO_Enqueue(students , new_student)) == FIFO_No_Error)
		{
			DPRINTF("\n [INFO]===> Roll Number %d is Saved Successfully\n" , new_student.Roll_Number) ;
		}
		else
		{
			DPRINTF("\n [ERROR]===> Failed to Add Students by File\n") ;
			return ;
		}
	}

	DPRINTF("\n [INFO]===> Students Information are Saved Successfully\n ") ;
	//Closing File
	fclose(Students_file) ;
}

//Enter Students Data Manually From Console
void Add_Student_Manually(FIFO_Buf_t *students)
{
	Item new_student ;
	int i ;

	DPRINTF("\n==== Enter Student Data ====\n") ;
	DPRINTF("\t Enter Roll Number: ") ;
	scanf("%d",&new_student.Roll_Number) ;

	//Check if Roll Number is exist
	if(Search_Studnent_by_RollNum(students , new_student.Roll_Number))
	{
		DPRINTF("\n [ERROR]===> Roll Number %d is Already Taken\n" , new_student.Roll_Number) ;
		DPRINTF("\n [ERROR]===> Failed to Add Student Manually\n") ;
		return ;
	}

	//else, We continue reading data
	DPRINTF("\t Enter First Name: ") ;
	scanf("%s", new_student.First_Name) ;

	DPRINTF("\t Enter Last Name: ") ;
	scanf("%s", new_student.Last_Name) ;

	DPRINTF("\t Enter GPA: ") ;
	scanf("%f", &new_student.GPA) ;

	DPRINTF("\t Enter Courses ID \n") ;
	for(i=0 ; i< Courses_Number ; ++i)
	{
		DPRINTF("\t \t Enter Courses Id: ") ;
		scanf("%d", &new_student.Course_Id[i]) ;
	}

	// Enqueue New Student
	if((FIFO_Enqueue(students , new_student)) == FIFO_No_Error)
	{
		DPRINTF("\n [INFO]===> Roll Number %d is Saved Successfully\n" , new_student.Roll_Number) ;
	}
	else
	{
		DPRINTF("\n [ERROR]===> Failed to Add Students by File\n") ;
		return ;
	}
}

// Get Student Data by Roll Number
void Get_Student_by_RollNum(FIFO_Buf_t *students)
{
	// Declare variable to take roll number from user
	int IndexNum ;
	// Declare variable to take Student Info
	Item *Student ;
	// Declare variable to take Queue Status
	FIFO_Buf_Status QueueStatus ;

	//Check if queue is empty
	QueueStatus = FIFO_IS_Empty(students) ;
	//Check if queue is empty or not exist
	if((QueueStatus == FIFO_Empty) || (QueueStatus == FIFO_Null))
	{
		DPRINTF("\n [ERROR]===> Failed to Find Student by Roll Number \n") ;
		return ;
	}

	//User Entered Roll Number
	DPRINTF("\n Enter Roll Number: ") ;
	scanf("%d",&IndexNum) ;

	//Search in Queue to find this Roll Number
	Student = Search_Studnent_by_RollNum(students , IndexNum) ;

	// Check if Roll Number is exist
	if(Student == NULL)
	{
		DPRINTF("\n [ERROR]===> Roll Number %d Not Found in Queue\n",IndexNum) ;
		return ;
	}
	else
	{
		// If Roll Number is exist we will print it
		Print_Student_Info(Student) ;
	}
}

// Get Student Data by First Name
void Get_Student_by_FirstName(FIFO_Buf_t *students)
{
	Item *Student = students->tail ;
	// Declare variables to take First Name from user and other for count in for loop
	char FName [Name_Length] , i ;
	// Declare variable to take Queue Status
	FIFO_Buf_Status QueueStatus ;

	//Check if queue is empty
	QueueStatus = FIFO_IS_Empty(students) ;
	//Check if queue is empty or not exist
	if((QueueStatus == FIFO_Empty) || (QueueStatus == FIFO_Null))
	{
		DPRINTF("\n [ERROR]===> Failed to Find Student by First Name \n") ;
		return ;
	}

	// User Entered First Name to search in Queue
	DPRINTF("\n Enter First Name of Student: ") ;
	scanf("%s",FName) ;

	//Loop inside Queue to find the student
	for (i=0 ; i < students->counter ; ++i)
	{
		// Compare between Two String FName and the Name in Queue
		if(!(strcmp(FName , Student->First_Name)))
		{
			Print_Student_Info(Student) ;
			return ;
		}
		else
		{
			DPRINTF("\n [ERROR]===> %s Not Found in Queue \n",FName) ;
			return ;
		}

		//Check if we reach to the last Item in the Queue
		if ((Student +1) == (students->base + students->length))
		{
			// Set to the start of Queue
			Student = students->base ;
		}
		else
		{
			// Just go to the Next Item
			Student++;
		}
	}
}

// Get Student Data Who Register this Course
void Get_Student_by_CourseId(FIFO_Buf_t *students)
{
	Item *Student ;
	// Declare variable to take Course Id from user
	int IndexId , i , j , Number_Enrolled_Student = 0 ;
	// Declare variable to take Queue Status
	FIFO_Buf_Status QueueStatus ;

	//Check if queue is empty
	QueueStatus = FIFO_IS_Empty(students) ;
	//Check if queue is empty or not exist
	if((QueueStatus == FIFO_Empty) || (QueueStatus == FIFO_Null))
	{
		DPRINTF("\n [ERROR]===> Failed to Find Student by Course Id \n") ;
		return ;
	}

	//Course Id Entered by User
	DPRINTF("\n Enter Course ID: ") ;
	scanf("%d",&IndexId) ;

	// Define variable to start from the end of Queue
	Student = students->tail ;
	//Loop inside Queue
	for (i=0 ; i < students->counter ; i++)
	{
		//Loop inside Courses
		for (j=0 ; j < Courses_Number ; j++)
		{
			//Check if we find student have this Course ID
			if(Student->Course_Id[j] == IndexId)
			{
				Print_Student_Info(Student) ;
				Number_Enrolled_Student++ ;
				DPRINTF("\n") ;
				break ;
			}
		}

		//Check if we reach to the last Item in the Queue
		if ((Student +1) == (students->base + students->length))
		{
			// Set to the start of Queue
			Student = students->base ;
		}
		else
		{
			// Just go to the Next Item
			Student++;
		}
	}

	//Check if Not Found Any students in Queue
	if (Number_Enrolled_Student == 0)
	{
		DPRINTF("\n [ERROR]===> Course Id %d Not Found \n",IndexId) ;
	}
	else
	{
		DPRINTF("\n [INFO]===> Total Number of Students Enrolled this Course: %d \n",Number_Enrolled_Student) ;
	}
}

// View Students Number in Queue
void Print_StudentsNum(FIFO_Buf_t *students)
{
	//Define Variables
	int counter = students->counter ;
	int capacity =students->length ;

	DPRINTF("[INFO]===> Total Number of Student is %d\n",counter) ;
	DPRINTF("[INFO]===> You can Add Up to %d Students\n",capacity) ;
	DPRINTF("[INFO]===> You Can Add %d More Students\n",capacity-counter) ;
}

// Delete Student from Queue
void Delete_Student_by_RollNum(FIFO_Buf_t *students)
{
	// Declare variables
	int IndexNum , i , flag = 0 ;

	Item *Student ;
	// Declare variable to take Queue Status
	FIFO_Buf_Status QueueStatus ;

	//Check if queue is empty
	QueueStatus = FIFO_IS_Empty(students) ;
	//Check if queue is empty or not exist
	if((QueueStatus == FIFO_Empty) || (QueueStatus == FIFO_Null))
	{
		DPRINTF("\n [ERROR]===> Failed to Delete Student by Roll Number \n") ;
		return ;
	}

	// Roll Number Entered by User
	DPRINTF("\n Enter Roll Number: ") ;
	scanf("%d",&IndexNum) ;

	// Define variable to start from the base of Queue
	Student = students->base ;
	//Loop inside Queue
	for (i = 0 ; i < students->counter ; ++i)
	{
		if(Student->Roll_Number == IndexNum)
		{
			// Deleting Student Info
			*Student = *(students->tail) ;

			// Update Counter of Queue ==> (Number of Students)
			students->counter-- ;

			//Check if we reach to the last Item in the Queue
			if ((students->tail +1) == (students->base + students->length))
			{
				// Set to the start of Queue
				students->tail = students->base ;
			}
			else
			{
				// Just go to the Next Item
				students->tail++;
			}

			// we will set flag for deleting student
			flag =1 ;
			break ;
		}
		else
		{
			// We will clear flag if we did not delete any student
			flag = 0 ;
		}
		Student++ ;

	}

	if (flag == 1)
	{
		DPRINTF("\n [INFO]===> The Roll Number of Student is Removed Successfully\n ") ;
	}
	else
	{
		DPRINTF("[ERROR]===> The Roll Number %d Not Found\n",IndexNum) ;
	}
}

// Update Specific Data in Queue
void Update_Student_by_RollNum(FIFO_Buf_t *students)
{
	Item *Update_Student , *Student ;
	// Declare variables
	int i , IndexRoll , IndexOption , IndexNewRoll , flag = 0 ;
	// Declare variable to take Queue Status
	FIFO_Buf_Status QueueStatus ;

	//Check if queue is empty
	QueueStatus = FIFO_IS_Empty(students) ;
	//Check if queue is empty or not exist
	if((QueueStatus == FIFO_Empty) || (QueueStatus == FIFO_Null))
	{
		DPRINTF("\n [ERROR]===> Failed to Delete Student by Roll Number \n") ;
		return ;
	}

	//Enter Roll Number You Want to Update
	DPRINTF("\n Enter Roll Number: ") ;
	scanf("%d",&IndexRoll) ;

	//Search about RollNumber to get its whole item
	Update_Student = Search_Studnent_by_RollNum(students , IndexRoll) ;

	//Check if ROllNumber is exist
	if (Update_Student == NULL)
	{
		DPRINTF("\n [ERROR]===> Roll Number %d Not Found\n", IndexRoll) ;
		return ;
	}
	else
	{
		//If We Found Roll Number then we will print all data
		DPRINTF("\n==== Student Data ====\n") ;
		Print_Student_Info(Update_Student) ;
	}

	DPRINTF("\n Which Data do you want to change ?\n") ;
	DPRINTF("\t 1: The Roll Number\n") ;
	DPRINTF("\t 2: The First Name\n") ;
	DPRINTF("\t 3: The Last Name\n") ;
	DPRINTF("\t 4: The GPA\n") ;
	DPRINTF("\t 5: The Course ID\n") ;
	DPRINTF("Enter Your Option: ") ;

	//Get the Option from User
	scanf("%d",&IndexOption) ;

	//Switch Case depend on Option from User
	switch(IndexOption)
	{
	case 1 :
		DPRINTF("Enter The New Roll Number: ") ;
		scanf("%d", &IndexNewRoll) ;

		Student = students->tail ;
		//Loop inside Queue
		for (i = 0 ; i < students->counter ; ++i)
		{
			//Check if Roll Number is exist
			if(Student->Roll_Number == IndexNewRoll)
			{
				//we will get out from loop
				DPRINTF("\n[ERROR]===> This Roll Number %d is exist\n",IndexNewRoll) ;

				//If the Roll Number Match with New Roll Number
				flag = 1 ;
				break ;
			}

			//Check if we reach to the last Item in the Queue
			if ((Student +1) == (students->base + students->length))
			{
				// Set to the start of Queue
				Student = students->base ;
			}
			else
			{
				// Just go to the Next Item
				Student++;
			}
		}

		//If the flag doesn't Change this mean that no Roll Number Match
		if(flag == 0)
		{
			Update_Student->Roll_Number = IndexNewRoll ;
			DPRINTF("\n[INFO]===> The Roll Number %d is Update Successfully\n",IndexNewRoll) ;
		}
		break ;

	case 2:
		DPRINTF("Enter the New First Name: ") ;
		scanf("%s",Update_Student->First_Name) ;
		DPRINTF("\n[INFO]===> The First Name %s is Updated Successfully\n",Update_Student->First_Name) ;
		break ;

	case 3:
		DPRINTF("Enter the New Last Name: ") ;
		scanf("%s",Update_Student->Last_Name) ;
		DPRINTF("\n[INFO]===> The Last Name %s is Updated Successfully\n",Update_Student->Last_Name) ;
		break ;

	case 4:
		DPRINTF("Enter the New GPA: ") ;
		scanf("%f",&Update_Student->GPA) ;
		DPRINTF("\n[INFO]===> The GPA %.1f is Updated Successfully\n",Update_Student->GPA) ;
		break ;

	case 5:
		DPRINTF("Enter the Course Number from %d to %d: ",1 , Courses_Number) ;
		scanf("%d",&IndexOption) ;
		DPRINTF("Enter the New Course Id: ") ;
		scanf("%d",&Update_Student->Course_Id[IndexOption - 1]) ;
		DPRINTF("\n[INFO]===> The Course ID %d is Updated Successfully\n",Update_Student->Course_Id[IndexOption - 1]) ;
		break ;

	default:
		break ;
	}
}

// Update Students in File
void Update_Student_File(FIFO_Buf_t *students)
{
	Item *Student ;
	int i ,j ;

	//Opening  file Update_Students.txt with option 'w' to write in it
	Update_Students_file = fopen("Update_Students.txt","w") ;

	//Check if file is exist and there is data in it or not
	if(Update_Students_file == NULL)
	{
		DPRINTF("\n [ERROR]===> Update_Students.txt Failed to Create") ;
		DPRINTF("\n [ERROR]===> Update_Students File is Failed") ;
		return ;
	}

	Student = students->tail ;
	//Loop inside Queue
	for (i =0 ; i < students->counter ; ++i)
	{
		//Write into File
		fprintf(Update_Students_file,"%d",Student->Roll_Number) ;
		fprintf(Update_Students_file,"%s",Student->First_Name) ;
		fprintf(Update_Students_file,"%s",Student->Last_Name) ;
		fprintf(Update_Students_file,"%0.1f",Student->GPA) ;

		for (j = 0 ; j < Courses_Number ; ++j)
		{
			fprintf(Update_Students_file,"%d",Student->Course_Id[j]) ;
		}

		//New Line After Every Item
		fprintf(Update_Students_file,"\n") ;

		//Check if we reach to the last Item in the Queue
		if ((Student +1) == (students->base + students->length))
		{
			// Set to the start of Queue
			Student = students->base ;
		}
		else
		{
			// Just go to the Next Item
			Student++;
		}
	}
	DPRINTF("\n[INFO]===> Students Details are Updated in file Successfully\n") ;

	//Close File
	fclose(Update_Students_file) ;
}

// Enter Students Data From Update File
void Add_Student_From_Update_File(FIFO_Buf_t *students)
{
	Item New_Student ;
	int i ;

	//Opening a Update_Students.txt file with option'r' Read
	Update_Students_file =fopen("Update_Students.txt","r") ;

	//Check if file is exist and there is data in it or not
	if(Update_Students_file == NULL)
	{
		DPRINTF("\n [ERROR]===> Update_Students.txt Failed to Create") ;
		DPRINTF("\n [ERROR]===> Update_Students File is Failed") ;
		return ;
	}

	//Reading Students until the end of file by using feof ==> (Check end of file)
	while (!feof(Update_Students_file))
	{
		//Reading Roll Number of the Student
		fscanf(Update_Students_file,"%d",&New_Student.Roll_Number) ;

		//Check if the Roll Number is exist
		if(Search_Studnent_by_RollNum(students , New_Student.Roll_Number) != NULL)
		{
			//Printing that if we find Roll Number Matching with other in Queue
			DPRINTF("\n[ERROR]===> Roll Number %d is Already Taken\n", New_Student.Roll_Number) ;

			//Ignore the rest of the line
			fscanf(Update_Students_file,"%*[^\n]") ;

			//Start Over from Next Line in text file
			continue ;

		}

		//Reading Data First Name, Last Name and GPA Sequential
		fscanf(Update_Students_file,"%s",New_Student.First_Name) ;
		fscanf(Update_Students_file,"%s",New_Student.Last_Name) ;
		fscanf(Update_Students_file,"%f",&New_Student.GPA) ;

		//Reading Course IDs
		for (i = 0 ; i < Courses_Number ; ++i)
		{
			fscanf(Update_Students_file,"%d",&New_Student.Course_Id[i]) ;
		}

		//Enqueue new student
		if((FIFO_Enqueue(students, New_Student)) == FIFO_No_Error)
		{
			DPRINTF("\n[INFO]===> Roll Number %d is Saved Successfully\n",New_Student.Roll_Number) ;
		}
		else
		{
			DPRINTF("\n[ERROR]===> Failed to Add Students by Update File\n") ;
			return ;
		}
	}
	DPRINTF("\n[INFO]===> Students are Saved successfully\n") ;

	//Close the File
	fclose(Update_Students_file) ;
}

// View All Students in Queue
void Show_Students_Info(FIFO_Buf_t *students)
{
	Item *Student ;
	char i ;
	FIFO_Buf_Status QueueStatus ;

	//Checking if the Queue is Empty
	QueueStatus = FIFO_IS_Empty(students) ;
	if ((QueueStatus == FIFO_Empty) || (QueueStatus == FIFO_Null))
	{
		DPRINTF("\n [ERROR]===> Failed to Show Students Info\n") ;
		return ;
	}

	DPRINTF("\nALL Students \n\n");

	Student = students->tail ;
	for (i = 0 ; i < students->counter ; ++i)
	{
		Print_Student_Info(Student) ;
		DPRINTF("\n") ;

		//Check if we reach to the last Item in the Queue
		if ((Student +1) == (students->base + students->length))
		{
			// Set to the start of Queue
			Student = students->base ;
		}
		else
		{
			// Just go to the Next Item
			Student++;
		}
	}
}

static void Print_Student_Info(struct SStudent_Info *student)
{
	int i ;

	DPRINTF("The Student Details are \n") ;
	DPRINTF("\t First Name: %s\n",student->First_Name) ;
	DPRINTF("\t Last Name: %s\n",student->Last_Name) ;
	DPRINTF("\t Roll Number: %d\n",student->Roll_Number) ;
	DPRINTF("\t GPA: %0.1f\n",student->GPA) ;
	DPRINTF("\tCourses IDs are\n") ;

	for (i = 0 ; i < Courses_Number ; i++)
	{
		DPRINTF("\t\tCourse %d Id: %d\n",i+1 , student->Course_Id[i]) ;
	}
}

static struct SStudent_Info *Search_Studnent_by_RollNum(FIFO_Buf_t *students , int roll)
{
	int i ;
	//We Start from the Tail because from the Base we can find that there is no data store / removed
	Item *Student = students->tail ;

	//Loop inside Queue
	for (i = 0 ; i < students->counter ; ++i)
	{
		// Check if we find the roll and we search about it till to break
		if(Student->Roll_Number == roll)
		{
			// Get out from loop
			break ;
		}
		//Check if we reach to the last Item in the Queue
		if ((Student +1) == (students->base + students->length))
		{
			// Set to the start of Queue
			Student = students->base ;
		}
		else
		{
			// Just go to the Next Item
			Student++;
		}
	}

	//Check if we couldn't find the Roll Number and we reach to last item
	if (i == students->counter)
	{
		//Return Null
		Student = NULL ;
	}

	//Return the Struct of the Roll Number we found
	return Student ;
}
