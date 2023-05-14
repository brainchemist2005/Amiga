//To Delete a Node
node* delete_node(node* root, char* name){
    node* temp;
    if(root==NULL)
        return(root);
    else if(strcmp(name, root->student_name)<0)
        root->left = delete_node(root->left, name);
    else if(strcmp(name, root->student_name)>0)
        root->right = delete_node(root->right, name);
    //Element Found, Check the status of element
    //In case it has #two-Children
    else if(root->left!=NULL && root->right!=NULL){
        //Right Subtree Replacing Number
        temp = find_min(root->right);
        strcpy(root->student_name, temp->student_name);
        root->right = delete_node(root->right, root->student_name);
    }
    else{
        temp = root;
        //1 left child or leaf case
        if(root->left == NULL){
            root = root->right;
            free(temp);
        }
        //1 right child or leaf case
        else if(root->right == NULL){
            root = root->left;
            free(temp);
        }
    }
    return(root);
}
