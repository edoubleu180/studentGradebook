#include "Gradebook.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Gradebook::addStudent(const std::string& name) {
    students.emplace_back(name);
}

void Gradebook::addGrade(const std::string& name, double grade) {
    for (auto& s : students) {
        if (s.getName() == name) {
            s.addGrade(grade);
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void Gradebook::listStudents() const {
    for (const auto& s : students) {
        std::cout << s.getName() << " | Avg: " << s.getAverage() << "\n";
    }
}

void Gradebook::saveToCSV(const std::string& filename) const {
    std::ofstream file(filename);

    for (const auto& s : students) {
        file << s.getName();
        for (double g : s.getGrades()) {
            file << "," << g;
        }
        file << "\n";
    }
}

void Gradebook::loadFromCSV(const std::string& filename) {
    students.clear();
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        std::getline(ss, name, ',');

        Student s(name);
        std::string gradeStr;

        while (std::getline(ss, gradeStr, ',')) {
            s.addGrade(std::stod(gradeStr));
        }

        students.push_back(s);
    }
}
