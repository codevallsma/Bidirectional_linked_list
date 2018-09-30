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
			printf("Error when inserting before the point of interest");
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




