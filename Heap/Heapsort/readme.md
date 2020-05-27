# HeapSort

Link : https://www.geeksforgeeks.org/heap-sort/

1.) Heap sort is one of the good and eficient sorting method in array

---

***Heapsort method:***

    1.) get the array
  
    2.) use the given array to build the heap
  
    3.) Now apply deletion for the  created heap then store the deleted element at the last
  
    but this will take too much time
    
---

 -> Here above code we use ***Heapify*** method to reduce the time
 
 steps:
 
  1.) create heap with the help of given array based on top to down comparision approach then swap
  
  2.) after done the creation of the heap now, swap the first and last elements 
  
   --------------------------then apply heapify for the 0'th position bcoz we change the root (  this will heapen in side the loop )
   
  3.) Now we get sorted array
  
  ---
  
  # priority Queue :
  
   -> It is another application of queue 
   
   -> Elementx are accessed and deleted based on their priority given (priority Queue in liked list is different )
   
   --------link : https://www.geeksforgeeks.org/priority-queue-using-linked-list/
   
   -> still i'm not working on this update when you work
   
   -> In heap concept we have Two types of Priority Queue:
   
    1.) Smallest Element higher Priority  ( Use Min Heap )
    2.) Greatest Element Higher Priority  ( Use Max Heap )
    
