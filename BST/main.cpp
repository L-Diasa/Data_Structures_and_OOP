#include <iostream>
#include "TreeNode.hpp"
#include "BST.hpp"
using namespace std;


int main(){
    // testing constructor
    BST bst1;

    // testing insert
    bst1.insert(7);
    bst1.insert(13);
    bst1.insert(5);

    // testing copy constructor
    BST bst2 = bst1;

    bst1.insert(10);
    bst1.insert(12);
    bst2.insert(6);
    bst2.insert(19);

    // testing search
    cout << "Searching in bst1:\n";
    bst1.search(3);
    bst1.search(7);
    bst1.search(19);
    cout << "\nSearching in bst2:\n";
    bst2.search(19);
    bst2.search(13);
    bst2.search(6);

    // testing assignment operator
    BST bst3, bst4;
    bst3 = bst2;
    bst4 = bst1;

    bst3.insert(1);
    bst4.insert(83);

    cout << "\nSearching in bst1:\n";
    bst1.search(83);
    cout << "\nSearching in bst2:\n";
    bst2.search(1);
    cout << "\nSearching in bst3:\n";
    bst3.search(6);
    cout << "\nSearching in bst4:\n";
    bst4.search(12);

    // testing detele
    bst4.deleteNode(13); // has two childern
    
    cout << "\nSearching in bst4:\n";
    bst4.search(13);
    bst4.search(10);
    bst4.search(83);
    bst4.search(12);
    
    bst1.deleteNode(10); // has one child

    cout << "\nSearching in bst1:\n";
    bst1.search(10);
    bst1.search(12);
    
    bst2.deleteNode(6); // is a leaf

    cout << "\nSearching in bst2:\n";
    bst2.search(6);
    bst2.search(5);
    cout << endl;
    
    // testing print
    bst1.print("Preorder");
    bst1.print("Inorder");
    bst1.print("Postorder");
    cout << endl;
    
    bst3.print("Preorder");
    bst3.print("Inorder");
    bst3.print("Postorder");
    cout << endl;
    
    BST bst5;
    bst5.insert(15);
    bst5.insert(10);
    bst5.insert(20);
    bst5.insert(8);
    bst5.insert(12);
    bst5.insert(16);
    bst5.insert(25);
    
    bst5.print("Preorder");
    bst5.print("Inorder");
    bst5.print("Postorder");
    
}

