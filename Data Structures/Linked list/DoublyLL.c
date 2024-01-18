//Doubly linked list

#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL,*tail=NULL;
struct node *temp;
struct node *newnode;

struct node* createDLL(int);

void displayDLL(struct node*);

struct node* insertAtBeginning(struct node*);

struct node* insertAtEnd(struct node*);

struct node* insertAtSpec(struct node*);

struct node* insertAfterSpec(struct node*);

struct node* deleteFromBeginning(struct node*);

struct node* deleteFromEnd(struct node*);

struct node* deleteFromSpec(struct node*);

struct node* reverseDLL(struct node*);

void main()
{
    int num=0;
    printf("Enter the no. of nodes in linked list:");
    scanf("%d",&num);

    //Creating a doubly linked list with the length of user choice
    createDLL(num);

    //Displaying the Doubly linked list
    displayDLL(head);

    /*

    //inserting a node at beginning
    insertAtBeginning(head);//function is not proper
    displayDLL(head);

    //inserting a node at the end
    //insertAtEnd(head);
    //displayDLL(head);

    //inserting a node at specific position
    insertAtSpec(head);
    displayDLL(head);

    //insert a node after the specified position
    insertAfterSpec(head);
    displayDLL(head);

    //deleting a node from the beginning of linked list
    deleteFromBeginning(head);
    displayDLL(head);

    //deleting a node from end of list
    deleteFromEnd(head);
    displayDLL(head);

    //deleting a node from specific position
    deleteFromSpec(head);
    displayDLL(head);

    //reversing a doubly linked list
    reverseDLL(head);
    displayDLL(head);
    */
    //

}

struct node* createDLL(int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data of node- %d:",i+1);
        scanf("%d",&(newnode->data));
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
            tail=temp;
        }
    }
    return head;
}


void displayDLL(struct node *head)
{
    if(head==NULL)
    {
        printf("\nDoubly linked list is empty!");
    }

    else
    {
    temp=head;
    printf("NULL->");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    }
}


struct node* insertAtBeginning(struct node *head)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter a node to add in beginning of list:");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;

    return head;
}

struct node* insertAtEnd(struct node* head)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter node to add in End of list:");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    newnode->prev=NULL;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;

    return head;
}

struct node* insertAtSpec(struct node *head)
{
    int pos;
    printf("\nEnter the position to insert node:");
    scanf("%d",&pos);
    if(pos<=0)
    {
        printf("Invalid position !");
    }
    else if(pos==1)
    {
        insertAtBeginning(head);
    }
    else
    {
        int i=1;
        temp=head;

        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the node data:");
        scanf("%d",&(newnode->data));
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
    }

    return head;
}

struct node* insertAfterSpec(struct node *head)
{
    int pos;
    printf("\nEnter the position of node to insert node at position+1:");
    scanf("%d",&pos);
    if(pos<0)
    {
        printf("Invalid position!");
    }
    else if(pos==0)
    {
        insertAtBeginning(head);
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data value:");
        scanf("%d",&(newnode->data));

        int i=1;
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
    }

    return head;
}

struct node* deleteFromBeginning(struct node *head)
{
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);

    return head;
}

struct node* deleteFromEnd(struct node *head)
{
    /* //this code is used when the tail pointer is not maintained
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    */
    //this code is used when maintaining a tail pointer
        tail->prev->next=NULL;
        free(tail);

        return head;
}

struct node* deleteFromSpec(struct node *head)
{
    temp=head;
    int i=1,pos;
    printf("\nEnter the position to delete node:");
    scanf("%d",&pos);
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);

    return head;
}

struct node* reverseDLL(struct node *head)
{
    temp=head;
    struct node *nextnode;
    while(temp!=NULL)
    {
        nextnode=temp->next;
        temp->next=temp->prev;
        temp->prev=newnode;
        temp=nextnode;
    }
    //swapping the head and tail pointers using third variable
    temp=head;
    head=tail;
    tail=temp;

    return head;
}
