#include <iostream>

namespace google_style {

// Node class for binary search tree
class Node {
 public:
  Node* left_child;
  int data;
  Node* right_child;
};

// BinarySearchTree class with various operations
class BinarySearchTree {
 private:
  Node* root;

 public:
  BinarySearchTree() { root = nullptr; }
  
  // Get the root node of the tree
  Node* GetRoot() { return root; }
  
  // Iteratively insert a key into the tree
  void IterativeInsert(int key);
  
  // Perform in-order traversal of the tree
  void InorderTraversal(Node* node);
  
  // Iteratively search for a key in the tree
  Node* IterativeSearch(int key);
  
  // Recursively insert a key into the tree
  Node* RecursiveInsert(Node* node, int key);
  
  // Recursively search for a key in the tree
  Node* RecursiveSearch(Node* node, int key);
  
  // Delete a node with a specific key from the tree
  Node* DeleteNode(Node* node, int key);
  
  // Calculate the height of a node in the tree
  int CalculateHeight(Node* node);
  
  // Find the in-order predecessor of a node
  Node* InorderPredecessor(Node* node);
  
  // Find the in-order successor of a node
  Node* InorderSuccessor(Node* node);
};

// Function to iteratively insert a key into the tree
void BinarySearchTree::IterativeInsert(int key) {
  Node* current = root;
  Node* parent = nullptr;

  // Handle case when root is empty
  if (root == nullptr) {
    Node* new_node = new Node;
    new_node->data = key;
    new_node->left_child = nullptr;
    new_node->right_child = nullptr;
    root = new_node;
    return;
  }

  while (current != nullptr) {
    parent = current;
    if (key < current->data) {
      current = current->left_child;
    } else if (key > current->data) {
      current = current->right_child;
    } else {
      return;  // Key already exists, no need to insert
    }
  }

  // Now 'current' points to nullptr and 'parent' points to the insert location
  Node* new_node = new Node;
  new_node->data = key;
  new_node->left_child = nullptr;
  new_node->right_child = nullptr;

  if (key < parent->data) {
    parent->left_child = new_node;
  } else {
    parent->right_child = new_node;
  }
}

// Function to perform in-order traversal of the tree
void BinarySearchTree::InorderTraversal(Node* node) {
  if (node) {
    InorderTraversal(node->left_child);
    std::cout << node->data << ", ";
    InorderTraversal(node->right_child);
  }
}

// Function to iteratively search for a key in the tree
Node* BinarySearchTree::IterativeSearch(int key) {
  Node* current = root;
  while (current != nullptr) {
    if (key == current->data) {
      return current;
    } else if (key < current->data) {
      current = current->left_child;
    } else {
      current = current->right_child;
    }
  }
  return nullptr;
}

// Function to recursively insert a key into the tree
Node* BinarySearchTree::RecursiveInsert(Node* node, int key) {
  if (node == nullptr) {
    Node* new_node = new Node;
    new_node->data = key;
    new_node->left_child = nullptr;
    new_node->right_child = nullptr;
    return new_node;
  }

  if (key < node->data) {
    node->left_child = RecursiveInsert(node->left_child, key);
  } else if (key > node->data) {
    node->right_child = RecursiveInsert(node->right_child, key);
  }
  return node;  // Key already exists in the tree
}

// Function to recursively search for a key in the tree
Node* BinarySearchTree::RecursiveSearch(Node* node, int key) {
  if (node == nullptr) {
    return nullptr;
  }

  if (key == node->data) {
    return node;
  } else if (key < node->data) {
    return RecursiveSearch(node->left_child, key);
  } else {
    return RecursiveSearch(node->right_child, key);
  }
}

// Function to delete a node with a specific key from the tree
Node* BinarySearchTree::DeleteNode(Node* node, int key) {
  Node* temp;

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
    if (CalculateHeight(node->left_child) > CalculateHeight(node->right_child)) {
      temp = InorderPredecessor(node->left_child);
      node->data = temp->data;
      node->left_child = DeleteNode(node->left_child, temp->data);
    } else {
      temp = InorderSuccessor(node->right_child);
      node->data = temp->data;
      node->right_child = DeleteNode(node->right_child, temp->data);
    }
  }
  return node;
}

// Function to calculate the height of a node in the tree
int BinarySearchTree::CalculateHeight(Node* node) {
  int left_height, right_height;
  if (node == nullptr) {
    return 0;
  }
  left_height = CalculateHeight(node->left_child);
  right_height = CalculateHeight(node->right_child);
  return left_height > right_height ? left_height + 1 : right_height + 1;
}

// Function to find the in-order predecessor of a node
Node* BinarySearchTree::InorderPredecessor(Node* node) {
  while (node && node->right_child != nullptr) {
    node = node->right_child;
  }
  return node;
}

// Function to find the in-order successor of a node
Node* BinarySearchTree::InorderSuccessor(Node* node) {
  while (node && node->left_child != nullptr) {
    node = node->left_child;
  }
  return node;
}

}  

int main() {
  // Create a binary search tree instance
  google_style::BinarySearchTree bst;

  // Iteratively insert keys into the tree
  bst.IterativeInsert(10);
  bst.IterativeInsert(5);
  bst.IterativeInsert(20);
  bst.IterativeInsert(8);
  bst.IterativeInsert(30);

  // Perform in-order traversal of the tree
  bst.InorderTraversal(bst.GetRoot());
  std::cout << std::endl;

    // Iteratively search for a key in the tree
  google_style::Node* temp = bst.IterativeSearch(2);
  if (temp != nullptr) {
    std::cout << "Iterative Search: Key " << temp->data << " found." << std::endl;
  } else {
    std::cout << "Iterative Search: Element not found." << std::endl;
  }

  // Recursively search for a key in the tree
  temp = bst.RecursiveSearch(bst.GetRoot(), 20);
  if (temp != nullptr) {
    std::cout << "Recursive Search: Key " << temp->data << " found." << std::endl;
  } else {
    std::cout << "Recursive Search: Element not found." << std::endl;
  }

  // Recursively insert keys into the tree
  bst.RecursiveInsert(bst.GetRoot(), 50);
  bst.RecursiveInsert(bst.GetRoot(), 70);
  bst.RecursiveInsert(bst.GetRoot(), 1);

  // Perform in-order traversal of the tree
  std::cout << "In-order Traversal after Recursive Insertions: ";
  bst.InorderTraversal(bst.GetRoot());
  std::cout << std::endl;

  // Create another binary search tree instance
  google_style::BinarySearchTree bs;
  bs.IterativeInsert(5);
  bs.IterativeInsert(2);
  bs.IterativeInsert(8);
  bs.IterativeInsert(7);
  bs.IterativeInsert(9);
  bs.IterativeInsert(1);

  // Find the in-order predecessor and successor
  temp = bs.InorderPredecessor(bs.GetRoot());
  std::cout << "In-order Predecessor: " << temp->data << std::endl;

  temp = bs.InorderSuccessor(bs.GetRoot());
  std::cout << "In-order Successor: " << temp->data << std::endl;

  // Perform in-order traversal of the tree
  std::cout << "In-order Traversal: ";
  bs.InorderTraversal(bs.GetRoot());
  std::cout << std::endl;

  // Delete a node from the tree
  bs.DeleteNode(bs.GetRoot(), 7);

  // Perform in-order traversal after deletion
  std::cout << "In-order Traversal after Deletion: ";
  bs.InorderTraversal(bs.GetRoot());
  std::cout << std::endl;

  return 0;
}
