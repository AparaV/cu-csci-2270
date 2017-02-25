/*
	Trees
	=====

	Each node has one parent and multiple children.
	Create a hierarchical structure

	Binary trees
	------------
		Each node has upto 2 children
		Each node has 3 pointers (to nodes of same type)
			- parent
			- left child
			- right child
		Top of the tree is the root => parent of root = NULL
		If node doesn't have left child, that pointer is NULL
		If node doesn't have right child, that pointer is NULL

	struct node{
		int key;
		node* parent;
		node* left;
		node* right;
	};

	Finding the bottom of the tree:
	-------------------------------
		Search tree by traversing each branch until we reach bottom of that branch
		When left == NULL, no more nodes in that branch. Same for right == NULL

	Subtrees
	--------
		Each tree is defined by subtrees

	Self-similarity: An object is similar to a part of itself
	Computationally we can examine smaller and smaller subtrees

	Recurisve structure: A structure that is defined in terms of itself
	Recursive algorithm: An algorithm that calls itself on smaller units until smallest case can be reached

	Printing nodes in binary tree
	-----------------------------

	void printNode(node *n){
		cout << n->key << endl;
		if (n->left != NULL) {
			printNode(n->left);
		}
		if (n->right != NULL) {
			printNode(n->right);
		}
		return;
	}

*/