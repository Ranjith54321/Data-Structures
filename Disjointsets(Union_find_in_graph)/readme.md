# Disjointset (Union and find):

  A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

  **Find:**
  
 ---> Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

  **Union:** 
  
  ---> Join two subsets into a single subset.
  
  **Note:**
  
    this is not like tree this this entirely differnt from trees 
    
    here parent child connection also differnt
    
 # materials : 
 
   refer  this oreder   **for the below two mwthods see the array operation carefully**
 
 **1.) for Navie approach :** **O(n)**
        
  ---> https://www.youtube.com/watch?v=NXw2eY6o5ck
  
  ----> https://www.youtube.com/watch?v=IytRwcLd5lU
  
   after video understanding trace the code
        
  code : https://www.geeksforgeeks.org/union-find/
  
  **2.) for Union by Rank and Path compression** algorithm (same as above but it improves time) **O(lon(n))**
  
  ----> https://www.youtube.com/watch?v=w7DpIm4rFkY
  
  code : https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
  
  # applications of Union_and_find in Graph datastructure:
    
    1) The application is to check whether a given graph contains a cycle or not. 
    
    2.) Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. 
    
    --> Note that we have discussed an algorithm to detect cycle. ... 
    
     If both the vertices are in the same subset, a cycle is found.
  
  