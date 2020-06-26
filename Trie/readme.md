# Trie 

--> Trie is spcial data structure, it is used to store strings that can be visualized like a graph.

--> It consists of nodes and edges.

--> It is an efficient informaion reTireval data structure.

--> If you store the string in **AVL tree** or **Balanced BST** for **search** operation it took  **O(M*log(n))**

   here ,
      M -> Length of the string
      N-> no of key's in the tree
      
--> In **Trie** we can search string in **O(M)**

--> In Trie each String is Stored in letter by letter

here we implement Trie using java,

```java
  class Trie {
    private class TrieNode {
        Map<Character, TrieNode> children;
        boolean endOfWord;
        public TrieNode() {
            children = new HashMap<>();
            endOfWord = false;
        }
    }

    private final TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
```

**see the code and compare with this image**

![](https://github.com/Ranjith54321/Data-Structures/blob/master/images/Trie.jpg)

[youtube-video-link](https://www.youtube.com/watch?v=AXjmTQ8LEoI&t=482s)

