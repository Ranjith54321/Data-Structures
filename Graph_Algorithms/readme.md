# GRAPH BASED ALGORITHMS:  #

---> **Spaning tree**

      It should visit all nodes in the graph but should not form the cycle
      
----> **Minimum Spanning tree**
    
       It should visit all nodes in the graph but should not form the cycle with **minimum edge weight**
       
**1.) MST bsed Algorithms**

    1.) Krushkals Algorithm 
    2.) Prims Algorithm
    
## 1.) Krushkals Algorithm:  ##

      1.) Find sortest path that should meet all the nodes woth minimum weight
      
      2.) here there is **no source vertex is given** it automatically takes based on smallest edge weight
      
      3.) sort the edge based in weights after that
      
      4.) It works bsed on Find and Union concept with path compression algorithm
      
      5.) here we have the set result if cyclic is not formed then add the edge into the result set
      
### 2.) Prim's Algorithm:   ###

      1.) Here source vertex is given we need to reach all the nodes with minimum over all edge weight
      
      2.) here we have two set's
                  
                   1.) key -> initially all values are INFINITY  (except source key[src]=0)  (to replace minimum edge weight for the nodes)
                   2.) set -> initially all values are FALSE  ( this is to know the reached vertex)
                   parent set is also there for mantain the reached nodes(for display)
                   
   ## SINGLE SOURCE SORTES PATH algorithms:    ##
   
          two famouse algorithms are;
            
              1.) Dijkstra’s shortest path algorithm
              2.) Bellman-Ford algorithm
             
        ----> here we see **Dijkstra’s shortest path algorithm** 
   
        1.) It is used to find the sortest path from source to all other vertex (see note book)
        
        2.) it is same as prims concept for implementaion
        
        3.) but we don't use parent set bcoz here source is the parent for all vertex
        
        4.) important condition --> key[j]>key[u]+graph[u][j] ******
      
