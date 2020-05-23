 for all the below concepts refer **gfg or youtube**:

 		BST Rules :

 			-> Left node should br less than the root node 

 			-> Right node should be greater than the root node

 			-> Duplicates are not allowed in BST

 	   For Deletion :

 	   		Case 1: -> If it is leaf node then no problem simply delete it 

 	   		Case 2: -> if any one one of the child node is null then replace deleted node with remining node

 	   		case 3: -> If Node contains two nodes then replace this node's value with inorder successer or inorder predicessor

		 	   		 50                            60
		           /     \         delete(50)      /   \
		          40      70       --------->    40    70 
		                 /  \                            \ 
		                60   80                           80   here we replaced it with inorder successer

 
1. height or width --> no of nodes from root to leaf

2. level -> no of node from after root to leaf (i.e,  height-1   this is only for under statnding coding is different for both) 

3. size of the tree -> total no of nodes in the tree

4. diameter -> leaf to leaf with maximum posible length (see gfg)

5. here  code searching for only **BST** 

**diameter of the tree and check balenced bst are based on finding height**
