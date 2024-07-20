#include "../Base/Node.h"

// Declarattion
template <typename T> class BinarySearchTree {
private:
    TreeNode<T> *root;
public:
    BinarySearchTree();
};

// Definition
template <typename T> BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}




