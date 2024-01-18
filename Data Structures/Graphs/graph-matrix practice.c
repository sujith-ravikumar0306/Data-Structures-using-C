#include<stdio.h>
int vertices;
int i,j;

//print adjacency matrix
void printMatrix(int arr[vertices][vertices])
{
    printf("\n\nAdjacency Matrix:\n");
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

//breadth first search
void bfs(int arr[vertices][vertices],int start)
{
    int visited[vertices];
    int queue[vertices],front=-1,rear=-1;
    for(i=0;i<vertices;i++)
    {
        visited[i]=0;
        queue[i]=0;
    }
    queue[front++];
    queue[++rear]=start;
    visited[start]=1;

     while(front<=rear)
        {
            start=queue[front++];
            printf("%d ",start);
            for(i=0;i<vertices;i++)
            {
                if(arr[start][i]==1 && visited[i]!=1)
                {
                    queue[++rear]=i;
                    visited[i]=1;
                }

            }
        }


}

//depth first search
void dfs(int arr[vertices][vertices],int visited[vertices],int start)
{
    printf("%d ",start);
    visited[start]=1;

    for(i=0;i<vertices;i++)
    {
        if(arr[start][i]==1 && visited[i]!=1)
        {
            dfs(arr,visited,i);
        }
    }

}


void main()
{
    printf("Enter the total vertices:");
    scanf("%d",&vertices);
    int arr[vertices][vertices];
    int visited[vertices];
    int src,dest;
    int start;

    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            arr[i][j]=0;
        }
    }
    printf("\nInput -1 to end the edges...\n");
    while(src!=-1 && dest!=-1)
    {
        printf("\nEnter the src:");
        scanf("%d",&src);
        printf("\nEnter the dest:");
        scanf("%d",&dest);
        arr[src][dest]=1;
        arr[dest][src]=1;
    }

    int ch;
    do
    {
        printf("\n\n----MENU----\n");
        printf("1.Print adjacency matrix\n2.BFS\n3.DFS\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printMatrix(arr);
                    break;
            case 2:printf("\nEnter a vertex to start BFS: ");
                    scanf("%d",&start);
                    bfs(arr,start);
                    break;
            case 3:for(i=0;i<vertices;i++)
                    {
                        visited[i]=0;
                    }
                    printf("\nEnter a vertex to start DFS: ");
                    scanf("%d",&start);
                    dfs(arr,visited,start);
                    break;
            case 4:break;
            default :printf("\nEnter a valid choice!");

        }

    }while(ch!=4);



}
