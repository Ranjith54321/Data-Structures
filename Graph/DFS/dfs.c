#include<stdio.h>
#include<stdlib.h>
struct node{
	int nextnode;
	struct node *link;
};
struct stack{
	int *st;
};
struct node **createlist(int n){
	int i;
	struct node **t;
	t = (struct node**)malloc(n*sizeof(struct node*));
	for(i=0;i<n;i++)
		t[i] = (struct node*)malloc(sizeof(struct node));
	return t;
}
struct node **addlist(struct node **list,int **a,int n){
	struct node *t,*p;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==1){
				t = (struct node*)malloc(sizeof(struct node));
				t->nextnode = j;
				t->link = NULL;
				if(list[i]==NULL){
					list[i] = t;
				}
				else{
					p = list[i];
					while(p->link){
						p = p->link;
					}
					p->link = t;
				}
			}
		}
	}
	return list;
}
struct stack *createstack(int n){
	struct stack *t = (struct stack*)malloc(sizeof(struct stack));
	t->st = (int*)malloc(n*sizeof(int));
	return t;
}
void print(struct node **list,int n){
	struct node *t;
	int i;
	for(i = 0; i < n; i++)
	{
		if(list[i]!=NULL){
			t = list[i]->link;
			printf("%d ",i);
			while(t){
				printf("-> %d ",t->nextnode);
				t = t->link;
			}
			printf("\n");
		}
	}

}
void dfs(struct node **list,struct stack *stack,int pos){
		stack->st[pos] = 1;
		struct node *t = list[pos];
		printf("%d ",pos);
		while(t){
			if(stack->st[t->nextnode]==0)
			    dfs(list,stack,t->nextnode);
			t = t->link;
		}
}
int main(){
	int n,i,j,**a;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	a = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		a[i] = (int*)malloc(n*sizeof(int));
	printf("Enter the weight for the nodes\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	struct node **list = createlist(n);
	list = addlist(list,a,n);
	print(list,n);
	struct stack *stack = createstack(n);
	int pos;
	printf("enter the start node\n");
	scanf("%d",&pos);
	dfs(list,stack,pos);

	return 0;
}
