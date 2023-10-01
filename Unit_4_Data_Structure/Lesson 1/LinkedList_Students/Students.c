/*
 * Students.c
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */


#include "Students.h"

void FillRecord (struct SStudent* NewStudent)
{
	// Use it to fill new record
	char temp_text [40] ;

	//Fill new record
	DPRINTF ("\n Enter the ID : ");
	gets (temp_text) ;
	NewStudent->student.ID =atoi(temp_text) ;   // convert to int

	DPRINTF ("\n Enter the full name : ");
	gets (NewStudent->student.name) ;

	DPRINTF ("\n Enter the height : ");
	gets (temp_text) ;
	NewStudent->student.height =atof(temp_text) ;   // convert to float
}

void AddStudent ()
{
	// Create struct to add element
	struct SStudent* pNewStudent ;
	// Create struct to point to last element
	struct SStudent* pLastStudent ;

	//Check if list is empty == True
	if (gpFirstStudent == NULL)
	{
		//Create new record
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent)) ;
		//Assign it to gpFirstStudent
		gpFirstStudent = pNewStudent ;
	}
	// List is not empty and contain record
	else
	{
		//Navigate until reach to the last record
		//pLastStudent will point to gpFirstStudent to start from the beginning of linked list
		pLastStudent = gpFirstStudent ;
		//Loop until reach to NULL ---> condition will be False and exit from loop
		while (pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent ;
		// After find last record we will create new record
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent)) ;
		//Make pLastStudent->PNextStudent point to pNewStudent
		pLastStudent->PNextStudent = pNewStudent ;
	}

	//Fill new record
	FillRecord(pNewStudent) ;
	// Set the next pointer (New_Student) to NULL (That is consider as last element in linked list)
	pNewStudent->PNextStudent = NULL ;

}

int DeleteStudent ()
{
	char temp_text [40] ;
	unsigned int selected_id ;

	//Get selected id
	DPRINTF ("\n Enter the student ID to be deleted : ") ;
	gets (temp_text) ;
	selected_id = atoi (temp_text) ;     //Convert to int

	// Check list is not empty
	if (gpFirstStudent)
	{
		// Create struct to point to selected student
		struct SStudent* pSelectedStudent = gpFirstStudent ;
		// Create struct to point to previous selected student
		struct SStudent* pPreviousStudent = NULL ;

		//Search for selected student by looping on all record
		while (pSelectedStudent)
		{
			//Compare each Node with selected student ID
			if (pSelectedStudent->student.ID == selected_id)
			{
				//If previous student is exist (That is mean the first student is not selected ID)
				if (pPreviousStudent)
				{
					//Previous recored will point to the next of selected student (Bc the selected ID between them is deleted)
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}
				//If previous student not exist (means previous student = NULL and first student is selected ID)
				else
				{
					//Assign gpFirstStudent to next node of deleted selected ID
					gpFirstStudent = pSelectedStudent->PNextStudent ;
				}
				//Deleted selected ID
				free (pSelectedStudent) ;
				//To exit from loop
				return 1 ;
			}
			//If selected student not first student then we will point to next student and so on
			//Store that recored in previous
			pPreviousStudent = pSelectedStudent ;
			// Selected student point to next student
			pSelectedStudent = pSelectedStudent->PNextStudent ;
		}
	}
	//If ID did not match or not found
	DPRINTF ("\n Cannot find Student ID.") ;
	return 0 ;
}

void ViewStudent ()
{
	// Create struct to point to current student
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	int count =0 ;

	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}
	else
	{
		//Loop to print all list
		while (pCurrentStudent)
		{
			DPRINTF ("\n Record Number %d ",count+1) ;
			DPRINTF ("\n \t ID : %d ",pCurrentStudent->student.ID) ;
			DPRINTF ("\n \t Name : %s ",pCurrentStudent->student.name) ;
			DPRINTF ("\n \t height : %f ",pCurrentStudent->student.height) ;
			pCurrentStudent = pCurrentStudent->PNextStudent ;
			count++ ;
		}
	}
}

void DeleteAll ()
{
	// Create struct to point to current student
	struct SStudent* pCurrentStudent = gpFirstStudent ;

	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}
	else
	{
		//Loop to print all list
		while (pCurrentStudent)
		{
			// Create struct to point to current student to delete it without manipulating with current student record
			struct SStudent* pTempStudent = pCurrentStudent ;
			//Current student point to next student
			pCurrentStudent = pCurrentStudent->PNextStudent ;
			free (pTempStudent) ;
		}
		//Point to Null Bc the list is empty
		gpFirstStudent = NULL ;
	}
}

void GetNode ()
{
	// Create struct to point to First student
	struct SStudent *pCurrentStudent = gpFirstStudent ;
	// Initialize counter
	unsigned int count = 1 ;

	unsigned int index ;
	char temp_text [40] ;

	DPRINTF ("\n Enter Node to Get : ") ;
	gets (temp_text) ;
	index = atoi(temp_text) ;

	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}

	// Search for selected student by looping on all record
	while (pCurrentStudent)
	{
		if (count == index)
		{
			DPRINTF ("\n The Record index %d",index) ;
			DPRINTF ("\n \t ID : %d ",pCurrentStudent->student.ID) ;
			DPRINTF ("\n \t Name : %s ",pCurrentStudent->student.name) ;
			DPRINTF ("\n \t height : %f ",pCurrentStudent->student.height) ;
		}


		pCurrentStudent = pCurrentStudent->PNextStudent ;
		count ++ ;
	}

}

void GetLength_Iterative ()
{
	// Create struct to point to First student
	struct SStudent *pCurrentStudent = gpFirstStudent ;
	// Create counter
	unsigned int count = 0 ;

	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}

	while (pCurrentStudent)
	{
		pCurrentStudent = pCurrentStudent->PNextStudent ;
		count ++ ;
	}

	DPRINTF ("\n Number of Nodes is : %d ", count) ;
}

int GetLength_Recursive (struct SStudent *pStudentNode)
{
	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}

	if (pStudentNode)
	{
		return 1 + GetLength_Recursive (pStudentNode->PNextStudent) ;
	}
	else
		return 0 ;
}

void GetNode_From_End ()
{
	// Initialize Main & Reference pointer to the beginning of the list
	struct SStudent* pMain = gpFirstStudent ;
	struct SStudent* pRef = gpFirstStudent ;
	// Initialize index to get specific Node from User
	unsigned int index ;
	char temp_text [40] ;

	DPRINTF ("\n Enter Node to Get From The End : ") ;
	gets (temp_text) ;
	index = atoi(temp_text) ;

	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}

	// Move Reference pointer from Main pointer by specific offset
	for ( ; index -- ; pRef = pRef->PNextStudent)
	{
		// Check if index out of scope
		if (pRef == NULL)
		{
			DPRINTF ("\n Out of Scope") ;
		}
	}

	//Move Main and Reference pointer one by one
	while (pRef->PNextStudent)
	{
		pMain = pMain->PNextStudent ;
		pRef = pRef->PNextStudent ;
	}
	DPRINTF ("\n The Record Index From The End ") ;
	DPRINTF ("\n \t ID : %d ",pMain->student.ID) ;
	DPRINTF ("\n \t Name : %s ",pMain->student.name) ;
	DPRINTF ("\n \t height : %f ",pMain->student.height) ;
}

void GetMiddle_Student ()
{
	// Initialize Fast & Slow pointer to the beginning of the list
	struct SStudent* pFast = gpFirstStudent ;
	struct SStudent* pSlow = gpFirstStudent ;

	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}

	// While this is condition not equal NULL
	while ( (pFast->PNextStudent) && (pFast->PNextStudent->PNextStudent) )
	{
		pFast = pFast->PNextStudent->PNextStudent ;
		pSlow = pSlow->PNextStudent ;
	}

	DPRINTF ("\n The Middle Record ") ;
	DPRINTF ("\n \t ID : %d ",pSlow->student.ID) ;
	DPRINTF ("\n \t Name : %s ",pSlow->student.name) ;
	DPRINTF ("\n \t height : %f ",pSlow->student.height) ;
}

void DetectLoop ()
{
	// Initialize Fast & Slow pointer to the beginning of the list
	struct SStudent* pFast = gpFirstStudent ;
	struct SStudent* pSlow = gpFirstStudent ;

	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}

	// While this is condition not equal NULL
	while ( (pFast->PNextStudent) && (pFast->PNextStudent->PNextStudent) )
	{
		pFast = pFast->PNextStudent->PNextStudent ;
		pSlow = pSlow->PNextStudent ;
		// Detect Closed Loop in Linked List (means Last Node not point to Null)
		if (pFast == pSlow)
			DPRINTF ("\n Loop Found ") ;
	}

	DPRINTF ("\n No Loop Found ") ;
}

void ReverseList ()
{
	// Initialize Current, Next, Previous Node
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	struct SStudent* pNext = NULL ;
	struct SStudent* pPrevious = NULL ;

	//Check list is empty
	if (gpFirstStudent == NULL)
	{
		DPRINTF ("\n Empty List ") ;
	}
	// If pCurrentStudent not equal NULL
	while (pCurrentStudent)
	{
		pNext = pCurrentStudent->PNextStudent ;
		pCurrentStudent->PNextStudent = pPrevious ;
		pPrevious = pCurrentStudent ;
		pCurrentStudent = pNext ;
	}

	// After Reverse
	gpFirstStudent = pPrevious ;
}
