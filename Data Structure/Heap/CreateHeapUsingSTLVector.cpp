#include <iostream>
#include <vector>

using namespace std;

// Function to insert a key into the max heap represented as a vector.
// The function ensures that the heap property is maintained after every insert.
void Insert(vector<int>& heap, int key) {
  // Insert the key at the end of the heap.
  int i = heap.size();
  heap.emplace_back(key);

  // Rearrange elements to maintain the heap property. 
  // We compare the inserted key with its parent and move it up the heap as required.
  while (i > 0 && key > heap[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
    heap[i] = heap[i % 2 == 0 ? (i / 2) - 1 : i / 2];
    i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
  }
  heap[i] = key;
}

// In-place version of the above function for an array.
void InsertInplace(int arr[], int n) {
  int i = n;
  int temp = arr[n];

  while (i > 0 && temp > arr[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
    arr[i] = arr[i % 2 == 0 ? (i / 2) - 1 : i / 2];
    i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
  }
  arr[i] = temp;
}

// Function to create a max heap from an array.
// This function inserts each element of the array into the heap.
void CreateHeap(vector<int>& heap, int arr[], int n) {
  for (int i = 0; i < n; i++) {
    Insert(heap, arr[i]);
  }
}

// In-place version of the above function.
void createHeap(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    InsertInplace(arr, i);
  }
}

// Template function to print arrays and vectors.
template <class T>
void Print(T& container, int n, char label) {
  cout << label << ": [";
  for (int i = 0; i < n; i++) {
    cout << container[i];
    if (i < n - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  cout << "Create Heap" << endl;
  int b[] = {10, 20, 30, 25, 5, 40, 35};
  Print(b, sizeof(b) / sizeof(b[0]), 'b');

  vector<int> v;
  CreateHeap(v, b, sizeof(b) / sizeof(b[0]));
  Print(v, v.size(), 'v');

  cout << "Inplace Insert" << endl;
  createHeap(b, sizeof(b) / sizeof(b[0]));
  Print(b, sizeof(b) / sizeof(b[0]), 'b');

  return 0;
}
