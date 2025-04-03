//A simple C++ program that implements a binary tree using linked lists and performs basic operations like insertion, traversal (in-order), and deletion.

// Crispus Joash Alwala- REG NO: SIT/B/01-03318/2023
// Anthony Ombiro- REG NO: SIT/B/01-03256/2023

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int key) {
        val = key;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Insert a new key
    void insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
        } else {
            insertRecursively(root, key);
        }
    }

    void insertRecursively(Node* currentNode, int key) {
        if (key < currentNode->val) {
            if (currentNode->left == nullptr) {
                currentNode->left = new Node(key);
            } else {
                insertRecursively(currentNode->left, key);
            }
        } else {
            if (currentNode->right == nullptr) {
                currentNode->right = new Node(key);
            } else {
                insertRecursively(currentNode->right, key);
            }
        }
    }

    // In-order traversal
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->val << " ";
            inorderTraversal(node->right);
        }
    }

    // Delete a key
    void deleteKey(int key) {
        root = deleteRecursively(root, key);
    }

    Node* deleteRecursively(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->val) {
            node->left = deleteRecursively(node->left, key);
        } else if (key > node->val) {
            node->right = deleteRecursively(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                return node->right;
            } else if (node->right == nullptr) {
                return node->left;
            }

            // Node with two children: Get the inorder successor
            Node* minLargerNode = minValueNode(node->right);
            node->val = minLargerNode->val;
            node->right = deleteRecursively(node->right, minLargerNode->val);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    BinaryTree btree;
    btree.insert(50);
    btree.insert(30);
    btree.insert(70);
    btree.insert(20);
    btree.insert(40);
    btree.insert(60);
    btree.insert(80);

    cout << "In-order traversal:" << endl;
    btree.inorderTraversal(btree.root); // Should output sorted order

    cout << "\nDeleting 20" << endl;
    btree.deleteKey(20);
    cout << "In-order traversal after deletion:" << endl;
    btree.inorderTraversal(btree.root);

    cout << "\nDeleting 30" << endl;
    btree.deleteKey(30);
    cout << "In-order traversal after deletion:" << endl;
    btree.inorderTraversal(btree.root);

    cout << "\nDeleting 50" << endl;
    btree.deleteKey(50);
    cout << "In-order traversal after deletion:" << endl;
    btree.inorderTraversal(btree.root);

    return 0;
}

