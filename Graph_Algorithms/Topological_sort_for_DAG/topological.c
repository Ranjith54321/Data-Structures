#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int nextnode;
    struct node *link;
};
struct visit{
    int *v,*stack;
    int top;
};
struct node **createlist(int n){
    struct node **t;
    int i;
    t = (struct node**)malloc(n*sizeof(struct node*));
    for(i=0;i<n;i++)
        t[i] = (struct node*)malloc(sizeof(struct node));
    return t;
}

struct visit *createvisit(int n){
    struct visit *t = (struct visit*)malloc(sizeof(struct visit));
    t->v = (int*)malloc(n*sizeof(int));
    t->stack = (int*)malloc(n*sizeof(int));
    t->top = -1;
    return t;
}

void put(struct node ***list,int s,int e,int n){
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
void print(struct node **list,int n){
    struct node *p;
    int i;
    for(i=0;i<n;i++){
        if(list[i]!=NULL){
            printf("%d ",i);
            p = list[i]->link;
            while(p){
                printf("->%d ",p->nextnode);
                p = p->link;
            }
            printf("\n");
        }
    }

}

void topoutil(int pos,struct node **list,struct visit *vis){
    vis->v[pos] = 1;
    struct node *l = list[pos];
    while(l){
        if(vis->v[l->nextnode]==0)
            topoutil(l->nextnode,list,vis);
        l = l->link;
    }
    vis->top++;
    vis->stack[vis->top] = pos;
}
void topo(struct node **list,int n){
    int i;
    struct visit *visit = createvisit(n);
    for(i=0;i<n;i++){
        if(!visit->v[i])         // concentrate here
            topoutil(i,list,visit);
    }
    for(i=visit->top;i>=0;i--)
        printf("%d ",visit->stack[i]);
}

int main(){
    int n,e,snode,enode,i,pos;
    printf("enter the no of vertices and edges\n");
    scanf("%d %d",&n,&e);
    struct node **list = createlist(n);
    printf("enter the %d edges\n",e);
    for(i=0;i<e;i++){
        scanf("%d %d",&snode,&enode);
        put(&list,snode,enode,n);
    }
    printf("Normal representation\n");
    print(list,n);

    topo(list,n);
    

    return 0;
}
