#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int *st;
};
struct stack *careatestack(int n){
	struct stack *t = (struct stack*)malloc(sizeof(struct stack));
	t->st = (int*)calloc(n,sizeof(int));
	return t;
}
void dfs(int **g,int *size,struct stack *stack,int pos){
	stack->st[pos] = 1;
	printf("%d ",pos);
	for(int i=0;i<size[pos];i++){
		if(stack->st[g[pos][i]]==0)
			dfs(g,size,stack,g[pos][i]);
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
	struct stack *t = careatestack(v);
	printf("directed or un-directed (yes/no)\n");
	printf("enter the %d no of edges\n",e);
	scanf("%s",ch);
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
	dfs(g,size,t,st);
	return 0;
}
