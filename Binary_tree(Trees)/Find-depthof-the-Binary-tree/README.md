The below recursive function is important for this operation:
```c
int maxDepth(struct tree *node){
    if(!node)
        return 0;
        
    else{
    
        int ldepth = maxDepth(node->left);
        int rdepth = maxDepth(node->right);
        
        if(ldepth>rdepth)
            return ldepth+1;
        else 
            return rdepth+1;
    }
}
```

You can work out and know how to work or use c_code_visualizer to know the work flow

source link:
https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
