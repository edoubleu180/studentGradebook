#pragma once
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    std::vector<double> grades;

public:
    Student(const std::string& name);

    void addGrade(double grade);
    double getAverage() const;
    std::string getName() const;
    const std::vector<double>& getGrades() const;
};
