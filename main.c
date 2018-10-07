#include "BidList.h"

int main(){

	int i;
	BidList bidlist;
	//Creating the list
	bidlist= BidList_Create();

	//INSERTING PARAMETERS
	printf("\nPrinting the elements we are inserting in the list in the order that are being inserted: \n");
	for(i=0;i<10;i++){
		//WE PRINT THIS VALUES IN ORDER TO SEE WHICH NUMBERS ARE BEING INSERTED IN THE LIST
		printf("%d ,", 9-i);
		//Inserting values to the list
		BidList_InsertSorted(bidlist, 9-i);
	}
	//PRINTING THE LIST
	printf("\nPrinting the elements of our list in order. From first to last;\n");
	BidList_GoBeginning(&bidlist);
	//Printing the values we have inside the list, from first to last
	while(!BidList_End(bidlist)){
		//consulting the element pointed by our point of interest
		i=BidList_Check(bidlist);
				//moving forward our point of interest
		BidList_Forward(&bidlist);
		//printing the element recently consulted in the list
		printf("%d ,", i);
	}
	//checking the last element
	i=BidList_Check(bidlist);
	printf("%d ,", i);

	//now our point of interest is going to point to the first element of the array
	BidList_GoBeginning(&bidlist);
	printf("\n\nNow our point of interest is pointing to the first element of our list, a 0, and the list shows it's a %d", BidList_Check(bidlist));
	//now our point of interest is going to point to the last element of the array
	BidList_GoEnd(&bidlist);
	printf("\n\nNow the last element of the list is an 9, and the list shows it's an %d", BidList_Check(bidlist));
	//and if we move our point of interest one position backwards it is now pointing to the node that contains the number 7
	BidList_Backwards(&bidlist);
	printf("\n\nNow our point of interest is pointing behind the previous point of interest, to the number 8, and the list shows the number %d", BidList_Check(bidlist));
	//deleting our point of interest, which is now located at the node that contains the number 8
	BidList_Delete(&bidlist);
	//showing the element pointed by our point of interest
	printf("\n\nNow we've deleted the number 8, now we are back pointing at number 9, and the list shows the number is a %d", BidList_Check(bidlist));

//PRINTING THE LIST
	printf("\n\nPrinting the elements of our list in order. We can see that the deleted number 8 doesn't appear in the list;\n");
	BidList_GoBeginning(&bidlist);
	//Printing the values we have inside the list, from first to last
	while(!BidList_End(bidlist)){
		//consulting the element pointed by our point of interest
		i=BidList_Check(bidlist);
				//moving forward our point of interest
		BidList_Forward(&bidlist);
		//printing the element recently consulted in the list
		printf("%d ,", i);
	}
	//checking the last element
	i=BidList_Check(bidlist);
	printf("%d \n\n,", i);
    BidList_Destroy(&bidlist);
return 0;

}