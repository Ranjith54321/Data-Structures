#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node* newNode(int );
void doubletree(struct node*); 
void insert(struct node **,int);
void display(struct node *); 
int main()
{
int d;
char ch[10];
struct node *root=NULL;
do
{
printf("Enter the element to be inserted\n");
scanf("%d",&d);
insert(&root,d);
printf("Do you want to insert another element\n");
scanf("%s",ch);
}while(!strcmp(ch,"Yes"));
printf("The elements are");
display(root); 
printf("\n");
doubletree(root);
printf("The elements of the double tree are");
display(root); 
printf("\n");
return 0;
}
void insert(struct node **root,int data)
{
struct node * n= (struct node*)malloc(sizeof(struct node));
n->data=data;
n->left=NULL;
n->right=NULL;

if(*root==NULL)
{
*root=n;
}
else
{
struct node *temp,*prev;
temp=*root;
while(temp!=NULL)
{
prev=temp;
if(temp->data>data)
{
temp=temp->left;
}
else
{
temp=temp->right;
}
}
if((prev->data)>data)
{
prev->left=n;
}
else
{
prev->right=n;
} 
}
}
void display(struct node *s) 
{
if(s!=NULL)
{

  display(s->left);
  printf(" %d",s->data);
  display(s->right);
}
}

struct node* newNode(int data)
{
struct node* node = (struct node*)malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

void doubletree(struct node* node) 
{
    if(!node)
        return;
    struct node *t = newNode(node->data);
    struct node *nextl = node->left;
    //struct node *nextr = node->right;
    node->left = t;
    t->left = nextl;
    //t->right = nextr;
    doubletree(node->left->left);
    doubletree(node->right);
}
