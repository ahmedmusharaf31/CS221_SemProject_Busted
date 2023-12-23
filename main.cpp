#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define ii long long

using namespace std;
struct Student
{
    string name;
    int studentID;
    int age;
    Student *left;
    Student *right;

    Student(const string &name, int studentID, int age)
    {
        this->name = name;
        this->studentID = studentID;
        this->age = age;
        this->left = NULL;
        this->right = NULL;
    }
};

class LibrarySystem
{
private:
    vector<Student> arrayBasedList; // Array-based list for storing students
    Student *linkedListHead;        // Linked list for dynamic student data
    stack<string> bookStack;        // Stack for book checkout
    queue<string> bookQueue;        // Queue for book return
    Student *bstRoot;               // Root of the Binary Search Tree

    public:

};

int main()
{

    return 0;
}

