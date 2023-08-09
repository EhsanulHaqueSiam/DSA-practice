#include <iostream>

class Node {
public:
    Node* left_child;  // Pointer to the left child node
    int data;  // Data stored in the node
    Node* right_child;  // Pointer to the right child node
    int height;  // Height of the node
};

class AVLTree {
public:
    Node* root;  // Root node of the AVL tree

    AVLTree() { root = nullptr; }

    // Helper methods for inserting/deleting
    int GetNodeHeight(Node* node);
    int GetBalanceFactor(Node* node);
    Node* PerformLLRotation(Node* node);
    Node* PerformRRRotation(Node* node);
    Node* PerformLRRotation(Node* node);
    Node* PerformRLRotation(Node* node);
    Node* GetInPredecessor(Node* node);
    Node* GetInSuccessor(Node* node);

    // Insertion
    Node* RecursiveInsert(Node* node, int key);

    // Traversal
    void InorderTraversal(Node* node);
    void InorderTraversal() { InorderTraversal(root); }
    Node* GetRoot() { return root; }

    // Deletion
    Node* DeleteNode(Node* node, int key);
};

int AVLTree::GetNodeHeight(Node* node) {
    return (node ? node->height : 0);
}

int AVLTree::GetBalanceFactor(Node* node) {
    return (node ? GetNodeHeight(node->left_child) - GetNodeHeight(node->right_child) : 0);
}

Node* AVLTree::PerformLLRotation(Node* node) {
    Node* left_child = node->left_child;
    Node* left_right_child = left_child->right_child;

    left_child->right_child = node;
    node->left_child = left_right_child;

    // Update heights
    node->height = GetNodeHeight(node);
    left_child->height = GetNodeHeight(left_child);

    // Update root
    if (root == node) {
        root = left_child;
    }

    return left_child;
}

Node* AVLTree::PerformRRRotation(Node* node) {
    Node* right_child = node->right_child;
    Node* right_left_child = right_child->left_child;

    right_child->left_child = node;
    node->right_child = right_left_child;

    // Update heights
    node->height = GetNodeHeight(node);
    right_child->height = GetNodeHeight(right_child);

    // Update root
    if (root == node) {
        root = right_child;
    }

    return right_child;
}

Node* AVLTree::PerformLRRotation(Node* node) {
    Node* left_child = node->left_child;
    Node* left_right_child = left_child->right_child;

    left_child->right_child = left_right_child->left_child;
    node->left_child = left_right_child->right_child;

    left_right_child->left_child = left_child;
    left_right_child->right_child = node;

    // Update heights
    left_child->height = GetNodeHeight(left_child);
    node->height = GetNodeHeight(node);
    left_right_child->height = GetNodeHeight(left_right_child);

    // Update root
    if (node == root) {
        root = left_right_child;
    }

    return left_right_child;
}

Node* AVLTree::PerformRLRotation(Node* node) {
    Node* right_child = node->right_child;
    Node* right_left_child = right_child->left_child;

    right_child->left_child = right_left_child->right_child;
    node->right_child = right_left_child->left_child;

    right_left_child->right_child = right_child;
    right_left_child->left_child = node;

    // Update heights
    right_child->height = GetNodeHeight(right_child);
    node->height = GetNodeHeight(node);
    right_left_child->height = GetNodeHeight(right_left_child);

    // Update root
    if (root == node) {
        root = right_left_child;
    }

    return right_left_child;
}

Node* AVLTree::GetInPredecessor(Node* node) {
    while (node && node->right_child != nullptr) {
        node = node->right_child;
    }
    return node;
}

Node* AVLTree::GetInSuccessor(Node* node) {
    while (node && node->left_child != nullptr) {
        node = node->left_child;
    }
    return node;
}

Node* AVLTree::RecursiveInsert(Node* node, int key) {
    if (node == nullptr) {
        node = new Node;
        node->data = key;
        node->left_child = nullptr;
        node->right_child = nullptr;
        node->height = 1;  // Starting height from 1 onwards instead of 0
        return node;
    }

    if (key < node->data) {
        node->left_child = RecursiveInsert(node->left_child, key);
    } else if (key > node->data) {
        node->right_child = RecursiveInsert(node->right_child, key);
    }

    // Update height
    node->height = GetNodeHeight(node);

    // Balance Factor and Rotation
    if (GetBalanceFactor(node) == 2 && GetBalanceFactor(node->left_child) == 1) {
        return PerformLLRotation(node);
    } else if (GetBalanceFactor(node) == 2 && GetBalanceFactor(node->left_child) == -1) {
        return PerformLRRotation(node);
    } else if (GetBalanceFactor(node) == -2 && GetBalanceFactor(node->right_child) == -1) {
        return PerformRRRotation(node);
    } else if (GetBalanceFactor(node) == -2 && GetBalanceFactor(node->right_child) == 1) {
        return PerformRLRotation(node);
    }

    return node;
}

void AVLTree::InorderTraversal(Node* node) {
    if (node) {
        InorderTraversal(node->left_child);
        std::cout << node->data << ", " << std::flush;
        InorderTraversal(node->right_child);
    }
}

Node* AVLTree::DeleteNode(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->left_child == nullptr && node->right_child == nullptr) {
        if (node == root) {
            root = nullptr;
        }
        delete node;
        return nullptr;
    }

    if (key < node->data) {
        node->left_child = DeleteNode(node->left_child, key);
    } else if (key > node->data) {
        node->right_child = DeleteNode(node->right_child, key);
    } else {
        Node* q;
        if (GetNodeHeight(node->left_child) > GetNodeHeight(node->right_child)) {
            q = GetInPredecessor(node->left_child);
            node->data = q->data;
            node->left_child = DeleteNode(node->left_child, q->data);
        } else {
            q = GetInSuccessor(node->right_child);
            node->data = q->            data;
            node->right_child = DeleteNode(node->right_child, q->data);
        }
    }

    // Update height
    node->height = GetNodeHeight(node);

    // Balance Factor and Rotation
    if (GetBalanceFactor(node) == 2 && GetBalanceFactor(node->left_child) == 1) {  // L1 Rotation
        return PerformLLRotation(node);
    } else if (GetBalanceFactor(node) == 2 && GetBalanceFactor(node->left_child) == -1) {  // L-1 Rotation
        return PerformLRRotation(node);
    } else if (GetBalanceFactor(node) == -2 && GetBalanceFactor(node->right_child) == -1) {  // R-1 Rotation
        return PerformRRRotation(node);
    } else if (GetBalanceFactor(node) == -2 && GetBalanceFactor(node->right_child) == 1) {  // R1 Rotation
        return PerformRLRotation(node);
    } else if (GetBalanceFactor(node) == 2 && GetBalanceFactor(node->left_child) == 0) {  // L0 Rotation
        return PerformLLRotation(node);
    } else if (GetBalanceFactor(node) == -2 && GetBalanceFactor(node->right_child) == 0) {  // R0 Rotation
        return PerformRRRotation(node);
    }

    return node;
}

int main() {
    AVLTree tree;

    int values[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        tree.root = tree.RecursiveInsert(tree.root, values[i]);
    }

    tree.InorderTraversal();
    std::cout << std::endl;

    tree.DeleteNode(tree.root, 28);

    tree.InorderTraversal();
    std::cout << std::endl;

    return 0;
}
