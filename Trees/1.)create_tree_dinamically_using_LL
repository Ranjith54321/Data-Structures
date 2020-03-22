#include <stdio.h>
#include <stdlib.h>
struct node
{
struct node *left, *right;
int data;
};
struct queue
{
struct node *arr[100];
int f,r;
};
void enqueue(struct queue **q, struct node *root)
{
(*q)->arr[(*q)->r] = root;
(*q)->r++;
}
int isEmpty(struct queue *q)
{ //printf("in is empty : %d\n",(q->f==q->r));
return q->f==q->r;  // it check if it is empty or not if epmpty return here 0  or else return 1 from here
}
struct node *dequeue(struct queue **q)
{
struct node *temp= (*q)->arr[(*q)->f];
(*q)->f++;
return temp;
}
struct node *newnode(int key)
{
struct node *new;
new = (struct node*) malloc(sizeof(struct node));
new->left = new->right = NULL;
new -> data = key;
return new;

}
struct node *insert(struct node *root, int key)
{
struct queue *q;
q = (struct queue*) malloc(sizeof(struct queue));
q->f = 0;
q->r = 0;
if(root==NULL)
root=newnode(key);
else
{
enqueue(&q,root);
while(!isEmpty(q))
{
struct node *temp = dequeue(&q);
if(!temp->left)
{
temp->left = newnode(key);
break;
}
else
enqueue(&q,temp->left);
if(!temp->right)
{
temp->right = newnode(key);
break;
}
else
enqueue(&q,temp->right);
}
}
return root;
}
void inorder(struct node *temp)
{
if(!temp)
return;
inorder(temp->left);
printf("%d ",temp->data);
inorder(temp->right);
}
int main()
{
struct node *root = NULL;
int key,op;
while(1)
{
printf("\nSelect an option:\n\t1.Insert\n\t2.Traverse\n\t3.Exit\n\t");
scanf("%d",&op);
switch(op)
{
case 1:
printf("\nEnter the data: ");
scanf("%d",&key);
root = insert(root, key);
break;
case 2:
inorder(root);
break;
case 3:
exit(1);
default:
printf("\nEnter a valid input");

}
}
return 0;
}
