#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

class TreeNode {
// private:
    int val;
    TreeNode *left;
    TreeNode *right;
    friend class BST;
    
public:
    // default constructor
    TreeNode() {
        left = right = NULL;
    }

    // explicit value constructor
    TreeNode(int i, TreeNode* L = 0, TreeNode* R = 0)
    : val(i), left(L), right(R) {};

    // accessor function
    int getItem () const{
        return val;
    }
};

#endif /* TreeNode_hpp */
