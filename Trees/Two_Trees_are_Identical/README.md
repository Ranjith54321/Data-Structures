the below recursive function is the important:

/* Given two trees, return true if they are 
 structurally identical */
 
int identicalTrees(struct node* a, struct node* b) 
{ 
    /*1. both empty */
    
    if (a==NULL && b==NULL) 
        return 1; 
  
    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL) 
    { 
        return
        ( 
            a->data == b->data && 
            identicalTrees(a->left, b->left) && 
            identicalTrees(a->right, b->right) 
        ); 
    } 
      
    /* 3. one empty, one not -> false */
    return 0; 
} 

source:
https://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
