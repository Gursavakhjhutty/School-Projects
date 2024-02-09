#include "roster.h"
#include <iostream>

Roster::Roster() { std::fill_n(classRosterArray, 5, nullptr); } // Use fill_n for initialization

Roster::~Roster() { 
    for (int i = 0; i <= lastIndex; ++i) { delete classRosterArray[i]; } // Simplify deallocation
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, new int[3]{daysInCourse1, daysInCourse2, daysInCourse3}, degreeProgram);
}

void Roster::remove(std::string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex--] = nullptr;
            std::cout << "Student ID " << studentID << " removed.\n";
            return;
        }
    }
    std::cout << "Error: Student with ID " << studentID << " not found.\n";
}

void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; i++) classRosterArray[i]->print();
}

void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            auto days = classRosterArray[i]->getDaysInCourse();
            std::cout << "Average days in course for student ID " << studentID << ": " << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
    }
}

void Roster::printInvalidEmails() const {
    std::cout << "Invalid emails:\n";
    for (int i = 0; i <= lastIndex; i++) {
        std::string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos)
            std::cout << email << std::endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; i++)
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
}
