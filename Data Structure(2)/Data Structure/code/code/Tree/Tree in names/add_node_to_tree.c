//To Add Node
node* add_student(node* root, node* ToAdd){
    if (root==NULL)
        root = ToAdd;
    else {
        if (strcmp(ToAdd->student_name, root->student_name)<0)
        //Change the left of the subtree
        root->left = add_student(root->left, ToAdd);
        else
        //Change the right of the subtree
        root->right = add_student(root->right, ToAdd);
    }
    return(root);
}
