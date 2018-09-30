/****************************************************************************************************************************************************
 * FUNCTIONALITY: Giving the user all the functionalities for creating, modifying and destroying a Bidirectional linked list with a point of interest.
   The element of the list is an integer.
 * AUTHOR: Eric Vallsmadella
 * CREATION DATE: 6/05/2018
 * LAST MODIFICATION: 10/05/2018
 ***************************************************************************************************************************************************/
#include "BidList.h"

//This is the function that allows us to create a bidirectional linked list
BidList  BidList_Create(){
	BidList l;
	//Asking for memory
	l.head = (Node*) malloc(sizeof(Node));
	l.tail = (Node*) malloc(sizeof(Node));

	//Checking if the memory is correctly assigned
	if(l.head == NULL || l.tail == NULL){
		printf("\nThere's an error when creating the list");
	}else{
		//Making the assignments of each field in order to get a bidirectional linked list
		l.head->prev = NULL;
		l.head->foll = l.tail;
		l.tail->foll= NULL;
		l.tail->prev = l.head;
	}

}

void  BidList_InsertFoward(BidList *l, int element){

}
void  BidList_InsertBefore(BidList *l, int element){

}
int  BidList_Check(BidList l){

}
void  BidList_Delete(BidList *l){

}
void  BidList_Forward(BidList *l){

}
void  BidList_Backwards(BidList *l){

}
void BidList_GoBeginning(BidList*l){

}
void BidList_GoEnd(BidList *l){

}
int BidList_End(BidList){

}
int BidList_Empty(BidList){

}
void BidList_Destroy(BidList *l){

}




