/*
Write a function to search a binary search tree for a value. The function will take in a pointer to the root node and a value to search for as arguments, and return a pointer to the found node or NULL if the value not found.

Use the following function header:
Node *search(Node *root, int value)

Use the following struct:
struct Node{
    int key;
    Node *parent;
    Node *left;
    Node *right;
    Node(Node *p, Node *l, Node *r){
        parent = p;
        left = l;
        right = r;
    }
};
*/

Node* search(Node* root, int value){
    Node* temp = root;
    while(temp != NULL) {
        if (temp->key < value){
            temp = temp->right;
        }
        else if (temp->key > value) {
            temp = temp->left;
        }
        else {
            break;
        }
    }
    return temp;
}
