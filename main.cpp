#include "roster.h"
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::cout << "Course Title: Scripting and Programming - Applications – C867\n"
              << "Programming Language Used: C++\n"
              << "WGU Student ID: [Your WGU Student ID]\n"
              << "Student Name: Gursavakh Jhutty\n";

    Roster classRoster;
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Gursavakh,Jhutty,gjhutty@wgu.edu,22,20,15,45,SOFTWARE"
    };

    for (const std::string& row : studentData) {
        std::istringstream inSS(row);
        std::string data[9], part;
        int i = 0, daysInCourse[3];
        while (getline(inSS, part, ',')) data[i++] = part;
        DegreeProgram dp = data[8] == "SECURITY" ? SECURITY : data[8] == "NETWORK" ? NETWORK : SOFTWARE;
        for (i = 0; i < 3; ++i) daysInCourse[i] = std::stoi(data[5 + i]);
        classRoster.add(data[0], data[1], data[2], data[3], std::stoi(data[4]), daysInCourse[0], daysInCourse[1], daysInCourse[2], dp);
    }

    std::cout << "Displaying all students:\n";
    classRoster.printAll();
    std::cout << "\nDisplaying invalid emails:\n";
    classRoster.printInvalidEmails();
    for (int i = 0; i < 5; ++i) classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
    std::cout << "\nDisplaying students in the SOFTWARE program:\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << "\nRemoving A3:\n";
    classRoster.remove("A3");
    std::cout << "\nDisplaying all students post-removal:\n";
    classRoster.printAll();
    std::cout << "\nAttempting to remove A3 again:\n";
    classRoster.remove("A3");

    return 0;
}
