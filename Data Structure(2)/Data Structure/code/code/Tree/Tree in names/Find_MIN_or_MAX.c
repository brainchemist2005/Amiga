//To Find MIn
node* find_min(node* root){
    if(root==NULL)
        return(NULL);
    else if(root->left==NULL)
        return(root);
    else
        return(find_min(root->left));
}

//To Find MAX
node* find_max(node* root){
    if(root==NULL)
        return(NULL);
    else if(root->right==NULL)
        return(root);
    else
        return(find_max(root->right));
}
