see explanation on gfg : https://www.geeksforgeeks.org/double-tree/

```c
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
    node->left = t;
    t->left = nextl;
    doubletree(node->left->left);
    doubletree(node->right);
}
```
