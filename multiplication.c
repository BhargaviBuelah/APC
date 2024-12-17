/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,  Dlist **tailR)
{
	// Initialize the result list
    *headR = NULL;
    *tailR = NULL;
	Dlist *head_res1=NULL;
	Dlist *tail_res1=NULL;
	Dlist *head_res2=NULL;
	Dlist *tail_res2=NULL;
	int count=0;
	int list_count=1;
    int zeros=1;
	// Process both lists until both reaches NULL
    /* Definition goes here */
	Dlist *temp2=*tail2;
	int carry=0;
    while (temp2 != NULL)
	{
		Dlist *head_res2=NULL;
		Dlist *tail_res2=NULL;
		*headR = NULL;
		carry=0;
        int num2 = (temp2 != NULL) ? temp2->data : 0;
        Dlist *temp1=*tail1;
		while(temp1 != NULL || carry != 0)
		{
			int num1 = (temp1 != NULL) ? temp1->data : 0;
			unsigned int  res=(num1*num2)+carry;
			carry = res / 10000; 
			int digit=res%10000;
			//Dlist *new=create_node(digit);
			if(list_count==1)					//storing result in result list 1
			{
				Dlist*new= create_node(digit);
				if(tail_res1==NULL)
				{
					tail_res1=new;
					new->prev=head_res1;
				}
				else
				{
					new->next=head_res1;
					head_res1->prev=new;
				}
				head_res1=new;
			}
			else					//storing result in result list 2
			{
				Dlist*new= create_node(digit);
				if(tail_res2==NULL)
				{
					tail_res2=new;
					new->prev=head_res2;
				}
				else
				{
					new->next=head_res2;
					head_res2->prev=new;
				}				
				head_res2=new;
			}
			if (temp1 != NULL) 		//if temp1 not equal to null moving pointer
			{
				temp1 = temp1->prev;
			}	
		} 
        if (temp2 != NULL) 				//if list 2 not equal to NULL moving pointer
			temp2 = temp2->prev;

		count++;
		list_count++;
		if(count>=2) //every 2 iterations 2 result lists  added and store in result headR
		{
			//printf("%d  \n ",count);
			//printf("---------------->>>>>>>>>>>hello\n");
			for(int i=0;i<zeros;i++)
			{
				Dlist*new= create_node(0);		//adding list last node to 0 in result 2
				new->prev=tail_res2;
				tail_res2=new;
			}
			zeros++;
			*headR = NULL;
			*tailR = NULL;
			addition(&head_res1,&tail_res1,&head_res2,&tail_res2,headR,tailR);  // adding 2 result list and storing data in result Slist
			//copying the result data into result 1;
           //print_list(head_res1);
		   //print_list(*headR);
          // printf("\n");
			if(copy(headR,tailR,&head_res1,&tail_res1)==SUCCESS)
			{
				//printf("Result copyed Suessfully\n");
				//print_list(head_res1);
               // printf("\n");
				delete_list(&head_res2,&tail_res2);
				//print_list(head_res2);
			}
		}
	 // print_list(head_res1);
	}
	if(count==1)
	return 0;
}
