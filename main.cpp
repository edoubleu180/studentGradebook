#include "Gradebook.h"
#include <iostream>

int main() {
    Gradebook gb;
    gb.loadFromCSV("data/students.csv");

    int choice;
    while (true) {
        std::cout << "\n=== STUDENT GRADEBOOK ===\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Grade\n";
        std::cout << "3. List Students\n";
        std::cout << "4. Save & Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            std::cout << "Student name: ";
            std::cin >> name;
            gb.addStudent(name);
        }
        else if (choice == 2) {
            std::string name;
            double grade;
            std::cout << "Student name: ";
            std::cin >> name;
            std::cout << "Grade: ";
            std::cin >> grade;
            gb.addGrade(name, grade);
        }
        else if (choice == 3) {
            gb.listStudents();
        }
        else if (choice == 4) {
            gb.saveToCSV("data/students.csv");
            std::cout << "Saved. Goodbye.\n";
            break;
        }
        else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
