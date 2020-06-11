#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isempty(int f,int r){ return (f==r)?1:0;}
void bfs(int **g,int *size,int *visit,int n,int st){
	int i;
	int *q = (int*)malloc(n*sizeof(int));
	int f=0,r=0;
	q[r] = st;
	r++;
	while(!isempty(f,r)){
		printf("%d ",q[f]);
		visit[q[f]] = 1;
		st = q[f];
		f++;
		for(i=0;i<size[st];i++){
			if(visit[g[st][i]]!=1){
				q[r] = g[st][i];
				visit[g[st][i]] = 1;
				r++;
			}
		}
	}
}
int main(){
	int v,e,s,d,i;
	char ch[4];
	printf("enter the no of vertices and edges\n");
	scanf("%d %d",&v,&e);
	int **g = (int**)malloc(v*sizeof(int*));
	for(i=0;i<v;i++)
		*(g+i) = (int*)calloc(v,sizeof(int));
	int *size = (int*)calloc(v,sizeof(int));
	int *visit = (int*)calloc(v,sizeof(int));
	printf("directed or un-directed (yes/no)\n");
  scanf("%s",ch);
	printf("enter the %d no of edges\n",e);
	if(strcmp(ch,"yes")==0){
		for(i=0;i<e;i++){
			scanf("%d %d",&s,&d);
			g[s][size[s]++] = d;
		}
	}
	else{
		for(i=0;i<e;i++){
			scanf("%d %d",&s,&d);
			g[s][size[s]++] = d;
			g[d][size[d]++] = s;
		}
	}
	int j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	int st;
	printf("enter the start vertex\n");
	scanf("%d",&st);
	bfs(g,size,visit,v,st);
	return 0;
}
