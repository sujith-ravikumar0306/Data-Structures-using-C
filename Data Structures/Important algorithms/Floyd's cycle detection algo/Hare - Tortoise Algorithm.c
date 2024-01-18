//FLOYD'S CYCLE DETECTION ALGO (OR) HARE - TORTOISE ALGORITHM

//This algorithm use two pointers to one fast and one slow to traverse through the array.
//This can be use to find presence of cycle, cycle starting point detection and removal of cycles from linked list.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//GLOBAL DECLARATIONS

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *newnode=NULL, *head=NULL, *temp=NULL;s

NODE *fast=NULL,*slow=NULL;

int i;
//FUNCTION PROTOTYPES

NODE* createList(int);

void printList(NODE*);

bool findCycle(NODE *);

NODE* findLoopStart(NODE*);

void removeCycle(NODE*);


//MAIN function

void main()
{
    int n;
    printf("Enter the total no. of nodes (>3):");
    scanf("%d",&n);
    //creating a linked list with loop
    createList(n);

    //print the linked list
    // printList(head);

    //finding for cycles in our list
    bool res=findCycle(head);
    if(res==true)
        printf("\nCYCLE DETECTED IN LIST");
    else
        printf("\nNO CYCLE DETECTED");

    //finding the starting point of loop if exists

    if(res!=false)
    {
        temp= findLoopStart(head);
        printf("\nLoop starting at : %d",temp->data);
    }

    //remove cycle from a list
    if(res!=false)
    {
        removeCycle(head);
    }

    //print the linked list
    printList(head);

}

//FUNCTION DEFINITIONS

//creating a list with loop
NODE* createList(int n)
{
    for(i=0;i<n;i++)
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        printf("\nEnter node-%d data: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
    }
    //loop from last node to 3rd node
    temp->next=head->next->next;
    return head;
}

//printing the list
void printList(NODE* head)
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

//Finding the presence of cycle in a list
bool findCycle(NODE* head)
{
    fast=slow=head;
    while(fast!=NULL && slow!=NULL && fast->next!=NULL)
    {
        slow=slow->next;        //tortoise (1 node per jump)
        fast=fast->next->next;  //hare  (2 nodes per jump)

        if(fast==slow)
        {
            return true;
        }
    }

    return false;
}

//find the starting point of loop
NODE* findLoopStart(NODE *head)
{
    fast=slow=head;
    while(fast!=NULL && slow!=NULL && fast->next!=NULL)
    {
        slow=slow->next;        //tortoise (1 node per jump)
        fast=fast->next->next;  //hare  (2 nodes per jump)

        if(fast==slow)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

//removing the cycle from a node

void removeCycle(NODE* head)
{
    NODE *prev=NULL; //pointer to the last node (previous to start of loop)
    fast=slow=head;
    while(fast!=NULL && slow!=NULL && fast->next!=NULL)
    {
        slow=slow->next;        //tortoise (1 node per jump)
        fast=fast->next->next;  //hare  (2 nodes per jump)

        if(fast==slow)
        {
            slow=head;
            while(slow!=fast)
            {
                prev=fast;          //*prev is always previous to fast node
                slow=slow->next;
                fast=fast->next;
            }
            //set the last node->next to NULL to remove the loop
            prev->next=NULL;
            printf("\nThe loop link between %d and %d is broken successfully!",prev->data,fast->data);
        }
    }

}
