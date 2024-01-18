//implementation of queue using linked list

#include<stdio.h>
#include<stdlib.h>

 typedef struct node{
    int data;
    struct node *next;
 }NODE;

 NODE *front=NULL;
 NODE *newnode=NULL;
 NODE *rear=NULL;
 NODE *temp;

 void enqueue(void);

 void dequeue(void);

 void peek(void);

 void display(void);

 void main()
 {
     int ch;

     do
     {
         int menu_ch;

         printf("\n\n------MENU------\n");
         printf("1.Enqueue item\n2.Dequeue item\n3.Peek front\n4.Display queue\n");
         printf("Enter your choice to perform operation:");
         scanf("%d",&menu_ch);

         switch(menu_ch)
         {
             case 1: enqueue();
                    break;
             case 2:dequeue();
                    break;
             case 3:peek();
                    break;
             case 4:display();
                    break;
             default:printf("\nWrong choice entered!\n");

         }

         printf("\n\nDo you want to continue?(1/0):");
         scanf("%d",&ch);

     }while(ch==1);

}

void enqueue()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("\n\nEnter element to enque:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    if(front==NULL && rear==NULL)
    {
        printf("\nThe queue is empty!");
    }
    else
    {
        temp=front;
        printf("\nThe %d is dequeued from the queue",temp->data);
        front=temp->next;
        free(temp);
    }

}

void peek()
{
    if(front==NULL && rear==NULL)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nThe front of Queue is: %d",front->data);
    }
}

void display()
{
    if(front==NULL)
    {
        printf("\nThe Queue is empty!");
    }
    else
    {
        temp=front;
        printf("\n-----Displaying queue-----\n");
        while(temp!=NULL)
        {
            printf("%d | ",temp->data);
            temp=temp->next;
        }
    }
}
