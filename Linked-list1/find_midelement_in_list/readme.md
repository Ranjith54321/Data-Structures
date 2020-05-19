int getMiddle(Node *head)
{

    int n=0,m;
    Node *temp = head,*ans;
    while(temp){
       n = n+1;
       temp = temp->next;
       }
       
       
       m = (n/2)+1;
       temp = head;
       int i=0;
       while(temp){
           i++;
           if(i==m){
               ans = temp;
               break;
           }
           temp = temp->next;
       }

       return ans->data;
    }


 2nd approach:**(recursive)**

int getMiddle(Node *head)
{

    if(head==NULL){
        return -1;
    }
    
    else{
    Node *slow = head;
    Node *fast = head;
    while((fast!=NULL)&&(fast->next!=NULL)){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow->data;
    }
}
