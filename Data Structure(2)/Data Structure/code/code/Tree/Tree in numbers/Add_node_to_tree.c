//To Add Node
node* add_node_to_tree(node* root, node* ToAdd){
    if (root==NULL)
        root = ToAdd;
    else {
        if (ToAdd->N < root->N)
        root->left = add_node_to_tree(root->left, ToAdd);
        else
        root->right = add_node_to_tree(root->right, ToAdd);
    }
    return(root);
}
