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

void  BidList_InsertForward(BidList *l, int element){
	Node *aux;
	if(l->poi->prev == NULL){
		printf("\nError when inserting a new element in the back of the point of interest, we are at the end of the list");
	}else{
		aux = (Node*) malloc(sizeof(Node));
		if(aux==NULL){
			printf("Error when inserting before the point of interest");
		}else{
			aux->element = element;
			aux->foll = l->poi;
			aux->prev = l->poi->prev;
			l->poi->prev->foll = aux;
			l->poi->prev=aux; 
		}
	}
}
//Function that allows us to insert an element in front of our point of interest (x-> (poi) -> (new node)-> y)
void  BidList_InsertBefore(BidList *l, int element){
	Node *aux;
	if(l->poi->foll == NULL){
		printf("\nError when inserting a new element in the back of the point of interest, we are at the end of the list");
	}else{
		aux = (Node*) malloc(sizeof(Node));
		if(aux==NULL){
			printf("\nError when inserting before the point of interest");
		}else{
			//inserting the element
			aux->element = element;
			aux->prev = l->poi;
			aux->foll = l->poi->foll;
			l->poi->foll->prev = aux;
			l->poi->foll = aux;
		}
	}
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




