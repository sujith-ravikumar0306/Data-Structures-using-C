//Implementation of dequeue
//Deque:- A queue in which the insertion and deletion can be done from both ends


#include<stdio.h>

#define N 5

int deque[N];
int f=-1,r=-1;

void enqueueFront(void);

void enqueueRear(void);

void dequeueFront(void);

void dequeueRear(void);

void peekFront(void);

void peekRear(void);

void display(void);

void main()
{
    int ch;

     do
     {
         int menu_ch;

         printf("\n\n------MENU------\n");
         printf("1.EnqueueFront item\n2.EnqueueRear item\n3.DequeueFront item \n4.DequeueRear item \n5.Peek front \n6.Peek rear \n7.Display Queue\n");
         printf("Enter your choice to perform operation:");
         scanf("%d",&menu_ch);

         switch(menu_ch)
         {
             case 1: enqueueFront();
                    break;
             case 2: enqueueRear();
                    break;
             case 3: dequeueFront();
                    break;
             case 4: dequeueRear();
                    break;
             case 5: peekFront();
                    break;
             case 6: peekRear();
                    break;
             case 7:display();
                    break;
             default:printf("\nWrong choice entered!\n");

         }

         printf("\n\nDo you want to continue?(1/0):");
         scanf("%d",&ch);

     }while(ch==1);


}

//insertion at the front
void enqueueFront()
{

    if((f==0 && r==N-1) || (f==r+1))
    {
        printf("\nThe Deque is full!");
    }
    else
    {
        int n;
        printf("\nEnter item to insert at front:");
        scanf("%d",&n);
        if(f==-1 && r==-1)
        {
        f=r=0;
        deque[f]=n;
        }
        else if(f==0)
        {
            f=N-1;
            deque[f]=n;
        }
        else
        {
            f--;
            deque[f]=n;
        }
    }


}

//insertion at the rear
void enqueueRear()
{
    if((f==0 && r==N-1) || (f==r+1))
    {
        printf("\nThe Deque is full!");
    }
    else
    {
        int n;
        printf("\nEnter item to add at rear:");
        scanf("%d",&n);
        if(f==-1 || r==-1)
        {
            f=r=0;
            deque[r]=n;
        }
        else if(r==N-1)
        {
            r=0;
            deque[r]=n;
        }
        else
        {
            r++;
            deque[r]=n;
        }
    }
}

//deletion at the front
void dequeueFront()
{
    if(f==-1 && r==-1)
    {
        printf("Deque is empty for deletion from front!");
    }
    else
    {
        int a;

        if(f==r)
        {
            a=deque[f];
            f=r=-1;
        }
        else if(f==N-1)
        {
            a=deque[f];
            f=0;
        }
        else
        {
            a=deque[f];
            f++;
        }
        printf("\nThe item deleted from front is %d.",a);
    }
}

//deletion at rear
void dequeueRear()
{
    if(f==-1 && r==-1)
    {
        printf("\nDeque is empty for deletion from rear!");
    }
    else
    {
        int a;

        if(f==r)
        {
            a=deque[r];
            f=r=-1;
        }
        else if(r==0)
        {
            a=deque[r];
            r=N-1;
        }
        else
        {
            a=deque[r];
            r--;
        }
         printf("\nThe item deleted from rear is %d.",a);
    }
}

//displaying the front
void peekFront()
{
    if(f==-1 && r==-1)
    {
        printf("\nThe Deque is empty!");
    }
    else
    {
        printf("\nThe Front of Deque is %d.",deque[f]);
    }
}

//displaying the rear
void peekRear()
{
    if(f==-1 && r==-1)
    {
        printf("\nThe Deque is empty!");
    }
    else
    {
        printf("\nThe Rear of Deque is %d.",deque[r]);
    }
}

//displaying the queue
void display()
{
    if(f==-1 && r==-1)
    {
        printf("\nDeque is Empty!");
    }
    else
    {
        int i=f;
        printf("\n---Displaying Deque---\n");
        while(i!=r)
        {
            printf("%d, ",deque[i]);
            i=(i+1)%N;
        }
        printf("%d",deque[r]);
    }

}
