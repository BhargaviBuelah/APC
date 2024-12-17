#include "apc.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

// Function to convert a string to 4-digit integers stored in a doubly linked list
void string_to_dlist(const char* str, Dlist** head, Dlist** tail) {
    int length = strlen(str);
    
    // Process the string in chunks of up to 4 digits
    for (int i = length; i > 0; i -= 4) {
        int start = (i - 4 < 0) ? 0 : i - 4; // Ensure the start index does not go negative
        char temp[5]; // Temporary string to hold up to 4 digits
        strncpy(temp, str + start, i - start); // Copy up to 4 digits from the string
        temp[i - start] = '\0'; // Null-terminate the string
         
        int value = atoi(temp); // Convert to integer
        insert_first_node(head, tail, value); // Append the value to the doubly linked list
    }
}

// Function to append a node to the doubly linked list
void insert_first_node(Dlist** head, Dlist** tail, int data) {
    Dlist* new_node = create_node(data);
    if (*tail == NULL) 
	{
        *tail = new_node; // If the list is empty
		*head=new_node;
       
    } 
	else 
	{
        new_node->next = *head; // Set the previous tail to new node
        (*head)->prev = new_node; // Link the old tail to new node
		*head=new_node;
        
    }
}
void print_list(Dlist *head)
{
		/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
		printf("Head -> ");
		while (head)		
		{
				/* Printing the list */
				printf("%d <-", head -> data);

				/* Travering in forward direction */
				head = head -> next;
				if (head)
					printf("> ");
			}
			printf(" Tail\n");
	}
}

Dlist * create_node(int data)
{
	Dlist *new= malloc(sizeof(Dlist));
	if(new==NULL)
	{
		printf("Memory allocation Failled\n");
		return 0;
	}
	new->data=data;
	new->next=NULL;
	new->prev=NULL;
	return new;
}
int compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2) 
{
   // printf("inside compare function\n");
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    int l1count = 0;
    int l2count = 0;
    int flag1=1;
    int flag2=1;

    // Count the lengths and compare nodes in one pass
/*
    if((*tail1)->data<1000)
    {
        char str[200];
        //convert to string and again do slising
         dlist_to_string(head1, tail1,str);
      
       delete_list(head1, tail1);
        string_to_dlist(str, head1, tail1);
    }  */
    while (temp1 != NULL || temp2 != NULL) {
        if (temp1 != NULL) 
        {
            if(flag1)
            {
                flag1=0;
                if(temp1->data==0)
                {
                    //deleting node;
                    Dlist *t=temp1;
                    temp1 = temp1->next;
                    free(t);
                }
                else
                {
                    l1count++;
                    temp1 = temp1->next;
                }
            }
            else
            {
                l1count++;
                temp1 = temp1->next;
            }
        }
        if (temp2 != NULL) {
             if(flag2)
            {
                flag2=0;
                if(temp2->data==0)
                {
                    //deleting node;
                    Dlist *t=temp2;
                    temp2 = temp2->next;
                    free(t);
                }
                else
                {
                    l2count++;
                    temp2 = temp2->next;
                }
            }
            else
            {
                l2count++;
                temp2 = temp2->next;
            }
        }
    }

    // Compare lengths first
    if (l1count > l2count)
        return -1;   // head1 is greater
    else if (l1count < l2count)
        return 1;  // head2 is greater

    // Lengths are equal, compare digit by digit
    temp1 = *head1;
    temp2 = *head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data > temp2->data)
            return -1;   // head1 is greater
        else if (temp1->data < temp2->data)
            return 1;  // head2 is greater
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;  // They are equal
}

// Function to convert a doubly linked list to a string
void dlist_to_string(Dlist** head, Dlist** tail, char* str) {
    // Ensure the string starts empty
    str[0] = '\0';

    // Traverse the list from head to tail
    Dlist* current = *head;
    while (current != NULL)
    {
        // Convert the current node's data to a string
        char buffer[10]; // Buffer to hold the integer as a string (assuming integers are less than 10 digits)
        sprintf(buffer, "%d", current->data);

        // Append the string representation of the data to the result string
        strcat(str, buffer);
        // Move to the next node
        current = current->next;
    }
    printf("---------->%s\n",str);
}


int copy(Dlist **headS, Dlist **tailS, Dlist **headD, Dlist **tailD)
{
    // Check if the singly linked list is empty
    if (*headS == NULL) {
        printf("The singly linked list is empty.\n");
        return FAILURE;
    }

    // Initialize the head of the doubly linked list
    *headD = NULL;
    *tailD = NULL;

    // Pointer to traverse the singly linked list
    Dlist *currentlist = *headS;

    // Traverse the singly linked list and copy elements to Dlist
    while (currentlist != NULL) {
        // Create a new node for the doubly linked list
        Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return FAILURE; // Return failure if memory allocation fails
        }

        // Copy data from Slist to Dlist
        newNode->data = currentlist->data;
        newNode->next = NULL;
        newNode->prev = NULL; // Initialize the prev pointer to NULL

        // If headD is NULL, this is the first node
        if (*headD == NULL) {
            *headD = newNode; // Set head of Dlist to the new node
            *tailD = newNode; 
        } else {
            (*tailD)->next = newNode; // Link the new node to the last node
            newNode->prev = *tailD;   // Set the previous pointer of the new node
            *tailD = newNode;         // Update the tail pointer to the new node
        }

        // Move to the next node in the singly linked list
        currentlist = currentlist->next;
    }

    return SUCCESS; // Return success after copying all elements
}

int delete_list(Dlist **head_res2, Dlist **tail_res2)
{
    if (*head_res2 == NULL)
        return SUCCESS;
    
    Dlist *temp = *head_res2;
    Dlist *t = temp;
    while (temp != NULL)
    {
        temp = temp->next;
        free(t);
        t = temp;
    }
    *head_res2 = NULL;
    *tail_res2 = NULL;
    return SUCCESS;
}


void print_result(Dlist *headR)
{
	if (headR == NULL)                   /*If list is empty*/
	{
		printf("IN List is empty\n");
	}
    else
    {
	    while (headR)                    /*printing the elements untill reach NULL*/		
	    {

			if(headR->data==0)
			{
				printf("000%d", headR -> data);
			}
			else if(headR->data<=9)
			{
				printf("000%d", headR -> data);
			}
			else if(headR->data<=99)
			{
				printf("00%d", headR -> data);
			}
			else if(headR->data<=999)
			{
				printf("0%d", headR -> data);
			}
			else
			{
				 printf("%d", headR -> data);
			}	   
		    headR = headR -> next;
	    }
    }
    printf("\n");
}