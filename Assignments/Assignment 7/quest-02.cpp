/*

Write a function to build a binary search tree from an array. The function will take in the array and the array size as arguments, and return a pointer to the root of the tree.

Use the following function header:
Node *build(int a[], int size);

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

Use the following print statements as nodes are added to the tree:
If the node is placed as the parent node:
        cout<<"root: "<<root->key<<" parent: "<<parent<<endl;
If the node is placed as the left child:
        cout<<"node: "<<node->key<<" left child of: "<<parent->key<<endl;
If the node is placed as the right child:
        cout<<"node: "<<node->key<<" right child of: "<<parent->key<<endl;

*/

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

Node* build(int a[], int size) {
    root = new Node(NULL, NULL, NULL);
    for (int i = 0; i < size; ++i) {
        //root node
        if (i == 0) {
            root->key = a[i];
            cout << "root: " << root->key << " parent: " << 0 << endl;
        }
        else {
            Node* temp = new Node(NULL, NULL, NULL);
            temp->key = a[i];

            //searching for position to place node
            bool left = false;
            Node* curr = root;
            Node* pos = curr;
            while (curr != NULL) {
                if (curr->key > a[i]) {
                    left = true;
                    pos = curr;
                    curr = curr->left;
                }
                else {
                    left = false;
                    pos = curr;
                    curr = curr->right;
                }
            }

            //adding node
            if (left) {
                pos->left = temp;
                temp->parent = pos;
                cout << "node: " << temp->key << " left child of: " << pos->key << endl;
            }
            else {
                pos->right = temp;
                temp->parent = pos;
                cout << "node: " << temp->key << " right child of: " << pos->key << endl;
            }
        }
    }
    return root;
}
