#include <iostream>
#include <cmath>

// Node definition for Polynomial. A polynomial is a collection of terms. Each term contains a coefficient and an exponent.
// In our linked list representation, each Node is a term.
struct Node {
  int coeff;   // coefficient
  int pow;     // exponent
  Node* next;  // pointer to next term
  
  Node(int coeff, int pow) : coeff(coeff), pow(pow), next(nullptr) {}
};

class Polynomial {
 public:
  Node* head;  // pointer to first term of Polynomial

  // Default constructor creates an empty Polynomial.
  Polynomial() : head(nullptr) {}

  // Function to create a new term and add it to the Polynomial.
  void createTerm(int coeff, int pow) {
    Node* new_node = new Node(coeff, pow);
    if (head == nullptr) {
      head = new_node;
    } else {
      Node* temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = new_node;
    }
  }

  // Function to evaluate the Polynomial for a given value of variable x.
  int evaluatePolynomial(int x) {
    Node* temp = head;
    int sum = 0;
    while (temp != nullptr) {
      // Using pow function to calculate power and multiplying with coefficient to calculate term result.
      sum += temp->coeff * std::pow(x, temp->pow);
      temp = temp->next;
    }
    return sum;
  }

  // Function to display the Polynomial.
  void displayPolynomial() {
    Node* temp = head;
    while (temp != nullptr) {
      std::cout << temp->coeff << "x^" << temp->pow;
      if (temp->next != nullptr) {
        std::cout << " + ";
      }
      temp = temp->next;
    }
    std::cout << "\n";
  }
};

int main() {
  Polynomial poly;
  poly.createTerm(5, 2);  // Add term 5x^2 to the polynomial.
  poly.createTerm(3, 1);  // Add term 3x^1 to the polynomial.
  poly.createTerm(2, 0);  // Add term 2x^0 to the polynomial.
  poly.displayPolynomial();  // Display the polynomial.
  
  int result = poly.evaluatePolynomial(2);  // Evaluate the polynomial for x = 2.
  std::cout << "Result: " << result << "\n";  // Display the result.
  
  return 0;
}
