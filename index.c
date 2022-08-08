#include<stdio.h>
struct NODE 
{
    int data;
    struct NODE *next, *pre;
};
typedef struct NODE node;   
node *head=NULL;
void insertFirst(int ele)
     {
         node *temp = ( node *) malloc( sizeof(node));
                if(temp==NULL)
                {
                    printf("\nMemory allocation fails");
                    return;
                }

                temp->data=ele;
                temp->next=NULL;
                temp->pre=NULL;
                if (head==NULL)
                    {
                        head=temp;
                        temp->pre=head;
                    }
                else
                    {
                        temp->next=head;
                        head->pre=temp;
                        head=temp;
                        temp->pre=NULL;

                    }
             // temp=NULL; will be done automatically
      }
void insertLast(int ele)
     {
         node *temp = ( node *) malloc( sizeof(node));
        if(temp==NULL)
            {
                printf("\nMemory allocation fails");
                return;
            }
        temp->data=ele;
        temp->next=NULL;
        temp->pre=NULL;
        if(head==NULL)
            {
                head=temp;
                temp->pre=head;
                //temp=NULL; will be done automatically
                return;
            }
        node *cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
         cur->next=temp;
         temp->pre=cur;

      }
   void create()
       { int x;
         char ans;
           do
            { printf("\nEnter the NODE data:");
              scanf("%d",&x);
              insertFirst(x);
              printf("\nDo you want to continue? Y/N\t");
              scanf(" %c",&ans);// leave a space between " and %c otherwise it will not work
            } while(ans=='Y' || ans=='y');

        }
void display(){
                if(head==NULL)
                {
                    printf("\nEmpty List");
                    return;
                }

                node *temp=head;
                while(temp->next!=NULL)
                    {
                        printf("%d\t",temp->data);
                        temp=temp->next;
                    }
                  printf("%d",temp->data);// last element to be printed
                }

  void delete( int ele)
  {   if(head==NULL)
      {
          printf("\nEmpty List");
          return;
      }
      node *cur;
      cur=head;

      while(cur->data!=ele)
      {

          cur=cur->next;
      }
      if(cur==NULL)
           printf("\nElement Not Found");
      else
          {
            if(cur==head)// if the data is at first node
               {
                 head=cur->next;
                 head->pre=NULL;
                 cur->next  =NULL;
                 cur->pre=NULL;
                 free(cur);
               }
            else if(cur->next==NULL)//last node
            {
                 (cur->pre)->next=NULL;
                 cur->pre=NULL;
                 free(cur);
            }
             else // in between node
            {
               (cur->pre)->next=cur->next;
               (cur->next)->pre=cur->pre;
               cur->next  =NULL;
               cur->pre=NULL;
               free(cur);
            }
          }

  }
int main()
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


