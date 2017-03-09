/*
	Write a C++ function that returns True if two trees have the same values (they are made of nodes with the same values.) It should return True if the trees have te same values or False otherwise. The function takes four arguments: treenode of tree1, treenode of tree2, and two arrays. Note that two trees can have the same values but not have the same structure. To successfully code this function up you will have to populate two arrays in ascending order with the values you find when traversing the two trees.
	For example: if sameValueTree() is called on the following two trees:
	1)                                 2)
	3                                  4
	/      \                           /
	2           4                     3
	/
	2
	It should return True.
	However, if sameValueTree() is called on the following two trees:
	3)                                 4)
	3                                  4
	/      \                           /      \
	2           4                     3           5
	/
	2
	It should return False.

	Few notes to help you out:
	1) Function header should be:
	bool sameValueTree(TreeNode *node1, TreeNode *node2, int *& array1, int *& array2 );

	2) The node structure is:
	struct TreeNode{
	int key;
	TreeNode *left;
	TreeNode *right;
	};

	3) The two arrays are passed to the function from main and are initialized as follow:
	int * array1 = NULL;
	int * array2 = NULL;

	4) You can use the function sizeTree() as a helper function. This was implemented for you and its defined as follow:
	int sizeTree(TreeNode * node);

	5) To help you with your implementation you can use the following global variables already initialized for you:
	int index1 = -1; // index to access array1
	int index2 = -1; // index to access array2
	int treeSize = -1; // once you find the size of the 2 BSTs assign it to this variable
	bool isEqual = true; // change this value accordingly and return it from sameValueTree()

	Hints:
	- populate the array correctly because there are test cases that will check your arrays
	- you may want to find out the size of each BST first.
	- handle the cases where the size of the 2 trees are not the same
	- you may want to choose a specific searching algorithm already seen in class to store the values in ascending order
	- remember to handle the base case (i.e. when counter1=counter2=Null) if you are going to use recursion.
	- You do not have to handle the case of repeated numbers in a tree. For example:
	3)                                 4)
	3                                  4
	/      \                           /      \
	2           4                     3           4
	/
	2
	This should still return False.
*/

void populateArray(TreeNode* root, int* &array, int* index) {
	if (root->left != NULL) {
		populateArray(root->left, array, index);
	}
	array[(*index)] = root->key;
	(*index)++;
	if (root->right != NULL) {
		populateArray(root->right, array, index);
	}
}

bool sameValueTree(TreeNode* root1, TreeNode* root2, int* &array1, int* &array2) {
	int size1 = sizeTree(root1);
	int size2 = sizeTree(root2);
	if (size1 != size2) {
		isEqual = false;
		return isEqual;
	}
	if (root1 == NULL && root2 == NULL) {
		isEqual = true;
		return isEqual;
	}
	isEqual = true;
	treeSize = size1;
	array1 = new int[treeSize];
	array2 = new int[treeSize];
	index1 = 0;
	index2 = 0;

	populateArray(root1, array1, &index1);
	populateArray(root2, array2, &index2);

	for (int i = 0; i < treeSize; ++i) {
		if (array1[i] != array2[i]) {
			isEqual = false;
			break;
		}
	}

	return isEqual;
}