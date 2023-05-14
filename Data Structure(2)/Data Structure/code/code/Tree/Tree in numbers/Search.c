//To Search a Number in a BST
node* search_number(node* root, int x){
    if(root == NULL)
        return(NULL);
    else if(x == root->N)
        return(root);
    else if(x < root->N)
        return(search_number(root->left, x));
    else
        return(search_number(root->right, x));
}
