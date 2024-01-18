//Doubly circular linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}NODE;

NODE *head=NULL,*tail=NULL,*newnode,*temp;

void createDCLL(void);

void displayDCLL(void);

int lengthOfList(void);

void insertAtBeginning(void);

void insertAtEnd(void);

void insertAtSpec(void);

void delAtBeginning(void);

void delAtEnd(void);

void delAtSpec(void);

void reverseDCLL(void);

void main()
{
    //creating a Doubly circular linked list
    createDCLL();

    //displaying a DCLL
      displayDCLL();

    /*
    //insertion at the beginning of DCLL
    insertAtBeginning();
    displayDCLL();

    //insertion at the end of DCLL
    insertAtEnd();
    displayDCLL();

    //insertion at specific position of DCLL
    insertAtSpec();
    displayDCLL();

    //deletion of node at beginning of list
    delAtBeginning();
    displayDCLL();

    //deletion of node at the end of list
    delAtEnd();
    displayDCLL();

    //deletion of node from a specific position
    delAtSpec();
    displayDCLL();
    */
    //reverse the DCLL
    reverseDCLL();  ***function must be reviewed***
    displayDCLL();

    printf("\nLength of list= %d",lengthOfList());
}


void createDCLL()
{
    int n;
    printf("Enter the number of nodes to create:");
    scanf("%d",&n);


    if(n<=0)
    {
        printf("\nThe List must have at least one node!");
    }
    else
    {
        printf("\n-----Creating Doubly Circular Linked List-----");
        for(int i=0;i<n;i++)
        {
            newnode=(NODE*)malloc(sizeof(NODE));
            printf("\nEnter node %d data:",i+1);
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            newnode->prev=NULL;

            if(head==NULL)
            {
                head=tail=newnode;
            }
            else
            {
                tail->next=newnode;
                newnode->prev=tail;
                newnode->next=head;
                head->prev=newnode;
                tail=newnode;
            }
        }

        printf("\nList created successfully!");
    }



}

void displayDCLL()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nLIST IS EMPTY !");
    }
    else
    {
        printf("\n\nList:\t");
        while(temp!=tail)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
    printf("\n\nhead=%d",head->data);
    printf("\ntail=%d",tail->data);
}

int lengthOfList()
{
    int count=1;     //count initiated from one since the while condition omits the tail node
    if(head!=NULL)
    {
        temp=head;
        while(temp->next!=head)//loop is true only till (tail->prev) node.
        {
            count++;
            temp=temp->next;
        }

    }
    else
    {
        count=0;
    }


    return count;
}

void insertAtBeginning()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("\n\nEnter node data to insert at beginning of list:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else
    {
        temp=head;
        newnode->next=temp;
        tail->next=newnode;
        newnode->prev=tail;
        head=newnode;
    }
}

void insertAtEnd()
{
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("\n\nEnter data to insert at the end of list:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==NULL)
    {
        head=tail=newnode;
        head->next=newnode;
        head->prev=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
}

void insertAtSpec()
{
    int pos,i=1,len;
    printf("\n\nEnter the position to insert node:");
    scanf("%d",&pos);
    len=lengthOfList();

    if(pos<1 || pos>len+1)
    {
        printf("\nInvalid position!");
    }
    if(pos==1)
    {
        insertAtBeginning();
    }
    else if(pos==len+1)
    {
        insertAtEnd();
    }
    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        printf("\n\nEnter data to insert at the end of list:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;

        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }

}

void delAtBeginning()
{
    int len=lengthOfList();
    if(len<=0)
    {
        printf("\n\nThe list is empty!");
    }
    else
    {
        temp=head;
        head=temp->next;
        tail->next=head;
        free(temp);

        printf("\nDeletion from beginning done successfully!");
    }
}

void delAtEnd()
{
    int len=lengthOfList();
    if(len<=0)
    {
        printf("\n\nThe list is empty!");
    }
    else
    {
        temp=tail;
        tail=temp->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);

        printf("\nDeletion of node from end done successfully!");
    }
}

void delAtSpec()
{
    int pos,len=lengthOfList();
    printf("\n\nEnter the position of node to delete:");
    scanf("%d",&pos);
    if(pos<=0 || pos>len)
    {
        printf("\nInvalid Position!");
    }
    else if(pos==1)
    {
        delAtBeginning();
    }
    else if(pos==len)
    {
        delAtEnd();
    }
    else
    {
        NODE *position;
        int i=1;
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        position=temp->next;
        temp->next=position->next;
        position->next->prev=temp;
        free(position);

        printf("\nDeletion from position- %d is successful!",pos);
    }
}

void reverseDCLL()
{
    NODE *nextnode;
    temp=head;
    while(temp!=tail)
    {
        nextnode=temp->next;
        temp->next=temp->prev;
        temp->prev=nextnode;
        temp=nextnode;
        printf("\n222");
    }
    temp=head;
    head=tail;
    tail=temp;

    printf("\nThe list is reversed successfully!");
}

