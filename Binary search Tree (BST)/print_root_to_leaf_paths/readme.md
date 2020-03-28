 > here you use stack(int array) then it will became easy

see the whole above prg then you can under stand

also see https://www.youtube.com/watch?v=zIkDfgFAg60

---
```c
void printPaths(struct node* node) 
{
int path[1000];
printPathsRecur(node, path, 0);
}

void printPathsRecur(struct node* node, int path[], int pathLen) 
{
    if(!node)
        return;
    i++;
    path[i] = node->data;
    n = i+1;
    printPathsRecur(node->left,path,n);
    if(!node->left && !node->right){
        printArray(path,n);
    }
    printPathsRecur(node->right,path,n);
    i--;
}
void printArray(int ints[], int len)
{
int i;
for (i=0; i<len; i++) {
	printf("%d ", ints[i]);
}
printf("\n");
}
```
