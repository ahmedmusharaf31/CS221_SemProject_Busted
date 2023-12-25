#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

// Define a structure for a student
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

// Define a structure for a book
struct Book
{
    string title;

    Book(const string &title)
    {
        this->title = title;
    }
};

// Class for Array-based List
class ArrayBasedList
{
private:
    vector<Student> studentsArray;

public:
    // Function to add a student to the array
    void addStudent(const Student &student)
    {
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

    // Function to delete a student from the array by name
    void deleteStudent(const string &name)
    {
        auto it = remove_if(studentsArray.begin(), studentsArray.end(), [&](const Student &s)
                            { return s.name == name; });

        if (it != studentsArray.end())
        {
            studentsArray.erase(it, studentsArray.end());
            cout << "Student deleted: " << name << endl;
        }
        else
        {
            cout << "Student not found with name: " << name << ". Cannot delete.\n";
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

// Class for Book Management System
class BookManagementSystem
{
private:
    stack<Book> bookCheckoutStack; // Stack for book checkout
    queue<Book> bookReturnQueue;   // Queue for book return

public:
    // Function to perform book checkout
    void checkoutBook(const string &bookTitle)
    {
        Book book(bookTitle);
        bookCheckoutStack.push(book);
        cout << "Book checked out: " << bookTitle << endl;
    }

    // Function to display books checked out
    void displayCheckedOutBooks()
    {
        cout << "Books Checked Out (Last-In-First-Out):\n";
        stack<Book> tempStack = bookCheckoutStack; // Create a temporary stack to preserve original stack
        while (!tempStack.empty())
        {
            cout << "Book: " << tempStack.top().title << endl;
            tempStack.pop();
        }
    }
};

// Class for Linked List
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
    LinkedList() : head(nullptr)
    {
        // Hardcoded students
        Student johnDoe("John Doe", 2001, 20);
        Student janeSmith("Jane Smith", 2002, 22);

        // Add hardcoded students to the linked list
        addStudent(johnDoe);
        addStudent(janeSmith);
    }

    // Function to add a student to the linked list
    void addStudent(const Student &student)
    {
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

int main()
{
    ArrayBasedList arrayBasedList;
    LinkedList linkedList;
    BookManagementSystem bookManagementSystem;

    // Add some hardcoded students
    arrayBasedList.addStudent(Student("Ahmed Billa", 1, 25));
    arrayBasedList.addStudent(Student("Abdullah Panther", 2, 23));
    arrayBasedList.addStudent(Student("Arsal Pimp", 3, 28));

    // Add some hardcoded books
    bookManagementSystem.checkoutBook("The Catcher in the Rye");
    bookManagementSystem.checkoutBook("To Kill a Mockingbird");

    int choice;

    do
    {
        // Display menu
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
        cout << "11. Display Hardcoded Students and Books\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice)
        {
        case 1:
        {
            // Add Student
            int studentID, age;
            string name;
            cout << "Enter student information:\n";
            cout << "Name: ";
            getline(cin, name);
            cout << "Student ID: ";
            cin >> studentID;
            cout << "Age: ";
            cin >> age;

            arrayBasedList.addStudent(Student(name, studentID, age));
            break;
        }
        case 2:
        {
            // Search Student
            string name;
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
            string name;
            cout << "Enter the name of the student to delete: ";
            getline(cin, name);
            arrayBasedList.deleteStudent(name);
            break;
        }
        case 6:
        {
            // Checkout Book
            string bookTitle;
            cout << "Enter the title of the book to checkout: ";
            getline(cin, bookTitle);
            bookManagementSystem.checkoutBook(bookTitle);
            break;
        }
        case 7:
        {
            // Return Book
            // Note: Return function needs to be implemented
            cout << "Returning book...\n";
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
            // Note: Return queue display function needs to be implemented
            cout << "Displaying return queue...\n";
            break;
        }
        case 10:
        {
            // Exit
            cout << "Exiting the Library Management System. Goodbye!\n";
            break;
        }
        case 11:
        {
            // Display Hardcoded Students and Books
            cout << "Hardcoded Students:\n";
            arrayBasedList.displayStudents();

            cout << "\nHardcoded Books Checked Out:\n";
            bookManagementSystem.displayCheckedOutBooks();
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
