#include<stdio.h>
#include<stdlib.h>
struct node{
  int nextnode;
  struct node *link;
};

struct node **createlist(int n){
  struct node **t = (struct node**)malloc(n*sizeof(struct node));
  int i;
  for(i=0;i<n;i++)
    t[i]  = (struct node*)malloc(sizeof(struct node));

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
  

  return 0;
}
