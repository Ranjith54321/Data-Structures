# HASHING

  Hashing is mainly implemented for fastest data searching and retrival purpose
  
  E.g:
  
        IF you have a array you going to apply fastest searching algorithm like binary search it gives O(logn) if best case's
        
        But in worst case Scenarios it gives O(n) Time complexity
        
        So, Hashing Can give O(1) for searching element
        
  ## Hashing Terminologies:
  
    1.) Hashtable
    2.) HashFunction
    3.) Collisoin
    4.) Collisoin Resolution Techniques
    
   ### 1.) HashTable
   
        It is a set or Generalization of array
        
        Stores data in an associate manner
        
        Each data value has unique index value (but not in a linear way)
        
        Hashtable is used to store <key,information> pair
        
 ### 2.) HashFunction:
   
        It calculates to locate the record
        
        This result will be the index to store the data
        
        h(k) is called the hash of the key k
        
   **Method for buliding hash function**
           
         1.) Division Method
         2.) Multipilcation Method
         3.) Extraction Method
         4.) Mid-Square Hashing
         5.) Folding Technique
         6.) Rotation
         7.) Universal Hashing
           
    The most common what we use is **Division Method**(---i.e, h(k) = k % (table_size)---)
    
 ### 3.) Collision:
 
       If two key values belong's to same index while implement Hashfunction like [-----h(k) = k % (table_size)------]
       
       it is called collision 
       
### 4.) Collision Resolution Technique:
    
        The technique which is used to avoid collision is called Collision Resolution Technique's
        
        1.) Diresct Chaining (or) Separate Chaining  [--> use h(k) = (k+i) % (table_size) then --> array of linked list with ]
            
        2.) Open Adderssing:
            |
            ----> Linear Probing  [--->  h(k) = (k+i) % (table_size),  where i=0,1,2,3,...    ]
            |
            ----> Quatradic Probing  [--->  h(k) = (k + i^2) % (table_size),  where i=0,1,2,3,...    ]
            |
            ----> Double Hashing    (not see yet) 
            |
            ----> Key offset   (we not see)
        
      (----refer on note book ------)
   usefull vide : https://www.youtube.com/watch?v=nEcUS90C4fo&feature=emb_logo
        
