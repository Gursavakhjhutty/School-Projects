#include "student.h"
#include <iostream>

//initialization list and loop for daysInCourse.
Student::Student(std::string id, std::string fn, std::string ln, std::string email, int age, int days[], DegreeProgram dp) 
    : studentID(id), firstName(fn), lastName(ln), emailAddress(email), age(age), degreeProgram(dp) {
    for (int i = 0; i < 3; ++i) daysInCourse[i] = days[i];
}

//function to display student detail
void Student::print() const {
    std::cout << "Student ID: " << studentID << "\tFirst Name: " << firstName 
              << "\tLast Name: " << lastName << "\tEmail: " << emailAddress 
              << "\tAge: " << age << "\tdaysInCourse: {" << daysInCourse[0] 
              << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\tDegree Program: " 
              << degreeProgram << std::endl;
}
