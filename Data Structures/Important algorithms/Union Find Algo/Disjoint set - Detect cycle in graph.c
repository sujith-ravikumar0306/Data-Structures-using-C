// DISJOINT SETS/ UNION-FIND Algorithm
//It is used to detect the cycle in graph

#include<stdio.h>
#include<stdlib.h>

//GLOBAL DECLARATIONS

struct Edge{

    int src;
    int dest;
};

struct graph
{
    int V,E;
    struct Edge* edges;
};

//FUNCTION PROTOTYPES

struct graph* createGraph(int , int);

int findParent(int [], int);

void unionSets(int[], int, int);

int isCycle(struct graph*);

void main()
{
    int V=4;    //no of edges
    int E=4;    //no of vertices

    struct graph* graph= createGraph(V, E);

    //add edges
    graph->edges[0].src=0;
    graph->edges[0].dest=1;

    graph->edges[1].src=1;
    graph->edges[1].dest=2;

    graph->edges[2].src=2;
    graph->edges[2].dest=3;

    graph->edges[3].src=3;
    graph->edges[3].dest=1;

    if(isCycle(graph))
    {
        printf("\nGraph contains a cycle");
    }
    else
    {
        printf("\nGraph has no cycle");
    }
}


//FUNCTION DEFINITIONS

//create a graph with V vertices and E edges
struct graph* createGraph(int V, int E)
{
    struct graph* Graph=(struct graph*)malloc(sizeof(struct graph));
    Graph->V=V;
    Graph->E=E;
    Graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    return Graph;
}

//find parent node using UNION-FIND algorithm

int findParent(int parent[], int i)
{
    if (parent[i]==-1)
        return -1;
    return findParent(parent,parent[i]);
}

//perform union of two sets by rank

void unionSets(int parent[], int x, int y)
{
    int xset= findParent(parent, x);
    int yset= findParent(parent, y);

    parent[xset]=yset;
}

//check if graph contains a cycle

int isCycle(struct graph *Graph)
{
    int i;
    int *parent=(int) malloc (Graph->V * (sizeof(int)));

    for(i=0; i<Graph->V;i++)
    {
        parent[i]=-1;
    }

    for(i=0;i<Graph->V;i++)
    {
        int x= findParent(parent, Graph->edges[i].src);
        int y= findParent(parent, Graph->edges[i].dest);

        if (x==y)
            return 1;
        unionSets(parent, x, y);
    }

    return 0;
}

