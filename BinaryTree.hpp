// **************************************
// *      Hassan Chizari 2024           *
// *      Gonzaga  University           *
// **************************************

// To avoid double compilation of the code 
#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>

using namespace std;

// A simple Node structure for the binary tree
struct Node {
    // Node properties
    int data;
    Node* left;
    Node* right;

    // Node constructor
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Class for the binary tree
class BinaryTree {
    Node* root;

    // Recursively insert a node
    Node* insertNode(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insertNode(node->left, data);
        } else {
            node->right = insertNode(node->right, data);
        }

        return node;
    }

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(Node* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    Node* searchNodeHelper(Node* node, int data) {
        if (node == nullptr) {
            return node;
        }

        if (node->data == data) {
            return node;
        } 
        
        return data < node->data ? searchNodeHelper(node->left, data) : searchNodeHelper(node->right, data);
    }
    
    Node* deleteNodeHelper(Node* node, int data) {
        if (node == nullptr) {
            return nullptr;  // Node not found
        }

        if (data < node->data) {
            node->left = deleteNodeHelper(node->left, data);
        } else
 
        if (data > node->data) {
            node->right = deleteNodeHelper(node->right, data);
        } else {
            // Node to be deleted found

            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                // Find inorder successor
                Node* successor = findMinNode(node->right);
                node->data = successor->data;
                node->right = deleteNodeHelper(node->right, successor->data);
            }
        }
        return node;
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    int heightHelper(Node* node) {
        if (node == nullptr) {
            return 0;  
        }

        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    // Insert a new node
    void insert(int data) {
        root = insertNode(root, data);
    }

    // Inorder traversal (left, root, right)
    void inorder() {
        inorderTraversal(root);
    }

    // Preorder traversal (root, left, right)
    void preorder() {
        preorderTraversal(root);
    }

    // Postorder traversal (left, right, root)
    void postorder() {
        postorderTraversal(root);
    }

    // Search for a value
    bool searchNode(int data) {
        Node *node = searchNodeHelper(root, data);
        if (node == nullptr) {
            return false;
        }
        return true;
    }

    void deleteNode(int data) {
        root = deleteNodeHelper(root, data);
    }

    int height() {
        return heightHelper(root);
    }

};

#endif