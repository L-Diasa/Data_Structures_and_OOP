#include "BST.hpp"
using namespace std;

// helper for destructor
void BST::destroy(TreeNode*& subtrRoot) {
    if(subtrRoot != nullptr){       // until all nodes are destoyed
        destroy(subtrRoot->left);   // destoy left subtree
        destroy(subtrRoot->right);  // destoy right subtree
        delete subtrRoot;           // actual destruction
    }
}

// helper for copying
void BST::helperCopy(TreeNode* & copyTo, TreeNode* subtrRoot) {
    if(subtrRoot != nullptr) {
        // create and assign a new node(with the same val) to the root
        copyTo = new TreeNode(subtrRoot->val);
        // repeat for its left and right childern
        helperCopy(copyTo->left, subtrRoot->left);
        helperCopy(copyTo->right, subtrRoot->right);
    }
}

// assignment operator=
const BST & BST::operator= (const BST & rightHandSide) {
    if(this != &rightHandSide) {     // check that it's not the same object
        this->~BST();               // destroy current binary search tree
        helperCopy(this->root, rightHandSide.root); // assign
    }
    return *this;
}

// helper insert function
TreeNode* BST::insert(TreeNode*& subtrRoot, int val) {
    if(subtrRoot == nullptr) {       // if root is null, insert
        return new TreeNode(val);
    }
    else{
        if(subtrRoot->val > val)    // if val is less
            // compare it to its left child
            subtrRoot->left = insert(subtrRoot->left, val);
        else                        // if val is greater
            // compare it to its right child
            subtrRoot->right = insert(subtrRoot->right, val);
        return subtrRoot;
    }
}

// helper search
bool BST::search(TreeNode* subtrRoot, int val) {
    if(subtrRoot == nullptr)        // if val does not exist, returns false
        return false;
    else if( subtrRoot->val == val) // if val exists, returns true
        return true;
    else{
        if(subtrRoot->val > val)    // if val is less
            return search( subtrRoot->left, val); // search in left subtree
        else// if val is greater
            return search( subtrRoot->right, val);// search in right subtree
    }
}

// delete
void BST::deleteNode(int val) {
    bool found;
    TreeNode* curr;
    TreeNode* parent;
    search(val, found, curr, parent);
    if(found){
        // if it has two childen, make it have 0 or 1
        if(curr->left != 0 && curr->right != 0){
            // find the node for replaceing the value
            TreeNode* currSucc = curr->right;
            parent = curr;
            while(currSucc->left != 0){
                parent = currSucc;
                currSucc = currSucc->left;
            }
            // chage values
            curr->val = currSucc->val;
            curr = currSucc;
        }
        // it has 0/1 child
        TreeNode* subtree; // pointer to the subtree of the curr node
        subtree = curr->left == nullptr ? curr->right : curr->left;
        // make the parent node point to the subtree
        if(parent == nullptr) // root being deleted
            root = subtree;
        else if(parent->right == curr) // right child being deleted
            parent->right = subtree;
        else
            parent->left = subtree; // left child being deleted
        delete curr; // delete
    }
    else{
        cout << "Item not in BST\n";
        return;
    }
}

// helper search for deletion
void BST::search(int val, bool& found,
                 TreeNode*& curr, TreeNode*& parent) {
    // start from the root
    found = 0;
    curr = root;
    parent = nullptr;
    // search for the node that has the same val
    while(curr != nullptr){
        if(curr->val == val){
            found = 1;
            break;
        }
        parent = curr;
        curr = curr->val < val ? curr->right : curr->left;
    }
}


// traversals:

// preorder
void BST::preorder(ostream &out, TreeNode* subtree) const {
    if(subtree != nullptr){
        out << subtree->val << " ";   // V
        preorder(out, subtree->left); // L
        preorder(out, subtree->right);// R
    }
}
// inorder
void  BST::inorder(ostream &out, TreeNode* subtree) const {
    if(subtree != nullptr){
        inorder(out, subtree->left); // L
        out << subtree->val << " ";  // V
        inorder(out, subtree->right);// R
    }
}
// postorder
void BST::postorder(ostream &out, TreeNode* subtree) const {
    if(subtree != nullptr){
        postorder(out, subtree->left); // L
        postorder(out, subtree->right);// R
        out << subtree->val << " ";    // V
    }
}

// print
void BST::print(string traversal) {
    if(traversal == "Preorder") {
        cout << "Preorder Traversal of BST: \n";
        preorder(cout, root);
        cout << endl;
    }
    else if(traversal == "Inorder") {
        cout << "Inorder Traversal of BST: \n";
        inorder(cout, root);
        cout << endl;
    }
    else if(traversal == "Postorder") {
        cout << "Postorder Traversal of BST: \n";
        postorder(cout, root);
        cout << endl;
    }
    else
        cout << "Traversal does not exist";
}
