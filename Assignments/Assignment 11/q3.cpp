/*
Write a C++ function to check whether the given tree is Binary Search Tree. The function takes one argument: the tree node. It returns True if the tree is a valid BST. Otherwise, it returns false. The function is initially called on the root of the tree.
NOTE: You will need to add a helper function.
bool isBST(TreeNode *node);

struct TreeNode
{
   int key;
   TreeNode *left;
   TreeNode *right;
};
*/

void inOrder(TreeNode* node, int* array, int* index){
    if (node->left != NULL){
        inOrder(node->left, array, index);
    }
    array[(*index)++] = node->key;
    if (node->right != NULL){
        inOrder(node->right, array, index);
    }

}


bool isBST(TreeNode* node){
    int* arr = new int[1000];
    int index = 0;
    inOrder(node, arr, &index);
    for(int i = 0; i < index - 1; ++i){
        if (arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;

}
