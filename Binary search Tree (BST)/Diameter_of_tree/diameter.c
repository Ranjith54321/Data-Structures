#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tnode  {
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode * s);
int max(int a, int b);
int height(struct tnode* node);
int diameter(struct tnode * tree);

int main()  {
	struct tnode * root=NULL;
	char ch[5];
	int num;
	do {
		printf("Enter the element to be inserted in the tree\n");
		scanf("%d",&num);
		insert(&root, num);
		printf("Do you want to insert another element?\n");
		scanf("%s",ch);
	}while(strcmp(ch,"yes")==0);

	printf("The elements in the tree are");
	inorder(root);
	printf("\n");
	printf("The diameter of the tree is %d\n",diameter(root));
	return 0;
}

void insert(struct tnode ** s, int num) {
	struct tnode *t,*curr,*p;
	t = (struct tnode*)malloc(sizeof(struct tnode));
	t->data = num;
	t->leftc = NULL;
	t->rightc = NULL;
	if(!(*s)){
	    (*s) = t;
	}
	else{
	    curr = (*s);
	    while(curr){
	        p = curr;
	        if(num>curr->data){
	            curr = curr->rightc;
	        }
	        else{
	            curr = curr->leftc;
	        }
	    }
	    if(p->data>num){
	        p->leftc = t;
	    }
	    else{
	        p->rightc = t;
	    }
	}
}
void inorder(struct tnode * s){
    if(!s)
        return;
    inorder(s->leftc);
    printf(" %d",s->data);
    inorder(s->rightc);
}
int diameter(struct tnode * tree)  {
    if(!tree)
        return 0;
        
    int lh = height(tree->leftc);
    int rh = height(tree->rightc);
        
    int ld = diameter(tree->leftc);
    int rd = diameter(tree->rightc);
    
    return max(1+lh+rh,max(ld,rd));
}
 

int height(struct tnode* node)  {
    if(!node)
        return 0;
    return 1+max(height(node->leftc),height(node->rightc));
} 

int max(int a, int b)  {
  return (a >= b)? a: b;
}
