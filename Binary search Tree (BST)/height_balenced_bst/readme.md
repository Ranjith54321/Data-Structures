check out youtube channels and gfg:

 --> https://www.youtube.com/watch?v=LU4fGD-fgJQ

**the ref image**

  ![](https://github.com/Ranjith54321/Data-Structures/blob/master/images/check_balenced_bst.PNG)

---

```c
int isBalanced(struct tnode *root)
{
	if(!root)
	    return 1;
	int lh = height(root->leftc);
	int rh = height(root->rightc);
	if(abs(lh-rh)<=1 && isBalanced(root->leftc) && isBalanced(root->rightc))
	    return 1;
	return 0;
}

int height(struct tnode* node)
{
	if(!node)
	    return 0;
	/*else{
	    int lh = height(node->leftc);
	    int rh = height(node->rightc);
	    
	    if(lh>rh)
	        return lh+1;
	    else
	        return rh+1;
	}*/
	return 1+max(height(node->leftc),height(node->rightc));
} 

int max(int a, int b)
{
  return (a >= b)? a: b;
}

```
