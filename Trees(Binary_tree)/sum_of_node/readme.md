long int sumBT(Node* root)
{

    if(!root)
        return 0;
    else return(root->key + sumBT(root->left) + sumBT(root->right));
    
}

for further explanation see gfg
