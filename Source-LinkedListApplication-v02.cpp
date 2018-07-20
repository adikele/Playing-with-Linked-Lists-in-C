/*
By Aditya Kelekar
dt: 15.6.18
PROGRAM OBJECTIVE:
Inserting characters in a linked list in two different ways to achieve reversal of a list of characters.

DESIRED OUTPUT:
Input the order for the desired display of characters (same order series or reverse order series).
Then, input a series of five characters.
The program should output the characters, in the series type desired by the user.
After processing a series of characters, program should ask for a new series of characters and display it; this should continue until the user quits.

EXPLANATION:
Program uses a linked list to store and (later) display entered characters in one of the two "series order":
(i) same order as entered
(ii) reverse order
Characters are inserted in the linked list in one of the two ways: insert-to-front-end and insert-to-rear-end.
Dynamic memory is allocated to save entered characters; memory is freed after characters are displayed.
User-entered "series order" choice for display of characters is validated; if data is invalid, user is asked to enter choice again.

POSSIBILE USE:
As a part of a bigger library that needs a linked list structure to save and process data.

STATUS OF PROGRAM:
Works! Tested with 3-5 samples. This is the GitHub publishing version.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 15

typedef char Titem;

// Interface of list
typedef struct node *Tpointer;  // Tpointer is a pointer to a "node" structure
typedef struct node {
	Titem item;
	Tpointer next;
} Tnode;

typedef Tpointer Tlist;

void initialize_list(Tlist *pList);
void insert_to_list_end(Tlist *pList, Titem data);
void insert_to_list_front(Tlist *pList, Titem data);
void print_list(Tlist list);
void cleanup_list(Tlist *pList);
void delete_list(Tlist *pList);

// Main
int main(void)  {
	Tlist list;
	Titem x1, x2, x3, x4, x5, charOrder;
	char buf[MAX];

	//initialize_list(&list); // set1 -- this code can be used for testing if an initialized list prints OK
	//printf("Printing an initialized list: "); // set1
	//print_list(list); // set1

	printf("Program displays entered characters according to user requirements.\n");
	printf("Options are: (i)same order or (ii)reverse order.\n\n");
	printf("In which order would you want characters displayed?\n");
	printf("Enter 'S' for same order, 'R' for reverse order, 'Q' to Quit\n");

	while (1)
	{	
		fgets(buf, MAX, stdin);
		sscanf(buf, "%c", &charOrder);
		while (1)
		{
			if ((charOrder == 'S') || (charOrder == 'R') || (charOrder == 'Q'))
				break;  //if valid data, move to process data
			fflush(stdin);
			printf("\nInvalid choice of character order. Please enter choice again.\n");
			fgets(buf, MAX, stdin);
			sscanf(buf, "%c", &charOrder);
		}

		if (charOrder == 'Q')
			break;

		initialize_list(&list);
		if (charOrder == 'S') // scan five characters such that the latest entered character is pushed to the rear end of the list
		{
			printf("\nEnter five characters and press enter...\n");
			fflush(stdin);

			scanf("%1c", &x1);
			insert_to_list_end(&list, x1);

			scanf("%1c", &x2);
			insert_to_list_end(&list, x2);

			scanf("%c", &x3);
			insert_to_list_end(&list, x3);

			scanf("%c", &x4);
			insert_to_list_end(&list, x4);

			scanf("%c", &x5);
			insert_to_list_end(&list, x5);
		}

		else
			if (charOrder == 'R') // scan five characters such that the latest entered character is pushed to the front of the list
			{
				printf("\nEnter five characters and press enter...\n");
				fflush(stdin);
				scanf("%1c", &x1);
				insert_to_list_front(&list, x1);

				scanf("%1c", &x2);
				insert_to_list_front(&list, x2);

				scanf("%c", &x3);
				insert_to_list_front(&list, x3);

				scanf("%c", &x4);
				insert_to_list_front(&list, x4);

				scanf("%c", &x5);
				insert_to_list_front(&list, x5);
			}

		if (charOrder == 'S')
		{
			printf("\nList of input characters in normal order:\n");
		}
		else
		{
			printf("\nList of input characters in reverse order:\n");
		}

		print_list(list);
		delete_list(&list);
		printf("\nLIST IS DELETED\n");
		printf("****************************\n\n");

		fflush(stdin);
		printf("Program displays entered characters according to user requirements. \n");
		printf("Options are: (i)same order or (ii)reverse order.\n\n");
		printf("In which order would you want characters displayed? \n");
		printf("Enter 'S' for same order, 'R' for reverse order, 'Q' to Quit\n");
	}
	return 0;
}

void initialize_list(Tlist *pList)
{
	*pList = NULL;
}

void insert_to_list_end(Tlist *pList, Titem data)
//Create a newnode and push it to the end of the list
// First, memory is created for the new node and then the item passed as parameter is saved in it
// The (newnode - 1) node should have newnode's address
// Newnode's "next" element should have NULL address;
{
	Tpointer newnode;
	Tpointer last;
	newnode = (Tpointer)malloc(sizeof(Tnode));
	newnode->item = data;
	last = *pList;  //initialize "last" pointer (which should point to a node) to point to the beginning of the list

	if (*pList == NULL)  //if the "list" passsed to the insert function was an empty list:
	{
		*pList = newnode; //the beginning of the list is being defined; the "newnode" pointer is being tied to the list  
		//since "list" was passed to the function as a pointer, this same pointer will be used for the rest of the program 
	}

	else //if the "list" passsed to this insert_to_list_end function had atleast one node in it:
	{
		while (last->next != NULL) // move the "last" pointer down the list to point to the last node
		{
			last = last->next;
		} //now the "last" pointer's "next" element has NULL

		last->next = newnode;  // the "newnode" pointer is being tied to the list  	
	}

	newnode->next = NULL; //the node pointed to by "newnode" is made the last node
}

// Insertion happens at the head of the list; earlier elements are pushed behind 
void insert_to_list_front(Tlist *pList, Titem data)
{
	Tpointer newnode;
	newnode = (Tpointer)malloc(sizeof(Tnode));
	newnode->item = data;

	if (*pList == NULL)
		newnode->next = NULL;       //if the "list" passsed to the insert function was an empty list:
	else
		newnode->next = *pList;  //put the address of the old "list" to the newnode's "next" element

	*pList = newnode;  //address of "list" is changed so that the address of the "newnode" is the new address of the list
	//that is, "newnode" is the new address of the list
}

//If an empty, unititialized list is printed, it is an error
void print_list(Tlist list) {
	Tpointer what;
	what = list;
	if (list == NULL)
	{
		printf("Empty list\n");
		return;
	}
	while (what->next != NULL) {
		printf("%c ", what->item);
		what = what->next;
	}
	printf("%c ", what->item);
}

void delete_list(Tlist *pList)
{
	Tpointer aux, auxDASHINGAHEAD;

	aux = *pList;  //initialize "aux" pointer (which should point to a node) to point to the beginning of the list

	if (*pList == NULL)  //if the "list" passed to the delete_list function was an empty list:
	{
		printf("\nList was Empty.. Nothing to Delete!");
	}

	else //if the "list" passsed to the delete_list function had atleast one node in it:
	{
		while (aux->next != NULL)
			//while the last node is not yet reached ..
		{
			auxDASHINGAHEAD = aux->next;
			free(aux);  // the "pointerD node" pointer is being freed
			aux = auxDASHINGAHEAD;
		} //now the "aux" pointer's "next" element has the address to the last node 
		free(aux);  // free the last node
	}
}


