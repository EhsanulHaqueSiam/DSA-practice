#include <iostream>

using namespace std;

class Node {
 public:
  Node* lchild;
  int data;
  Node* rchild;
  int height;
};

class AVL {
 public:
  AVL() : root(nullptr) {}

  // Public API
  void Insert(int key);
  void Inorder();
  Node* getRoot() { return root; }

 private:
  Node* root;

  // Helper functions for inserting
  int NodeHeight(Node* p);
  int BalanceFactor(Node* p);
  Node* LLRotation(Node* p);
  Node* RRRotation(Node* p);
  Node* LRRotation(Node* p);
  Node* RLRotation(Node* p);
  Node* rInsert(Node* p, int key);
  void Inorder(Node* p);
};

int AVL::NodeHeight(Node* p) {
  int hl = (p && p->lchild) ? p->lchild->height : 0;
  int hr = (p && p->rchild) ? p->rchild->height : 0;

  // Return the greater of hl or hr incremented by 1
  return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node* p) {
  int hl = (p && p->lchild) ? p->lchild->height : 0;
  int hr = (p && p->rchild) ? p->rchild->height : 0;

  // Calculate and return the balance factor
  return hl - hr;
}

Node* AVL::LLRotation(Node* p) {
  Node* pl = p->lchild;
  Node* plr = pl->rchild;

  // Perform rotation
  pl->rchild = p;
  p->lchild = plr;

  // Update heights post rotation
  p->height = NodeHeight(p);
  pl->height = NodeHeight(pl);

  // If the rotated node was the root, update the root
  if (root == p) root = pl;

  return pl;
}

Node* AVL::RRRotation(Node* p) {
  Node* pr = p->rchild;
  Node* prl = pr->lchild;

  // Perform rotation
  pr->lchild = p;
  p->rchild = prl;

  // Update heights post rotation
  p->height = NodeHeight(p);
  pr->height = NodeHeight(pr);

  // If the rotated node was the root, update the root
  if (root == p) root = pr;

  return pr;
}

Node* AVL::LRRotation(Node* p) {
  Node* pl = p->lchild;
  Node* plr = pl->rchild;

  // Perform rotation
  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;
  plr->lchild = pl;
  plr->rchild = p;

  // Update heights post rotation
  pl->height = NodeHeight(pl);
  p->height = NodeHeight(p);
  plr->height = NodeHeight(plr);

  // If the rotated node was the root, update the root
  if (p == root) root = plr;

  return plr;
}

Node* AVL::RLRotation(Node* p) {
  Node* pr = p->rchild;
  Node* prl = pr->lchild;

  // Perform rotation
  pr->lchild = prl->rchild;
  p->rchild = prl->lchild;
  prl->rchild = pr;
  prl->lchild = p;

  // Update heights post rotation
  pr->height = NodeHeight(pr);
  p->height = NodeHeight(p);
  prl->height = NodeHeight(prl);

  // If the rotated node was the root, update the root
  if (root == p) root = prl;

  return prl;
}

Node* AVL::rInsert(Node* p, int key) {
  if (p == nullptr) {
    Node* t = new Node;
    t->data = key;
    t->lchild = nullptr;
    t->rchild = nullptr;
    t->height = 1;  // Start height from 1 for new nodes
    return t;
  }

  // Insert in left subtree
  if (key < p->data) {
    p->lchild = rInsert(p->lchild, key);
  }
  // Insert in right subtree
  else if (key > p->data) {
    p->rchild = rInsert(p->rchild, key);
  }

  // Update node height post insertion
  p->height = NodeHeight(p);

  // Balance Factor & Rotations
  if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
    return LLRotation(p);
  } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
    return LRRotation(p);
  } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
    return RRRotation(p);
  } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
    return RLRotation(p);
  }

  return p;
}

void AVL::Inorder(Node* p) {
  if (p) {
    Inorder(p->lchild);
    cout << p->data << ", " << flush;
    Inorder(p->rchild);
  }
}

void AVL::Insert(int key) {
  root = rInsert(root, key);
}

void AVL::Inorder() {
  Inorder(root);
  cout << endl;
}

int main() {
  // Create and test AVL tree with LR rotation
  AVL tlr;
  tlr.Insert(50);
  tlr.Insert(10);
  tlr.Insert(20);

  tlr.Inorder();
  cout << tlr.getRoot()->data << endl;

  // Create and test AVL tree with RL rotation
  AVL trl;
  trl.Insert(20);
  trl.Insert(50);
  trl.Insert(30);

  trl.Inorder();
  cout << trl.getRoot()->data << endl;

  return 0;
}
