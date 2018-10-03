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
		l.poi = l.head;
	}

}

void  BidList_InsertSorted(BidList l, int element){
	Node* aux, *tmp;
	aux= (Node*)malloc(sizeof(Node));
	if(aux==NULL){
		printf("\nError when inserted sorted!");
	}else{
		aux->e=element;
		tmp=l.poi // we copy our point of interest
		l.poi= l.head;
		/*we move through our list while our element to be inserted is greater than the element pointed by our point of interest
		and also, while our point of interest is not pointing at the end of our list */
		while(l.poi->foll->element < element && l.poi->seg!= l.tail){
			l.poi= l.poi->seg
		}
		aux->seg=l.poi->seg;
		aux->prev=l.poi;
		l.poi->seg= aux;
		l.poi=tmp; //we reestablish our original point of interest
	}//else
}

//Checks our element located in the Node pointed by our point of interest
int  BidList_Check(BidList l){
	int element = error_value;
	//Checking if it's not an empty list
	if(l.poi != l.head && l.head != l.tail){
		element = l.poi->e;
	}else{
		//Error message, list empty
		printf("\nError when consulting, the list is empty");
	}
	return element;
}
//This function allows us to delete our point of interest
void  BidList_Delete(BidList *l){
	Node *aux;
	//Making sure we are not at the beginnig or at the end of our list
	if(l.poi != l.head && l.head != l.tail){
		//Assigning our auxiliar value to the point of interest
		aux= l->poi;
		//Assigning the previous node to point at the next node of our point of interest
		l->poi->prev->foll= l->poi->foll;
		//Assigning the following node to point at the previous Node of our point of interest
		l->poi->foll->prev= l->poi->prev;
		//Assigning our new point of interest
		l->poi = l->poi->seg;
		//Deleting our old point of interest
		free(aux);
	}else{
		printf("\nError when deleting, the point of interest is at the beginning or at the end of the list ");
	}
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




