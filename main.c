/********************************************************
 * Name: N.Bhargavi
 * Date:21-11-24
 * Description:Arithmetic Precession Calculator
*********************************************************/
#include"apc.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    /* Declare the pointers */
    //Dlist *head1, *tail1, *head2, *tail2, *headR, *tailR;
    char option, operator;
	operator=argv[2][0];
    // long long int num1=atoi(argv[1]);
	// long long int num2=atoi(argv[3]);
	//printf("----->%lld\n",num1);
	//printf("----->%lld\n",num2);
		//storing operator
		/* Code for reading the inputs */
		/* Function for extracting the operator */
    Dlist *headR=NULL;
	Dlist *tailR =NULL;
    Dlist *head1=NULL;
	Dlist *tail1 =NULL;
	string_to_dlist(argv[1], &head1, &tail1);		//converting string to number and storing in linked list

    Dlist *head2=NULL;
	Dlist *tail2 =NULL;
	string_to_dlist(argv[3], &head2, &tail2);

    print_list(head1);
	print_list(head2);

    switch (operator)
	{
			case '+':
				/* call the function to perform the addition operation */
				addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				//print_list(headR);
				printf("Result : ");
				print_result(headR);
				break;
            case '-':	
				/* call the function to perform the subtraction operation */
				int val=compare(&head1,&tail1,&head2,&tail2);
				if(val == -1)		//(h1>h2)
				{
					printf("Result :");
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					//print_list(headR);
					print_result(headR);
				}
				else if (val == 1)	//(h1<h2)
				{
					printf("Result :%c",'-');
					subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
					//print_list(headR);
					print_result(headR);
				}
				else
				{
					printf("Result : 0");
				}				
				break;
            case 'x':	
				/* call the function to perform the multiplication operation */
				multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				//print_result(headR);
				printf("Result : ");
				print_result(headR);
				break;

			case '/':	
				/* call the function to perform the division operation */
				val=compare(&head1,&tail1,&head2,&tail2);
				if(val == -1)		//(h1>h2)
				{
					//printf("Result :\n");
					division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					printf("Result : ");
					print_result(headR);
				}
				else if (val == 1)	//(h1<h2)
				{
					printf("Result : 0");
				}
				else
				{
					printf("Result : 1");
				}
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
    }
}