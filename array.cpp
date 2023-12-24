#include <bits/stdc++.h>

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
