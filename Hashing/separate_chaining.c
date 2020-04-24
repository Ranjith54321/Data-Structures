#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int key, age;
	char name[100];
	struct node *next;
};

struct hash {
	struct node *head;
	int count;
};

struct node * createNode(int key, char *name, int age) {
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->key = key;
	newnode->age = age;
	strcpy(newnode->name, name);
	newnode->next = NULL;
	return newnode;
}


void insertToHash(int key, char *name, int age, struct hash* hashTable, int eleCount) {
        struct hash *h;
        struct node *d = createNode(key,name,age);
        int i;
        for(i=0;i<eleCount;i++){
            if((key%eleCount)==i){
                h = &(hashTable[i]);
                if(h->head==NULL){
                    h->head = d;
                    h->count++;
                }
                else{
                    d->next = h->head;
                    h->head = d;
                    h->count++;
                }
            }
        }
}


void deleteFromHash(int key, struct hash* hashTable, int eleCount) {
    
       /* struct node *d;
        d = hashTable[key%eleCount].head;
        int c=0,ck=1;
        struct node *p,*t=d;
        while(t){
            if(d->key==key){
                printf("Data deleted successfully from Hash Table\n");
                if(c==0){ // if head
                  hashTable[key%eleCount].head = d->next;   
                  hashTable[key%eleCount].count--;
                  ck=0;
                  break;
                }
                else{ // not head
                p->next = t->next;
                hashTable[key%eleCount].count--;
                ck=0;
                 break;
              }
        }// if key matches
        c++;
        p = t;
        t = t->next;
    }
    if(ck==1)
        printf("Given data is not present in Hash Table\n");*/
        struct node *t,*p;
        struct hash *h = &(hashTable[key%eleCount]);
        //int c=0;
        if(h->count==0){
        	printf("empty\n");
        	return;
        }
        else{
        	t = h->head;
        	p = t;
        	while(key==t->key){
        		printf("Data deleted successfully from Hash Table\n");
        		if(key==(h->head->key)){
        			h->head = t->next;
        			return;
        		}
        		else{
        			p->next = t->next;
        			return;
        		}
        		//c++;
        		p = t;
        		t = t->next;
        	}
        	printf("Given data is not present in Hash Table\n");
        }
    
}

void searchInHash(int key, struct hash* hashTable, int eleCount) {
        struct hash h = hashTable[key%eleCount];
        struct node *d = h.head;
        int c=0;
        while(d){
            if(d->key == key){
                printf("VoterID  : %d\nName     : %s\nAge      : %d\n",d->key,d->name,d->age);
                break;
            }
            c++;
            d = d->next;
        }
        if(c==h.count)
            printf("Search element unavailable in Hash Table\n");
        
}

void display(struct hash* hashTable, int eleCount) {
	struct node *myNode;
	int i;
	for (i = 0; i < eleCount; i++) {
		if (hashTable[i].count == 0)
			continue;
		myNode = hashTable[i].head;
		if (!myNode)
			continue;
		printf("\nData at index %d in Hash Table:\n", i);
		printf("ID          Name          Age   \n");
		printf("--------------------------------\n");
		while (myNode != NULL) {
			printf("%-12d", myNode->key);
			printf("%-15s", myNode->name);
			printf("%d\n", myNode->age);
			myNode = myNode->next;
		}
	}
	return;
}

int main() {
	int n, ch, key, age;
	char name[100];
	struct hash *hashTable = NULL;
	int eleCount = 0;
	printf("Enter the size of the Hash Table:\n");
	scanf("%d", &n);
	eleCount = n;
	/* create hash table with "n" no of buckets */
	hashTable = (struct hash *)calloc(n, sizeof (struct hash));
	while (1) {
		printf("1. Insertion\n2. Deletion\n");
		printf("3. Searching\n4. Display\n5. Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				printf("Enter the key value:\n");
				scanf("%d", &key);
				getchar();
				printf("Name:\n");
				fgets(name, 100, stdin);
				name[strlen(name) - 1] = '\0';
				printf("Age:\n");
				scanf("%d", &age);
				/*inserting new node to hash table */
				insertToHash(key, name, age, hashTable, eleCount);
				break;

			case 2:
				printf("Enter the key to perform deletion:\n");
				scanf("%d", &key);
				/* delete node with "key" from hash table */
				deleteFromHash(key, hashTable, eleCount);
				break;

			case 3:
				printf("Enter the key to search:\n");
				scanf("%d", &key);
				searchInHash(key, hashTable, eleCount);
				break;
			case 4:
				display(hashTable,eleCount);
				break;
			case 5:
				return 0;
			default:
				printf("Invalid choice\n");
				break;
		}
	}
	return 0;
}
