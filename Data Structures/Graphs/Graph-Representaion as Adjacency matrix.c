//Undirected graph in c using adjacency matrix

#include<stdio.h>

/*GLOBAL VARIABLES*/
int vertices,i,j;

/*FUNCTION PROTOTYPES*/
void printMatrix(int [vertices][vertices]);

void bfs(int[vertices][vertices],int);

void dfs(int[][vertices],int [],int);

int main()
{
    int ch,root;
    int src,dest;

    printf("Enter the no. of vertices in graph (0 to n-1):");
    scanf("%d",&vertices);

    int adj[vertices][vertices];
    int visited[vertices];

    //initializing all elements of matrix to zero
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            adj[i][j]=0;
        }
    }

    printf("\nEnter the vertex in (src-dest) form and -1 to represent end.\n");
    while(src!=-1 && dest!=-1)
    {
        printf("\nEnter source vertex:");
        scanf("%d",&src);
        printf("Enter destination vertex:");
        scanf("%d",&dest);
        adj[src][dest]=1;
        adj[dest][src]=1;
    }

    do
    {
        printf("\n\n1.Print matrix\n2.BFS\n3.DFS\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printMatrix(adj);
                    break;
            case 2:printf("Enter vertex to start BFS:");
                    scanf("%d",&root);
                    bfs(adj,root);
                    break;
            case 3:printf("Enter vertex to start DFS:");
                    scanf("%d",&root);
                    //initialising all the visited nodes to zero
                    for(i=0;i<vertices;i++)
                    {
                        visited[i]=0;
                    }
                    dfs(adj,visited,root);
                    break;
            case 4:break;

            default :printf("Wrong choice entered!\n");
        }
    }while(ch!=4);

}



/*FUNCTION DECLARATIONS*/

//print adjacency matrix for graph
void printMatrix(int adj[vertices][vertices])
{
    printf("\nAdjacency Matrix:\n\n");

    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

}

//breadth first search of graph
void bfs(int adj[vertices][vertices],int root)
{
    int visited[vertices];
    int queue[vertices],front=-1,rear=-1;

    for(i=0;i<vertices;i++)
    {
        queue[i]=0;
        visited[i]=0;
    }
    //initialize the root as first into the stack
    queue[front++];
    queue[++rear]=root;
    visited[root]=1;

    printf("\n\nBFS:\n");
    //stack operations until dead end or stack is empty
    while(front<=rear)
    {
        root=queue[front++];
        printf("%d",root);

        //check for unvisited vertex to avoid unnecessary backtracking
        for(i=0;i<vertices;i++)
        {
            if(adj[root][i]==1 && visited[i]!=1)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}

//depth first search of a graph
/*   NOTE: We know that DFS can be implemented using a stack. Since the function calls are all stored in memory along
stack fashion, just calling the function recursively for changing values of i(nodes) will give you the DFS.  */
void dfs(int adj[][vertices],int visited[],int root)
{
    printf("%d ",root);
    visited[root]=1;
    for(i=0;i<vertices;i++)
    {
        if(adj[root][i]==1 && visited[i]!=1)
        {
            dfs(adj,visited,i);
        }
    }
}


