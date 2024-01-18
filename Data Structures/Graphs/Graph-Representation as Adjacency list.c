  //Representation of graph as an adjacency list

#include<stdio.h>
#include<stdlib.h>

/*GLOBAL DECLARATIONS*/
int vertices;

int i,j;

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *newnode=NULL,*temp=NULL;

/*FUNCTION PROTOTYPES*/
void readGraph(NODE*[]);

void printGraph(NODE*[]);

void printBFS(NODE*[vertices],int[vertices],int);

void printDFS(NODE*[vertices],int,int[vertices]);

/*MAIN FUNCTION*/
void main()
{
    /*LOCAL DECLARATIONS*/
    int ch;

    printf("Enter the no. of vertices:");
    scanf("%d",&vertices);

    //create an array of NODE type to store the vertices and extend their adjacency list
    NODE *adj[vertices];
    int visited[vertices];

    for(i=0;i<vertices;i++)
    {
        adj[i]=NULL;
    }

    int start;

    /*MAIN() STATEMENTS*/

    readGraph(adj);

    do
    {
        printf("\n\n----MENU----");
        printf("\n1.Print adjacency list\n2.BFS\n3.DFS\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printGraph(adj);
                    break;

            case 2: printf("\nEnter a vertex to start bfs:");
                    scanf("%d",&start);
                    printBFS(adj,visited,start);
                    break;

            case 3:printf("\nEnter a vertex to start dfs:");
                     scanf("%d",&start);

                     printf("\nThe DFS:");
                    for(i=0;i<vertices;i++)
                    {
                        visited[i]=0;
                    }
                     printDFS(adj,start,visited);
                     break;

            case 4:break;

            default:printf("\nEnter a valid choice!");
        }

    }while(ch!=4);


}

/*FUNCTION DECLARATIONS*/

//read the graph with vertex and edges
void readGraph(NODE *arr[])
{
    int list;
    int data;

    for(i=0;i<vertices;i++)
    {
        printf("\nEnter the total vertices adjacent to %d: ",i);
        scanf("%d",&list);
        for(j=0;j<list;j++)
        {
            newnode=(NODE*)malloc(sizeof(NODE));
            printf("\nEnter the %d-vertex adjacent to %d :",j+1,i);
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;

            if(arr[i]==NULL)
            {
                arr[i]=newnode;
                printf("\n---INITIAL");
            }
            else
            {
                temp->next=newnode;
                printf("\n---temp");
            }
            temp= newnode;
        }
    }
}

//print the adjacency list
void printGraph(NODE *arr[])
{
    for(i=0;i<vertices;i++)
    {
        printf("\nThe vertices adjacent to %d are: ",i);
        temp=arr[i];
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}

//breadth first search
void printBFS(NODE *adj[vertices],int visited[vertices],int start)
{
    int queue[vertices],front=-1,rear=-1;
    for(i=0;i<vertices;i++)
    {
        queue[i]=0;
        visited[i]=0;
    }
    queue[++rear]=start;
    queue[front++];

    printf("\nThe BFS from %d is: ",start);
    while(front<=rear)
    {
        start=queue[front++];
        temp=adj[start];
        visited[start]=1;
        printf("%d ",start);

        while(temp!=NULL)
        {
            if(visited[temp->data]!=1)
            {
                queue[++rear]=temp->data;
                visited[temp->data]=1;
            }
            temp=temp->next;
        }
    }
}

//depth first search
void printDFS(NODE *adj[vertices],int start,int visited[vertices])
{
    visited[start]=1;
    printf("%d ",start);
    NODE *temp1=adj[start];

    while(temp1!=NULL)
    {
        if(visited[temp1->data]!=1)
            printDFS(adj,temp1->data,visited);
        temp=temp->next;
    }

}
