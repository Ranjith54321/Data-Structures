# LRU CACHE :

 ## Least Recently Used Cache :
 
  Contdition's :
  
      Cache must have initial capacity
      
      every time if we access or modefy any cache which is most recently used 
      
      others are lest recently used 
      
      we need to perform insertion , deletion , and access of cache in O(1) time 
      
   
 
  Implementation :
    
        -> For easy insertion and deletion operation we use Dublby Linked List with two ends (head and tail)
        
        -> for easy access of cache we use HashMap so we can fecth the cache easily
        
        -> the most recently used cache must be present at starting of the linked list 
        
        -> the least recently used cache must be present at ending of the linked list 
        
        -> if extra cache comes then delete the least recently used cache and insert the new cache
        
        
        
   for more details read [LRU Cache](https://www.geeksforgeeks.org/design-a-data-structure-for-lru-cache/)
    
      
