/*
Write a C++ function to delete the given value's right child from the binary search tree. The function takes two arguments, tree node and value of the node whose right child has to be deleted.
Also replace the deleted node with minimum value from its left sub tree.
The final tree will not be a valid BST.
void deleteAndReplaceLeftMin(TreeNode *root, int key);

struct TreeNode
{
int key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};
*/

TreeNode* treeMin(TreeNode* root){
    if (root == NULL){
        return NULL;
    }
    TreeNode* temp = root;
    while (temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

TreeNode* search(TreeNode* root, int x){
    TreeNode* temp = root;
    while (temp != NULL) {
        if (temp->key > x){
            temp = temp->left;
        }
        else if (temp->key < x) {
            temp = temp->right;
        }
        else {
            break;
        }
    }
    return temp;
}

void deleteAndReplaceLeftMin(TreeNode *root, int key){
    TreeNode* target = search(root, key);
    TreeNode* min = treeMin(target->right);
    TreeNode* toDelete = new TreeNode;
    toDelete = target->right;
    // case 1
    if (min == toDelete) {
        target->right = toDelete->right;
        if (toDelete->right != NULL) {
            toDelete->right->parent = target;
        }
    }
    // case 2
    else if (min == toDelete->left){
        min->left = min->right;
        if (min->right != NULL) {
            min->right->parent = min;
        }
        min->right = toDelete->right;
        if (toDelete->right != NULL) {
            toDelete->right->parent = min;
        }
        target->right = min;
        min->parent = target;
    }
    // case 3
    else {
        min->parent->left = min->right;
        if (min->right != NULL) {
            min->right->parent = min->parent;
        }
        min->right = toDelete->right;
        if (toDelete->right != NULL) {
            toDelete->right->parent = min;
        }
        min->left = toDelete->left;
        toDelete->left->parent = min;
        min->parent = target;
        target->right = min;
    }
    delete toDelete;
}
