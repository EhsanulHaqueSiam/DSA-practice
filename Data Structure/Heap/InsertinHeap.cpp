#include <iostream>
#include <vector>

using namespace std;

// Inserts an element into a max heap defined in a raw array.
// The process involves placing the element at the end of the heap
// and then bubbling it up to its correct position.
void InsertA(int A[], int n) {
    int i = n;
    int temp = A[n];

    // Check if the new node's parent is smaller. If so, then swap.
    // The check for even/odd is to handle 0-based index array.
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

// Inserts an element into a max heap defined using an STL vector.
void Insert(vector<int>& vec, int key) {
    // Insert key at the end of the vector.
    auto i = vec.size();
    vec.emplace_back(key);

    // Bubble up the inserted element to its correct position.
    while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
        vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    vec[i] = key;
}

// Utility function to print the elements of the heap.
template <class T>
void Print(const T& vec, int n) {
    cout << "Max Heap: [";
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};

    // Insert 50 into the heap defined in the raw array.
    InsertA(a, 9);
    Print(a, sizeof(a) / sizeof(a[0]));
    cout << endl;

    // Using STL vector to represent heap.
    vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    Print(v, v.size());

    // Reserve space for potential additional elements.
    v.reserve(15);

    // Insert 50 into the heap defined in the STL vector.
    Insert(v, 50);
    Print(v, v.size());

    return 0;
}
