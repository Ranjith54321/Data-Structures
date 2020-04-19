#include <stdio.h>
#include <stdlib.h>
 
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
 
struct subset
{
    int parent;
    int rank;
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
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    if(subsets[i].parent!=i)
        subsets[i].parent = find(subsets,subsets[i].parent);
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xr = find(subsets,x);
    int yr = find(subsets,y);
    
    if(subsets[xr].rank < subsets[yr].rank){
        subsets[xr].parent = yr;
        subsets[yr].rank++;
    }
    if(subsets[yr].rank < subsets[xr].rank){
        subsets[yr].parent = xr;
        subsets[xr].rank++;
    }
    else{
        subsets[xr].parent = yr;
        subsets[yr].rank++;
    }
}
struct subset *createsubset(int v){
    struct subset *s = (struct subset*)malloc(v*sizeof(struct subset));
    return s;
}
// The main function to check whether a given graph contains cycle or not
int isCycle( struct Graph* graph )
{
    struct subset *s = createsubset(graph->V);
    int i;
    for(i=0;i<(graph->V);i++){
        s[i].parent = i;
        s[i].rank = 0;
    }
    //memset(s,0,sizeof(struct subset)*(graph->V));
    
    for(i=0;i<(graph->E);i++){
        int x = find(s,graph->edge[i].src);
        int y = find(s,graph->edge[i].dest);
        
        if(x==y)
            return 1;
        
        Union(s,x,y);
    }
    return 0;
}
 
// Driver program to test above functions
int main()
{
 
    int V = 3, E = 3,i;
    struct Graph* graph = NULL;
	printf("Enter the number of egdes and vertices\n");
	scanf("%d%d",&E,&V);
 
	graph = createGraph(V, E);
	for(i=0;i<E;i++){
		printf("Enter the source and destination of edge %d\n",i);
		scanf("%d%d",&(graph->edge[i].src),&(graph->edge[i].dest));
	}

    if (isCycle(graph))
        printf( "Graph contains cycle\n" );
    else
        printf( "Graph doesn't contain cycle\n" );
 
    return 0;
}
