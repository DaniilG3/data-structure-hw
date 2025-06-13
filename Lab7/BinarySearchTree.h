#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <stack>

// Template class for BinarySearchTree
template <typename T>
class BinarySearchTree {
private:
    struct TreeNode {
        T* data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T* value) : data(value), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;
    int size;

    void insert(TreeNode*& node, T* value, T*& result);
    T* find(TreeNode* node, T* value) const;
    T* deleteNode(TreeNode*& node, T* value);
    void displayInOrder(TreeNode* node) const;
    void destroyTree(TreeNode* node);

public:
    BinarySearchTree() : root(nullptr), size(0) {}
    ~BinarySearchTree() { destroyTree(root); }

    T* insert(T* value);
    T* find(T* value) const;
    int getSize() const { return size; }
    T* deleteNode(T* value);
    void displayInOrder() const { displayInOrder(root); }
};

template <typename T>
T* BinarySearchTree<T>::insert(T* value) {
    T* result = nullptr;
    insert(root, value, result);
    return result;
}

template <typename T>
void BinarySearchTree<T>::insert(TreeNode*& node, T* value, T*& result) {
    if (!node) {
        node = new TreeNode(value);
        result = value;
        ++size;
    } else if (*value == *(node->data)) {
        node->data->addCount();
        result = node->data;
    } else if (*value < *(node->data)) {
        insert(node->left, value, result);
    } else {
        insert(node->right, value, result);
    }
}

template <typename T>
T* BinarySearchTree<T>::find(T* value) const {
    return find(root, value);
}

template <typename T>
T* BinarySearchTree<T>::find(TreeNode* node, T* value) const {
    if (!node) return nullptr;
    if (*value == *(node->data)) return node->data;
    if (*value < *(node->data)) return find(node->left, value);
    return find(node->right, value);
}

template <typename T>
T* BinarySearchTree<T>::deleteNode(T* value) {
    return deleteNode(root, value);
}

template <typename T>
T* BinarySearchTree<T>::deleteNode(TreeNode*& node, T* value) {
    if (!node) return nullptr;
    if (*value < *(node->data)) return deleteNode(node->left, value);
    if (*value > *(node->data)) return deleteNode(node->right, value);

    T* result = node->data;
    if (!node->left) {
        TreeNode* temp = node->right;
        delete node;
        node = temp;
    } else if (!node->right) {
        TreeNode* temp = node->left;
        delete node;
        node = temp;
    } else {
        TreeNode* minNode = node->right;
        while (minNode->left) minNode = minNode->left;
        node->data = minNode->data;
        deleteNode(node->right, minNode->data);
    }
    --size;
    return result;
}

template <typename T>
void BinarySearchTree<T>::displayInOrder(TreeNode* node) const {
    if (!node) return;
    displayInOrder(node->left);
    std::cout << "word: " << node->data->getWord()
              << " - count: " << node->data->getCount() << std::endl;
    displayInOrder(node->right);
}

template <typename T>
void BinarySearchTree<T>::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node->data;
        delete node;
    }
}

#endif  // BINARYSEARCHTREE_H

// The print format of displayInOrder should be as follows
// std::cout << "word: " << current->data->getWord() << " - count: " << current->data->getCount() << std::endl;

