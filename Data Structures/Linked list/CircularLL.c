//Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head=NULL;
struct node* temp;
struct node* newnode;
struct node* tail=NULL;

void createCLL(int);

void displayCLL(struct node*);

struct node* insertAtBeginning(struct node*);

struct node* insertAtEnd(struct node*);

struct node* insertAtSpec(struct node*);

struct node* delFromStart(struct node*);

struct node* delFromEnd(struct node*);

struct node* delFromSpec(struct node*);

struct node* reverseList(struct node*);

void main()
{
    int num=0;
    printf("Enter the no of nodes to create Circular Linked List:");
    scanf("%d",&num);

    //creating a circular linked list
    createCLL(num);
    displayCLL(tail);

    /*
    //insert a node at the beginning of list
    insertAtBeginning(tail);
    displayCLL(tail);

    //inserting a node at the end of list
    insertAtEnd(tail);
    displayCLL(tail);

    //inserting node at a specific position
    insertAtSpec(tail);
    displayCLL(tail);

    //delete at starting of the list
    delFromStart(tail);

    //delete a node from end of list
    delFromEnd(tail);

    //delete a node from specific position
    delFromSpec(tail);
    */

}

void createCLL(int num)
{
    if(num<=0)
    {
        printf("List must contain atleast one node!");
    }
    else
    {
        printf("\n-----Creating Circular Linked List-----");
        for(int i=0;i<num;i++)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the data for node- %d:",i+1);
            scanf("%d",&(newnode->data));
            newnode->next=NULL;
            if(head==NULL)
            {
                head=tail=newnode;
                tail->next=newnode;
            }
            else
            {
                newnode->next=tail;
                tail->next=newnode;
                tail=tail->next;
            }

        }
    }

}


void displayCLL(struct node* tail)
{
            temp=tail->next;
            while(temp->next!=tail->next)
            {
                printf("%d-> ",temp->data);
                temp=temp->next;
            }
            //printf("%d->",temp->data);
            //printf("%d",head->data);
}

struct node* insertAtBeginning(struct node* tail)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert at beginning of Circular LL:");
    scanf("%d",&(newnode->data));
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }

    return tail;
}

struct node* insertAtEnd(struct node *tail)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert at End of Circular LL:");
    scanf("%d",&(newnode->data));
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }

    return tail;
}

struct node* insertAtSpec(struct node *tail)
{
    temp=tail->next;
    int i=1,pos;
    printf("\nEnter a position:");
    scanf("%d",&pos);
    if(pos<1)
    {
        printf("Invalid position!");
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter node data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

    return tail;
}

struct node* delFromStart(struct node *tail)
{
    head=tail->next;
    tail->next=head->next;
    free(head);
    return tail;
}

struct node* delFromEnd(struct node *tail)
{
 temp=tail->next;
 while(temp!=tail)
 {
     temp=temp->next;
 }
 temp->next=tail->next;
 free(tail);
 tail=temp;

 return tail;
}

struct node* delFromSpec(struct node *tail)
{
    struct node *current,*nextnode;
    int pos,i=1;
    printf("\nEnter the position of node to delete from the list:");
    scanf("%d",&pos);

    if(pos<1 /* ||  pos>total length*/)
    {
        printf("\nInvalid Position!");
    }
    else if(pos==1)
    {
        delFromStart(tail);
    }
    else
    {
        current=tail->next;
        while(i<pos)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    }

    return tail;
}

struct node* reverseList(struct node *tail)
{
    struct node *curr,*prev,*nextnode;
    curr=tail->next;
    nextnode=curr->next;
    while(curr->next!=tail->next)
    {
        prev=current;
        curr=nextnode;
        nextnode=curr->next;
        curr->next=prev;
    }
    nextnode->next=tail;
    tail=nextnode;
}
