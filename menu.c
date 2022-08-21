#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct NODE { int CIN;
               char name[20];
               char address[50];
               char type[10];
               char date[12];
               char place[12];
               char officer[20];
               char date_arrest[12];
               struct NODE *next; };
typedef struct NODE node;
node *head=NULL;

void insertFirst(char name_[],char address_[],char type_[],char date_[],char place_[],char officer_[],char date_arrest_[])
     {
         node *temp = ( node *) malloc( sizeof(node));
                if(temp==NULL)
                {
                    printf("\nMemory allocation fails");
                    return;
                }

                strncpy(temp->name,name_,30);
                temp->address[50]=address_;
                temp->type[10]=type_;
                temp->date[12]=date_;
                temp->place[12]=place_;
                temp->officer[20]=officer_;
                temp->date_arrest[12]=date_arrest_;
                temp->next=head;
                head=temp;
               /* if (head==NULL)
                    head=temp;
                else
                    {
                        temp->next=head;
                        head=temp;
                    }*/

      }

void insertLast(char name_,char address_,char type_,char date_,char place_,char officer_,char date_arrest_)
     {
         node *temp = ( node *) malloc( sizeof(node));
        if(temp==NULL)
            {
                printf("\nMemory allocation fails");
                return;
            }


                temp->name[20]=name_;
                temp->address[50]=address_;
                temp->type[10]=type_;
                temp->date[12]=date_;
                temp->place[12]=place_;
                temp->officer[20]=officer_;
                temp->date_arrest[12]=date_arrest_;
                temp->next=head;
        temp->next=NULL;
        if(head==NULL)
            {
                head=temp;
                return;
            }
        node *cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
         cur->next=temp;
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




void display(){
                if(head==NULL)
                {
                    printf("\nEmpty List");
                    return;
                }

                node *temp=head;
                while(temp->next!=NULL)
                    {
                        printf("%s\t",temp->name);
                        printf("%s\t",temp->address);
                        printf("%s\t",temp->type);
                        printf("%s\t",temp->date);
                        printf("%s\t",temp->place);
                        printf("%s\t",temp->officer);
                        printf("%s\t",temp->date_arrest);

                        temp=temp->next;
                    }
                        printf("%s\t",temp->name);
                        printf("%s\t",temp->address);
                        printf("%s\t",temp->type);
                        printf("%s\t",temp->date);
                        printf("%s\t",temp->place);
                        printf("%s\t",temp->officer);
                        printf("%s\t",temp->date_arrest);// last element to be printed
                }

  void delete( int ele)
  {   if(head==NULL)
      {
          printf("\nEmpty List");
          return;
      }
      node *cur,*pre;
      cur=head;
      pre=NULL;
      while(cur->CIN!=ele)
      {
          pre=cur;
          cur=cur->next;
      }
      if(cur==NULL)
           printf("\nElement Not Found");
      else
          {
            if(pre==NULL)// if the data is at first node
               {
                 head=cur->next;
                 cur->next  =NULL;
                 free(cur);
               }
            else
                {
                  pre->next=cur->next;
                  cur->next=NULL;
                  free(cur);
                }
          }

  }




/*int main()
{
    create();
    printf("\nCreated List: \n");
    display();
    insertLast(100);
    printf("\nList after insertLast:\n ");
    display();
    int ele;
    printf("\nEnter element to be deleted  : ");
    scanf("%d",&ele);
    delete(ele);
    printf("\nList after deletion: \n");
    display();


}*/

int registrar();
int lawyer();
int judge();
int main()
{

    int i=0;
    int selection;
    printf("############### WELCOME TO JUDICIARY INFORMATION SYSTEM ###############\n\n");
    while(i<1)
    {
        printf(" Please select your designation : \n 1. REGISTRAR\n 2. JUDGE \n 3. LAWYER\n\n####################################\n\n");
        scanf("%d",&selection);
        switch(selection)
        {case 1:

               i++;
               registrar();
               break;

         case 2:


                i++;
                break;

        case 3:

                i++;
                break;

        default:

                printf("   INVALID INPUT   \n\n PLEASE ENTER A CORRECT INPUT");

    }
    }
}

int registrar()
{

    printf("\n    WELCOME REGISTRAR !       ");
    printf("\n    PLEASE LOGIN USING ADMIN CREDENTIALS\n");
   // char admin[]="admin";
    char admin1[10];
    char admin[]="1";
    char admin_pass[]="1";
    char admin_pass1[10];
    printf("_______  ENTER  LOGIN ID :-    ");
    scanf("%s",admin1);
    printf("\n_______  ENTER  PASSWORD :-    ");
    scanf("%s",admin_pass1);
    if(strcmp(admin,admin1)==0 &&strcmp(admin_pass,admin_pass1)==0)
    {   int registrar_temp=0;
        printf("\n-----LOGIN SUCCESFUL !\n-------> [1] Enter the case details.\n\n-------> [2] Assign Hearing Date.\n\n-------> [3] Assign NEW hearing date\n\n-------> [4] View Pending Cases");
        scanf("%d",&registrar_temp);
        if(registrar_temp=1)
        {
            printf("\n-------> Name Of the Defendant :");
            char defendant_name[20];
            scanf("%s",defendant_name);
            printf("\n-------> Address Of the Defendant :");
            char defendant_address[50];
            scanf("%s",defendant_address);
            printf("\n------->  the type of case :");
            char case_type[10];
            scanf("%s",case_type);
            printf("\n-------> Date when the crime was committed:(dd/mm/yyyy) ");
            char date_crime[20];
            scanf("%s",date_crime);
            printf("\n-------> Place where the crime was committed: ");
            char place_crime[12];
            scanf("%s",place_crime);
            printf("\n-------> Name of Arresting Office: ");
            char  officer_name[20];
            scanf("%s",officer_name);
            printf("\n-------> Date of Arrest: ");
            char arrest_date[12];
            scanf("%s",arrest_date);
            insertFirst(defendant_name[20],defendant_address[50],case_type[10],date_crime[20],place_crime[12],officer_name[20],arrest_date[12]);
            display();
        }
    }
    else
    {
        printf("\n_______LoginID OR Password is incorrect\n");
        registrar();

    }


}
