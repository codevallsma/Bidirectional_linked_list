/****************************************************************************************************************************************************
 * FUNCTIONALITY: Giving the user all the functionalities for creating, modifying and destroying a Bidirectional linked list with a point of interest.
   The element of the list is an integer.
 * AUTHOR: Eric Vallsmadella
 * CREATION DATE: 6/05/2018
 * LAST MODIFICATION: 10/05/2018
 ***************************************************************************************************************************************************/
#include "BidList.h"

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
    return l;
}

void  BidList_InsertSorted(BidList l, int element){
	Node* aux, *tmp;
	aux= (Node*)malloc(sizeof(Node));
	if(aux==NULL){
		printf("\nError when inserted sorted!");
	}else{
		
		aux->element=element;
		tmp=l.poi; // we copy our point of interest
		l.poi= l.head;

		/*we move through our list while our element to be inserted is greater than the element pointed by our point of interest
		and also, while our point of interest is not pointing at the end of our list */
        if(l.poi->foll!= l.tail){
            while(l.poi->foll!= l.tail && l.poi->foll->element < element ){
                l.poi= l.poi->foll;
            }
        }

		aux->foll=l.poi->foll;
		aux->prev=l.poi;
		l.poi->foll= aux;
		l.poi=tmp; //we reestablish our original point of interest

	}//else
}

//Checks our element located in the Node pointed by our point of interest
int  BidList_Check(BidList l){

	int element = error_value;
	//Checking if it's not an empty list
	if(l.poi != l.head && l.head != l.tail){
		element = l.poi->element;
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
	if(l->poi != l->head && l->head != l->tail){
		//Assigning our auxiliar value to the point of interest
		aux= l->poi;
		//Assigning the previous node to point at the next node of our point of interest
		l->poi->prev->foll= l->poi->foll;
		//Assigning the following node to point at the previous Node of our point of interest
		l->poi->foll->prev= l->poi->prev;
		//Assigning our new point of interest
		l->poi = l->poi->foll;
		//Deleting our old point of interest
		free(aux);
	}else{
		printf("\nError when deleting, the point of interest is at the beginning or at the end of the list ");
	}
}

void  BidList_Forward(BidList *l){

	//checking if our point of interest it's not located at the end of the list
	if(l->poi->foll==l->tail){
        printf("\nError, your point of interest is at the end of the list");
    }else{
    	//Pointing our point of interest to the next position
        l->poi= l->poi->foll;
    }
}

void  BidList_Backwards(BidList *l){
	//checking if our point of interest it's not located at the beggining of the list
	if(l->poi->prev==l->head){
        printf("\nError, your point of interest is at the beggining of the list");
    }else{
    	//Pointing our point of interest to the previous position
        l->poi= l->poi->prev;
    }
}

void BidList_GoBeginning(BidList*l){
	l->poi = l->head;
}

void BidList_GoEnd(BidList *l){
	l->poi = l->tail;
}

int BidList_End(BidList l){
	return l.poi->foll == l.tail;
}

int BidList_Empty(BidList l){
	return l.head->foll == 	NULL;
}

void BidList_Destroy(BidList *l){
	
	Node *aux;
	//we erase every node pointed by our head untill we erase the last node of the list (included)
    while(l->head!=NULL){
    	//assigning our head to an auxiliar variable
        aux= l->head;
        //we move forward our head one position
        l->head= l->head->foll;
        //we free the node pointed by our aux variable
        free(aux);
    }
}




