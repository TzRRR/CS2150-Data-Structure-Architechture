// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode* t1 = new TreeNode(val);
    if (val == "+" || val == "-" || val == "*" || val == "/"){
        t1-> right = expressionStack.top();
        expressionStack.pop();
        t1-> left = expressionStack.top();
        expressionStack.pop();
        expressionStack.push(t1);
    }
    else{
        expressionStack.push(t1);
        
    }
    
    
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
    if (tree == NULL){
        return;
    }
    cout << tree-> value << " ";
    printPrefix(tree-> left);
    printPrefix(tree-> right);
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
    if (tree == NULL){
        return;
    }
    if (tree-> value == )
    printInfix(tree-> left);
    cout << "(" << tree-> value << " ";
    printInfix(tree-> right);
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    if (tree == NULL){
        return;
    }
    printPrefix(tree-> left);
    printPrefix(tree-> right);
    cout << tree-> value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
    if (tree == NULL){
        return 0;
    }
    if (tree-> left == NULL && tree-> right == NULL){
        return stoi(tree-> value);
    }
    else{
        int l = calculate(tree-> left);
        int r = calculate(tree-> right);
        if (tree-> value == "+"){
            return l + r;
        }
        else if (tree-> value == "-"){
            return l - r;
        }
        else if (tree-> value == "*"){
            return l * r;
        }
        else{
            return l / r;
        }
    }
    
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    TreeNode* temp = expressionStack.top();
    expressionStack.pop();
    return calculate (temp);
}
