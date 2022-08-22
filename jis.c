/*
Example of a linked list of strings
*/

#include <stdio.h>
#include <stdlib.h> //has functions malloc() and free()
#include <string.h>

#define MAX 50  //maximum characters in the word
#define QUIT "quit" //end the loop

/*
A self-referential structures contains a pointer
that points to another structure of the same type
and link together to form dynamic data structures.
data: stores a word (string)
next: is a pointer to the next node
*/int CIN=10000;
struct node{
   char data[MAX];
   char address[MAX];
   char type[MAX];
   char date[MAX];
   char place[MAX];
   char officer[MAX];
   char datearrest[MAX];
   int cin;
   struct node *next;
};

//type definition for "new" data types
typedef struct node Node;
typedef struct node* NodePointer;

//function prototypes
void insertIntoLinkedList(char [],char [],char [],char [],char [],char [],char [],int, NodePointer *);
void displayLinkedList(NodePointer);
void deleteFromLinkedList(char [], NodePointer *);

/*
main method - asks the user to enter a word,
and inserts the word into a linked list in alphabetical order,
and deletes words at the user's request.
*/
/*int main(){
//stores each word
   char word[MAX]={'\0'};
//stores a pointer to the 1st node in the linked list
   NodePointer head = NULL;

//keep inserting until user enters "quit"
   while(0 != strcmp(word, QUIT)){
      printf("Enter a word to INSERT into linked list (enter \"%s\" to quit): ", QUIT);
      scanf("%s",word);
      if(0 != strcmp(word, QUIT)){
      //&head: send the address of the pointer to the 1st node in list
         insertIntoLinkedList(word, &head);
         displayLinkedList(head);
      }
   }//end of while
   */

//keep deleting until user enters "quit"
   //strncpy(word, "don't quit", MAX);
   //printf("\n");
   //while(0 != strcmp(word, QUIT) && NULL != head){
    //  printf("Enter a word to DELETE from linked list (enter \"%s\" to quit): ", QUIT);
     // scanf("%s",word);
      //if(0 != strcmp(word, QUIT)){
       //  deleteFromLinkedList(word, &head);
        // displayLinkedList(head);
     // }
   //}

   //return 0;
//}//end of main

/*
Inserts a word in alphabetical order into a linked list
word2: is a string
head2: is the a pointer to the 1st node in a linked list
This parameter is a pointer to a pointer,
because we are passing the address of the linked list to the function,
and the linked list itself is a pointer to the 1st node in the list.
*/
void insertIntoLinkedList(char word2[],char word3[],char word4[],char word5[],char word6[],char word7[],char word8[],int number,NodePointer *head2){
//pointer to a new node to be inserted into linked list
   NodePointer newNode = NULL;
//pointer to the previous node in the linked list
   NodePointer previous = NULL;
//pointer to the current node in the linked list
   NodePointer current = *head2;

//create a node on the heap
   newNode = malloc(sizeof(Node));
/*
check to see if space is available
if no space on heap, malloc() will return NULL
*/
   if(NULL != newNode){
   //copy over word to the node
      strcpy(newNode->data, word2);
      strcpy(newNode->address, word3);
      strcpy(newNode->type, word4);
      strcpy(newNode->date, word5);
      strcpy(newNode->place, word6);
      strcpy(newNode->officer, word7);
      strcpy(newNode->datearrest, word8);
      newNode->cin=number;

   //figure out where to insert in linked list
      while(NULL != current && strcmp(word2, current->data)>0){
      //move previous to current
         previous = current;
      //move current to next node
         current = current->next;
      }//end of while
      //insert at beginning of linked list
      if(NULL == previous){
         newNode->next = current;
         //change the address stored in head
         *head2 = newNode;
      }//end of if
      else{
      //insert between previous and current
         previous->next = newNode;
         newNode->next = current;
      }//end of else
   }//end of if
}//end of function


//displays the linked list
void displayLinkedList(NodePointer current){
   //for empty list
   if(NULL == current){
      printf("The linked list is empty!\n\n");
      return;
   }
   printf("\n>>>>>> Case Details <<<<<<<<<");
   //loop through list
   while(NULL != current){
   //display each node
      printf("\n> DEFENDANT:   %s \n", current->data);
      printf("> DEFENDANT ADDRESS:   %s \n", current->address);
      printf("> CASE TYPE:    %s \n", current->type);
      printf("> DATE OF CRIME:    %s \n", current->date);
      printf("> PLACE OF CRIME:    %s \n", current->place);
      printf("> ARRESTING OFFICER:    %s \n", current->officer);
      printf("> DATE OF ARREST: %s \n", current->datearrest);
      printf("> CIN : %d",current->cin);
      //go to next node
      current = current->next;
   }
   printf("\n\n");
}//end of function


/*
Deletes a word from a linked list
word3: is a string
head3: is the a pointer to the 1st node in a linked list
This parameter is a pointer to a pointer,
because we are passing the address of the linked list to the function,
and the linked list itself is a pointer to the 1st node in the list.
*/
void deleteFromLinkedList(char word3[], NodePointer *head3){
//pointer to a temp node to be deleted from linked list
   NodePointer tempNode = NULL;
//pointer to the previous node in the linked list
   NodePointer previous = NULL;
//pointer to the current node in the linked list
   NodePointer current = *head3;

//check for empty list
   if(NULL == current){
      printf("Cannot delete from empty list!\n");
      return;
   }

/*
check to see if 1st node can be deleted
*/
   if(0 == strcmp(word3, current->data)){
   //get address of 1st node
      tempNode = current;
   //change head to next node
      *head3 = current->next;
   //delete the node
      printf("deleting \"%s\" . . .\n", tempNode->data);
      free(tempNode);
   }
   else{
   //loop through linked list
      while(NULL != current && 0 != strcmp(word3, current->data)){
         //printf("current = %s\n", current->data);
      //move to next node in linked list
         previous = current;
         current = current->next;
      }//end of while
      if(NULL != current){
      //get current node's address and store in tempNode
         tempNode = current;
         //printf("tempNode = %s\n", tempNode->data);
      //skip over current node
         previous->next = current->next;
      //delete node at current pointer
         printf("deleting \"%s\" . . .\n", tempNode->data);
         free(tempNode);
      }//end of if
   }//end of else
}//end of function

int registrar();
int lawyer();
int judge();
int main()
{
 char word[MAX]={'\0'};
  NodePointer head = NULL;
    int i = 0;
    int selection;
    printf("############ WELCOME TO JUDICIARY INFORMATION SYSTEM (JIS) ############\n\n");
    while (i < 1)
    {
        printf(" Please select your designation : \n [1] REGISTRAR\n [2] JUDGE \n [3] LAWYER\n\n#######################################################################\n\n");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:

            i++;
            registrar();
            break;

        case 2:

            i++;
            judge();
            break;

        case 3:

            i++;
            lawyer();
            break;

        default:

            printf("INVALID INPUT \n PLEASE ENTER A CORRECT INPUT");
            break;
        }
    }
}

int registrar()
{
 NodePointer head = NULL;
    printf("\n    HELLO REGISTRAR!       ");
    printf("\n    PLEASE LOGIN INTO JIS USING YOUR CREDENTIALS\n");
    // char admin[]="admin";
    char admin1[10];
    char admin[] = "1";
    char admin_pass[] = "1";
    char admin_pass1[10];
    printf("----> ENTER USERNAME :-    ");
    scanf("%s", admin1);
    printf("\n----> ENTER PASSWORD :-    ");
    scanf("%s", admin_pass1);
    if (strcmp(admin, admin1) == 0 && strcmp(admin_pass, admin_pass1) == 0)
    {
        int registrar_temp = 0;
        int registrar_temp2=1;
        printf("\nLOGIN SUCCESFUL! :)\n\n> [1] Enter the case details.\n\n> [2] Assign Hearing Date.\n\n> [3] Assign New hearing date\n\n> [4] View Pending Cases\n\n");
        scanf("%d", &registrar_temp);
        if (registrar_temp = 1)
        {   while(registrar_temp2=1)
            {


                printf("\n>>>>>>> Name Of the Defendant :");
                char defendant_name[20];
                scanf("%s", defendant_name);
                printf("\n>>>>>>> Address Of the Defendant :");
                char defendant_address[50];
                scanf("%s", defendant_address);
                printf("\n>>>>>>>  Type of case :");
                char case_type[10];
                scanf("%s", case_type);
                printf("\n>>>>>>> Date when the crime was committed:(dd/mm/yyyy) ");
                char date_crime[20];
                scanf("%s", date_crime);
                printf("\n>>>>>>> Place where the crime was committed: ");
                char place_crime[12];
                scanf("%s", place_crime);
                printf("\n>>>>>>> Name of Arresting Office: ");
                char officer_name[20];
                scanf("%s", officer_name);
                printf("\n>>>>>>> Date of Arrest: ");
                char arrest_date[12];
                scanf("%s", arrest_date);
                //insertFirst(defendant_name[20], defendant_address[50], case_type[10], date_crime[20], place_crime[12], officer_name[20], arrest_date[12]);
                insertIntoLinkedList(defendant_name,defendant_address, case_type, date_crime, place_crime, officer_name, arrest_date,CIN, &head);

                printf("The Case Identification Number is :  %d\n\n",CIN);
                CIN++;
                displayLinkedList(head);
                printf("DO YOU WANT TO ADD ANOTHER CASE ?? \n>>> [1] YES\n>>> [0] NO");
                scanf("%s",&registrar_temp2);
            }
        }

    }
    else
    {
        printf("\n### :( Uh Oh Your Username or Password is incorrect ####\n\n Please Retry\n");
        registrar();
    }
}

int lawyer()
{

    printf("\nHELLO LAWYER! WELCOME TO JIS WHERE YOU CAN PREVIEW OLD CASES FOR YOUR REFERENCE");
    printf("\nPLEASE LOGIN INTO JIS USING YOUR CREDENTIALS\n");
    // char admin[]="admin";
    char admin11[10];
    char adminl[] = "1";
    char admin_passl[] = "1";
    char admin_pass11[10];
    printf("------> ENTER USERNAME :-    ");
    scanf("%s", admin11);
    printf("\n------>  ENTER PASSWORD :-    ");
    scanf("%s", admin_pass11);
    if (strcmp(adminl, admin11) == 0 && strcmp(admin_passl, admin_pass11) == 0)
    {
        printf("\nLOGIN SUCCESFUL! :)\n\t\t");

        printf("\n>>>>>>>Lawyers are required to pay a charge of 50rs per browsed case. Please Enter your card details to continue\n");
        int h = 16;
        char card_det[h]; // card authentication
        scanf("%s", &card_det);
        if (h==16)
        {
            printf("\nThank you! Your card details have been validated successfully\n");

        }
        else
        {
            printf("\nSorry! Your card details are invalid\n");
        }
    }
    else
    {
        printf("\n### :( Uh Oh Your Username or Password is incorrect ####\n\n Please Retry\n");
        lawyer();
    }
}

int judge()
{

    printf("\nHELLO JUDGE! WELCOME TO JIS WHERE YOU CAN PREVIEW OLD CASES FOR YOUR REFERENCE");
    printf("\nPLEASE LOGIN INTO JIS USING YOUR CREDENTIALS\n");
    // char admin[]="admin";
    char admin12[10];
    char adminj[] = "1";
    char admin_passj[] = "1";
    char admin_pass12[10];
    printf("------> ENTER USERNAME :-    ");
    scanf("%s", admin12);
    printf("\n------>  ENTER PASSWORD :-    ");
    scanf("%s", admin_pass12);
    if (strcmp(adminj, admin12) == 0 && strcmp(admin_passj, admin_pass12) == 0)
    {
        printf("\nLOGIN SUCCESFUL! :)\n\t\t");

        printf("\n>>>>>>>Old Cases<<<<<<<<\n");

    }
    else
    {
        printf("\n### :( Uh Oh Your Username or Password is incorrect ####\n\n Please Retry\n");
        judge();
    }
}
