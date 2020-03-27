#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
int n,i=-1;
void printPaths(struct node* );
void printArray(int[],int);
void printPathsRecur(struct node*,int[],int); 
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
printf("\nPaths from root to leaf node:\n");
printPaths(root);
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

void printPaths(struct node* node) 
{
int path[1000];
printPathsRecur(node, path, 0);
}

void printPathsRecur(struct node* node, int path[], int pathLen) 
{
    if(!node)
        return;
    i++;
    path[i] = node->data;
    n = i+1;
    printPathsRecur(node->left,path,n);
    if(!node->left && !node->right){
        printArray(path,n);
    }
    printPathsRecur(node->right,path,n);
    i--;
}
void printArray(int ints[], int len)
{
int i;
for (i=0; i<len; i++) {
	printf("%d ", ints[i]);
}
printf("\n");
}
