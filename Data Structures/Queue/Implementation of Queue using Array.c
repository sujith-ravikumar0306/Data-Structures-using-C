//Implementation of queue using an array

#include<stdio.h>

#define N 5

int queue[N];
int front=-1;
int rear=-1;

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
         printf("1.Enqueue item\n2.Dequeue item\n3.Peek front\n4.Display Queue\n");
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
    if(rear==N-1)
    {
        printf("\nOverflow Condition!");
    }
    else
    {
            int item;
            printf("\nEnter item to add in queue:");
            scanf("%d",&item);

        if(front==-1 && rear==-1)
        {
            front=rear=0;
            queue[rear]=item;
        }

        else
        {
            rear++;
            queue[rear]=item;
        }
    }

}

void dequeue()
{
    //if there are no items in the queue
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty to perform operation!");
    }
    //if there is only one item in the queue where front and rear points towards it
    else if(front==rear)
    {
        printf("\nDequeue item: %d",queue[front]);
        front=rear=-1;
    }
    //if there exists more than one item in the queue
    else
    {
        printf("\nDequeue item: %d",queue[front]);
        front++;
    }
}

void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nThe front item in queue: %d",queue[front]);
    }

}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\n-----Displaying Queue-----\n");
        for(int i=front ;i<=rear;i++)
        {
            printf("%d | ",queue[i]);
        }
    }
}

