#include<stdio.h>
#include<stdlib.h>
struct node{
	int nextnode;
	struct node *link;
};
struct stack{
	int *a;
	int top;
};
struct visit
{
	int *visited;
};
struct node **createlist(int n){
	struct node **t;
	int i;
	t = (struct node**)malloc(n*sizeof(struct node*));
	for(i=0;i<n;i++)
		t[i] = (struct node*)malloc(sizeof(struct node));
	return t;
}
struct stack *createstack(int n){
	struct stack *t = (struct stack*)malloc(sizeof(struct stack));
	t->a = (int*)malloc(n*sizeof(int));
	t->top = -1;
	return t;
}
struct visit *ceatevisit(int n){
	struct visit *t = (struct visit*)malloc(sizeof(struct visit));
	t->visited = (int*)malloc(n*sizeof(int));
	return t;
}
void putlist(struct node ***list,int s,int e,int n){
	struct node **l = *(list),*p,*t;
	int i;
	for(i=0;i<n;i++){
		if(s==i){
			t = (struct node*)malloc(sizeof(struct node));
			t->nextnode = e;
			t->link = NULL;

			if(l[i]==NULL){
				l[i] = t;
			}
			else{
				p = l[i];
				while(p->link){
					p = p->link;
				}
				p->link = t;
			}
		}
	}
}
void print(struct node **l,int n){
	int i;
	struct node *p;
	for(i=0;i<n;i++){
		if(l[i]!=NULL){
			printf("%d ",i);
			p = l[i]->link;
			while(p){
				printf("-> %d ",p->nextnode);
				p = p->link;
			}
			printf("\n");
		}
	}
}
void printpaths(int st,int end,struct stack *stk,struct node **list,struct visit *visi){
	visi->visited[st] = 1;
	if(st==end){
		int i;
		for(i=0;i<=stk->top;i++){
			printf("%d ",stk->a[i]);
		}
		visi->visited[st] = 0;
		printf("\n");
	}
	else{
		struct node *p = list[st]->link;
		while(p){
			if(!(visi->visited[p->nextnode])){
				stk->top++;
				stk->a[stk->top] = p->nextnode;
				printpaths(p->nextnode,end,stk,list,visi);

				stk->top--;
				
			}
			p = p->link;
		}
	}
	visi->visited[st] = 0;
}
int main(){
	int n,e,snode,enode,i,start,end;
	printf("enter the no of node and edges\n");
	scanf("%d %d",&n,&e);
	printf("enter the %d edges\n",e);
	struct node **list = createlist(n);
	for(i=0;i<e;i++){
		scanf("%d %d",&snode,&enode);
		putlist(&list,snode,enode,n);
	} 

	print(list,n);

    printf("enter the staring and ending node\n");
    scanf("%d %d",&start,&end);
    struct stack *stack = createstack(n);
    struct visit *visit = ceatevisit(n);
    stack->top++;
    stack->a[stack->top] = start;
    printpaths(start,end,stack,list,visit);
	return 0;
}
