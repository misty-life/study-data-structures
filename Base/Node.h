#pragma once

// Node Declaration
template <typename T> class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node();
    Node(const T initData);
};

template <typename T> class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode();
    TreeNode(const T initData);
};

// Node Definition
template <typename T> Node<T>::Node() {
    prev = nullptr;
    next = nullptr;
}

template <typename T> Node<T>::Node(const T initData) : data(initData) {
    prev = nullptr;
    next = nullptr;
}

template <typename T> TreeNode<T>::TreeNode() {
    left = nullptr;
    right = nullptr;
}

template <typename T> TreeNode<T>::TreeNode(const T initData) : data(initData) {
    left = nullptr;
    right = nullptr;
}