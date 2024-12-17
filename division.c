/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
	unsigned long int count =0;
	while(compare(head1,tail1,head2,tail2)<=0)
	{
       
        //     printf("list1 : ");
        //         print_list(*head1);
        //         sleep(1);
        // // printf("-------hiiii\n");
        // printf("list2 : ");
        //     print_list(*head2);
        //       sleep(1);
            subtraction(head1,tail1,head2,tail2,headR,tailR);
          // print_list(*headR);
           // sleep(1);
            delete_list(head1,tail1);

            //print_result(*headR);
            copy(headR,tailR,head1, tail1);
            // printf("new head1 : ");
            // print_list(*head1);
            //print_list(*head1);
            count++;
	}
	printf("Result : %lu \n",count);
}
*/
void division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
    /* temp1 pointer initialised to point head1 */
    Dlist *temp1=*head1;
    /* temp2 pointer initialised to point head2 */
    Dlist *temp2=*head2;
    /* res variable declared and c variable initialised to zero*/
    int res,c=0;
    /* num1 and num2 variable initialised */
    long long int num1=0,num2=0;
    /* run the loop till temp1 reachs NULL */
    while(temp1!=NULL)
    {
        /* extracting first operand value and storing in num */
        num1=num1*10000+temp1->data;
        /* updating temp1 */
        temp1=temp1->next;
    }
    /* run the loop till temp1 reachs NULL */
    while(temp2!=NULL)
    {
        /* extracting first operand value and storing in num */
        num2=num2*10000+temp2->data;
        /* updating temp1 */
        temp2=temp2->next;
    }
    /* check is first operand is zero */
    if(num2==0)
    {
        /* prinitng error message */
        printf("Division by zero is not permitted\n");

        return;
    }
    /* run the loop till num1 is greater equal to num2*/
    while(num1>=num2)
    {
        /* performing subtraction operation */
        num1=num1-num2;
        /* incrementing c */
        c++;
    }
    /* calling inser_first function to store resultant in double list */
    insert_first_node(headR,tailR,c);
}