 code link: https://www.includehelp.com/ds/program-for-insertion-and-deletion-in-heap.aspx
 
 It is one of the Concept of complete binary tree
 
 Types:
 
 1.)min heap 
 
             10                      10
         /      \               /       \  
       20        100          15         30  
      /                      /  \        /  \
    30                     40    50    100   40
    
 
 2.) Max Heap:
        
             100                    100
         /      \               /       \  
       30        10          50         40  
      /                      /  \        /  \
    20                     40    15    10   30
    
    
     --
     ** below are common for both the types **
     
# Insertion

      -> **Bottom - up approach**
      
      1. **Bottom - up approach** like how to we add in binary tree then you have to follow the heap property based on min or max heap
      
      2. for Zero indexed array to find parent = (i-1)/2  i'th location's node's parent we use this when insertion
      
# Deletion
    
      -> **Top to Down approach**
      
      1. replace target node's value by last node's (n-1 th node) value then delete then n-1 th node
      
      2. Now check node with it's left and right child then replace the node based on the heap property
      
