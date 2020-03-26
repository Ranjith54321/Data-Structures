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
	if((*s) == NULL) {
		(*s) = (struct tnode *) malloc( sizeof (struct tnode));
		(*s)->data = num;
		(*s)->leftc = NULL;
		(*s)->rightc = NULL;
	}
	else {
		if(num < (*s)->data)
  			insert(&( (*s)->leftc ), num);
		else
		 	insert(&( (*s)->rightc ), num);
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
