#include <iostream>

using namespace std;

// Node structure to represent non-zero elements in SparseMatrix
struct Node {
  int col;
  int val;
  Node* next;
};

// SparseMatrix class
class SparseMatrix {
 private:
  Node** row_heads;  // Dynamic array storing head nodes of each row
  int total_rows, total_cols;

 public:
  // Constructor
  SparseMatrix(int rows, int cols);
  
  // Function to create a sparse matrix
  void Create(int i, int j, int val);
  
  // Function to display a sparse matrix
  void Display();

  // Destructor
  ~SparseMatrix();
};

// SparseMatrix Constructor
SparseMatrix::SparseMatrix(int rows, int cols) {
  total_rows = rows;
  total_cols = cols;
  
  // Initializing heads of each row with NULL
  row_heads = new Node*[total_rows];
  for (int i = 0; i < total_rows; ++i) {
    row_heads[i] = nullptr;
  }
}

// Create function to add non-zero values to SparseMatrix
void SparseMatrix::Create(int i, int j, int val) {
  if (i >= total_rows || j >= total_cols) {
    cout << "Invalid row or column index" << endl;
    return;
  }

  Node* new_node = new Node;
  new_node->col = j;
  new_node->val = val;
  new_node->next = nullptr;

  if (row_heads[i] == nullptr || row_heads[i]->col > j) {
    new_node->next = row_heads[i];
    row_heads[i] = new_node;
  } else {
    Node* curr = row_heads[i];
    while (curr->next != nullptr && curr->next->col < j) {
      curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
  }
}

// Function to display the SparseMatrix
void SparseMatrix::Display() {
  for (int i = 0; i < total_rows; ++i) {
    Node* curr = row_heads[i];
    for (int j = 0; j < total_cols; ++j) {
      if (curr != nullptr && curr->col == j) {
        cout << curr->val << " ";
        curr = curr->next;
      } else {
        cout << "0 ";
      }
    }
    cout << "\n";
  }
}

// Destructor to clean up memory
SparseMatrix::~SparseMatrix() {
  for (int i = 0; i < total_rows; ++i) {
    Node* curr = row_heads[i];
    while (curr != nullptr) {
      Node* temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
  delete[] row_heads;
}

// main function to demonstrate SparseMatrix creation and display
int main() {
  SparseMatrix sm(4, 4);

  // Adding some non-zero values to the sparse matrix
  sm.Create(0, 0, 1);
  sm.Create(0, 3, 2);
  sm.Create(2, 1, 3);
  sm.Create(3, 3, 4);

  // Displaying the sparse matrix
  sm.Display();

  return 0;
}
