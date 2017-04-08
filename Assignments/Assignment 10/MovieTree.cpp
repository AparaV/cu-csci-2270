/** CSCI 2270-110  Data Structures
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Assignment 10
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include "MovieTree.h"

using namespace std;

//constructor
MovieTree::MovieTree() {
	nil = new MovieNode(-1, "NULL_MOVIE", 0, -1);
	nil->isRed = false;
	root = nil;
} // end of constructor

//destructor
MovieTree::~MovieTree() {
	DeleteAll(root);
	root = NULL;
	delete nil;
	nil = NULL;
} // end of destructor

//public - print inventory
void MovieTree::printMovieInventory() {
	if (root == nil) {
		cout << "Empty" << endl;
	}
	else {
		//cout << "Root: " << root->title << endl;
		printMovieInventory(root);
	}
} // end of public print inventory

//public - count movies
int MovieTree::countMovieNodes() {
	return countMovieNodes(root);
} // end of public count movies

//public - delete movie
void MovieTree::deleteMovieNode(string title) {
	MovieNode* movie = searchMovieTree(root, title); // find movie
	if (movie == nil) {
		cout << "Movie not found." << endl;
	}
	else {
		rbDelete(movie, true); // delete node
	}
} // end of public delete movie

//public - add movie
void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity) {
	//create node
	MovieNode* movie = new MovieNode(ranking, title, releaseYear, quantity);
	movie->leftChild = nil;
	movie->rightChild = nil;
	movie->parent = nil;
	movie->isRed = true;

	//bst insert
	MovieNode* temp = root;
	MovieNode* parent = nil;
	//search for position
	while (temp != nil) {
		parent = temp;
		if (movie->title < temp->title) {
			temp = temp->leftChild;
		}
		else {
			temp = temp->rightChild;
		}
	} // end of search

	if (parent == nil) {
		root = movie;
	}
	else if (movie->title < parent->title) {
		parent->leftChild = movie;
	}
	else {
		parent->rightChild = movie;
	}
	movie->parent = parent;
	// end bst insert

	rbAddFixup(movie); // balancing

} // end of public add movie

//public - find movie
void MovieTree::findMovie(string title) {
	MovieNode* movie = searchMovieTree(root, title);
	if (movie == nil) {
		cout << "Movie not found." << endl;
	}
	else {
		cout << "Movie Info:" << endl;
		cout << "===========" << endl;
		cout << "Ranking:" << movie->ranking << endl;
		cout << "Title:" << movie->title << endl;
		cout << "Year:" << movie->year << endl;
		cout << "Quantity:" << movie->quantity << endl;
	}
} // end of public find movie

//public - rent movie
void MovieTree::rentMovie(string title) {
	MovieNode* movie = searchMovieTree(root, title);
	if (movie == nil) {
		cout << "Movie not found." << endl;
	}
	else {
		movie->quantity--;
		cout << "Movie has been rented." << endl;
		cout << "Movie Info:" << endl;
		cout << "===========" << endl;
		cout << "Ranking:" << movie->ranking << endl;
		cout << "Title:" << movie->title << endl;
		cout << "Year:" << movie->year << endl;
		cout << "Quantity:" << movie->quantity << endl;
		if (movie->quantity == 0) {
			deleteMovieNode(title);
		}
	}
} // end of public rent movie

//public - is red black tree valid
bool MovieTree::isValid() {
	if (rbValid(root) == 0) {
		return false;
	}
	return true;
} // end of public is tree valid

//public - count longest path
int MovieTree::countLongestPath() {
	return countLongestPath(root);
} // end of public longest path

//private - delete all movies
//use this for the post-order traversal deletion of the tree
void MovieTree::DeleteAll(MovieNode* node) {
	if (node != nil && node != NULL) {
		DeleteAll(node->leftChild);
		DeleteAll(node->rightChild);
		cout << "Deleting: " << node->title << endl;
		rbDelete(node, false); // delete without balancing
	}
} // end of private delete all movies

//private - print inventory
void MovieTree::printMovieInventory(MovieNode* node) {
	if (node->leftChild != nil) {
		printMovieInventory(node->leftChild);
	}
	cout << "Movie: " << node->title << " " << node->quantity << endl;
	if (node->rightChild != nil) {
		printMovieInventory(node->rightChild);
	}
} // end of private print inventory

//private - red black fix tree after adding
//called after insert to fix tree
void MovieTree::rbAddFixup(MovieNode* z) {
	while (z->parent->isRed) {
		//z's parent is a left child
		if (z->parent == z->parent->parent->leftChild) {
			MovieNode* uncle = z->parent->parent->rightChild;
			//case 1
			if (uncle->isRed) {
				z->parent->isRed = false;
				uncle->isRed = false;
				z->parent->parent->isRed = true;
				z = z->parent->parent;
			}
			//case 2 and 3
			else {
				if (z == z->parent->rightChild) {
					z = z->parent;
					leftRotate(z);
				}
				//now it is a case 3
				z->parent->isRed = false;
				z->parent->parent->isRed = true;
				rightRotate(z->parent->parent);
			}
		}
		//z's parent is a right child
		else {
			MovieNode* uncle = z->parent->parent->leftChild;
			//case 1
			if (uncle->isRed) {
				z->parent->isRed = false;
				uncle->isRed = false;
				z->parent->parent->isRed = true;
				z = z->parent->parent;
			}
			//case 2 and 3
			else {
				if (z == z->parent->leftChild) {
					z = z->parent;
					rightRotate(z);
				}
				//now it is a case 3
				z->parent->isRed = false;
				z->parent->parent->isRed = true;
				leftRotate(z->parent->parent);
			}
		}
	} // end while
	root->isRed = false;
} // end of private red black fix tree after adding

//private - left rotate
//rotate the tree left with x as the root of the rotation
void MovieTree::leftRotate(MovieNode* x) {
	MovieNode* y = x->rightChild;
	x->rightChild = y->leftChild;
	if (y->leftChild != nil) {
		y->leftChild->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil) {
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
} // end of private left rotate

//private - delete node
//delete a node. Call this from deleteMovieNode, the actual delete functionality happens here.
void MovieTree::rbDelete(MovieNode* z, bool balance) {
	MovieNode* y = z;
	MovieNode* x = nil;
	bool originalColor = y->isRed;
	if (z->leftChild == nil) {
		x = z->rightChild;
		rbTransplant(z, z->rightChild);
		delete z;
	}
	else if (z->rightChild == nil) {
		x = z->leftChild;
		rbTransplant(z, z->leftChild);
		delete z;
	}
	else {
		y = treeMinimum(z->rightChild);
		originalColor = y->isRed;
		x = y->rightChild;
		if (y->parent == z) {
			x->parent = y;
		}
		else {
			rbTransplant(y, y->rightChild);
			y->rightChild = z->rightChild;
			y->rightChild->parent = y;
		}
		rbTransplant(z, y);
		y->leftChild = z->leftChild;
		y->leftChild->parent = y;
		y->isRed = z->isRed;
		delete z;
	}
	if (!originalColor && balance) {
		rbDeleteFixup(x);
	}
	nil->parent = NULL;
	nil->rightChild = NULL;
	nil->leftChild = NULL;
	nil->isRed = false;
	nil->title = "NULL_MOVIE";
}

//private - right rotate
//rotate the tree right with y as the root of the rotation
void MovieTree::rightRotate(MovieNode* y) {
	MovieNode* x = y->leftChild;
	y->leftChild = x->rightChild;
	if (x->rightChild != nil) {
		x->rightChild->parent = y;
	}
	x->parent = y->parent;
	if (y->parent == nil) {
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
} // end of private right rotate

//private - red black fix tree after deleting
//called after delete to fix the tree
void MovieTree::rbDeleteFixup(MovieNode* x) {
	while (x != root && !x->isRed) {
		//x is the left child
		if (x == x->parent->leftChild) {
			MovieNode* w = x->parent->rightChild;
			//case 1
			if (w->isRed) {
				w->isRed = false;
				x->parent->isRed = true;
				leftRotate(x->parent);
				w = x->parent->rightChild;
			}
			//case 2
			if (!w->leftChild->isRed && !w->rightChild->isRed) {
				w->isRed = true;
				x = x->parent;
			}
			else {
				// case 3
				if (!w->rightChild->isRed) {
					w->leftChild->isRed = false;
					w->isRed = true;
					rightRotate(w);
					w = x->parent->rightChild;
				}
				// case 4
				w->isRed = x->parent->isRed;
				x->parent->isRed = false;
				w->rightChild->isRed = false;
				leftRotate(x->parent);
				x = root;
			}
		} // end of left child
		//x is right child
		else {
			MovieNode* w = x->parent->leftChild;
			//case 1
			if (w->isRed) {
				w->isRed = false;
				x->parent->isRed = true;
				rightRotate(x->parent);
				w = x->parent->leftChild;
			}
			//case 2
			if (!w->rightChild->isRed && !w->leftChild->isRed) {
				w->isRed = true;
				x = x->parent;
			}
			else {
				// case 3
				if (!w->leftChild->isRed) {
					w->rightChild->isRed = false;
					w->isRed = true;
					leftRotate(w);
					w = x->parent->leftChild;
				}
				// case 4
				w->isRed = x->parent->isRed;
				x->parent->isRed = false;
				w->leftChild->isRed = false;
				rightRotate(x->parent);
				x = root;
			}
		} // end of right child
	}
	x->isRed = false;
} // end of private red black fix tree after deleting

//private - transplant
//replace node u in tree with node v. Your solution doesn't necessarily need to use this method
void MovieTree::rbTransplant(MovieNode* u, MovieNode* v) {
	if (u->parent == nil) {
		root = v;
	}
	else if (u == u->parent->leftChild) {
		u->parent->leftChild = v;
	}
	else {
		u->parent->rightChild = v;
	}
	v->parent = u->parent;
} // end of private transplant

//private - red black tree valid
//check if the tree is valid, with node as the root of the tree
//returns 0 if the tree is invalid, otherwise returns the black node height
int MovieTree::rbValid(MovieNode* node) {
	int lh = 0;
	int rh = 0;
	// If we are at a nil node just return 1
	if (node == nil) {
		return 1;
	}
	else{
		// First check for consecutive red links. 
		if (node->isRed){
			if (node->leftChild->isRed || node->rightChild->isRed){
				cout << "This tree contains a red violation" << endl;
				return 0;
			}
		}
		// Check for valid binary search tree. 
		if ((node->leftChild != nil && node->leftChild->title.compare(node->title) > 0) || (node->rightChild != nil && node->rightChild->title.compare(node->title) < 0)){
			cout << "This tree contains a binary tree violation" << endl;
			return 0;
		}
		// Deteremine the height of let and right children. 
		lh = rbValid(node->leftChild);
		rh = rbValid(node->rightChild);
		// black height mismatch 
		if (lh != 0 && rh != 0 && lh != rh){
			cout << "This tree contains a black height violation" << endl;
			return 0;
		}
		// If neither height is zero, increment if it if black. 
		if (lh != 0 && rh != 0){
			if (node->isRed) {
				return lh;
			}
			else {
				return lh + 1;
			}
		}
		else {
			return 0;
		}
	}

} // end of private red black tree valid

//private - count movies
//number of unique titles in the tree
int MovieTree::countMovieNodes(MovieNode* node) {
	int count = 0;
	if (node->leftChild != nil) {
		count += countMovieNodes(node->leftChild);
	}
	if (node->rightChild != nil) {
		count += countMovieNodes(node->rightChild);
	}
	if (node != nil) {
		count++;
	}
	return count;
} // end of private count movies

//private - count longest path
//longest path from node to a leaf node in the tree
int MovieTree::countLongestPath(MovieNode* node) {
	if (node == nil) {
		return 0;
	}
	int leftHeight = countLongestPath(node->leftChild);
	int rightHeight = countLongestPath(node->rightChild);
	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	}
	else {
		return rightHeight + 1;
	}
} // end of private count longest path

//private - tree minimum
MovieNode* MovieTree::treeMinimum(MovieNode* node) {
	while (node->leftChild != nil) {
		node = node->leftChild;
	}
	return node;
} // end of private tree minimum

//private - search movie
MovieNode* MovieTree::searchMovieTree(MovieNode* node, string title) {
	if (node->leftChild != nil && node->title > title) {
		return searchMovieTree(node->leftChild, title);
	}
	if (node->title == title) {
		return node;
	}
	if (node->rightChild != nil && node->title < title) {
		return searchMovieTree(node->rightChild, title);
	}
	return nil;
} // end of private search movie