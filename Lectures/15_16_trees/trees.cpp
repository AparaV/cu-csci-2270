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

/*
	Recursion
	=========
		- Base case - no further recursive calls
		- Reduce all cases to base case

	Binary Search Trees (BST)
	=========================
		- Special binary tree
		- for any node in a tree:
			nodes in left sub-tree will have values lesser than that node
			nodes in right sub-tree will have values greater than or equal to that node
		- Tree is constructed as data is read ~ same data in different order can generate different trees ~ tree balancing

	Building BST
	------------
		Ex: 4, 2, 6, 9, 1, 3
				4
			 2	   6
		   1   3	 9

		If built correctly, data can be retrieved quickly

	Operations on BST
	-----------------
		- Inserting new node
		- Search for value / node
		- Delete node
		- Print contents of tree

	1. Inserting new node
	---------------------
	
		void insert(value) {									//node information
			node* parent = NULL;
			node* temp = root;									//root is a known property
			node* n = new Node(value, NULL, NULL, NULL);		//(key, parent, left, right)
			while (temp != NULL) {								//find where node is to be placed
				parent = temp;
				if (n->key < temp->key) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			}
			if (parent == NULL) {								//tree is empty
				root = n;
			}
			else if (n->key < parent->key) {
				parent->left = n;
				n->parent = parent;
			}
			else {
				parent->right = n;
				n->parent = parent;
			}
		}
*/