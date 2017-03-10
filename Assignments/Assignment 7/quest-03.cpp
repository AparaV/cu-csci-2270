/*

Write a C++ function to delete the given value from the binary search tree. The function takes two arguments, tree node and value of the node to be deleted.
You only need to consider the case where the node has two children. The node should be replaced by the minimum node in its right subtree.

void deleteAndReplaceMinRight(TreeNode *root, int key);

struct TreeNode
{
int key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};

For example:
         25
       /    \
     15      30
           /    \
          28    35
         / \    / \
        27 29  33 70
If the node to be deleted is 30, delete it and replace it with the minimum of its right subtree. Final tree:
         25
       /    \
     15      33
             / \
            28  35
          /  \    \
        27   29    70

*/

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

TreeNode* search(TreeNode* root, int searchKey) {
    TreeNode* n = root;
	while (n != NULL) {						//go through the tree
        if (n->key > searchKey) {
        	n = n->left;
        }
        else if (n->key < searchKey) {
        	n = n->right;
        }
        else {								//value is found
    	return n;
	    }
	}
	return NULL;
}

TreeNode* minimum(TreeNode* root) {
    TreeNode* x = root;
	while (x->left != NULL) {
	    x = x->left;
    }
	return x;
}

void deleteAndReplaceMinRight(TreeNode* root, int key) {
    TreeNode* n = search(root, key);
    TreeNode* min = minimum(n->right);

    if (min == n->right) {
        if (n == n->parent->left) {
            n->parent->left = min;
            min->parent = n->parent;
            min->left = n->left;
            min->left->parent = min;
        }
        else if (n == n->parent->right) {
            n->parent->right = min;
            min->parent = n->parent;
            min->left = n->left;
            min->left->parent = min;
        }
    }
    //cout << "hello";
    else {
        min->parent->left = min->right;
        if (min->right != NULL) {
            min->right->parent = min->parent;
        }

        min->parent = n->parent;
        if (n == n->parent->left) {
            n->parent->left = min;
        }
        if (n == n->parent->right) {
            n->parent->right = min;
        }

        min->left = n->left;
        min->right = n->right;
        n->left->parent = min;
        n->right->parent = min;/**/

    }

    delete n;
}
