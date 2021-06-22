#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// a structure to represent an edge in graph
struct Edge
{
    int src, dest;
};
 
// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A utility function to find the subset of an element i
int find(int parent[], int i)
{
	if(parent[i]==-1)
	    return i;
	return find(parent,parent[i]);
}
 
// A utility function to do union of two subsets
void Union(int parent[], int x, int y) // important note : don't use union bcoz union (will show error) is a key word available in c so use Union 
{
	int xset = find(parent,x);
	int yset = find(parent,y);
	if(xset!=yset)
	    parent[xset] = yset;
}
 
// The main function to check whether a given graph contains cycle or not
int isCycle( struct Graph* graph )
{
	int *parent = (int*)malloc(sizeof(int)*(graph->V));
	memset(parent,-1,sizeof(int)*(graph->V));
	int i;
	for(i=0;i<(graph->E);i++){
	    int x = find(parent,graph->edge[i].src);
	    int y = find(parent,graph->edge[i].dest);
	    
	    if(x==y)
	        return 1;
	        
	    Union(parent,x,y);
	}
	return 0;
}
 
// Driver program to test above functions
int main()
{
   
    int edge,vertex,i;
    struct Graph* graph = NULL;
    printf("Enter the number of egdes and vertices\n");
    scanf("%d%d",&edge,&vertex);
	
    graph = createGraph(vertex,edge);
    for(i=0;i<edge;i++){
	printf("Enter the source and destination of edge %d\n",i);
  	scanf("%d%d",&(graph->edge[i].src),&(graph->edge[i].dest));
    }
    if (isCycle(graph))
        printf( "Graph contains cycle\n" );
    else
        printf( "Graph doesn't contain cycle\n" );
    return 0;
}
