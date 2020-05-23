
   # AVL TREE : 

	--> it is a updated version of BST 
	--> the main use of BST is to assecc the elements in logerthemic time 
	--> but this will not be acheived in all cases

		eg 1: 
				   30 
			           /  \ 
			         20   40 
			        /  \     \ 
			       10  25    50    here searching 50 we can achive in O(logh)  // h-> height

			       but ...

		eg 2:        10 
		              \ 
		              20 
		         	\
		         	25
		                 \ 
		                 30
		       		   \
		       		   40
		       		     \
		       		     50   here searching 50 it takes O(h)   

		    but in AVL we can achive O(logh) for all the elements even in worst case  
 ### Balance Factor
	--> Balance factor of a node in an AVL tree is the difference between 
		the height of the left subtree and that of the right subtree of that node.
	--> Balance Factor = (Height of Left Subtree - Height of Right Subtree) or (Height of Right Subtree - Height of Left Subtree)
	--> The self balancing property of an avl tree is maintained by the balance factor. 
	--> The value of balance factor should always be -1, 0 or +1.

  ## Rotation's in AVL tree 

   **To maintain the balance factor -1 , 0 , 1 we need this kind of rotations**

 ### 1.) LEFT LEFT case :

		  		T1, T2, T3 and T4 are subtrees.
	         z                                      y 
	        / \                                   /   \
	       y   T4      Right Rotate (z)          x      z
	      / \          - - - - - - - - ->      /  \    /  \ 
	     x   T3                               T1  T2  T3  T4
	    / \
	  T1   T2

 ### 2.) RIGHT RIGHT case : 

		  z                                y
		 /  \                            /   \ 
		T1   y     Left Rotate(z)       z      x
		    /  \   - - - - - - - ->    / \    / \
		   T2   x                     T1  T2 T3  T4
		       / \
		     T3  T4

 ### 3.) LEFT RIGHT case :

		     z                               z                           x
		    / \                            /   \                        /  \ 
		   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
		  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
		T1   x                          y    T3                    T1  T2 T3  T4
		    / \                        / \
		  T2   T3                    T1   T2

 ### 4.) RIGHT LEFT case :

		   z                            z                            x
		  / \                          / \                          /  \ 
		T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
		    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
		   x   T4                      T2   y                  T1  T2  T3  T4
		  / \                              /  \
		T2   T3                           T3   T4


   ### **Deletion**

	--> Deletion is very similar to the BST deletion 
   
	--> but at each delete operaration we need to maintain the height of the corresponding node's

	--> see the source code very carefully 

	 --> in height update :

```
	struct Node *rightRotate(struct Node *y) 
		{ 
		   struct Node *x = y->left; 
		   struct Node *T2 = x->right; 

		   // Perform rotation 
		   x->right = y; 
		   y->left = T2; 
                 
		   // Update heights 		// see care fully 
		   y->height = max(height(y->left), height(y->right))+1;   // which node is modified here y then start to update 
		   									//that height firts
		   x->height = max(height(x->left), height(x->right))+1; // then only we can update it parent i,e x's height  

		    // Return new root 
		    return x; 
		} 

  ```

 --> avl tree passing reference see care fully note code 

  --> see gfg code(avl_insertion_and_deletion) and avl_refence passing care fully 
