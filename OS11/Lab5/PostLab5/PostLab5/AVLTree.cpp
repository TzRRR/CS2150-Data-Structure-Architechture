// Tianze Ren, tr2bx, 10/14/2022, AVLTree.cpp
#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    inserth(root, x);
}

void AVLTree::inserth(AVLNode*& n, string& x){
    if (n == NULL){
        AVLNode* n1 = new AVLNode();
        n1-> value = x;
        n = n1;
    }
    else{
        if (n-> value < x){
            inserth(n-> right, x);
            n-> height = max(height(n-> left), height(n-> right)) + 1;
            balance(n);
        }
        else if (n-> value > x){
            inserth(n-> left, x);
            n-> height = max(height(n-> left), height(n-> right)) + 1;
            balance(n);
        }
    }
    
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    return pathToh("", root, x);
}

string AVLTree::pathToh(string output, AVLNode*& n, const string& x) {
    if (find(x)){
        if (n-> value == x){
            output = output + n-> value;
            return output;
        }
        else{
            if (n-> value < x){
                output = output + n-> value + " ";
                return pathToh(output, n-> right, x);
            }
            else{
                output = output + n-> value + " ";
                return pathToh(output, n-> left, x);
            }
        }
    }
    else{
        return output;
    }
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    return findh(root, x);
}

bool AVLTree::findh(AVLNode*& n, const string& x) const{
    if (n == NULL){
        return false;
    }
    else{
        if (n-> value == x){
            return true;
        }
        else if (n-> value < x){
            return findh (n-> right, x);
        }
        else{
            return findh (n-> left, x);
        }
    }
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() {
    // YOUR IMPLEMENTATION GOES HERE
    return numNodesh(root);
}

int AVLTree::numNodesh(AVLNode*& n){
    if (n == NULL){
      return 0;
    }
    else {
      return 1 + (numNodesh(n -> left) + numNodesh(n -> right));
   }
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  if (height(n-> right) - height(n-> left) < -1 && height(n-> left-> right) - height(n-> left-> left) < 0){
        n = rotateRight(n);
    }
      else if (height(n-> right) - height(n-> left) < -1 && height(n-> left-> right) - height(n-> left-> left) > 0){
        n-> left = rotateLeft(n-> left);
        n = rotateRight(n);
    }
      else if (height(n-> right) - height(n-> left) > 1 && height(n-> right-> right) - height(n-> right-> left) > 0){
        n = rotateLeft(n);
    }
      else if (height(n-> right) - height(n-> left) > 1 && height(n-> right-> right) - height(n-> right-> left) < 0){
        n-> right = rotateRight(n-> right);
        n = rotateLeft(n);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* r = n-> right;
    AVLNode* rl = r-> left;
    
    r-> left = n;
    n-> right = rl;
    
    n-> height = max(height(n-> left), height(n-> right)) + 1;
    r-> height = max(height(r-> left), height(r-> right)) + 1;
    
    return r;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* l = n-> left;
    AVLNode* lr = l-> right;
    
    l-> right = n;
    n-> left = lr;
    
    n-> height = max(height(n-> left), height(n-> right)) + 1;
    l-> height = max(height(l-> left), height(l-> right)) + 1;
    
    return l;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int AVLTree::max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
