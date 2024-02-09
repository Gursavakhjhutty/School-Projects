#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
private:
    std::string studentID, firstName, lastName, emailAddress;
    int age, daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days[], DegreeProgram degreeProgram) : 
    studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
        for (int i = 0; i < 3; ++i) this->daysInCourse[i] = days[i];
    }
    ~Student() {}

    // getting things
    std::string getStudentID() const { return studentID; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getEmailAddress() const { return emailAddress; }
    int getAge() const { return age; }
    const int* getDaysInCourse() const { return daysInCourse; }
    DegreeProgram getDegreeProgram() const { return degreeProgram; }

    // Setting things
    void setStudentID(const std::string& ID) { studentID = ID; }
    void setFirstName(const std::string& firstName) { this->firstName = firstName; }
    void setLastName(const std::string& lastName) { this->lastName = lastName; }
    void setEmailAddress(const std::string& emailAddress) { this->emailAddress = emailAddress; }
    void setAge(int age) { this->age = age; }
    void setDaysInCourse(const int days[]) { for (int i = 0; i < 3; ++i) this->daysInCourse[i] = days[i]; }
    void setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

    void print() const;
};

#endif
