/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 08
** Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include "MovieTree.h"

using namespace std;

//Constructor
MovieTree::MovieTree() {
	root = NULL;
} //end of ctor

//Destructor
MovieTree::~MovieTree() {
	DeleteAll(root);
	root = NULL;
} //end of dtor

//Print inventory
void MovieTree::printMovieInventory() {
	printMovieInventory(root);
} // end of printing inventory

//Count movies
int MovieTree::countMovieNodes() {
	int totalCount = 0;
	countMovieNodes(root, &totalCount);
	return totalCount;
} // end of count movie nodes

//Delete movie
void MovieTree::deleteMovieNode(string title) {
	MovieNode* movie = search(title);
	if (movie == NULL) {
		cout << "Movie not found." << endl;
		return;
	}
	//not root
	else if (movie != root) {
		bool left = movie == movie->parent->leftChild;
		//no children
		if (movie->rightChild == NULL && movie->leftChild == NULL) {
			if (left) {
				movie->parent->leftChild = NULL;
			}
			else {
				movie->parent->rightChild = NULL;
			}
			delete movie;
		} // end no children
		//one child
		else if (movie->rightChild == NULL || movie->leftChild == NULL) {
			if (left) {
				if (movie->leftChild != NULL) {
					movie->parent->leftChild = movie->leftChild;
				}
				else if (movie->rightChild != NULL) {
					movie->parent->leftChild = movie->rightChild;
				}
			}
			else {
				if (movie->leftChild != NULL) {
					movie->parent->rightChild = movie->leftChild;
				}
				else if (movie->rightChild != NULL) {
					movie->parent->rightChild = movie->rightChild;
				}
			}
			delete movie;
		} // end of one child
		//two children
		else {
			MovieNode* min = treeMinimum(movie->rightChild);
			//min is right child
			if (min == movie->rightChild) {
				if (left) {
					movie->parent->leftChild = min;
					min->parent = movie->parent;
					movie->leftChild->parent = min;
					min->leftChild = movie->leftChild;
				}
				else {
					movie->parent->rightChild = min;
					min->parent = movie->parent;
					movie->leftChild->parent = min;
					min->leftChild = movie->leftChild;
				}
			} // end of min is right child
			else {
				if (left) {
					min->parent->leftChild = NULL;
					if (min->rightChild != NULL) {
						min->rightChild->parent = min->parent;
					}
					min->parent->leftChild = min->rightChild;
					min->parent = movie->parent;
					movie->parent->leftChild = min;
					min->leftChild = movie->leftChild;
					if (movie->leftChild != NULL) {
						movie->leftChild->parent = min;
					}
					min->rightChild = movie->rightChild;
					if (movie->rightChild != NULL) {
						movie->rightChild->parent = min;
					}
				}
				else {
					min->parent->leftChild = NULL;
					if (min->rightChild != NULL) {
						min->rightChild->parent = min->parent;
					}
					min->parent->leftChild = min->rightChild;
					min->parent = movie->parent;
					movie->parent->rightChild = min;
					min->leftChild = movie->leftChild;
					if (movie->leftChild != NULL) {
						movie->leftChild->parent = min;
					}
					min->rightChild = movie->rightChild;
					if (movie->rightChild != NULL) {
						movie->rightChild->parent = min;
					}
				}
			} // end of if min is not the right child
			delete movie;
		}  // end of two children
	} // end of not root
	//root
	else {
		//no children
		if (movie->leftChild == NULL && movie->rightChild == NULL) {
			delete movie;
			root = NULL;
		} // end of no children
		//one child
		else if (movie->leftChild == NULL || movie->rightChild == NULL) {
			if (movie->rightChild != NULL) {
				movie->rightChild->parent = NULL;
				root = movie->rightChild;
			}
			else if (movie->leftChild != NULL) {
				movie->leftChild->parent = NULL;
				root = movie->leftChild;
			}
			delete movie;
		} // end of one child
		//two children
		else {
			MovieNode* min = treeMinimum(movie->rightChild);
			//min is right child
			if (min == movie->rightChild) {
				root = min;
				min->parent = NULL;
				movie->leftChild->parent = min;
				min->leftChild = movie->leftChild;
			} // end of min is right child
			else {
				root = min;
				if (min->rightChild != NULL) {
					min->rightChild->parent = min->parent;
				}
				min->parent->leftChild = min->rightChild;
				min->parent = NULL;
				min->leftChild = movie->leftChild;
				if (movie->leftChild != NULL) {
					movie->leftChild->parent = min;
				}
				min->rightChild = movie->rightChild;
				if (movie->rightChild != NULL) {
					movie->rightChild->parent = min;
				}
			} // end of if min is not the right child
			delete movie;
		} // end of two children
	} // end of if movie is root

} // end of delete movie node

//Add movie
void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity) {
	MovieNode* movie = new MovieNode(ranking, title, releaseYear, quantity);
	//if tree is empty
	if (root == NULL) {
		root = movie;
		return;
	}
	MovieNode* curr = root;
	//search for position
	bool left = false;
	while (curr != NULL) {
		if (curr->title > movie->title) {
			left = true;
			if (curr->leftChild == NULL) {
				break;
			}
			curr = curr->leftChild;
		}
		else {
			left = false;
			if (curr->rightChild == NULL) {
				break;
			}
			curr = curr->rightChild;
		}
	} // end of search

	if (left) {
		curr->leftChild = movie;
		movie->parent = curr;
	}
	else {
		curr->rightChild = movie;
		movie->parent = curr;
	}

	return;
} // end of add movie node

//Find movie
void MovieTree::findMovie(string title) {
	MovieNode* movie = search(title);
	if (movie == NULL) {
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
} // end of find movie

//Rent movie
void MovieTree::rentMovie(string title) {
	MovieNode* movie = search(title);
	if (movie == NULL) {
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
} // end of rent movie

//Private functions

//Delete all
//use this for the post-order traversal deletion of the tree
void MovieTree::DeleteAll(MovieNode * node) {
	if (node->leftChild != NULL) {
		DeleteAll(node->leftChild);
	}
	if (node->rightChild != NULL) {
		DeleteAll(node->rightChild);
	}
	if (node != NULL) {
		cout << "Deleting: " << node->title << endl;
		deleteMovieNode(node->title);
	}
} // end of delete all

//Print movie inventory
void MovieTree::printMovieInventory(MovieNode * node) {
	if (node->leftChild != NULL) {
		printMovieInventory(node->leftChild);
	}
	cout << "Movie: " << node->title << " " << node->quantity << endl;
	if (node->rightChild != NULL) {
		printMovieInventory(node->rightChild);
	}
} // end of print movie inventory

//count movie nodes
void MovieTree::countMovieNodes(MovieNode *node, int *c) {
	if (node->leftChild != NULL) {
		countMovieNodes(node->leftChild, c);
	}
	if (node->rightChild != NULL) {
		countMovieNodes(node->rightChild, c);
	}
	if (node != NULL) {
		(*c)++;
	}
} // end of count movie nodes

//search
MovieNode* MovieTree::search(string title) {
	MovieNode* movie = root;
	while (movie != NULL) {
		if (movie->title > title) {
			movie = movie->leftChild;
		}
		else if (movie->title == title) {
			break;
		}
		else if (movie->title < title) {
			movie = movie->rightChild;
		}
	}
	return movie;
} // end of search

//search recursive
MovieNode* MovieTree::searchRecursive(MovieNode *node, string value) {
	if (node->leftChild != NULL) {
		searchRecursive(node->leftChild, value);
	}
	if (node->title == value) {
		return node;
	}
	if (node->rightChild != NULL) {
		searchRecursive(node->rightChild, value);
	}
} // end of search recursive

//tree minimum
MovieNode* MovieTree::treeMinimum(MovieNode *node) {
	while (node->leftChild != NULL) {
		node = node->leftChild;
	}
	return node;
} // end of finding tree minimum