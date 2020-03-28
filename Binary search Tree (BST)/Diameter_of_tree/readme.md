#finr diameter

youtube link : https://www.youtube.com/watch?v=ey7DYc9OANo

***

```c
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
```
