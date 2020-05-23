
	#1 AVL TREE

		--> it is a updated version of BST 
		--> the main use of BST is to assecc the elements in logerthemic time 
		--> but this will not be acheived in all cases

		eg: 
					    30 
			           /  \ 
			         20   40 
			        /  \     \ 
			       10  25    50    here searching 50 we can achive in O(logh)  // h-> height

			       but ...

			        10 
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
