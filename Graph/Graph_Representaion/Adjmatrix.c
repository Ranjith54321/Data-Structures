#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void matrix(int **,int);
int main()
{
  int n,e,i,**w,c,b;
   char ch[5];
  printf("Please enter the number of nodes in the graph\n");
  scanf("%d",&n);
  printf("Please enter the number of edges in the graph\n");
  scanf("%d",&e);
  w=(int**)malloc(n*sizeof(int*));
  for(i=0;i<n;i++)
   {
    *(w+i)=(int *)calloc(n,sizeof(int));
   }
  printf("Is the graph directed\n");
  scanf("%s",ch);
    if(strcmp("yes",ch)!=0)
  {
      for(i=0;i<e;i++){
        printf("Enter the start node, end node and weight of edge no %d\n",i);
        scanf("%d %d",&c,&b);
        scanf("%d",&w[c][b]);
        w[b][c] = w[c][b];
      }
      printf("\n");
  }
  else
{
    for(i=0;i<e;i++){
        printf("Enter the start node, end node and weight of edge no %d\n",i);
        scanf("%d %d",&c,&b);
        scanf("%d",&w[c][b]);
        //w[b][c] = w[c][b];
      }
      printf("\n");
}  
printf("\n");
 matrix(w,n);
 
 return 0;
}

void matrix(int **w,int n)
{
    int i,j;
    printf("Adjacency Matrix Representation:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",w[i][j]);
        }
        printf("\n");
    }
}
