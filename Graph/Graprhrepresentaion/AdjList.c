#include<stdio.h>
#include<stdlib.h>
struct node{
  int nextnode;
  struct node *link;
};
struct stack{
  int *visited;
  //int top;
};
struct queue
{
  int *b;
  int rear,front;
};
struct node **createlist(int n){
  struct node **t = (struct node**)malloc(n*sizeof(struct node));
  int i;
  for(i=0;i<n;i++)
    t[i]  = (struct node*)malloc(sizeof(struct node));

  return t;
}
struct stack *createstak(int n){
  struct stack *t = (struct stack*)malloc(sizeof(struct stack));
  t->visited = (int*)malloc(n*sizeof(int));
  //t->top = -1;

  return t;
}
struct queue *createqueue(int n){
  struct queue *t = (struct queue*)malloc(sizeof(struct queue));
  t->b = (int*)malloc(n*sizeof(int));
  t->front = 0;
  t->rear = 0;

  return t;
}

void put(struct node ***list,int s,int e,int n){
  int i,j;
    struct node *t,*p,**l = *(list);
    for(i=0;i<n;i++){
      if(s==i){
        t = (struct node*)malloc(sizeof(struct node));
        t->nextnode = e;
        t->link = NULL;
        if(l[i]==NULL){
          l[i] = t;
        }
        else{
            //printf("%d\n",e);
          p = l[i];
          while(p->link){
            p = p->link;
          }
          p->link = t;
        }
      }
      if(e==i){
          t = (struct node*)malloc(sizeof(struct node));
        t->nextnode = s;
        t->link = NULL;
        if(l[i]==NULL){
          l[i] = t;
        }
        else{
            //printf("%d\n",e);
          p = l[i];
          while(p->link){
            p = p->link;
          }
          p->link = t;
        }
      }
    }
}
void print(struct node **list,int n){
  int i;
    for(i=0;i<n;i++){
        if(list[i]!=NULL){
            struct node *p = list[i]->link;  // the values always store index 1 boz
            printf("%d",i);                     // the address strored on the  th index
            while(p){
                printf("-> %d",p->nextnode);
                p = p->link;
            }
            printf("\n");
        }
    }

}
int isqueueempty(struct queue *q){
  if(q->front == q->rear)
    return 0;
  else
    return 1;
}
void bfs(struct node **list,struct stack *s,struct queue *q,int pos){
  s->visited[pos] = 1;
  q->b[q->rear] = pos;
  q->rear = q->rear+1;

  while(isqueueempty(q)!=0){
    pos = q->b[q->front];
    q->front = q->front+1;

    printf("%d ",pos);

    struct node *p = list[pos]->link;
    while(p){
      if(!s->visited[p->nextnode]){
        s->visited[p->nextnode] = 1;
        q->b[q->rear] = p->nextnode;
        q->rear = q->rear+1;
      }
      p = p->link;
    }
  } 

}
int main(){
    
  int n,v,snode,enode,i;
  //printf("enter the no of node and endges\n");
  scanf("%d %d",&n,&v);
  struct node **list = createlist(n);
//  printf("%d no of edges\n",v);
  for(i=0;i<v;i++){
    scanf("%d %d",&snode,&enode);
    put(&list,snode,enode,n);
  }

  print(list,n);
  
  struct stack *stack = createstak(n);
  struct queue *queue = createqueue(n); 
  bfs(list,stack,queue,0);

  return 0;
}
