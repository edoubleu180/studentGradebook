#pragma once
#include "Student.h"
#include <vector>
#include <string>

class Gradebook {
private:
    std::vector<Student> students;

public:
    void addStudent(const std::string& name);
    void addGrade(const std::string& name, double grade);
    void listStudents() const;
    void saveToCSV(const std::string& filename) const;
    void loadFromCSV(const std::string& filename);
};
