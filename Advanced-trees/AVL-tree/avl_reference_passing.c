#include<stdio.h>
#include<stdlib.h>
 
// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get height of the tree
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
      struct node *x = y->left;
      struct node *t2 = x->right;

      x->right = y;
      y->left = t2;

      y->height = max(height(y->left),height(y->right))+1;
      x->height = max(height(x->left),height(x->right))+1;
      return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
        struct node *y = x->right;
        struct node *t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;
      return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N)
{
        if(!N)
          return 0;
        return (height(N->left) - height(N->right));
}
 
void insert(struct node** node, int key)
{
      if(!(*node)){
        (*node) = newNode(key);
        return;
      }
      else if(key < (*node)->key)
        insert(&((*node)->left),key);
      else if(key > (*node)->key)
        insert(&((*node)->right),key);
      else
        return;

      (*node)->height = max(height((*node)->left),height((*node)->right))+1;

      int bal = getBalance((*node));

      if(bal>1 && key < ((*node)->left->key))
        (*node) = rightRotate((*node));
      if(bal<-1 && key > ((*node)->right->key))
        (*node) = leftRotate((*node));
      if(bal>1 && key > ((*node)->left->key)){
        (*node)->left = leftRotate((*node)->left);
        (*node) = rightRotate((*node));
      }
      if(bal<-1 && key < ((*node)->right->key)){
        (*node)->right = rightRotate((*node)->right);
        (*node) = leftRotate((*node));
      }
      return;
}
 
/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
       struct node *curr = node;
        while(curr->left)
          curr = curr->left;
        return curr;
}
 
void deleteNode(struct node** root, int key)
{
      if(!(*root)){
          printf("Element not found\n");
        return;
      }
      else if(key < (*root)->key)
        deleteNode(&((*root)->left),key);
      else  if(key > (*root)->key)
        deleteNode(&((*root)->right),key);
      else{
        if(((*root)->left==NULL) || ((*root)->right==NULL)){
          struct node *temp = (*root)->left ? (*root)->left : (*root)->right;
          if(!temp){
            temp = (*root);  // from here to there is the weak point   
            (*root) = NULL;
          }
          else
            *(*root) = *temp; // here is you'r weak point 
          free(temp);
        }
        else{
          struct node *temp = minValueNode((*root)->right);
          (*root)->key = temp->key;
          deleteNode(&((*root)->right),temp->key);
        }
      }
      if(!(*root))
        return;
      (*root)->height = max(height((*root)->left),height((*root)->right))+1;

      int bal = getBalance((*root));
      if(bal>1 && getBalance((*root)->left)>=0)
        (*root) = rightRotate((*root));
      if(bal<-1 && getBalance((*root)->right)<=0)
        (*root) = leftRotate((*root));
      if(bal>1 && getBalance((*root)->left)<0){
        (*root)->left = leftRotate((*root)->left);
        (*root) = rightRotate((*root));
      }
      if(bal<-1 && getBalance((*root)->right)>0){
        (*root)->right = rightRotate((*root)->right);
        (*root) = leftRotate((*root));
      }
      return;
}
 
// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
/* Drier program to test above function*/
int main()
{
  struct node *root = NULL;
  int choice, num;
  /* Constructing tree given in the above figure */
  root = NULL;
  while(1){
    printf("1.Insert the element\n");
    printf("2.Delete the element\n");
    printf("3.Pre-Order traversal\n");
    printf("4.Quit\n");
    printf("Enter your choice :\n");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
        printf("Enter the element to be inserted:\n");
        scanf("%d", &num);
        insert(&root, num);
        break;
      case 2:
        printf("Enter the element to be deleted:\n");
        scanf("%d", &num);
        deleteNode(&root, num);
        break;
      case 3:
        preOrder(root);
        printf("\n");
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice\n");
    }/*End  of switch */
  }/*End of while */
  return 0;
}/*End of main()*/