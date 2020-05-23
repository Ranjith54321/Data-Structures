#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree{
  int data;
  struct tree * left;
  struct tree * right;
};

struct queue
{
    int front, rear;
    int size;
    struct tree* *array;
};


struct tree* newNode(int);
struct queue* createQueue(int);
void enqueue(struct tree *, struct queue*);
struct tree* dequeue(struct queue*);
void insert(struct tree **, int, struct queue*);
unsigned int getLeafCount(struct tree*); 




int main()
{
    int n;
    char ch[10];
    struct tree * p;
    p=NULL;
    struct queue * q;
    q=createQueue(100);
    do
    {
        printf("Enter the element to be inserted in the tree\n");
        scanf("%d",&n);
        insert(&p,n,q);
        printf("Do you want to insert another element?\n");
        scanf("%s",ch);
    }while((strcmp(ch,"yes"))==0);
    unsigned int x= getLeafCount(p);
    printf("Leaf count of the tree is %d\n",x);
    return 0;
}


void insert(struct tree **root, int data, struct queue* queue)
{
    struct tree * t,*q;
    t=newNode(data);
    if(*root==NULL)
    {
        *root=t;
        enqueue(t,queue);
    }
    else
    {
        q=queue->array[queue->front];
        if(q->left==NULL)
        {
            q->left=t;
            enqueue(t,queue);
        }
        else if(q->right==NULL)
        {
            q->right=t;
            enqueue(t,queue);
        }
    if(q->left!=NULL && q->right!=NULL && q!=NULL)
    {
        dequeue(queue);
    }
    }
    
}


struct queue* createQueue(int size)
{
    struct queue * p=(struct queue *)malloc(sizeof(struct queue));
    p->front=-1;
    p->rear=-1;
    p->size=size;
    p->array=(struct tree **)malloc(sizeof(struct tree)*size);
    int i;
    for(i=0;i<size;i++)
    {
        p->array[i]=NULL;
    }
    return p;
}

void enqueue(struct tree *root, struct queue* queue)
{
    if(queue->rear==(queue->size)-1)
    {
        return;
    }
    else if(queue->rear==-1)
    {
        queue->rear++;
        queue->front++;
    }
    else
    queue->rear++;
    queue->array[queue->rear]=root;
}

struct tree* dequeue(struct queue* queue)
{
    if(queue->front==-1)
    {
        return NULL;
    }
    struct tree *t=queue->array[queue->front];
    if(queue->front==queue->rear)
    {
        queue->front=-1;
        queue->rear=-1;
    }
    else
    {
        queue->front++;
    }
    return t;
}

struct tree* newNode(int data)
{
    struct tree * t=(struct tree *)malloc(sizeof(struct tree));
    t->data=data;
    t->left=NULL;
    t->right=NULL;
    return t;
}


unsigned int getLeafCount(struct tree* node)
{
    if(node == NULL)        
    return 0; 
  if(node->left == NULL && node->right==NULL)       
    return 1;             
  else 
    return getLeafCount(node->left)+ 
           getLeafCount(node->right);
}
