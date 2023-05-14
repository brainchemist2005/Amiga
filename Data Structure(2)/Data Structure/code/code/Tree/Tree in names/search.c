//To Search a Number in a BST
node* search_student(node* root, char* name){
    if(root == NULL)
        return(NULL);
    else if(strcmp(root->student_name, name)==0)
        return(root);
    else if(strcmp(name, root->student_name)<0)
        return(search_student(root->left, name));
    else
        return(search_student(root->right, name));
}
