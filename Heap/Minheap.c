#include <stdio.h>

void display(int *array, int n)
{
	int i;
	for(i=0;i<n;i++)
	    printf("%d ",array[i]);
	printf("\n");
}
 
void insert(int *array, int num, int location)
{
	int p;
	while(location>0){
	    p = (location-1)/2;
	    if(num>=array[p]){
	        array[location] = num;
	        return;
	    }
	    array[location] = array[p];
	    location = p;
	}
	array[0] = num;
}
 
void delete(int *array,int num, int *n)
{
	int p,l,r,t,i;
	for(i=0;i<(*n);i++){
	    if(array[i]==num)
	        break;
	}
	if(array[i]!=num){
	    printf("%d not found in heap list\n",num);
	    return;
	}
	array[i] = array[(*n)-1];
	*n = (*n)-1;
	p = (i-1)/2;
	if(array[i]<array[p]){
	    insert(array,array[i],i);
	    return;
	}
	l = 2*i+1;
	r = 2*i+2;
	while(r<(*n)){
	    if(array[i]<=array[l] && array[i]<=array[r])
	        return;
	    if(array[r]>=array[l]){    // always concentrate here order should be same compare between two childern not with parent
	        t = array[i];
	        array[i] = array[l];
	        array[l] = t;
	        i = l;
	    }
	    else{
	        t = array[i];
	        array[i] = array[r];
	        array[r] = t;
	        i = r;
	    }
	    l = 2*i+1;
	    r = 2*i+2;
	}
	if(l==(*n)-1 && array[i]>array[l]){
	    t = array[i];
	    array[i] = array[l];
	    array[l] = t;
	}
	return;
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
				printf("Enter the element to be deleted from the list :\n");
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
		}/*End  of switch */
	}/*End of while */
	return 0;
}
