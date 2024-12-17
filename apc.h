#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;


/*converting input arg string into dlist*/
void string_to_dlist(const char* str, Dlist** head, Dlist** tail);
/*prining the list*/
void print_list(Dlist *head);
/*adding to lists and storing into result list*/
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
/*insert at first in the list */
void insert_first_node(Dlist** head, Dlist** tail, int data);
/*creating the node */
Dlist * create_node(int data);

/*subtracting two lists and storing into result list*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
/*comparing the both list*/
int compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2) ;
/*multiplying two lists and storing into result list*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,  Dlist **tailR);
/*copying one list data into anothe list */
int copy(Dlist **headS, Dlist **tailS,Dlist **headD,Dlist **tailD);
/*deleting the double linked list*/
int delete_list(Dlist **head_res2,Dlist **tail_res2);
/*division of two lists and storing into result list*/
//int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
void division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);
/*converting list to string*/
void dlist_to_string(Dlist** head, Dlist** tail, char* str) ;
/*printing the result*/
void print_result(Dlist *headR);
#endif