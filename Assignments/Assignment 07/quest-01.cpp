/*

Find all nodes in a BST that are between a given range of values. Then build a linked list of the values and the list should be in ascending order.
NOTE: the head of the linked list is declared globally in the back end and its initial value is NULL. Just add the nodes to the linked list using head. The printing of the linked list will also be done in the backend. Helper functions can be used.
void RangeSearch(TreeNode *node, char m, char n);
Tree Struct:
struct TreeNode
{
   char key;
   TreeNode *left;
   TreeNode *right;
   TreeNode *parent;
};

Linked list Struct:

struct Node{
   char key;
   Node *next;
};

Node *head = NULL;

For example:
Start range: b

End range: g

so you would find b, c, d, e, f, g

       Input Tree:
          g
       /    \
      e      o
     / \    /
    a   f  i
     \
      b
       \
        c
         \
          d

Linked List:

        b -> c -> d -> e -> f -> g -> NULL
*/

struct TreeNode
{
   char key;
   TreeNode *left;
   TreeNode *right;
   TreeNode *parent;
};

struct Node{
   char key;
   Node *next;
};

bool find(TreeNode* root, char x) {
    bool found = false;
    TreeNode* n = root;
    while (n != NULL) {
        if (n->key > x) {
            n = n->left;
        }
        else if (n->key < x) {
            n = n->right;
        }
        else {
            found = true;
            break;
        }
    }
    return found;
}

void append(char x) {
    Node* temp = new Node;
    temp->key = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    }
    else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}


void RangeSearch(TreeNode* root, char m, char n) {
    for(char i = m; i <= n; ++i){
        if (find(root, i)) {
            append(i);
        }
    }


}
