#include <stdio.h>
#include <stdlib.h>


struct tnode{
	struct tnode *leftc ;
	int data ;
	struct tnode *rightc ;
} ;

void insert ( struct tnode **, int ) ;
struct tnode* delete(struct tnode *, int );
int search ( struct tnode *root,int key) ;
void inorder ( struct tnode * ) ;
struct tnode *minval(struct tnode *root);
int main()
{
	struct tnode *bt ;
	int  b,n;
	printf("Binary Search Tree Implementation.\n\nChoice 1: Insert an element.\nChoice 2: Delete an element.\nChoice 3: Display.\n");
	printf("\nEnter your choice :\n");
	scanf("%d",&n);
	bt = NULL ;  /* empty tree */
	while((n==1)||(n==2)||(n==3))
	{
		switch ( n )
		{
			case 1:
			{
				printf("Enter the element to be inserted :\n");
				scanf("%d",&b);
				insert (&bt,b) ;
				break;
			}
			case 2:
			{
				printf("Enter the element to be deleted :\n");
				scanf("%d",&b);
				if(bt==NULL){
				    printf("Tree is empty\n");
				    break;
				}
				else if(!search(bt,b)){
				    printf("Data to be deleted, not found\n");
				    break;
				}
				else{bt = delete ( bt, b ) ;
				break;}
			}
			case 3:
			{
				if(bt==NULL)
				{
					printf("There are no elements in the BST.");
				}
				else
				{
					inorder ( bt ) ;
				}
				printf("\n");
				break;
			}
			default:
			{
				break;
			}
		}
		printf("Enter your choice :\n");
		scanf("%d",&n);
	}
	return 0;
}
int search ( struct tnode *root,int key){
    if(!root){
        return 0;
    }
    else if(root->data == key){
        return 1;
    }
    else if(key<root->data)
        return search(root->leftc,key);
    else
        return search(root->rightc,key);
}
/* inserts a new node in a binary search tree */
void insert ( struct tnode **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr = malloc ( sizeof ( struct tnode ) ) ;

		( *sr ) -> leftc = NULL ;
		( *sr ) -> data = num ;
		( *sr ) -> rightc = NULL ;
	}
	else  /* search the node to which new node will be attached */
	{
		/* if new data is less, traverse to left */
		if ( num < ( *sr ) -> data )
			insert ( &( ( *sr ) -> leftc ), num ) ;
		else
			/* else traverse to right */
			insert ( &( ( *sr ) -> rightc ), num ) ;
	}
}
struct tnode *minval(struct tnode *root){
    struct tnode *curr = root;
    while(curr && curr->leftc)
        curr = curr->leftc;
    return curr;
}
/* deletes a node from the binary search tree */
struct tnode* delete(struct tnode *root, int item) {
	if(root==NULL){
	    //printf("Tree is empty\n");
	    return root;
	}
	if(item<root->data)
	    root->leftc = delete(root->leftc,item);
	else if(item>root->data)
	    root->rightc = delete(root->rightc,item);
	else{
	    if(!root->leftc){
	        struct tnode *t = root->rightc;
	        free(root);
	        return t;
	    }
	    else if(!root->rightc){
	        struct tnode *t = root->leftc;
	        free(root);
	        return t;
	    }
	    
	    struct tnode *t = minval(root->rightc);
	    root->data = t->data;
	    
	    root->rightc = delete(root->rightc,t->data);
	}
	return root;
}

void inorder ( struct tnode *sr ) {
    if(!sr)
        return;
    inorder(sr->leftc);
    printf("%d ",sr->data);
    inorder(sr->rightc);
}
