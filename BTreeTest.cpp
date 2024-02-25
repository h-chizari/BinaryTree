#include "BinaryTree.hpp"

int main() {
    BinaryTree tree;

    // Insert nodes
    cout << "Inserting all the nodes: "  << endl;
    tree.insert(10);
    tree.insert(8);
    tree.insert(30);
    tree.insert(5);
    tree.insert(1);
    tree.insert(6);
    tree.insert(9);
    tree.insert(20);
    tree.insert(21);
    tree.insert(12);
    tree.insert(85);
    tree.insert(100);  
    tree.insert(33);

    // Perform operations
    cout << "Inorder traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder();
    cout << endl;

    int item1 = 30;
    cout << "Searching for: " << item1 << " "; 
    cout << (tree.searchNode(item1) ? "Found!":"Not found!");
    cout << endl;

    int item2 = 35;
    cout << "Searching for: " << item2 << " "; 
    cout << (tree.searchNode(item2) ? "Found!":"Not found!");
    cout << endl;

    cout << "Deleting item 70" << endl;
    tree.deleteNode(70);
    cout << "Inorder traversal: ";
    tree.inorder();
    cout << endl;

    cout << "The height of the tree is:";
    cout << tree.height();
    cout << endl;

    tree.insert(90);
    tree.insert(100);
    tree.insert(110);

    cout << "After inserting 3 new items the height of the tree is:";
    cout << tree.height();
    cout << endl;   
    return 0;
}
