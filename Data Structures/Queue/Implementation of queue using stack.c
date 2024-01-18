//Implementation of queue using stack (a primary stack and a secondary stack)
//Enqueue operation - O(1)
//Dequeue operation - O(n)

#include<stdio.h>

#define N 5

int s1[N],s2[N];
int top1=-1,top2=-1;
int count=0;

void push1(int);

void push2(int);

int pop1(void);

int pop2(void);

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


//The backend modules to be used in queue operations starts here...

void push1(int x)
{
    if(top1==N-1)
    {
        printf("\nQueue overflow!");
    }
    else
    {
        top1++;
        s1[top1]=x;
    }
}

void push2(int x)
{
    if(top2==N-1)
    {
        printf("\nQueue overflow!");
    }
    else
    {
        top2++;
        s2[top2]=x;
    }
}

int pop1()
{
    return s1[top1--];
}

int pop2()
{
    return s2[top2--];
}

//The backend modules to be used in queue operations ends here.

//Starting of actual queue operations

void enqueue()
{
    int num;
    printf("\nEnter item to add in queue:");
    scanf("%d",&num);
    push1(num);
    count++;
}

void dequeue()
{
    if(top1==-1 && top2==-1)
    {
        printf("Queue is empty!");
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            int a=pop1();
            push2(a);
        }
        int b=pop2();
        printf("\nThe dequeued element is: %d",b);
        count--;
        for(int i=0;i<count;i++)
        {
            int a=pop2();
            push1(a);
        }
    }
}

void display()
{
    printf("\n----Displaying queue----\n");
    for(int i=0;i<=top1;i++)
    {
        printf("%d,",s1[i]);
    }
}

void peek()
{
    printf("\nThe front item in queue is: %d",s1[0]);
}
