//Implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>

 typedef struct node{
    int data;
    struct node *next;
 }NODE;

 NODE *top=NULL;
 NODE *newnode=NULL;
 NODE *temp;

 void push(void);

 void pop(void);

 void peek(void);

 void display(void);

 void main()
 {
     int ch;

     do
     {
         int menu_ch;

         printf("\n\n------MENU------\n");
         printf("1.Push item\n2.Pop item\n3.Peek top\n4.Display stack\n");
         printf("Enter your choice to perform operation:");
         scanf("%d",&menu_ch);

         switch(menu_ch)
         {
             case 1: push();
                    break;
             case 2:pop();
                    break;
             case 3:peek();
                    break;
             case 4:display();
                    break;
             default:printf("\nWrong choice entered!\n");

         }

         printf("\nDo you want to continue?(1/0):");
         scanf("%d",&ch);

     }while(ch==1);

}

void push()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("\n\nEnter element to push:");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}

void display()
{
    temp=top;
    if(top==NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("\n-----");
            printf("\n| %d |",temp->data);
            temp=temp->next;
        }
        printf("\n-----");
    }

    printf("\nTop=%d",top->data);
}

void peek()
{
    if(top==NULL)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\n\nThe top element in stack is: %d",top->data);
    }

}

void pop()
{
    if(top==NULL)
    {
        printf("\nStack is empty!");
    }
    else
    {
        temp=top;
        top=temp->next;
        printf("\nElement: %d is popped from top.",temp->data);
        free(temp);
    }

}
