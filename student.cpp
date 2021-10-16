//
//  student.cpp
//  C867-Task1
//
//  Created by Tyler Hastain on 4/26/21.
//

/*Course Title: Scripting and Programming - Applications – C867, Programming Language: C++, My Student ID: 001052526, My Name: Tyler Hastain*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include "student.h"

//Parameterless Constructor
Student::Student() {
    this->studentID = "A-";
    this->firstName = "None";
    this->lastName = "None";
    this->emailAddress = "email@domain.com";
    this->age = 18;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInEachCourse[i] = 0;
    this->degreeProgram = degreeProgramOptions::SOFTWARE;
}

//Full Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInEachCourse[daysInCourseArraySize], degreeProgramOptions degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInEachCourse[i] = daysInEachCourse[i];
    this->degreeProgram = degreeProgram;
}

//Deconstrutor
Student::~Student(){
    //does nothing right now
}

//StudentID Mutator & Accessor
void Student::setStudentID(string studentIDInput) {
    this->studentID = studentIDInput;
    return;
}
string Student::getStudentID() {
    return this->studentID;
}
//------------------------------------------------------------------
//FirstName Mutator & Accessor
void Student::setFirstName(string firstNameInput) {
    this->firstName = firstNameInput;
    return;
}
string Student::getFirstName() {
    return this->firstName;
}
//------------------------------------------------------------------
//LastName Mutator & Accessor
void Student::setLastName(string lastNameInput) {
    this->lastName = lastNameInput;
    return;
}
string Student::getLastName() {
    return this->lastName;
}
//------------------------------------------------------------------
//EmailAddress Mutator & Accessor
void Student::setEmailAddress(string emailAddressInput) {
    this->emailAddress = emailAddressInput;
    return;
}
string Student::getEmailAddress() {
    return this->emailAddress;
}
//------------------------------------------------------------------
//Age Mutator & Accessor
void Student::setAge(int ageInput) {
    this->age = ageInput;
    return;
}
int Student::getAge() {
    return this->age;
}
//------------------------------------------------------------------
//Num of Days to Complete Each Course Mutator & Accessor
void Student::setDaysArray(int daysInEachCourse[]) {
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInEachCourse[i] = daysInEachCourse[i];
    return;
}
int* Student::getDaysArray() {
    return this->daysInEachCourse;
}
//------------------------------------------------------------------
//DegreeProgram Mutator & Accessor
void Student::setDegreeProgram (degreeProgramOptions degreeProgramInput) {
    this->degreeProgram = degreeProgramInput;
    return;
}
degreeProgramOptions Student::getDegreeProgram() {
    return this->degreeProgram;
}
//------------------------------------------------------------------
//Displaying the table headers for the data
void Student::displayTableHeaders(){
    cout << "Output Format: Student ID | First Name | Last Name | Age | DegreeProgram | Days To Complete Each Course" << endl;
    
    return;
}
//------------------------------------------------------------------
//Displaying the data in the table
void Student::print(){
    cout << this->getStudentID() << '\t';
    cout << "First Name: " << this->getFirstName() << '\t';
    cout << "Last Name: " << this->getLastName() << '\t';
    //Email address is not needed in the print function
    //cout << "Email Address: " << this->getEmailAddress() << '\t';
    cout << "Age: " << this->getAge() << '\t';
    cout << "daysInCourse: " << this->getDaysArray()[0] << ", ";
    cout << this->getDaysArray()[1] << ", ";
    cout << this->getDaysArray()[2] << '\t';
    cout << "Degree Program: " << degreeProgramString[this->getDegreeProgram()] << endl;
    
    return;
}
