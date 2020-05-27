#include <stdio.h>

void display(int *array, int n)
{
	if(n==0){
	    printf("Heap is empty");
    }
    else{
        int i;
        for(i=0;i<n;i++){
            printf("%d ",array[i]);
        }
    }
    printf("\n");
}
 
void insert(int *array, int num, int loc)
{
		int p;
		while(loc>0){
		    p = (loc-1)/2;
		    if(num<=array[p]){
		        array[loc] = num;
		        return;
		    }
		    array[loc] = array[p];
		    loc = p;
		}
		array[0] = num;
}
 
void delete(int *array,int num, int *n)
{
		int i,right,left,p,t;
		for(i=0;i<(*n);i++){
		    if(num==array[i]){
		        break;
		    }
		}
		if(array[i]!=num){
		    printf("%d not found in heap list\n",num);
		    return;
		}
		array[i] = array[(*n)-1];
		(*n) = (*n)-1;
		p = (i-1)/2;
		if(array[i]>array[p]){
		    insert(array,array[i],i);
		    return;
		}
		left = 2*i+1;
		right = 2*i+2;
		while(right<(*n)){
		    if(array[right]<=array[i] && array[left]<=array[i])
		        return;
		    if(array[right]>=array[left]){ // here order shoild be same
		        t = array[right];
		        array[right] = array[i];
		        array[i] = t;
		        i = right;
		    }
		    else{
		        t = array[left];
		        array[left] = array[i];
		        array[i] = t;
		        i = left;
		    }
		    left = 2*i+1;
		    right = 2*i+2;
		}
		if(left==(*n)-1 && array[left]>array[i]){
		        t = array[left];
		        array[left] = array[i];
		        array[i] = t;
		}
}

int main()
{
	int array[100], n;
	int choice, num;
	n = 0;/*Represents number of nodes in the heap*/
	while(1)
	{
		printf("1.Insert the element \n");
		printf("2.Delete the element \n");
		printf("3.Display all elements \n");
		printf("4.Quit \n");
		printf("Enter your choice :\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element to be inserted to the list :\n");
				scanf("%d", &num);
				insert(array,num, n);
				n = n + 1;
				break;
			case 2:
				printf("Enter the elements to be deleted from the list :\n");
				scanf("%d", &num);
				delete(array,num,&n);
				//n = n - 1;
				break;
			case 3:
				display(array,n);
				break;
			case 4:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
