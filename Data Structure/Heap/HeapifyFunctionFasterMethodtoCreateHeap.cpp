#include <iostream>

using std::cout;
using std::endl;
using std::flush;
using std::string;

// Function to swap two integers in an array.
void Swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Function to delete the root (maximum element) from a max heap and return it.
int Delete(int A[], int n) {
    int x = A[0];  // Max element is root for max heap.
    A[0] = A[n-1];

    int i = 0;
    int j = 2 * i + 1;

    while (j < n-1) {
        // Compare left and right children of current node to get the larger child.
        if (A[j] < A[j+1]) {
            j = j+1;
        }

        // If current node is smaller than the larger child, swap them.
        if (A[i] < A[j]) {
            Swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        } else {
            break;  // If no swaps are needed, break from loop.
        }
    }
    return x;
}

// Function to convert an array into a max heap.
void Heapify(int A[], int n) {
    // Start from the last parent node.
    // Last parent node = (n/2) - 1.
    for (int i = (n/2) - 1; i >= 0; i--) {
        int j = 2 * i + 1;  // Left child for current i

        while (j < n-1) {
            // Compare left and right children of current node to get the larger child.
            if (A[j] < A[j+1]) {
                j = j+1;
            }

            // If current node is smaller than the larger child, swap them.
            if (A[i] < A[j]) {
                Swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;  // If no swaps are needed, break from loop.
            }
        }
    }
}

// Template function to print an array with a description.
template <class T>
void Print(T& vec, int n, const string& s) {
    cout << s << ": [";
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n-1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    Print(A, sizeof(A)/sizeof(A[0]), "A");

    Heapify(A, sizeof(A)/sizeof(A[0]));
    Print(A, sizeof(A)/sizeof(A[0]), "Heapified A");
    cout << endl;

    int B[] = {5, 10, 30, 20};
    Print(B, sizeof(B)/sizeof(B[0]), "B");

    Heapify(B, sizeof(B)/sizeof(B[0]));
    Print(B, sizeof(B)/sizeof(B[0]), "Heapified B");

    return 0;
}
