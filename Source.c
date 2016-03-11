/* 
Copyright Aditya Kelekar

PROGRAM OBJECTIVE: 
Inserting characters in a linked list in two different ways.

DESIRED OUTPUT:
Input ten chracters; the program will reverse the later five characters.

EXPLANATION:
The first five elements are scanned in a way that the new data is pushed to the end of the list.
The next five elements are scanned in a way that the new data is pushed to the front of the list.

STATUS OF PROGRAM:
Working. Input 1234512345 gives ouput 5 4 3 2 1 1 2 3 4 5
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char Titem;

// Interface of list
typedef struct node *Tpointer;  // Tpointer is a pointer to a "node" structure
typedef struct node {
    Titem item;
    Tpointer next;
} Tnode;


typedef Tpointer Tlist;  
void initialize_list (Tlist *list);
void insert_to_list_end(Tlist *list, Titem data);
void insert_to_list_front(Tlist *list, Titem data);
void print_list (Tlist list);
void cleanup_list(Tlist *list);

// Application
int main (void)  {
    Tlist list;
	Titem x1, x2, x3, x4, x5;

    initialize_list(&list);
	
	printf("\nThe user has to input ten chracters; the program will reverse the later five characters");
	
	printf ("\nEnter ten characters and press enter...\n"); 		
	//scan the first five elements such that the new data is pushed to the end of the list
	scanf ("%1c", &x1);
    insert_to_list_end(&list, x1);

    scanf ("%1c", &x2);
    insert_to_list_end(&list, x2);

	scanf ("%c", &x3);
    insert_to_list_end(&list, x3);

	scanf ("%c", &x4);
    insert_to_list_end(&list, x4);

	scanf ("%c", &x5);
    insert_to_list_end(&list, x5);
	
	//scan the next five elements such that the new data is pushed to the front of the list
	scanf ("%1c", &x1);
    insert_to_list_front(&list, x1);

    scanf ("%1c", &x2);
    insert_to_list_front(&list, x2);

	scanf ("%c", &x3);
    insert_to_list_front(&list, x3);

	scanf ("%c", &x4);
    insert_to_list_front(&list, x4);

	scanf ("%c", &x5);
    insert_to_list_front(&list, x5);

    print_list(list);
    fflush(stdin); getchar();
}



void initialize_list (Tlist *list) 
{
*list = NULL;
}


void insert_to_list_end(Tlist *list, Titem data) 
	//Create a newnode and push it to the end of the list
	// First, memory is created for the new node and then the item passed as parameter is saved in it
	// The (newnode - 1) element should have newnode's address
	// Newnode's next should have NULL address;
{   
	Tpointer newnode; 
	Tpointer last;
	newnode = (Tpointer) malloc(sizeof(Tnode));
	newnode -> item = data;
	last = *list;  //initialize "last" pointer to point to the beginning of the list

if (*list == NULL)  //if the "list" passsed to the insert function was an empty list:
{ 
	*list = newnode; //the beginning of the list is being defined; the "newnode" pointer is being tied to the list  
	//since "list" was passed to the function as a pointer, this same pointer will be used for the rest of the program 
}

else //if the "list" passsed to the insert function had atleast one node in it:
{
	while (last->next != NULL) // move the "last" pointer down the list to point to the last element
	{
		last = last->next;
	} //now the "last" pointer's "next" element has NULL
	last -> next = newnode;  // the "newnode" pointer is being tied to the list  	
}

newnode -> next = NULL; //the element pointed to by "newnode" is made the last element
}


void insert_to_list_front(Tlist *list, Titem data) 
// Insertion happens at the head of the list; earlier elements are pushed behind 
{
    
    Tpointer newnode;
    newnode = (Tpointer) malloc(sizeof(Tnode));
    newnode -> item = data;

    if (*list == NULL)
	    newnode -> next = NULL;       //if the "list" passsed to the insert function was an empty list:
    else
	    newnode -> next = *list;  //put the address of the old "list" to the newnode's "next" element

     *list = newnode;  //address of "list" is changed so that the address of the "newnode" is the new address of the list
	 //that is, "newnode" is the new address of the list
}



void print_list (Tlist list) {
    Tpointer what;

    printf("\nList of input characters:");
	printf("\n The first five characters you get them last but you get them straight,");
	printf("\n The next five characters you get first, but you get them reversed!\n ");
    what = list;
    while (what->next != NULL) {
    printf("%c ", what->item);	    
	    what = what->next;
    }
    printf("%c ", what->item);
}


