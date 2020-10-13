import java.util.HashMap;
import java.util.Scanner;
class Node{
	int key,value;
	Node pre,next;
	public Node(int key,int value){
		this.key = key;
		this.value = value;
		pre=null;
		next=null;
	}
}
class LRUCache{
	int count,capacity;
	Node head,tail;
	HashMap<Integer,Node> map;
	public LRUCache(int capacity){
		this.capacity = capacity;
		count=0;
		map = new HashMap<>();
		head = new Node(0,0);
		tail = new Node(0,0);
		head.next = tail;
		tail.pre = head;
		head.pre = null;
		tail.next = null;
	}
	public  void addFront(Node node){
		node.next = head.next;
		node.next.pre = node;
		node.pre = head;
		head.next = node;
	}
	public  void deleteNode(Node node){
		node.next.pre = node.pre;
		node.pre.next = node.next;
	}
	public  void set(int key,int value){
		if(map.get(key)!=null){
			Node node = map.get(key);
			node.value = value;
			deleteNode(node);
			addFront(node);
		}else{
			Node node = new Node(key,value);
			map.put(key,node);
			if(count < capacity){
				count++;
				addFront(node);
			}else{
				map.remove(tail.pre.key);
				deleteNode(tail.pre); // delete tail node
				addFront(node);
			}
		}
	}// set method
	public  void get(int key){
		if(map.get(key)!=null){
			Node node = map.get(key);
			int value = node.value;
			deleteNode(node);
			addFront(node);
			System.out.println("value for "+key+" is "+value);
		}else{
			System.out.println("no key value found -1");
		}
	}
}
class Test{// this is main class
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the capacity of the Cache");
		int capacity = sc.nextInt();
		LRUCache Cache = new LRUCache(capacity); // set the capacity
		int Choice=0;

		do{
			System.out.println("Enter Choice");
			System.out.println("1.) set or replace value     2.) get value   3.)exit");
			Choice = sc.nextInt(); // we created obejct so we don't need for static method keep in your mind
			switch(Choice){
				case 1:{
					System.out.println("Enter Key and value");
					int key = sc.nextInt();
					int value = sc.nextInt();

					Cache.set(key,value);
					break;
				}
				case 2:{
					System.out.println("Enter the Key");
					int key = sc.nextInt();

					Cache.get(key);
					break;
				}
				case 3:{
					System.out.println("Bye.....");
					break;
				}
			}
		}while(Choice!=3);
		/*LRUCache cache = new LRUCache(2); 
   
        cache.set(1, 10);  

        cache.set(2, 20);  
       
                           cache.get(1); // returns 10 

        cache.set(3, 30);  
  
    
                cache.get(2); // returns -1

        cache.set(4, 40);  
      
               cache.get(1); // returns -1 (not found) 
        
                           cache.get(3); // returns 30 
        
                           cache.get(4); // return 40 
                           */
	}
}