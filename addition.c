/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	int carry=0;

	  // Initialize the result list
    *headR = NULL;
    *tailR=NULL;
	// Process both lists until both are exhausted
    
	// Process both lists until both are exhausted
    while (temp1 != NULL || temp2 != NULL || carry != 0)
	{
		//printf("Hellooo\n");
        int num1 = (temp1 != NULL) ? temp1->data : 0;
        int num2 = (temp2 != NULL) ? temp2->data : 0;
		//printf("num1:  %d  \n",num1);
		//printf("num2:  %d  \n",num2);
		//printf("carry:  %d  \n",carry);
		int res=num1+num2+carry;
	//	printf("result:  %d  \n",res);
		carry = res / 10000; 
		int digit=res%10000;
		Dlist *new=create_node(digit);

		 if (*tailR == NULL) 
		{
            // If result list is empty, initialize head and tail
            *headR = new;
            *tailR = new;
			//printf("head: %d",(*headR)->data);
		}
		else
		{
            // If list is not empty, insert at the head
            new->next = *headR;    // Point the new node's next to the current head
            (*headR)->prev = new;  // Update the previous pointer of the old head to the new node
            *headR = new;          // Update head to point to the new node
                //printf("head: %d",(*headR)->data);
		}
        // Move to the previous nodes in the input lists
        if (temp1 != NULL) 
		{
			temp1 = temp1->prev;
			//printf("hhh %p\n",temp1);
			//printf("DATA %d",temp1->data);
		}
			
        if (temp2 != NULL) 
			temp2 = temp2->prev;
	}
	printf("\n");
	

	return 0;
}


	