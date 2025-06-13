#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>

// Enumeration for colors of nodes in Red-Black Tree
enum Color { BLACK, RED };

// Class template for Red-Black Tree
template <typename T>
class RedBlackTree {
private:
    // Structure for a node in Red-Black Tree
    struct Node {
        T data;
        Node* parent;
        Node* left;
        Node* right;
        Color color;
        int subtreeKeyCount;

        // Constructor to initialize node with data and
        // color
        Node() {};

        Node(T value)
            : data(value)
            , color(RED)
            , parent(nullptr)
            , left(nullptr)
            , right(nullptr)
            , subtreeKeyCount(1)
        {
        }
    };

    Node* root; // Root of the Red-Black Tree
    Node* TNULL;

    void updateSubtreeKeyCount(Node* node) {
        if (node == TNULL) return;
        node->subtreeKeyCount = 1 + getSubtreeKeyCount(node->left) + getSubtreeKeyCount(node->right);
    }


    int getSubtreeKeyCount(Node* node) const {
        return node == TNULL ? 0 : node->subtreeKeyCount;
    }

    // Utility function: Left Rotation
    void leftRotate(Node* node) {
        Node* child = node->right;
        node->right = child->left;
        if (child->left != TNULL)
            child->left->parent = node;
        child->parent = node->parent;
        if (node->parent == nullptr)
            root = child;
        else if (node == node->parent->left)
            node->parent->left = child;
        else
            node->parent->right = child;
        child->left = node;
        node->parent = child;
        updateSubtreeKeyCount(node);
        updateSubtreeKeyCount(child);
    }

    // Utility function: Right Rotation
    void rightRotate(Node* node) {
        Node* child = node->left;
        node->left = child->right;
        if (child->right != TNULL)
            child->right->parent = node;
        child->parent = node->parent;
        if (node->parent == nullptr)
            root = child;
        else if (node == node->parent->left)
            node->parent->left = child;
        else
            node->parent->right = child;
        child->right = node;
        node->parent = child;
        updateSubtreeKeyCount(node);
        updateSubtreeKeyCount(child);
    }

    // Utility function: Fixing Insertion Violation
    void insertFix(Node* node)
    {
        Node* parent = nullptr;
        Node* grandparent = nullptr;
        while (node->parent->color == RED) {
            parent = node->parent;
            grandparent = parent->parent;
            if (parent == grandparent->right) {
                Node* uncle = grandparent->left;
                if (uncle != nullptr && uncle->color == RED) {
                    uncle->color = BLACK;
                    parent->color = BLACK;
                    grandparent->color = RED;
                    node = grandparent;
                }
                else {
                    if (node == parent->left) {
                        node = parent;
                        rightRotate(node);
                    }
                    parent->color = BLACK;
                    grandparent->color = RED;
                    leftRotate(grandparent);
                }
            }
            else {
                Node* uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    uncle->color = BLACK;
                    parent->color = BLACK;
                    grandparent->color = RED;
                    node = grandparent;
                }
                else {
                    if (node == parent->right) {
                        node = parent;
                        leftRotate(node);
                    }
                    parent->color = BLACK;
                    grandparent->color = RED;
                    rightRotate(grandparent);
                }
            }
            if (node == root) {
                break;
            }
        }
        root->color = BLACK;
    }

    // Utility function: Fixing Deletion Violation
    void deleteFix(Node* node) {
        Node* sibling;
        while (node != root && node->color == BLACK) {
            if (node == node->parent->left) {
                sibling = node->parent->right;
                if (sibling != nullptr && sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    leftRotate(node->parent);
                    sibling = node->parent->right;
                }
                if ((sibling->left == nullptr || sibling->left->color == BLACK)
                    && (sibling->right == nullptr || sibling->right->color == BLACK)) {
                    sibling->color = RED;
                    node = node->parent;
                }
                else {
                    if (sibling->right == nullptr || sibling->right->color == BLACK) {
                        if (sibling->left != nullptr) {
                            sibling->left->color = BLACK;
                        }
                        sibling->color = RED;
                        rightRotate(sibling);
                        sibling = node->parent->right;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    if (sibling->right != nullptr) {
                        sibling->right->color = BLACK;
                    }
                    leftRotate(node->parent);
                    node = root;
                }
            }
            else {
                sibling = node->parent->left;
                if (sibling != nullptr && sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    rightRotate(node->parent);
                    sibling = node->parent->left;
                }
                if ((sibling->left == nullptr || sibling->left->color == BLACK)
                    && (sibling->right == nullptr || sibling->right->color == BLACK)) {
                    sibling->color = RED;
                    node = node->parent;
                }
                else {
                    if (sibling->left == nullptr || sibling->left->color == BLACK) {
                        if (sibling->right != nullptr) {
                            sibling->right->color = BLACK;
                        }
                        sibling->color = RED;
                        leftRotate(sibling);
                        sibling = node->parent->left;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    if (sibling->left != nullptr)
                        sibling->left->color = BLACK;
                    rightRotate(node->parent);
                    node = root;
                }
            }
        }
        if (node != nullptr) {
            node->color = BLACK;
        }
    }

    // Utility function: Find Node with Minimum Value
    Node* minValueNode(Node* node)
    {
        while (node->left != TNULL)
            node = node->left;
        return node;
    }

    // Utility function: Transplant nodes in Red-Black Tree
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    // Utility function: Helper to print Red-Black Tree
    void printHelper(Node* root, std::string indent, bool last)
    {
        if (root != TNULL) {
            std::cout << indent;
            if (last) {
                std::cout << "R----";
                indent += "   ";
            }
            else {
                std::cout << "L----";
                indent += "|  ";
            }
            std::string sColor = (root->color == RED) ? "RED" : "BLACK";
            std::cout << root->data << "(" << sColor << ")"
                << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    // Utility function: Delete all nodes in the Red-Black
    // Tree
    void deleteTree(Node* node)
    {
        if (node != TNULL) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    T GetNthKey(Node* node, int& n) const {
        if (node == TNULL) throw std::out_of_range("Index out of range.");
        T leftResult = 0;
        try {
            leftResult = GetNthKey(node->left, n);
            return leftResult;
        } catch (...) {
            if (n == 0) return node->data;
            n--;
            return GetNthKey(node->right, n);
        }
    }

public:
    // Constructor: Initialize Red-Black Tree
    RedBlackTree() {
        TNULL = new Node();
        TNULL->color = BLACK;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        TNULL->subtreeKeyCount = 0;
        root = TNULL;
    }

    // Destructor: Delete Red-Black Tree
    ~RedBlackTree() { deleteTree(root); }

    // Public function: Insert a value into Red-Black Tree
    void insert(T key)
    {
        Node* node = new Node(key);
        node->left = TNULL;
        node->right = TNULL;
        Node* parent = nullptr;
        Node* current = root;
        while (current != TNULL) {
            parent = current;
            current->subtreeKeyCount++;
            if (node->data < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        node->parent = parent;
        if (parent == nullptr) {
            root = node;
        }
        else if (node->data < parent->data) {
            parent->left = node;
        }
        else {
            parent->right = node;
        }

        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFix(node);
    }

    // Public function: Remove a value from Red-Black Tree
    void remove(T key) {
        Node* node = root;
        Node* z = TNULL;
        Node* x;
        Node* y;

        // Locate the node to delete
        while (node != nullptr) {
            if (node->data == key) {
                z = node;
                break;
            }
            if (node->data <= key) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }

        // If the node to be deleted is not found
        if (z == TNULL) {
            std::cout << "Key not found in the tree" << std::endl;
            return;
        }

        y = z;
        Color yOriginalColor = y->color;

        // Case 1: z has only one child or no child
        if (z->left == TNULL) {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            transplant(z, z->left);
        }
        // Case 2: z has two children
        else {
            y = minValueNode(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;

        Node* current = x->parent;
        while (current != nullptr) {
            updateSubtreeKeyCount(current);
            current = current->parent;
        }

        if (yOriginalColor == BLACK) {
            deleteFix(x);
        }
    }

    T GetNthKey(int n) const {
        if (n < 0 || n >= root->subtreeKeyCount) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = root;
        while (current != TNULL) {
            int leftCount = getSubtreeKeyCount(current->left);
            if (n < leftCount) {
                current = current->left;
            } else if (n == leftCount) {
                return current->data;
            } else {
                n -= (leftCount + 1);
                current = current->right;
            }
        }

        throw std::out_of_range("Index out of range");
    }

    int getSubtreeKeyCount(T key) const {
        Node* current = root;
        while (current != TNULL) {
            if (current->data == key) {
                return current->subtreeKeyCount;
            } else if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        std::cout << "Key not found in the tree" << std::endl;
        return -1;
    }

    // Public function: Print the Red-Black Tree
    void printTree() {
        if (root == TNULL)
            std::cout << "Tree is empty." << std::endl;
        else {
            std::cout << "Red-Black Tree:" << std::endl;
            printHelper(root, "", true);
        }
    }
};
#endif
