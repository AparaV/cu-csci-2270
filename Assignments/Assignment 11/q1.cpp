/*
struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
};

void doubleTree(TreeNode *node);

Write a C++ function which does the following operation:
For each node in a binary search tree, create a new duplicate node, and insert the duplicate as the left child of the original node. The function is called on the root of the tree.
NOTE: You should set the new nodes children to NULL and handle the appropriate cases for no or more children

*/

void insert(TreeNode* child, TreeNode* parent){
    child->left = parent->left;
    parent->left = child;
}

void doubleTree(TreeNode* root){
    if (root != NULL){
        TreeNode* child = new TreeNode;
        child->key = root->key;
        child->left = NULL;
        child->right = NULL;
        insert(child, root);
        doubleTree(root->left->left);
        doubleTree(root->right);
    }
}
