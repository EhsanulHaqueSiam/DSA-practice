#include <iostream>
#include <cmath>

// The Node struct represents each term in the polynomial.
// Each term is characterized by a coefficient and an exponent.
struct Node {
  int coeff;   // Coefficient of the term
  int exp;     // Exponent of the term
  Node* next;  // Pointer to the next term

  // Constructor for Node
  Node(int c, int e, Node* n = nullptr) : coeff(c), exp(e), next(n) {}
};

class Polynomial {
 public:
  Node* poly;  // Pointer to the first term of the polynomial

  // Constructor for Polynomial. Initializes poly to nullptr indicating an empty polynomial.
  Polynomial() : poly(nullptr) {}

  // Function to create the polynomial
  void Create() {
    Node* last = nullptr;
    int num;

    std::cout << "Enter number of terms: ";
    std::cin >> num;
    std::cout << "Enter each term with coeff and exp\n";

    for (int i = 0; i < num; i++) {
      int c, e;
      std::cin >> c >> e;
      Node* t = new Node(c, e);

      if (poly == nullptr) {
        poly = last = t;
      } else {
        last->next = t;
        last = t;
      }
    }
  }

  // Function to display the polynomial
  void Display() {
    Node* p = poly;
    while (p) {
      std::cout << p->coeff << "x^" << p->exp;
      if (p->next != nullptr) {
        std::cout << " + ";
      }
      p = p->next;
    }
    std::cout << "\n";
  }

  // Function to evaluate the polynomial for a given value of x
  long Eval(int x) {
    long val = 0;
    Node* p = poly;

    while (p) {
      val += p->coeff * std::pow(x, p->exp);
      p = p->next;
    }
    return val;
  }
};

int main() {
  Polynomial polynomial;
  polynomial.Create();
  polynomial.Display();
  std::cout << "Value of polynomial for x=1: " << polynomial.Eval(1) << "\n";
  return 0;
}
