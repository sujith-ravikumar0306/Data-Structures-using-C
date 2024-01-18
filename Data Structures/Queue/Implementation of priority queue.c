//implementation of priority queue using linked list
//NOTE:-The lower the PRN(priority number),the higher the priority.

#include<stdio.h>
#include<stdlib.h>

 typedef struct node{
    int data;
    int PRN;
    struct node *next;
    struct node *prev;
 }NODE;

 NODE *front=NULL;
 NODE *newnode=NULL;
 NODE *rear=NULL;
 NODE *temp,*temp1;

 void createPri(void);

 void enqueuePri(void);

 void pollPri(void);

 void peekPri(void);

 void displayPri(void);

 void main()
 {
     int ch;

     createPri();
     do
     {
         int menu_ch;
         printf("\n\n------MENU------\n");
         printf("1.Add item to queue\n2.Poll the highest priority item\n3.View item with highest priority\n4.Display queue\n");
         printf("Enter your choice to perform operation:");
         scanf("%d",&menu_ch);

         switch(menu_ch)
         {
             case 1:enqueuePri();
                    break;
             case 2:pollPri();
                    break;
             case 3:peekPri();
                    break;
             case 4:displayPri();
                    break;
             default:printf("\nWrong choice entered!\n");

         }

         printf("\n\nDo you want to continue?(1/0):");
         scanf("%d",&ch);

     }while(ch==1);

}

//Create a priority queue
void createPri()
{
     int n,i;

    printf("Enter the no of items to insert in Priority queue:");
    scanf("%d",&n);
    if(n<1)
    {
        printf("\nPriority queue must have at least one item!");
    }
    else
    {


    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter item:");
        scanf("%d",&newnode->data);
        printf("\nEnter priority:");
        scanf("%d",&newnode->PRN);
        newnode->next=NULL;
        newnode->prev=NULL;

        //when the first item is inserted
        if(front==NULL && rear==NULL)
        {
            front=rear=newnode;
        }

        //insertion of remaining items
        else
        {

                //new item has highest priority than front
                if(newnode->PRN < front->PRN)
                {
                    front->prev=newnode;
                    newnode->next=front;
                    front=newnode;
                }

                //new item has same priority as that of front(first come first serve)
                else if(newnode->PRN==front->PRN)
                {
                    newnode->prev=front;
                    newnode->next=front->next;
                    front->next=newnode;
                }

                //new item has priority greater than or equal to that of rear
                else if((newnode->PRN > rear->PRN) || (newnode->PRN==rear->PRN))
                {
                    rear->next=newnode;
                    newnode->prev=rear;
                    rear=newnode;
                }

                //new item has priority in between that of front and rear
                else
                {
                    temp=front->next;

                    while(temp!=NULL)
                    {
                        if(newnode->PRN < temp->PRN)
                        {
                            temp1=temp->prev;
                            newnode->prev=temp->prev;
                            newnode->next=temp;
                            temp1->next=newnode;
                            temp->prev=newnode;

                        }
                        temp=temp->next;
                    }
                }
        }
    }

    }

}

//add a item into priority queue
void enqueuePri()
{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter item:");
        scanf("%d",&newnode->data);
        printf("\nEnter priority:");
        scanf("%d",&newnode->PRN);
        newnode->next=NULL;
        newnode->prev=NULL;

        //If the priority queue is initially empty
        if(front==NULL && rear==NULL)
        {
            front=rear=newnode;
        }
        //if priority queue already have item(s).
        else
        {

                //new item has highest priority than front
                if(newnode->PRN < front->PRN)
                {
                    front->prev=newnode;
                    newnode->next=front;
                    front=newnode;
                }

                //new item has same priority as that of front(first come first serve)
                else if(newnode->PRN==front->PRN)
                {
                    newnode->prev=front;
                    newnode->next=front->next;
                    front->next=newnode;
                }

                //new item has priority greater than or equal to that of rear
                else if((newnode->PRN > rear->PRN) || (newnode->PRN==rear->PRN))
                {
                    rear->next=newnode;
                    newnode->prev=rear;
                    rear=newnode;
                }

                //new item has priority in between that of front and rear
                else
                {
                    temp=front->next;

                    while(temp!=NULL)
                    {
                        if(newnode->PRN==temp->PRN)
                        {
                            newnode->prev=temp;
                            newnode->next=temp->next;
                            temp->next=newnode;
                        }
                        else if(newnode->PRN < temp->PRN)
                        {
                            temp1=temp->prev;
                            newnode->prev=temp->prev;
                            newnode->next=temp;
                            temp1->next=newnode;
                            temp->prev=newnode;

                        }

                        temp=temp->next;
                    }
                }
        }

}

//Remove the highest priority item
void pollPri()
{
    if(front==NULL)
    {
        printf("\nThe priority queue is empty!");
    }
    else
    {
        temp=front;
        printf("\nThe item: %d with PRN: %d is removed from queue.",temp->data,temp->PRN);
        front=temp->next;
        free(temp);
    }

}

//View the highest priority item
void peekPri()
{
    printf("\nThe highest priority item:%d with PRN:%d.",front->data,front->PRN);
}


//display the priority queue
void displayPri()
{

    if(front==NULL)
    {
        printf("\nThe Priority queue is empty!");
    }
    else
    {
        printf("\n---Displaying Priority Queue---\n");
        temp=front;
        while(temp!=NULL)
        {
            printf("item: %d ,PRN: %d | ",temp->data,temp->PRN);
            temp=temp->next;
        }
        printf("NULL");

    }
}
