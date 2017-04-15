/*
Write a function to apply left or right rotations to a binary search tree based on the height of the left and right sub-trees of the root. The function should first determine if a binary search tree is height balanced, and if not, rotate the tree until it is. Your algorithm may need to apply a left or right rotation multiple times. You will not need to apply both a left and right rotation to any tree. The function should return the root of the tree.
TreeNode* CheckHeightAndRotate(TreeNode *root);
TreeNode struct:
struct TreeNode
{
int key;
TreeNode *leftChild;
TreeNode *rightChild;
TreeNode *parent;
};
*/

void leftRotate(TreeNode* x, TreeNode* &root);
void rightRotate(TreeNode* y, TreeNode* &root);
int leftHeight(TreeNode* node);
int rightHeight(TreeNode* node);

TreeNode* CheckHeightAndRotate(TreeNode* root){
    int lh = leftHeight(root), rh = rightHeight(root);
    TreeNode* temp = root;
    while (lh != rh) {
        if (temp == NULL) {
            temp = root;
        }
        else if (lh - rh >= 2) {
            rightRotate(temp, root);
            temp = root;
            lh = leftHeight(root);
            rh = rightHeight(root);
        }
        else if (rh - lh >= 2) {
            leftRotate(temp, root);
            temp = root;
            lh = leftHeight(root);
            rh = rightHeight(root);
        }
        else if (lh - rh > 0) {
            temp = temp->leftChild;
        }
        else {
            temp = temp->rightChild;
        }
    }

    return root;
}

void leftRotate(TreeNode* x, TreeNode* &root) {
    TreeNode* y = x->rightChild;
	x->rightChild = y->leftChild;
	if (y->leftChild != NULL) {
		y->leftChild->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL) {
		root = y;
	}
	else {
		if (x == x->parent->leftChild) {
			x->parent->leftChild = y;
		}
		else {
			x->parent->rightChild = y;
		}
	}
	y->leftChild = x;
	x->parent = y;
}

void rightRotate(TreeNode* y, TreeNode* &root){
    TreeNode* x = y->leftChild;
	y->leftChild = x->rightChild;
	if (x->rightChild != NULL) {
		x->rightChild->parent = y;
	}
	x->parent = y->parent;
	if (y->parent == NULL) {
		root = x;
	}
	else {
		if (y == y->parent->leftChild) {
			y->parent->leftChild = x;
		}
		else {
			y->parent->rightChild = x;
		}
	}
	x->rightChild = y;
	y->parent = x;
}

int leftHeight(TreeNode* node){
    TreeNode* temp = node;
    int lh = 0;
    while (temp->leftChild != NULL) {
        lh++;
        temp = temp->leftChild;
    }
    return lh;
}

int rightHeight(TreeNode* node){
    TreeNode* temp = node;
    int rh = 0;
    while (temp->rightChild != NULL) {
        rh++;
        temp = temp->rightChild;
    }
    return rh;
}
