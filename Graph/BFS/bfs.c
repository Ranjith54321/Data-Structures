#include<stdio.h>
#include<stdlib.h>
struct node{
	int nextnode;
	struct node *link;
};
struct queue{
	int *que;
	int front,rear;
};
struct stack{
	int *st;
};
struct node **createlist(int n){
	struct node **t;
	int i;
	t = (struct node**)malloc(n*sizeof(struct node*));
	for(i=0;i<n;i++)
		t[i] = (struct node*)malloc(sizeof(struct node));

	return t;
}
struct queue* createqueue(int n){
	struct queue *t = (struct queue*)malloc(sizeof(struct queue));
	t->que = (int*)malloc(n*sizeof(int));
	t->front = t->rear = 0;
	return t;
}
struct stack *createstack(int n){
	struct stack *t = (struct stack*)malloc(sizeof(struct stack));
	t->st = (int*)malloc(n*sizeof(int));
	return t;
}
struct node **put(struct node **list,int s,int e,int n){
	struct node **l = list,*t,*p;
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
		}// one direction
		if(e==i){
			t = (struct node*)malloc(sizeof(struct node));
			t->nextnode = s;
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
		}// one direction
	}
	return list;
}
void print(struct node **list,int n){
	struct node *p;
	int i;
	for(i=0;i<n;i++){
		if(list[i]!=NULL){
			printf("%d ",i);
				p = list[i]->link;
				while(p){
					printf("-> %d ",p->nextnode);
					p = p->link;
				}
				printf("\n");
			}
	}
}
int isqueempty(struct queue *q){
	if(q->front==q->rear)
		return 0;
	else
		return 1;
}
void bfs(struct node **list,struct queue *queue,struct stack *stack,int pos){
		stack->st[pos] = 1;
		queue->que[queue->rear] = pos;
		queue->rear = queue->rear+1;

		while(isqueempty(queue)!=0){
			pos = queue->que[queue->front];
			queue->front = queue->front+1;
			printf("%d ",pos);
			struct node *p = list[pos]->link; // here vvvvvv important
			while(p){
				if(stack->st[p->nextnode]==0){
					queue->que[queue->rear] = p->nextnode;
					queue->rear = queue->rear+1;
					stack->st[p->nextnode] = 1;
				}
				p = p->link;
			}
		}
}
int main(){
	int n,e,snode,enode,i,pos;
	printf("enter the no of vertices and edges\n");
	scanf("%d %d",&n,&e);
	struct node **list = createlist(n);
	printf("%d no of edges\n",e);
	for(i=0;i<e;i++){
		scanf("%d %d",&snode,&enode);
		list = put(list,snode,enode,n);
	}
	printf("normal printed way\n");
	print(list,n);

	// for bfs operation we need queue stack
	struct queue *queue = createqueue(n);
	struct stack *stack = createstack(n);
	printf("print in BFS way\n");
	printf("enter the starting vertices\n");
	scanf("%d",&pos);
	bfs(list,queue,stack,pos);

	return 0;
}
