 //Stack implementation using array

 #include<stdio.h>

 int stack[5];
 int top=-1;

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

 //inserting an element in stack
 void push()
 {

     if(top==6)
     {
         printf("\nStack Overflow!\n");
     }
     else
     {
        int ele;
        printf("\n\nEnter element to push:");
        scanf("%d",&ele);
        top++;
        stack[top]=ele;
     }

     printf("\nItem pushed successfully!\n");
 }

 //deleting an element from top in a stack
 void pop()
 {
     if(top==-1)
     {
         printf("\nStack Underflow!\n");
     }
     else
     {
         int pop_ele=top;

        top--;
        printf("\nThe popped element is:%d\n",stack[pop_ele]);
     }

 }

 //Printing the top element of the stack
 void peek()
 {
     printf("\nThe value at top is:%d\n",stack[top]);
 }

 //displaying the stack;
 void display()
 {
     if(top==-1)
     {
         printf("\nStack is empty!\n");
     }
     else
     {
         int i,count=0;
        printf("\n\n-----Displaying stack-----\n");
        for(i=top;i>=0;i--)
        {
            printf("-----\n");
            printf("| %d |\n",stack[i]);
            count++;
        }
        printf("-----");
        printf("\nTotal elements in stack=%d",count);
        printf("\nTop element=%d",stack[top]);

     }

 }
