#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

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
    Student* searchStudent(const string &name)
    {
        auto it = find_if(studentsArray.begin(), studentsArray.end(), [&](const Student &s) {
            return s.name == name;
        });

        if (it != studentsArray.end()) {
            return &(*it); // Return pointer to the found student
        } else {
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
        mergeSort(studentsArray.begin(), studentsArray.end(), [](const Student &a, const Student &b) {
            return a.name < b.name;
        });
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

    // Adding sample students to the array
    arrayBasedList.addStudent("John Doe", 12345, 20);
    arrayBasedList.addStudent("Alice Smith", 67890, 22);
    arrayBasedList.addStudent("Bob Johnson", 54321, 21);

    // Displaying the unsorted array
    arrayBasedList.displayStudents();

    // Sorting and displaying the array
    arrayBasedList.sortStudents();
    arrayBasedList.displayStudents();

    // Searching for a student by name
    string searchName = "Alice Smith";
    Student *foundStudent = arrayBasedList.searchStudent(searchName);

    if (foundStudent != nullptr)
    {
        cout << "Student found: " << foundStudent->name << ", ID: " << foundStudent->studentID << ", Age: " << foundStudent->age << endl;
    }
    else
    {
        cout << "Student not found with name: " << searchName << endl;
    }

        LinkedList linkedList;
         // Adding sample students to the linked list
    linkedList.addStudent("John Doe", 12345, 20);
    linkedList.addStudent("Alice Smith", 67890, 22);
    linkedList.addStudent("Bob Johnson", 54321, 21);

    // Displaying the linked list
    linkedList.displayStudents();

    // Deleting a student by name
    string deleteName = "Alice Smith";
    linkedList.deleteStudent(deleteName);

    // Displaying the updated linked list
    linkedList.displayStudents();
    // Creating instances of the classes
    ArrayBasedList arrayBasedList;
    LinkedList linkedList;
    BookManagementSystem bookManagementSystem;
    BinarySearchTree binarySearchTree;

    // Adding sample students to the array-based list, linked list, and binary search tree
    arrayBasedList.addStudent("John Doe", 12345, 20);
    arrayBasedList.addStudent("Alice Smith", 67890, 22);
    arrayBasedList.addStudent("Bob Johnson", 54321, 21);

    linkedList.addStudent("John Doe", 12345, 20);
    linkedList.addStudent("Alice Smith", 67890, 22);
    linkedList.addStudent("Bob Johnson", 54321, 21);

    binarySearchTree.addStudent("John Doe", 12345, 20);
    binarySearchTree.addStudent("Alice Smith", 67890, 22);
    binarySearchTree.addStudent("Bob Johnson", 54321, 21);

    // Searching for a student by name in the binary search tree
    string searchName = "Alice Smith";
    Student *foundStudent = binarySearchTree.searchStudent(searchName);

    if (foundStudent != nullptr)
    {
        cout << "Student found: " << foundStudent->name << ", ID: " << foundStudent->studentID << ", Age: " << foundStudent->age << endl;
    }
    else
    {
        cout << "Student not found with name: " << searchName << endl;
    }

    return 0;
}
