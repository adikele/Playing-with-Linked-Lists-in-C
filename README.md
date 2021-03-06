This repository has two source code files. 
The files are two versions of a program with the same objective and are independent of each other. 
Version 2's output demonstrates the program's objective in a clearer manner than Version 1; so please use Version 2.

Other files:
1. Logical steps for insert_to_list_end function along with diagram to illustrate the insertion of a “newnode” in a list 
2. Flowchart of the "version 2" program
3. Screenshots of the display during a sample test run

If you have any comments about the program, I am happy to have your feedback!
Aditya

********************************
Notes for version 2 "Source-LinkedListApplication-v02.cpp":
dt: 15.6.18

PROGRAM OBJECTIVE:
Inserting characters in a linked list in two different ways to achieve reversal of a list of characters.

DESIRED OUTPUT:
Input the order for the desired display of characters (same order series or reverse order series).
Then, input a series of five characters.
The program should output the characters, in the series type desired by the user.
After processing a series of characters, program should ask for a new series of characters and display it; this should continue until the user quits.

EXPLANATION AND FEATURES:
Program uses a linked list to store and (later) display entered characters in one of the two "series order":
(i) same order as entered
(ii) reverse order
Characters are inserted in the linked list in one of the two ways: insert-to-front-end and insert-to-rear-end.
Dynamic memory is allocated to save entered characters; memory is freed after characters are displayed.
User-entered "series order" choice for display of characters is validated; if data is invalid, user is asked to enter choice again.

POSSIBILE USE:
As a part of a bigger library that needs a linked list structure to save and process data.

STATUS OF PROGRAM:
Works! Tested 2-5 times with valid and invalid data. This is the GitHub publishing version.

******************************
Notes for version 1 "Source.c":
dt: 11.3.16

In this program, I insert characters in a linked list in two different methods. In the first method, the new item is stored to the rear end of the linked list, and in the second method, it is stored in the front end of the list. Printing out the items stored shows the differences in the way they were stored.

In both the cases, the insertion function uses malloc () function to generate a newnode. Using malloc () function enables the program to allocate storage space as needed in response to demand.
