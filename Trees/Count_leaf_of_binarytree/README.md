recursive function;

/* Function to get the count of leaf nodes in a binary tree*/

unsigned int getLeafCount(struct node* node) 
{ 

  if(node == NULL)        
    return 0; 
    
  if(node->left == NULL && node->right==NULL)       
    return 1;             
    
  else 
    return getLeafCount(node->left)+ 
           getLeafCount(node->right); 
           
}

source:
https://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/
