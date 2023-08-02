/* 
Question:

**Student Management System**

You are tasked with developing a Student Management System using C++. The system will allow users to perform various operations related to student records using a singly linked list data structure. Your task is to implement the provided code to fulfill the following requirements:

1. Implement a singly linked list data structure using templates (`LinkedListNode` and `SinglyLinkedList` classes).
2. Implement a `Student` class that represents a student record with the following properties:
   - `int id` : Student ID
   - `string name` : Student Name
   - `double cgpa` : Cumulative Grade Point Average
   - `SinglyLinkedList<int> studentList` : A linked list to store student IDs

3. Implement the following functions in the `Student` class:
   - `void displayStudent()`: Display the details of a student.
   - `void addToStudentList(int id)`: Add a student ID to the linked list.
   - `void removeFromStudentList(int id)`: Remove a student ID from the linked list.
   - `void displayStudentList()`: Display the list of student IDs.
   - `bool operator<(const Student& other) const`: Operator overload to compare students based on CGPA.
   - `bool operator>(const Student& other) const`: Operator overload to compare students based on CGPA in descending order.

4. Implement the `main` function to create a Student Management System that provides the following functionalities:
   - Show all students.
   - Add a new student.
   - Remove a student by ID.
   - Show a student by ID.
   - Show students sorted by CGPA in ascending order.
   - Show students sorted by CGPA in descending order.
   - Sort students by CGPA in ascending order.
   - Sort students by CGPA in descending order.
   - Exit the program.

You need to complete the provided code and add appropriate logic in the `main` function to achieve the desired functionalities. The program should handle user inputs, perform operations on student records and student IDs, and display relevant information.

**Instructions:**
- Complete the code in the `Student` class to implement the specified functionalities.
- Implement the `main` function to create the Student Management System as described.
- Provide user-friendly prompts for input and output.
- Ensure the program handles user inputs and validations gracefully.
- Include relevant comments and documentation to explain your code.

Feel free to add any additional enhancements or features to the Student Management System as you see fit. */

#include <iostream>
#include <string>
using namespace std;

// Linked list node template
template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode* next;

    LinkedListNode(T value) : data(value), next(nullptr) {}
};

// Singly linked list template
template <typename T>
class SinglyLinkedList {
public:
    LinkedListNode<T>* head;

    SinglyLinkedList() : head(nullptr) {}

    // Insert a new element at the end of the list
    void insert(T value) {
        LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
        if (!head) {
            head = newNode;
        } else {
            LinkedListNode<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Display all elements in the list
    void displayAll() {
        LinkedListNode<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Remove an element from the list
    bool remove(T value) {
        if (!head) {
            return false;
        }

        if (head->data == value) {
            LinkedListNode<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        LinkedListNode<T>* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            LinkedListNode<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            return true;
        }

        return false;
    }

    // Sort the linked list in ascending or descending order
    void sort(bool ascending = true) {
        if (!head || !head->next) {
            return;
        }

        LinkedListNode<T>* current = head;
        LinkedListNode<T>* index = nullptr;
        T tempData;

        while (current != nullptr) {
            index = current->next;
            while (index != nullptr) {
                if (ascending ? (index->data < current->data) : (index->data > current->data)) {
                    tempData = current->data;
                    current->data = index->data;
                    index->data = tempData;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    // Destructor to release memory
    ~SinglyLinkedList() {
        LinkedListNode<T>* current = head;
        while (current) {
            LinkedListNode<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Student class
class Student {
public:
    int id;
    string name;
    double cgpa;
    SinglyLinkedList<int> studentList; // Linked list for student IDs

    // Constructor with parameters
    Student(int id, string name, double cgpa) : id(id), name(name), cgpa(cgpa) {
        studentList.insert(id);
    }

    // Default constructor
    Student() : id(0), name(""), cgpa(0.0) {}

    // Display student information
    void displayStudent() {
        cout << "ID: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
    }

    // Add student to the student list
    void addToStudentList(int id) {
        studentList.insert(id);
    }

    // Remove student from the student list
    void removeFromStudentList(int id) {
        studentList.remove(id);
    }

    // Display student list
    void displayStudentList() {
        studentList.displayAll();
    }

    // Operator overload for comparing CGPA
    bool operator<(const Student& other) const {
        return cgpa < other.cgpa;
    }

    // Operator overload for comparing CGPA in descending order
    bool operator>(const Student& other) const {
        return cgpa > other.cgpa;
    }
};

// Main function
int main() {
    SinglyLinkedList<Student> studentsList;

    int option;

    cout << "Student Management System\n";
    cout << "-------------------------\n";

    do {
        cout << "Select an option:\n"
             << "1. Show all students\n"
             << "2. Add new student\n"
             << "3. Remove student\n"
             << "4. Show a student by ID\n"
             << "5. Show students by CGPA (ascending)\n"
             << "6. Show students by CGPA (descending)\n"
             << "7. Sort students by CGPA (ascending)\n"
             << "8. Sort students by CGPA (descending)\n"
             << "9. Exit\n";
        cin >> option;

        switch (option) {
            case 1: {
                // Show all students
                cout << "All Students:\n";
                studentsList.displayAll();
                cout << endl;
                break;
            }
            case 2: {
                // Add new student
                int id;
                string name;
                double cgpa;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter CGPA: ";
                cin >> cgpa;
                Student newStudent(id, name, cgpa);
                studentsList.insert(newStudent);
                cout << "Student added successfully.\n\n";
                break;
            }
            case 3: {
                // Remove student
                int id;
                cout << "Enter the ID of the student to remove: ";
                cin >> id;
                // Remove student logic
                break;
            }
            case 4: {
                // Show a student by ID
                int id;
                cout << "Enter the ID of the student: ";
                cin >> id;
                // Find and display student by ID
                break;
            }
            case 5: {
                // Show students by CGPA (ascending)
                studentsList.sort();
                cout << "Students sorted by CGPA in ascending order:\n";
                studentsList.displayAll();
                cout << endl;
                break;
            }
            case 6: {
                // Show students by CGPA (descending)
                studentsList.sort(false);
                cout << "Students sorted by CGPA in descending order:\n";
                studentsList.displayAll();
                cout << endl;
                break;
            }
            case 7: {
                // Sort students by CGPA (ascending)
                studentsList.sort();
                cout << "Students sorted by CGPA in ascending order:\n";
                studentsList.displayAll();
                cout << endl;
                break;
            }
            case 8: {
                // Sort students by CGPA (descending)
                studentsList.sort(false);
                cout << "Students sorted by CGPA in descending order:\n";
                studentsList.displayAll();
                cout << endl;
                break;
            }
            case 9: {
                // Exit
                cout << "Exiting the program. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid option. Please select a valid option.\n";
                break;
            }
        }

    } while (option != 9);

    return 0;
}
