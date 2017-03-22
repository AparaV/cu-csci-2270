/*
	Tree Balancing
	==============
		* AVL Trees - simple, not used
		* Red-black tree - not simple, used everywhere
	Both work by assigning additional properties to the tree, performing rotations to preserve the properties
	Red-black do recolorings

	Red-Black Trees
	---------------
		* BST
		* Each node is assigned a color (red/black)

		node {
			color;
			key;
			parent;
			leftChild;
			rightChild;
		}

	Properties of red-black tree
		#1 Node is either red or black
		#2 Root is black
		#3 Every leaf node (nodes at the bottom of the tree) is black
		#4 If the node is red, both children must be black
		#5 For each node, all paths to leaf nodes contain same number of black nodes

	In regular BST, leaf nodes are where children are NULL
	In red-black tree, leaf nodes are emoty nodes

	RB tree operations
	------------------
	To restore properties:
		* Recolor - change color of node
		* Rotation - change the height of a subtree, parent-child connections
		* Left and right rotation - inverses of each other
			After a right rotate, a left rotate will give back the original tree

	Inserting a node into a red-black tree
	--------------------------------------
		Same as inserting node in BST with some additional steps
		1. Replace NULL with null node
		2. Set color of new node to red
		3. Resolve the violations by recoloring and rotations

		Add a node to empty tree (10)
					10 (Red)
			Rule: new node is red
			Violoation: root must be black
			Fix: re-color to black
		Add node to tree (5)
					10 (black)
				5 (red)
			No violations
		Add 4 to tree
						10 (b)
					5 (r)
				4 (r)
			Violoation: both children of red node should be black

			6 possible configurations that red-black tree can take
			3 configurations are symmetric of other 3
			Depends on whether parent is left or right child

			First, identify "uncle"
						10
					5		y
				x
			x is new node. y is uncle node
			Case 1: Uncle is red
				This implies that parent of x is also red
				x also red because it was just added
			Case 2: new node is right child and Uncle is black
			Case 3: new node is left child and Uncle is black

		redBlackInsert(value) {
			node* x = insert(value);
			//see moodle notes/code
		}

	Deleting a node
	---------------
		Violation:
			Change number of black nodes on a path.
			Need to balance

		Algorithm: Same as BST
			0, 1, 2 child case
			x is replacement node
			if x is black, need to re-balance

		RBBalance(x) {
			//see moodle notes/code

		}

*/