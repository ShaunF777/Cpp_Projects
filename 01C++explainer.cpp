/*
    Simple C++ Project: Student Management System

    This example demonstrates key C++ features compared to C and Python.
    Comments throughout the code explain each step and syntax, helping you see 
    both automatic object creation (Alice/Bob) and interactive input in C++.
    These features make C++ safer and more expressive than C, 
    while offering more control and efficiency than Python.

    To compile: g++ -std=c++11 C++explainer.cpp -o student_management
    Then to run it: ./student_management
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

    // --- Automatic input: Add Alice and Bob ---
    // Adding students (in Python, you'd use lists and dictionaries)
    // emplace_back constructs a Student object in-place in the vector (avoids extra copy)
    students.emplace_back("Alice", 20); // Adds a Student named Alice, age 20
    students.emplace_back("Bob", 22);   // Adds a Student named Bob, age 22

    // Adding grades
    students[0].addGrade(90); // Adds a grade of 90 for Alice
    students[0].addGrade(85); // Adds a grade of 85 for Alice
    students[1].addGrade(78); // Adds a grade of 78 for Bob

    // --- Manual input: Add more students interactively ---
    int numStudents;
    std::cout << "Enter number of additional students: ";
    std::cin >> numStudents;
    std::cin.ignore(); // Clear newline from input buffer

    // Loop to input each new student
    for (int i = 0; i < numStudents; ++i) {
        std::string name; // C++ string (safer than char[])
        int age;
        std::cout << "Enter name for student #" << (i + 3) << ": ";
        std::getline(std::cin, name); // Reads full line (including spaces)
        std::cout << "Enter age for " << name << ": ";
        std::cin >> age;

        Student s(name, age); // Create Student object

        int numGrades;
        std::cout << "Enter number of grades for " << name << ": ";
        std::cin >> numGrades;
        // Loop to input grades
        for (int j = 0; j < numGrades; ++j) {
            int grade;
            std::cout << "Enter grade #" << (j + 1) << ": ";
            std::cin >> grade;
            s.addGrade(grade); // Add grade to student
        }
        students.push_back(s); // Add student to vector
        std::cin.ignore(); // Clear newline for next input
    }

    // --- Output: Print all students ---
    std::cout << "\nStudent Information:\n";
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
      C++ supports classes and objects for organizing code and data.
      C has no classes; Python uses classes and methods.

    - Constructors and member functions
      Functions defined inside a class (like addGrade(), printInfo()).
      Used to initialize and operate on objects.

    - std::getline
      Reads an entire line (including spaces) from input.
      In C, you'd use fgets; in Python, input() always reads a full line.

    - emplace_back
      Efficiently constructs an object directly in the vector, avoiding unnecessary copies.
      C has no equivalent; Python lists use append() but without type safety.

    - std::string (vs char arrays in C)
      A safe, flexible string class. In C, you'd use char arrays (manual memory management).
      In Python, strings are built-in and dynamic.

    - std::vector (dynamic arrays, safer than malloc/free in C)
      A dynamic array from the C++ Standard Library.
      Unlike C arrays (fixed size) or Python lists (dynamic), vectors grow as needed and manage memory automatically.

    - Range-based for loops (C++11)
      for (const Student& s : students) iterates over each element,
      similar to Python's "for s in students". In C, you'd use a for loop with indices.

    - Encapsulation (private/protected/public)
      Controls access to class members for better data protection.

    - No need for manual memory management for most cases (RAII)
      C++ manages object lifetimes automatically, reducing memory errors.

    - Streams (cout/cin) instead of printf/scanf
      std::cin / std::cout: Stream-based input/output.
      C uses scanf/printf (format strings); Python uses input()/print().

    Compared to Python:
    - Static typing, explicit types
    - Compilation required
    - Similar OOP concepts, but with more control over memory and performance
*/