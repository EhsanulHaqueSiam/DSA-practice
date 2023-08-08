#include <iostream>

class TreeNode {
public:
    TreeNode* left_child;
    int value;
    TreeNode* right_child;
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() { root = nullptr; }

    TreeNode* GetRoot() { return root; }

    // Iteratively insert a key into the BST
    void Insert(int key);

    // Inorder traversal of the BST
    void InorderTraversal(TreeNode* node);

    // Iteratively search for a key in the BST
    TreeNode* Search(int key);

    // Recursively insert a key into the BST
    TreeNode* RecursiveInsert(TreeNode* node, int key);

    // Recursively search for a key in the BST
    TreeNode* RecursiveSearch(TreeNode* node, int key);

    // Delete a key from the BST
    TreeNode* Delete(TreeNode* node, int key);

    // Calculate the height of a node
    int CalculateHeight(TreeNode* node);

    // Find the inorder predecessor of a node
    TreeNode* InorderPredecessor(TreeNode* node);

    // Find the inorder successor of a node
    TreeNode* InorderSuccessor(TreeNode* node);
};

void BinarySearchTree::Insert(int key) {
    TreeNode* temp = root;
    TreeNode* parent = nullptr;

    // If the tree is empty
    if (root == nullptr) {
        TreeNode* new_node = new TreeNode;
        new_node->value = key;
        new_node->left_child = nullptr;
        new_node->right_child = nullptr;
        root = new_node;
        return;
    }

    while (temp != nullptr) {
        parent = temp;
        if (key < temp->value) {
            temp = temp->left_child;
        } else if (key > temp->value) {
            temp = temp->right_child;
        } else {
            return; // Key already exists in the tree
        }
    }

    // Now temp points at nullptr and parent points at the insertion location
    TreeNode* new_node = new TreeNode;
    new_node->value = key;
    new_node->left_child = nullptr;
    new_node->right_child = nullptr;

    if (key < parent->value) {
        parent->left_child = new_node;
    } else {
        parent->right_child = new_node;
    }
}

void BinarySearchTree::InorderTraversal(TreeNode* node) {
    if (node) {
        InorderTraversal(node->left_child);
        std::cout << node->value << ", ";
        InorderTraversal(node->right_child);
    }
}

TreeNode* BinarySearchTree::Search(int key) {
    TreeNode* temp = root;
    while (temp != nullptr) {
        if (key == temp->value) {
            return temp;
        } else if (key < temp->value) {
            temp = temp->left_child;
        } else {
            temp = temp->right_child;
        }
    }
    return nullptr;
}

TreeNode* BinarySearchTree::RecursiveInsert(TreeNode* node, int key) {
    TreeNode* new_node;
    if (node == nullptr) {
        new_node = new TreeNode;
        new_node->value = key;
        new_node->left_child = nullptr;
        new_node->right_child = nullptr;
        return new_node;
    }

    if (key < node->value) {
        node->left_child = RecursiveInsert(node->left_child, key);
    } else if (key > node->value) {
        node->right_child = RecursiveInsert(node->right_child, key);
    }
    return node;
}

TreeNode* BinarySearchTree::RecursiveSearch(TreeNode* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key == node->value) {
        return node;
    } else if (key < node->value) {
        return RecursiveSearch(node->left_child, key);
    } else {
        return RecursiveSearch(node->right_child, key);
    }
}

TreeNode* BinarySearchTree::Delete(TreeNode* node, int key) {
    TreeNode* q;

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

    if (key < node->value) {
        node->left_child = Delete(node->left_child, key);
    } else if (key > node->value) {
        node->right_child = Delete(node->right_child, key);
    } else {
        if (CalculateHeight(node->left_child) > CalculateHeight(node->right_child)) {
            q = InorderPredecessor(node->left_child);
            node->value = q->value;
            node->left_child = Delete(node->left_child, q->value);
        } else {
            q = InorderSuccessor(node->right_child);
            node->value = q->value;
            node->right_child = Delete(node->right_child, q->value);
        }
    }
    return node;
}

int BinarySearchTree::CalculateHeight(TreeNode* node) {
    int left_height;
    int right_height;
    if (node == nullptr) {
        return 0;
    }
    left_height = CalculateHeight(node->left_child);
    right_height = CalculateHeight(node->right_child);
    return left_height > right_height ? left_height + 1 : right_height + 1;
}

TreeNode* BinarySearchTree::InorderPredecessor(TreeNode* node) {
    while (node && node->right_child != nullptr) {
        node = node->right_child;
    }
    return node;
}

TreeNode* BinarySearchTree::InorderSuccessor(TreeNode* node) {
    while (node && node->left_child != nullptr) {
        node = node->left_child;
    }
    return node;
}

int main() {
    BinarySearchTree bst;

    // Iterative insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);

    // Inorder traversal
    bst.InorderTraversal(bst.GetRoot());
    std::cout << std::endl;

    // Iterative search
    TreeNode* temp = bst.Search(2);
    if (temp != nullptr) {
        std::cout << temp->value << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    // Recursive search
    temp = bst.RecursiveSearch(bst.GetRoot(), 20);
    if (temp != nullptr) {
        std::cout << temp->value << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    // Recursive insert
    bst.RecursiveInsert(bst.GetRoot(), 50);
    bst.RecursiveInsert(bst.GetRoot(), 70);
    bst.RecursiveInsert(bst.GetRoot(), 1);
    bst.InorderTraversal(bst.GetRoot());
    std::cout << "\n" << std::endl;

    // Inorder predecessor and inorder successor
    BinarySearchTree bs;
    bs.Insert(5);
    bs.Insert(2);
    bs.Insert(8);
    bs.Insert(7);
    bs.Insert(9);
    bs.Insert(1);

    temp = bs.InorderPredecessor(bs.GetRoot());
    std::cout << "InPre: " << temp->value << std::endl;

    temp = bs.InorderSuccessor(bs.GetRoot());
    std::cout << "InSucc: " << temp->value << std::endl;

    bs.InorderTraversal(bs.GetRoot());
    std::cout << std::endl;

    // Delete
    bs.Delete(bs.GetRoot(), 7);
    bs.InorderTraversal(bs.GetRoot());

    return 0;
}
