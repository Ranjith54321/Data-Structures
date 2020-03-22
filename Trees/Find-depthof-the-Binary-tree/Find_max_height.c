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
int maxDepth(struct tree* node); 
struct tree* newNode(int data); 
struct queue* createQueue(int size); 
void enqueue(struct tree *root, struct queue* queue); 
struct tree* dequeue(struct queue* queue);
void insert(struct tree **root, int data, struct queue* queue);
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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void enqueue(struct tree *root,struct queue *queue){
    queue->array[queue->rear] = root;
    queue->rear = queue->rear+1;
}
struct tree *dequeue(struct queue *queue){
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
int maxDepth(struct tree *node){
    if(!node)
        return 0;
    else{
        int ldepth = maxDepth(node->left);
        int rdepth = maxDepth(node->right);
        
        if(ldepth>rdepth)
            return ldepth+1;
        else 
            return rdepth+1;
    }
}
int main()
{
    int data;
    struct tree *root = NULL;
    char s[3];
    struct queue *queue = createQueue(50);
    do{
        printf("Enter the element to be inserted in the tree\n");
            scanf("%d",&data);          
        insert(&root, data, queue);
    printf("Do you want to insert another element?\n");
              scanf("%s",s);
    }while(strcmp(s,"yes")==0);
    printf("Hight of tree is %d\n",maxDepth(root));
	return 0;
}
