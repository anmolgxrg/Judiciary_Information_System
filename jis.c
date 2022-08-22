#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    int CIN;
    char name[20];
    char address[50];
    char type[10];
    char date[12];
    char place[12];
    char officer[20];
    char date_arrest[12];
    struct NODE *next;
};
typedef struct NODE node;
node *head = NULL;

void insertFirst(char name_, char address_, char type_, char date_, char place_, char officer_, char date_arrest_)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nMemory allocation fails");
        return;
    }

    temp->name[50] = name_;
    temp->address[50] = address_;
    temp->type[10] = type_;
    temp->date[12] = date_;
    temp->place[12] = place_;
    temp->officer[20] = officer_;
    temp->date_arrest[12] = date_arrest_;
    temp->next = head;
    head = temp;
    /* if (head==NULL)
         head=temp;
     else
         {
             temp->next=head;
             head=temp;
         }*/
}

void insertLast(char name_, char address_, char type_, char date_, char place_, char officer_, char date_arrest_)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nMemory allocation fails");
        return;
    }

    temp->name[20] = name_;
    temp->address[50] = address_;
    temp->type[10] = type_;
    temp->date[12] = date_;
    temp->place[12] = place_;
    temp->officer[20] = officer_;
    temp->date_arrest[12] = date_arrest_;
    temp->next = head;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

/* void create()
     { int x;
       char ans;
         do
          { printf("\nEnter the NODE data:");
            scanf("%d",&x);
            insertFirst(x);
            printf("\nDo you want to continue? Y/N\t");
            scanf(" %c",&ans);// leave a space between " and %c otherwise it will not work
          } while(ans=='Y' || ans=='y');

      }*/

void display()
{
    if (head == NULL)
    {
        printf("\nEmpty List");
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d\t", temp->name);
        printf("%d\t", temp->address);
        printf("%d\t", temp->type);
        printf("%d\t", temp->date);
        printf("%d\t", temp->place);
        printf("%d\t", temp->officer);
        printf("%d\t", temp->date_arrest);

        temp = temp->next;
    }
    printf("%d\t", temp->name);
    printf("%d\t", temp->address);
    printf("%d\t", temp->type);
    printf("%d\t", temp->date);
    printf("%d\t", temp->place);
    printf("%d\t", temp->officer);
    printf("%d\t", temp->date_arrest); // last element to be printed
}

void delete (int ele)
{
    if (head == NULL)
    {
        printf("\nEmpty List");
        return;
    }
    node *cur, *pre;
    cur = head;
    pre = NULL;
    while (cur->CIN != ele)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        printf("\nElement Not Found");
    else
    {
        if (pre == NULL) // if the data is at first node
        {
            head = cur->next;
            cur->next = NULL;
            free(cur);
        }
        else
        {
            pre->next = cur->next;
            cur->next = NULL;
            free(cur);
        }
    }
}

int registrar();
int lawyer();
int judge();
int main()
{

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

    printf("\n    HELLO REGISTRAR!       ");
    printf("\n    PLEASE LOGIN INTO JIS USING YOUR CREDENTIALS\n");
    // char admin[]="admin";
    char admin1[10];
    char admin[] = "1";
    char admin_pass[] = "1";
    char admin_pass1[10];
    printf("------> ENTER USERNAME :-    ");
    scanf("%s", admin1);
    printf("\n------>  ENTER PASSWORD :-    ");
    scanf("%s", admin_pass1);
    if (strcmp(admin, admin1) == 0 && strcmp(admin_pass, admin_pass1) == 0)
    {
        int registrar_temp = 0;
        printf("\nLOGIN SUCCESFUL! :)\n\n> [1] Enter the case details.\n\n> [2] Assign Hearing Date.\n\n> [3] Assign New hearing date\n\n> [4] View Pending Cases\n\n\t\t");
        scanf("%d", &registrar_temp);
        if (registrar_temp = 1)
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
            insertFirst(defendant_name[20], defendant_address[50], case_type[10], date_crime[20], place_crime[12], officer_name[20], arrest_date[12]);
            display();
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
            display();
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
        display();
    }
    else
    {
        printf("\n### :( Uh Oh Your Username or Password is incorrect ####\n\n Please Retry\n");
        judge();
    }
}
