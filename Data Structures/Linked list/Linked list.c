//---------------
// LINKED LISTS
//---------------

//Implementation of linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

        struct node *head=NULL;
        struct node *newnode=NULL;
        struct node *temp=NULL;

int lastcount;

struct node* createLinkedList(int);

void display(struct node*);

struct node* insertAtStart(struct node*);

struct node* insertAtEnd(struct node*);

struct node* insertAtSpec(struct node*);

struct node* deleteAtStart(struct node*);

struct node* delAtEnd(struct node*);

struct node* delAtSpec(struct node*);

void countNodes(struct node*);

void reverseList(struct node*);

void main()
{
    int n=0;
    printf("Enter the no of elements in linked list:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Linked list must have at least one node!");
    }
    else{
        printf("-------Creating a Linked List-------\n");

        //creating a linked list
        head= createLinkedList(n);

        //dispalting the linkedlist
        display(head);

        /*

        //inserting node at the starting of linked list
        insertAtStart(head);
        display(head);

        //inserting node at the end of linked list
        insertAtEnd(head);
        display(head);

        //inserting node at a specific position
        insertAtSpec(head);
        display(head);

        //deleting the node at first position
        //deleteAtStart(head);
        //display(head);

        //deleting a node at the end of list
        delAtEnd(head);
        display(head);


        //deleting a node at specific position
        delAtSpec(head);
        display(head);

         */
         //count the total number of nodes in a list
         countNodes(head);

         //reversing the list using iterative method
         reverseList(head);
         display(head);

    }
}


//Creating a linked list of n nodes
struct node* createLinkedList(int n)
{
        int i=0;
        for(i=0;i<n;i++)
            {
                //creation of individual isolated nodes
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter node %d :",i+1);
                scanf("%d",&(newnode->data));
                newnode->next=NULL;

                //insertion of 1st node
                if(head==NULL)
                {
                    head=newnode;
                }
                //insertion of other nodes
                else
                {
                    //temp is a iterating value for inserting nodes and set to head
                    temp=head;
                    //check until temp->next is not NULL
                    while(temp->next!=NULL)
                    {
                        //temp will now point the last node of list to which newnode is to be added
                        temp=temp->next;
                        //throws out of loop after reaching the last node of existing list
                    }
                    //now the temp itself is moved to the new node making it a last node
                        temp->next=newnode;
                }

            }
        return head;
}


void display(struct node *head)
{
     temp=head;
    //execute loop until the temp->next=null , i.e, the last node.
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        //update the temp node for each iteration
        temp=temp->next;
    }
    printf("NULL");
}

struct node* insertAtStart(struct node *newnode)
{
    int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter a node to add in the beginning of list:");
    scanf("%d",&(newnode->data));
    newnode->next=head;
    head=newnode;
    printf("Node inserted at the beginning successfully!\n");
    return head;
}

struct node* insertAtEnd(struct node *newnode)
{
    int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter a node to insert at the end:");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    printf("Node inserted at the end successfully!\n");
    return head;
}

struct node* insertAtSpec(struct node *newnode)
{
    int pos,data,i;
    printf("\nEnter the position of node to insert:");
    scanf("%d",&pos);
    if(pos>lastcount || pos<1)
    {
        printf("Invalid Position!");
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the node data:");
        scanf("%d",(&newnode->data));
        newnode->next=temp->next;
        temp->next=newnode;
    }

    return head;
}


struct node* deleteAtStart(struct node *head)
{
    temp=head;
    head=head->next;
    free(temp);
    printf("\n\nDeletion of 1st node !\n");
    return head;
}

struct node* delAtEnd(struct node *head)
{
    struct node *prevnode;
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
        if(temp==head)
        {
            head=NULL;
        }
        else
        {
            prevnode->next=NULL;
        }
        free(temp);
    }

    return head;
}

struct node* delAtSpec(struct node* head)
{
    struct node *position;
    int pos,i=1;
    temp=head;
    printf("Enter the position of element to be deleted:");
    scanf("%d",pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    position=temp->next;
    temp->next=position->next;
    free(position);

    return head;
}

void countNodes(struct node *head)
{
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("\nTotal no. of nodes = %d",count);
}

void reverseList(struct node *head)
{
    struct node *previous=NULL, *current, *next=NULL;
    current=next=head;
    while(current!=NULL)
    {
        //next pointer is sent to next of current node
        next=current->next;
        //current node's next is set to previous node
        current->next=previous;
        //now the previous node is moved to next position
        previous=current;
        //the current node is now updated from its position by 1(position of nextnode at that time)
        current=next;
        //the loop will end after traversing until the next and current becomes NULL
        //At the end the previous node alone consists of the address of last node to be made as head
    }
    head=previous;
}

