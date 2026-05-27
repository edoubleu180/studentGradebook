#include "Student.h"
#include <numeric>

Student::Student(const std::string& name) : name(name) {}

void Student::addGrade(double grade) {
    grades.push_back(grade);
}

double Student::getAverage() const {
    if (grades.empty()) return 0.0;
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}

std::string Student::getName() const {
    return name;
}

const std::vector<double>& Student::getGrades() const {
    return grades;
}
