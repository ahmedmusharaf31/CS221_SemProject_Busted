#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <limits> // for std::numeric_limits

using namespace std;

struct Student
{
    string name;
    int studentID;
    int age;

    Student(const string &name, int studentID, int age)
    {
        this->name = name;
        this->studentID = studentID;
        this->age = age;
    }
};

class ArrayBasedList
{
private:
    vector<Student> studentsArray;

public:
    // Function to add a student to the array
    void addStudent(const string &name, int studentID, int age)
    {
        Student student(name, studentID, age);
        studentsArray.push_back(student);
    }

    // Function to search for a student by name
    Student *searchStudent(const string &name)
    {
        auto it = find_if(studentsArray.begin(), studentsArray.end(), [&](const Student &s)
                          { return s.name == name; });

        if (it != studentsArray.end())
        {
            return &(*it); // Return pointer to the found student
        }
        else
        {
            return nullptr; // Return nullptr if not found
        }
    }

    // Function to display all students in the array
    void displayStudents()
    {
        cout << "Array-Based List of Students:\n";
        for (const auto &student : studentsArray)
        {
            cout << "Name: " << student.name << ", ID: " << student.studentID << ", Age: " << student.age << endl;
        }
    }

    // Function to sort students using Merge Sort
    void sortStudents()
    {
        mergeSort(studentsArray.begin(), studentsArray.end(), [](const Student &a, const Student &b)
                  { return a.name < b.name; });
    }
    

private:
    // Merge Sort implementation for vector of Students
    template <typename RandomIt, typename Compare>
    void mergeSort(RandomIt first, RandomIt last, Compare comp)
    {
        if (last - first > 1)
        {
            auto mid = first + (last - first) / 2;
            mergeSort(first, mid, comp);
            mergeSort(mid, last, comp);
            inplace_merge(first, mid, last, comp);
        }
    }
};

class LinkedList
{
private:
    struct Node
    {
        Student data;
        Node *next;

        Node(const Student &data) : data(data), next(nullptr) {}
    };

    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a student to the linked list
    void addStudent(const string &name, int studentID, int age)
    {
        Student student(name, studentID, age);
        Node *newNode = new Node(student);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    // Function to display all students in the linked list
    void displayStudents()
    {
        cout << "Linked List of Students:\n";
        Node *current = head;
        while (current != nullptr)
        {
            cout << "Name: " << current->data.name << ", ID: " << current->data.studentID << ", Age: " << current->data.age << endl;
            current = current->next;
        }
    }

    // Function to delete a student from the linked list by name
    void deleteStudent(const string &name)
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty. Cannot delete.\n";
            return;
        }

        if (head->data.name == name)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted: " << name << endl;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr && current->data.name != name)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Student not found with name: " << name << ". Cannot delete.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Student deleted: " << name << endl;
    }
};

class BookManagementSystem
{
private:
    stack<string> bookCheckoutStack; // Stack for book checkout
    queue<string> bookReturnQueue;   // Queue for book return

public:
    // Function to perform book checkout
    void checkoutBook(const string &bookTitle)
    {
        bookCheckoutStack.push(bookTitle);
        cout << "Book checked out: " << bookTitle << endl;
    }

    // Function to perform book return
    void returnBook(const string &bookTitle)
    {
        bookReturnQueue.push(bookTitle);
        cout << "Book returned: " << bookTitle << endl;
    }

    // Function to display books checked out
    void displayCheckedOutBooks()
    {
        cout << "Books Checked Out (Last-In-First-Out):\n";
        while (!bookCheckoutStack.empty())
        {
            cout << "Book: " << bookCheckoutStack.top() << endl;
            bookCheckoutStack.pop();
        }
    }

    // Function to display books in the return queue
    void displayReturnQueue()
    {
        cout << "Books in Return Queue (First-In-First-Out):\n";
        while (!bookReturnQueue.empty())
        {
            cout << "Book: " << bookReturnQueue.front() << endl;
            bookReturnQueue.pop();
        }
    }
};
class BinarySearchTree
{
private:
    struct TreeNode
    {
        Student data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(const Student &data) : data(data), left(nullptr), right(nullptr) {}
    };

    TreeNode *root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to add a student to the binary search tree
    void addStudent(const string &name, int studentID, int age)
    {
        Student student(name, studentID, age);
        root = insert(root, student);
    }

    // Function to search for a student by name in the binary search tree
    Student *searchStudent(const string &name)
    {
        return search(root, name);
    }

private:
    // Recursive function to insert a student into the binary search tree
    TreeNode *insert(TreeNode *node, const Student &student)
    {
        if (node == nullptr)
        {
            return new TreeNode(student);
        }

        if (student.name < node->data.name)
        {
            node->left = insert(node->left, student);
        }
        else if (student.name > node->data.name)
        {
            node->right = insert(node->right, student);
        }

        return node;
    }

    // Recursive function to search for a student by name in the binary search tree
    Student *search(TreeNode *node, const string &name)
    {
        if (node == nullptr || node->data.name == name)
        {
            return (node == nullptr) ? nullptr : &(node->data);
        }

        if (name < node->data.name)
        {
            return search(node->left, name);
        }
        else
        {
            return search(node->right, name);
        }
    }
};
int main()
{
    ArrayBasedList arrayBasedList;
    LinkedList linkedList;
    BookManagementSystem bookManagementSystem;
    BinarySearchTree binarySearchTree;

    int choice;

    do
    {
        string name; // Declare 'name' here to make it accessible in the entire loop

        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display Students\n";
        cout << "4. Sort Students\n";
        cout << "5. Delete Student\n";
        cout << "6. Checkout Book\n";
        cout << "7. Return Book\n";
        cout << "8. Display Checked Out Books\n";
        cout << "9. Display Return Queue\n";
        cout << "10. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice)
        {
        case 1:
        {
            // Add Student
            int studentID, age;
            cout << "Enter student information:\n";
            cout << "Name: ";
            getline(cin, name);
            cout << "Student ID: ";
            cin >> studentID;
            cout << "Age: ";
            cin >> age;

            arrayBasedList.addStudent(name, studentID, age);
            break;
        }
        case 2:
        {
            // Search Student
            cout << "Enter a name to search: ";
            getline(cin, name);
            Student *foundStudent = arrayBasedList.searchStudent(name);
            if (foundStudent != nullptr)
            {
                cout << "Student found: " << foundStudent->name << ", ID: " << foundStudent->studentID << ", Age: " << foundStudent->age << endl;
            }
            else
            {
                cout << "Student not found with name: " << name << endl;
            }
            break;
        }
        case 3:
        {
            // Display Students
            arrayBasedList.displayStudents();
            break;
        }
        case 4:
        {
            // Sort Students
            arrayBasedList.sortStudents();
            cout << "Array-Based List after sorting:\n";
            arrayBasedList.displayStudents();
            break;
        }
        case 5:
        {
            // Delete Student
            cout << "Enter the name of the student to delete: ";
            getline(cin, name);
            linkedList.deleteStudent(name);
            break;
        }
        case 6:
        {
            // Checkout Book
            cout << "Enter the title of the book to checkout: ";
            getline(cin, name);
            bookManagementSystem.checkoutBook(name);
            break;
        }
        case 7:
        {
            // Return Book
            cout << "Enter the title of the book to return: ";
            getline(cin, name);
            bookManagementSystem.returnBook(name);
            break;
        }
        case 8:
        {
            // Display Checked Out Books
            bookManagementSystem.displayCheckedOutBooks();
            break;
        }
        case 9:
        {
            // Display Return Queue
            bookManagementSystem.displayReturnQueue();
            break;
        }
        case 10:
        {
            // Exit
            cout << "Exiting the Library Management System. Goodbye!\n";
            break;
        }
        default:
        {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
        }

    } while (choice != 10);

    return 0;
}
