#include "BidList.h"

int main(){

	int i;
	BidList bidlist;
	//Creating the list
	bidlist= BidList_Create();
	printf("\nPrinting the elements we are inserting in the list in the order that are being inserted: \n");
	for(i=0;i<10;i++){
		//WE PRINT THIS VALUES IN ORDER TO SEE WHICH NUMBERS ARE BEING INSERTED IN THE LIST
		printf("%d ,", 9-i);
		//Inserting values to the list
		BidList_InsertSorted(bidlist, 9-i);
	}
	printf("\nPrinting the elements of our list in order. From first to last;\n");
	BidList_GoBeginning(&bidlist);
    printf("hola1");
	//avoiding the first ghost element
	//Printing the values we have inside the list, from first to last
	while(!BidList_End(bidlist)){
		//moving forward our point of interest
		BidList_Forward(&bidlist);
		//consulting the element pointed by our point of interest
		i=BidList_Check(bidlist);
		//printing the element recently consulted in the list
		printf("%d ,", i);
	}
    BidList_Destroy(&bidlist);
return 0;

}