//Graph --- Adjacency matrix and Adjacency list representation

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node ** convmattolist(int **,int,char *);
void printlist(struct node **,int);
void printadjmatrix(int **,int);

struct node
{
	int nodeno;
	int edgeweight;
	struct node *link;
};


int main()
{
	int **A;
	int rows,edges,snode,enode,weight;
	int i;
	char directed[4];

	struct node **list;


	printf("Please enter the number of nodes in the graph\n");
	scanf("%d",&rows);

	printf("Please enter the number of edges in the graph\n");
	scanf("%d",&edges);

	printf("Is the graph directed\n");
	scanf("%s",directed);

	A = (int **)malloc(rows * sizeof(int *));
	for(i=0;i<rows;i++)
		*(A+i) = (int *) calloc(rows,sizeof(int));

	// Read the graph information and construct the adjacency matrix
	if(strcmp("yes",directed)!=0){
	    for(i=0;i<edges;i++){  // this is undirected so bi derctional
	        printf("Enter the start node, end node and weight of edge no %d\n",i);
	        scanf("%d %d %d",&snode,&enode,&weight);
	        A[snode][enode] = weight;
	        A[enode][snode] = weight;
	    }
	}
	else{
	    for(i=0;i<edges;i++){
	        printf("Enter the start node, end node and weight of edge no %d\n",i);
	        scanf("%d %d %d",&snode,&enode,&weight);
	        A[snode][enode] = weight;
	    }
	}
    // create list 
	list = convmattolist(A,rows,directed);
	printadjmatrix(A,rows);
	printlist(list,rows);
        return 0;

}


struct node ** convmattolist(int **A,int rows,char *dir)
{    
    struct node **t,*p,*cu;
    int i,j;
    t = (struct node**)malloc(sizeof(struct node*)); // t = (struct node**)malloc(rows*sizeof(struct node*)) 
    for(i=0;i<rows;i++){			// above is also valid
        t[i] = (struct node*)malloc(sizeof(struct node));
    }
	for(i=0;i<rows;i++){
	    for(j=0;j<rows;j++){
	        if(A[i][j]!=0){
	            p = (struct node*)malloc(sizeof(struct node));
	            p->nodeno = j;
	            p->edgeweight = A[i][j];
	            p->link = NULL;
	            if(t[i]==NULL){
	                t[i] = p;
	            }
	            else{
	                cu = t[i];
	                while(cu->link){
	                    cu = cu->link;
	                }
	                cu->link = p;
	            }
	        }
	    }
	}
	return t;
}

void printadjmatrix(int **A,int rows)
{   int i,j;
	printf("Adjacency Matrix Representation:\n");
	for(i=0;i<rows;i++){
	    for(j=0;j<rows;j++){
	        printf("%d ",A[i][j]);
	    }
	    printf("\n");
	}
}


void printlist(struct node **list,int rows)
{
	printf("Adjacency List Representation:\n");
	struct node *t;
	int i;
	for(i=0;i<rows;i++){
	    if(list[i]->link!=NULL){
	        t = list[i]->link;
	        printf("Node %d is connected to the following nodes:\n",i);
	        while(t){
	            printf("Node %d with edge weight %d\n",t->nodeno,t->edgeweight);
	            t = t->link;
	        }
	    }
	}

}
