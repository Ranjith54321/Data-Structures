#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int age, key;
	char name[100];
	int marker;
};

void insertInHash(int key, char *name, int age, struct node * hashTable, int tableSize, int* totEle) {
         
        if((*totEle)==tableSize){
            printf("Can't Insert. Hash Table is full!\n");
            return;
        }
        int i=0;
        while(1){
            int p = (key+i)%tableSize;
            if(!(hashTable[p].marker)){
                hashTable[p].age = age;
                hashTable[p].key = key;
                strcpy(hashTable[p].name,name);
                hashTable[p].marker = 1;
                *totEle = *totEle+1;
                return;
            }
            else
                i = i+1;
        }
}

void deleteFromHash(int key, struct node* hashTable, int tableSize, int* totEle ) {
        int i;
        if(*totEle==0){
		    //printf("Hash Table is Empty!!\n");
		    printf("%d is not available in Hash Table\n",key);
		    return;
	    }
	    else{
	        for(i=0;i<tableSize;i++){
	            if(key==hashTable[i].key){
	                hashTable[i].marker = 0;
	                strcpy(hashTable[i].name,"");
	                printf("%d deleted from Hash Table\n",key);
	                *totEle = *totEle-1;
	                return;
	            }
	        }
	        printf("%d is not available in Hash Table\n",key);
	    }
}

void searchElement(int key, struct node* hashTable, int tableSize, int totEle) {
        if(!totEle){
            //printf("Hash Table is Empty!!\n");
            printf("%d is not present in hash table\n",key);
		    return;
        }
        else{
            int i;
            for(i=0;i<tableSize;i++){
                if(hashTable[i].key==key){
                printf("Voter ID : %d\n", hashTable[i].key);
			    printf("Name : %s\n", hashTable[i].name);
			    printf("Age : %d\n", hashTable[i].age);
			    return;
                }
            }
            printf("%d is not present in hash table\n",key);
        }
}

void display(struct node* hashTable, int tableSize, int totEle) {
	int i;
	if (totEle == 0) {
		printf("Hash Table is Empty!!\n");
		return;
	}
	printf("%s%13s%13s%13s\n","ID","Name","Age","Index");
	printf("-----------------------------------------\n");
	for (i = 0; i < tableSize; i++) {
		if (hashTable[i].marker == 1) {
			printf("%d", hashTable[i].key);
			printf("%13s", hashTable[i].name);
			printf("%13d", hashTable[i].age);
			printf("%13d\n", i);
		}
	}
	printf("\n");
	return;
}

int main() {
	int tableSize = 0, totEle = 0;
	struct node *hashTable = NULL;
	int key, age, ch;
	char name[100];
	printf("Enter the Table Size:\n");
	scanf("%d", &tableSize);
	hashTable = (struct node *)calloc(tableSize, sizeof(struct node));
	while (1) {
		printf("1. Insert\n2. Delete\n");
		printf("3. Search\n4. Display\n");
		printf("5. Exit\nEnter your choice:\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				printf("Enter the key value:\n");
				scanf("%d", &key);
				getchar();
				printf("Enter the Name:\n");
				fgets(name, 100, stdin);
				name[strlen(name) - 1] = '\0';
				printf("Enter the Age:\n");
				scanf("%d", &age);
				insertInHash(key, name, age,hashTable,tableSize,&totEle);
				break;
			case 2:
				printf("Enter the key value:\n");
				scanf("%d", &key);
				deleteFromHash(key,hashTable,tableSize,&totEle);
				break;
			case 3:
				printf("Enter the key value:\n");
				scanf("%d", &key);
				searchElement(key,hashTable,tableSize,totEle);
				break;
			case 4:
				display(hashTable,tableSize,totEle);
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid option\n");
				break;
		}
	}
	return 0;
}
