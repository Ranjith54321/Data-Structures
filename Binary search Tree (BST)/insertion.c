#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tnode {
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode *);
void preorder(struct tnode *);
void postorder(struct tnode *);

int main() {
	struct tnode * root=NULL;
	char ch[5];
	int num;
	do  {
		printf("Enter the element to be inserted in the tree\n");
		scanf("%d",&num);
		insert(&root, num);
		printf("Do you want to insert another element?\n");
		scanf("%s",ch);
	}while(strcmp(ch,"yes")==0);
	printf("Inorder Traversal : The elements in the tree are");
	inorder(root);
	printf("\n");
	printf("Preorder Traversal : The elements in the tree are");
	preorder(root);
	printf("\n");
	printf("Postorder Traversal : The elements in the tree are");
	postorder(root);
	printf("\n");
	return 0;
}

void insert(struct tnode ** s, int num) {
    struct tnode *t,*curr,*parent;
    t = (struct tnode*)malloc(sizeof(struct tnode));
    t->data = num;
    t->leftc = NULL;
    t->rightc = NULL;
    if((*s)==NULL){
        (*s) = t;
    }
    else{
        curr = (*s);
        while(curr){
            parent = curr;
            if(num>curr->data){
                curr = curr->rightc;
            }
            else{
                curr = curr->leftc;
            }
        }
        if(num>parent->data)
            parent->rightc = t;
        else
            parent->leftc = t;
    }
    
}

void inorder(struct tnode * s)  {
    if(s==NULL)
        return;
    inorder(s->leftc);
    printf(" %d",s->data);
    inorder(s->rightc);
}

void preorder(struct tnode * s) {
    if(s==NULL)
        return;
    printf(" %d",s->data);
    preorder(s->leftc);
    preorder(s->rightc);
}

void postorder(struct tnode * s) {
    if(s==NULL)
        return;
    postorder(s->leftc);
    postorder(s->rightc);
    printf(" %d",s->data);
}
