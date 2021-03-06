//DEFINING OUR LIBRARY
#ifndef _BidList_H
#define _BidList_H

//CONSTANTS
#define error_value -500

//System libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Own types
typedef struct x{
    int element;
    struct x *foll;
    struct x *prev;
}Node;
typedef struct{
    Node *head;
    Node *tail;
    Node *poi; //point of interest
}BidList;

//Functions and procedures 
BidList  BidList_Create();
void  BidList_InsertSorted(BidList l, int element);
int  BidList_Check(BidList l);
void  BidList_Delete(BidList *l);
void  BidList_Forward(BidList *l);
void  BidList_Backwards(BidList *l);
void BidList_GoBeginning(BidList*l);
void BidList_GoEnd(BidList *l);
int BidList_End(BidList l);
int BidList_Empty(BidList l);
void BidList_Destroy(BidList *l);
#endif