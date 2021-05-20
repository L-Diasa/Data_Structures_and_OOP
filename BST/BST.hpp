#ifndef BST_hpp
#define BST_hpp

#include <new>
#include <iostream>
#include "TreeNode.hpp"
using namespace std;

class BST {
    TreeNode *root;
    
    /*---helper funtions---*/
    // for search
    bool search(TreeNode* subtrRoot, int val);
    // for insert
    TreeNode* insert(TreeNode*& subtrRoot, int val);
    // for copying
    void helperCopy(TreeNode*& copyTo, TreeNode* subtrRoot);
    // for destructor
    void destroy(TreeNode*& subtrRoot);
    // for deletion
    void search(int val, bool& found,
                TreeNode*& curr, TreeNode*& parent);
    
    /*---traverse funtions---*/
    // preorder
    void preorder(ostream &out, TreeNode* subtree) const;
    // inorder
    void inorder(ostream &out, TreeNode* subtree) const;
    // postorder
    void postorder(ostream &out, TreeNode* subtree) const;
    
public:
    // constructor
    BST() {
        root = nullptr;
    }
    
    // copy constructor
    BST(const BST & original) : root(nullptr) {
        helperCopy(this->root, original.root);
    }
    
    // destructor
    ~BST() {
        destroy(root);
    }
    
    // assignment operator=
    const BST & operator= (const BST & rightHandSide);

    // insert a node in the tree
    void insert(int val) {
        root = insert(root, val);
    }
    
    // delete a node from the tree
    void deleteNode(int val);
    
    // search for an element in the tree
    void search(int val) {
        cout << "Item to find " << val << ": ";
        cout << (search(root, val) ? "Found" :
                 "Not found") << endl;
    }
    
    // print the contents of the tree
    void print(string traversal);
};


#endif /* BST_hpp */
