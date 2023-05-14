//Traverse inOrder
void traverse_tree_inorder(node* root){                              
    if(root==NULL)                                      
        return;                                         
    else{
        traverse_tree_inorder(root->left);
        printf("%d", root->N);
        traverse_tree_inorder(root->right);
    }
}


//Traverse preOrder
void traverse_tree_inorder(node* root){                              
    if(root==NULL)                                      
        return;                                         
    else{
        printf("%d", root->N);
		traverse_tree_inorder(root->left); 
		traverse_tree_inorder(root->right);
    }
}


//Traverse postOrder
void traverse_tree_inorder(node* root){                              
    if(root==NULL)                                      
        return;                                         
    else{
        traverse_tree_inorder(root->left);
		traverse_tree_inorder(root->right);
		printf("%d", root->N);
    }
}

