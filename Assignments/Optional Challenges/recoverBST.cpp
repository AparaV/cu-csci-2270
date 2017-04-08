/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    void recoverTree(TreeNode* root){
      TreeNode *first = NULL, *second = NULL;
      TreeNode *previous = new TreeNode(-999999999); // prevents unexpected behaviour

      TreeNode *current, *temp;
      current = root;

      // Morris Traversal
      while (current != NULL){
          if (current->left == NULL){

              // if i were to print the current here, i'd get
              // 1, 2, 3, 4, ... in a valid bst
              // but here i might get 6, 2, 3, 4, 5, 1
              // so i need to swap 6 and 1 because 6 > 2 and 1 > 5
              // therefore i store these values over here by comparing
              // the values with with previous nodes
              // during the first time, the previous node is set to -9999999
              // to prevent unexpected behaviour
              if (first == NULL && previous->val >= current->val){
                  first = previous;
              }
              if (first != NULL && current->val <= previous->val){
                  second = current;
              }
              previous = current;

              current = current->right;
          }
          else{
              temp = current->left;
              while (temp->right != NULL && temp->right != current){
                  temp = temp->right;
              }

              if (temp->right == NULL){
                  temp->right = current;
                  current = current->left;
              }
              else {
                  temp->right = NULL;

                  // if i were to print the current here, i'd get
                  // 1, 2, 3, 4, ... in a valid bst
                  // but here i might get 6, 2, 3, 4, 5, 1
                  // so i need to swap 6 and 1 because 6 > 2 and 1 > 5
                  // so i store these values over here by comparing
                  // with previous nodes
                  // during the first time, the previous node is set to -9999999
                  // to prevent unexpected behaviour
                  if (first == NULL && previous->val >= current->val){
                      first = previous;
                  }
                  if (first != NULL && current->val <= previous->val){
                      second = current;
                  }
                  previous = current;

                  current = current->right;
              }
          }
      }

      // now i just swap those two values
      // note that there is no need to swap the node themselves
      // just the values is good enough
      int x = first->val;
      first->val = second->val;
      second->val = x;
    }
};
