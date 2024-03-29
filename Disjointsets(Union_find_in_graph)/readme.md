# Disjointset (Union and find):

  A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

  **Find:**
  
 ---> Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

  **Union:** 
  
  ---> Join two subsets into a single subset.
  
  **Note:**
  
    this is not like tree this this entirely differnt from trees.
    
    here parent child connection also differnt.
    
 # materials : 
 
   refer  this oreder   **for the below two methods see the array operation carefully**
 
 **1.) for Navie approach :** **O(n)**
        
  ---> https://www.youtube.com/watch?v=NXw2eY6o5ck
  
  ----> https://www.youtube.com/watch?v=IytRwcLd5lU
  
   after video understanding trace the code
   
   ### setps : 
         -->  here we have only one set(array) (parent).
          
          1.) Initialize all node's parents as -1.
          
          2.) in find function :
            -> if parent is -1 then return that nodes otherwise find it's deepest parent.
            
          3.) in Union function :
            -> find both nodes parent then if they are not equal then set destination node as the parent of source node.
        
  code : https://www.geeksforgeeks.org/union-find/
  
  **2.) for Union by Rank and Path compression** algorithm (same as above but it improves time) **O(lon(n))**
  
  ----> https://www.youtube.com/watch?v=w7DpIm4rFkY
  
  code : https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
  
  ### steps :
          --> here we have parent and rank variables. 
          
          1.) Initialize all node's parents as it-self and rank of all nodes as 0.
          
          2.) In find function :
              -> if the parent is euqal to it-self then return otherwise find it's deepest parent.
              
          3.) In Union function :
              -> find the source and destination nodes parent's.
              
              -> The node which has the high rank that is the parent for the other node.
              
              -> initially while all node's rank are 0 make destination nodes as the parent of source node.
  
  # applications of Union_and_find in Graph datastructure:
    
    1) The application is to check whether a given graph contains a cycle or not. 
    
    2.) Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. 
    
    --> Note that we have discussed an algorithm to detect cycle. ... 
    
     If both the vertices are in the same subset, a cycle is found.
    
    3.) One Important Thing here you have to Notice :
           That is in both cases we are searching deepest parent but here in this algorithm while searching parent we are doing one more extra thing,
        
                  int find(subset[] subsets, int i)
              {
                  if (subsets[i].parent != i)
                      subsets[i].parent = find(subsets, subsets[i].parent); // here we are updating the parent of the searching element.
                  return subsets[i].parent;
              }
              
           Eg : 
           
                                  9
                             /    |    \  
                            4     5      6
                         /     \        /  \
                        0        3     7    8
                                /  \
                               1    2  
                               
                      In this example while searching 3 we are updating 3's parent as 9 so that it will reduce the searching time. (see below updated tree diagram)
                      
                                  9
                           /    /  \    \
                          4    5    6     3  (-> 3 is here now 3's parent is 9 not 4) because 9 is 3 is deepest parent.
                       /           /  \   /  \
                      0           7    8  1   2
              
              
              4.) In Union we are combining the elements by creating parent node with the helo of rank,
                     -> Initially all node's rank is 0. you can take any one of the node as parent and keep the rule till the end. 
                                         and increment the rank if both rank are equal.
              
    
  
