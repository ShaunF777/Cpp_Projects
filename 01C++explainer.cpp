/*
    Simple C++ Project: Student Management System

    This example demonstrates key C++ features compared to C and Python.
    Comments explain differences and new features.

    To compile: g++ -std=c++11 student_management.cpp -o student_management
*/

#include <iostream>     // C++ standard I/O stream (instead of stdio.h)
#include <vector>       // C++ Standard Template Library (STL) vector
#include <string>       // C++ string class

// C++ supports classes (object-oriented programming)
class Student {
private:
    std::string name;   // C++ string (safer and easier than char arrays in C)
    int age;
    std::vector<int> grades; // Dynamic array (vector) from STL

public:
    // Constructor (special function to initialize objects)
    Student(const std::string& n, int a) : name(n), age(a) {}

    // Member function to add a grade
    void addGrade(int grade) {
        grades.push_back(grade);
    }

    // Member function to print student info
    void printInfo() const {
        // std::cout is the standard output stream (console output)
        // The << operator here is the "stream insertion" operator, not a bitwise operator.
        // It sends data to the output stream (prints to the console).
        std::cout << "Name: " << name << ", Age: " << age << ", Grades: ";
        
        // Range-based for loop: iterates over each element 'g' in the 'grades' container
        for (int g : grades) { 
            // Prints each grade followed by a space
            std::cout << g << " ";
        }
        
        // Prints a newline character and flushes the output buffer
        std::cout << std::endl;
    }
};

int main() {
    // In C, you'd use arrays and structs; in C++, we use classes and vectors
    std::vector<Student> students; //creates an empty vector (dynamic array) that will store objects of type Student.

    // Adding students (in Python, you'd use lists and dictionaries)
    // emplace_back constructs a Student object in-place in the vector (avoids extra copy)
    students.emplace_back("Alice", 20); // Adds a Student named Alice, age 20
    students.emplace_back("Bob", 22);   // Adds a Student named Bob, age 22

    // Adding grades
    students[0].addGrade(90);
    students[0].addGrade(85);
    students[1].addGrade(78);

    // Print all students
    // This is a range-based for loop in C++.
    // It iterates over each element in the 'students' container (like a vector or array).
    // 'const Student& s' means 's' is a constant reference to each Student object in 'students'.
    // This avoids copying each Student and prevents modification inside the loop.
    // Inside the loop, 's.printInfo();' calls the printInfo() method for each Student.
    for (const Student& s : students) {
        s.printInfo();
    }

    // C++ has automatic memory management for objects with RAII (no need for malloc/free)
    // C++ supports function overloading, templates, exceptions, and more

    return 0;
}

/*
    Key C++ features shown:
    - Classes and objects (OOP)
    - Constructors and member functions
    - std::string (vs char arrays in C)
    - std::vector (dynamic arrays, safer than malloc/free in C)
    - Range-based for loops (C++11)
    - Encapsulation (private/protected/public)
    - No need for manual memory management for most cases (RAII)
    - Streams (cout/cin) instead of printf/scanf

    Compared to Python:
    - Static typing, explicit types
    - Compilation required
    - Similar OOP concepts, but with more control over memory and performance
*/