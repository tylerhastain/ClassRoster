//
//  roster.cpp
//  C867-Task1
//
//  Created by Tyler Hastain on 4/26/21.
//

/*Course Title: Scripting and Programming - Applications – C867, Programming Language: C++, My Student ID: 001052526, My Name: Tyler Hastain*/

#include <stdio.h>
#include "roster.h"

using namespace std;

void Roster::parse(string studentData) {
    
    degreeProgramOptions degreeprogram = SOFTWARE; /*Default Value*/
    
    int rhSide = studentData.find(","); /*find the comma*/
    string stuID = studentData.substr(0, rhSide); /*extracts the student ID substring from in front of the comma*/
    
    int lhSide = rhSide + 1; /*moves past the previous comma*/
    rhSide = studentData.find(",", lhSide);
    string fName = studentData.substr(lhSide, rhSide - lhSide); /*first name*/
    
    lhSide = rhSide + 1; /*moves past the previous comma*/
    rhSide = studentData.find(",", lhSide);
    string lName = studentData.substr(lhSide, rhSide - lhSide); /*last name*/
    
    lhSide = rhSide + 1; /*moves past the previous comma*/
    rhSide = studentData.find(",", lhSide);
    string email = studentData.substr(lhSide, rhSide - lhSide); /*email address*/
    
    lhSide = rhSide + 1; /*moves past the previous comma*/
    rhSide = studentData.find(",", lhSide);
    int Age = stoi(studentData.substr(lhSide, rhSide - lhSide)); /*Age*/
    
    lhSide = rhSide + 1; /*moves past the previous comma*/
    rhSide = studentData.find(",", lhSide);
    int daysInCourse1 = stoi(studentData.substr(lhSide, rhSide - lhSide)); /*Days in Course 1*/
    
    lhSide = rhSide + 1; /*moves past the previous comma*/
    rhSide = studentData.find(",", lhSide);
    int daysInCourse2 = stoi(studentData.substr(lhSide, rhSide - lhSide)); /*Days in Course 2*/
    
    lhSide = rhSide + 1; /*moves past the previous comma*/
    rhSide = studentData.find(",", lhSide);
    int daysInCourse3 = stoi(studentData.substr(lhSide, rhSide - lhSide)); /*Days in Course 3*/
    
    lhSide = rhSide + 1; /*moves past the previous comma*/
    int lhSide1 = lhSide + 1;
    rhSide = studentData.find(",", lhSide);
    if(studentData.at(lhSide) == 'N') degreeprogram = NETWORK;
    else if (studentData.at(lhSide) == 'S' && studentData.at(lhSide1) == 'E') degreeprogram = SECURITY;
    /*Degree Program*/
    
    add(stuID, fName, lName, email, Age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram); /*Turns into an object*/
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInEachCourse1, int daysInEachCourse2, int daysInEachCourse3, degreeProgramOptions degreeProgram) {
    
    int daysInCourses[3] = { daysInEachCourse1, daysInEachCourse2, daysInEachCourse3 };
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourses, degreeProgram);
}

//My old printAll() - Does not reference the student class print function.
/*void Roster::printAll() {
    
    Student::displayTableHeaders();
    
    for (int i = 0; i<= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]->getStudentID(); cout << '\t';
        cout << "First Name: " << classRosterArray[i]->getFirstName(); cout << '\t';
        cout << "Last Name: " << classRosterArray[i]->getLastName(); cout << '\t';
        //The following (email address) is not called for in the prompt for printAll().
        //cout << "Email Address: " << classRosterArray[i]->getEmailAddress(); cout << '\t';
        cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
        cout << "daysInCourse: " << classRosterArray[i]->getDaysArray()[0]; cout << '\t';
        cout << classRosterArray[i]->getDaysArray()[1]; cout << '\t';
        cout << classRosterArray[i]->getDaysArray()[2]; cout << '\t';
        cout << "Degree Program: " << degreeProgramString[classRosterArray[i]->getDegreeProgram()] << endl;
    }
}*/

void Roster::printAll() {
    
    Student::displayTableHeaders();
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        
        Roster::classRosterArray[i]->print();
        
    }
}

void Roster::printByDegreeProgram(degreeProgramOptions degreeprogram)
{
    Student::displayTableHeaders();
    
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram) classRosterArray[i]->print();
    }
    cout << endl;
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string eAdd = (classRosterArray[i]->getEmailAddress());
        if (eAdd.find(' ') != string::npos || eAdd.find('@') == string::npos || eAdd.find('.') == string::npos) {
            any = true;
            cout << eAdd << " (" << classRosterArray[i]->getStudentID() << "): " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << endl;
        }
    }
    if (!any) cout << "NONE" << endl;
}

/*My old 'printAverageDaysInCourse' method - "A method that prints the average number of days in the 3 courses for a single student that is passed as a parameter is not evident." Left this here for clarity sake.*/
void Roster::printAverageDaysInCourse() {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << classRosterArray[i]->getStudentID() << ": ";
        cout << ((double) classRosterArray[i]->getDaysArray()[0] + (double) classRosterArray[i]->getDaysArray()[1] + (double) classRosterArray[i]->getDaysArray()[2])/3.0 << endl;
    }
}

void Roster::printSingleAverageDaysInCourse(string studentID) {
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        
        if (Roster::classRosterArray[i]->getStudentID() == studentID) {
        
            cout << classRosterArray[i]->getStudentID() << ": " << ((double) classRosterArray[i]->getDaysArray()[0] + (double) classRosterArray[i]->getDaysArray()[1] + (double) classRosterArray[i]->getDaysArray()[2])/3.0 << endl;
        }
    }
}

void Roster::removeStudent(string studentID) {
    
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            success = true;
            if (i < numberOfStudents - 1)
            {
                Student* temp = classRosterArray[i]; //swap w/ last student
                classRosterArray[i] = classRosterArray[numberOfStudents - 1];
                classRosterArray[numberOfStudents - 1] = temp;
            }
            Roster::lastIndex--; /*last student no longer visible*/
            /*Not quite deleted yet*/
        }
    }
    if (success) {
        cout << studentID << " removed from Roster." << endl;
        this->printAll(); /*displays all students except the removed one*/
    } else {
        cout << studentID << " not found." << endl;
    }
}

Roster::~Roster() {
    cout << "DESTRUCTOR CALLED." << endl << endl;
    
    for (int i = 0; i < numberOfStudents; i++) {
        cout << "Destroying Student Number " << i + 1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
