//
//  student.h
//  C867-Task1
//
//  Created by Tyler Hastain on 4/26/21.
//

/*Course Title: Scripting and Programming - Applications – C867, Programming Language: C++, My Student ID: 001052526, My Name: Tyler Hastain*/

#ifndef student_h
#define student_h

#pragma once
#include <iostream>
#include <string>

//Including the degree.h file for the degree program section of Student class
#include "degree.h"

using namespace std;

//Creating the Student class that can be used for objects in student.cpp
class Student {
public: //public 1 section of class
    //Number of Days in Each Course Array Constant
    const static int daysInCourseArraySize = 3;
    
private: //private section of class
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInEachCourse[daysInCourseArraySize];
    degreeProgramOptions degreeProgram;
    
public: //public 2 section of class
    //Parameterless constructor
    Student();
    
    //Constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInEachCourse[daysInCourseArraySize], degreeProgramOptions degreeProgram);
    
    //Desctructor
    ~Student();
    
    //StudentID Mutator & Accessor
    void setStudentID(string studentIDInput);
    string getStudentID();
    
    //FirstName Mutator & Accessor
    void setFirstName(string firstNameInput);
    string getFirstName();
    
    //LastName Mutator & Accessor
    void setLastName(string lastNameInput);
    string getLastName();
    
    //EmailAddress Mutator & Accessor
    void setEmailAddress(string emailAddressInput);
    string getEmailAddress();
    
    //Age Mutator & Accessor
    void setAge(int ageInput);
    int getAge();
    
    //Num of Days to Complete Each Course Mutator & Accessor
    void setDaysArray(int daysInEachCourse[]);
    int* getDaysArray();
    
    //DegreeProgram Mutator & Accessor
    void setDegreeProgram (degreeProgramOptions degreeProgramInput);
    degreeProgramOptions getDegreeProgram();
    
    //Display Table Headers
    static void displayTableHeaders();
    
    //Display Table Data
    void print();
    
}; // End of Class Declaration

#endif /* student_h */
