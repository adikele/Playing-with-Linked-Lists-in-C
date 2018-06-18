This repository has two source code files. 
The files are two versions of a program with the same objective and are independent of each other. 
Version 2's output demonstrates the program's objective in a clearer manner than Version 1; so please use Version 2.
If you have any comments about the program, I am happy to have your feedback!
Aditya

version 2:
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
Works! Tested. This is the GitHub publishing version.

******************************
version 1:
dt: 11.3.16

In this program, I insert characters in a linked list in two different methods. In the first method, the new item is stored to the rear end of the linked list, and in the second method, it is stored in the front end of the list. Printing out the items stored shows the differences in the way they were stored.

In both the cases, the insertion function uses malloc () function to generate a newnode. Using malloc () function enables the program to allocate storage space as needed in response to demand.

Reviewing the two insertion functions, one notes that writing in C provides the user flexibility on filling a linked list.
