//To Delete a Node
node* delete_node(node* root, int x){
    node* temp;
    if(root==NULL)
        return(root);
    else if(x < root->N)
        root->left = delete_node(root->left, x);
    else if(x > root->N)
        root->right = delete_node(root->right, x);
    //Element Found, Check the status of element
    //In case it has #two-Children
    else if(root->left!=NULL && root->right!=NULL){
        //Right Subtree Replacing Number
        temp = find_min(root->right);
        root->N = temp->N;
        root->right = delete_node(root->right, root->N);
    }
    else{
        temp = root;
        if(root->left == NULL){
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            root = root->left;
            free(temp);
        }
    }
    return(root);
}
