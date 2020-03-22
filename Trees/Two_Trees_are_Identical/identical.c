#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
    int data;
    struct tree *right,*left;
};
struct queue
{
    int front, rear;
    int size;
    struct tree* *array;
};
int identicalTrees(struct tree* a, struct tree* b);
struct tree* newNode(int data);
struct queue* createQueue(int size);
void enqueue(struct tree *root, struct queue* queue);
struct tree* dequeue(struct queue* queue);
void insert(struct tree **root, int data, struct queue* queue);
int isepmty(struct queue *q);

struct queue* createQueue(int size){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = 0;
    q->rear = 0;
    q->size = size;
    q->array = (struct tree**)malloc(size*sizeof(struct tree));
    return q;
}
struct tree *newNode(int data){
    struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
void enqueue(struct tree *root, struct queue* queue){
    queue->array[queue->rear] = root;
    queue->rear = queue->rear+1;
}
struct tree* dequeue(struct queue* queue){
    struct tree *temp = queue->array[queue->front];
    queue->front = queue->front+1;
    return temp;
}
int isempty(struct queue *q){
    return q->front==q->rear;
}
void insert(struct tree **root, int data, struct queue* queue){
    if((*root)==NULL){
        (*root) = newNode(data);
    }
    else{
        enqueue(*root,queue);
        while(!isempty(queue)){
            struct tree *temp = dequeue(queue);
            if(!temp->left){
                temp->left = newNode(data);
                break;
            }
            else{
                enqueue(temp->left,queue);
            }
            if(!temp->right){
                temp->right = newNode(data);
                break;
            }
            else{
                enqueue(temp->right,queue);
            }
        }
    }
}
int identicalTrees(struct tree* a, struct tree* b){
    if(a==NULL && b==NULL){
        return 1;
    }
    if(a!=NULL && b!=NULL){
        return(a->data==b->data && identicalTrees(a->left,b->left) && identicalTrees(a->right,b->right));
    }
    else{
        return 0;
    }
}
int main()
{
	int data,t;
	struct tree *root1 = NULL;
	struct tree *root2 = NULL;
	char s[3];
	struct queue *queue1 = createQueue(50);
	struct queue *queue2 = createQueue(50);
	do{
	    printf("Data to be inserted in 1st tree or 2nd tree?\n");
	    scanf("%d",&t);
	    if(t==1){
	        printf("Enter the element to be inserted in the 1st tree\n");
	        scanf("%d",&data);
	        insert(&root1,data,queue1);
	    }
	    else{
	        printf("Enter the element to be inserted in the 2nd tree\n");
	        scanf("%d",&data);
	        insert(&root2,data,queue2);
	    }
	    printf("Do you want to insert element?\n");
	    scanf("%s",s);
	}while(strcmp(s,"yes")==0);
	if(identicalTrees(root1, root2)){
	    printf("Both tree are identical.\n");
	}
	else{
	    printf("Trees are not identical.\n");
	}
	
	return 0;
}
