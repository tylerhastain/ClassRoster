//
//  roster.h
//  C867-Task1
//
//  Created by Tyler Hastain on 4/26/21.
//

/*Course Title: Scripting and Programming - Applications – C867, Programming Language: C++, My Student ID: 001052526, My Name: Tyler Hastain*/

#ifndef roster_h
#define roster_h

#pragma once
#include "student.h"

using namespace std;

class Roster {
private:
    int lastIndex = -1;  //Starts @ -1 so that the first instance is 0 instead of 1
    const static int numberOfStudents = 5;  //5 Total Students
    Student* classRosterArray[numberOfStudents];  //Not dynamically declared
    
public:
    void parse(string row); /*Parse method goes through a set of comma delimited strings and extracts the data of a student*/
    
    void add(string stuID,
             string fName,
             string lName,
             string email,
             int Age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             degreeProgramOptions degreeprogram
             );
    
    void printAll(); /*calls the print method in the student() class for each student*/
    
    void printByDegreeProgram(degreeProgramOptions degreeprogram); /*degreeprogram is passed in*/
    
    void printInvalidEmails(); /*Prints studenst w/ invalid emails. Must have '@' and '.' but no ' '.*/
    
    void printAverageDaysInCourse(); /*Avg number of days in the 3 courses*/
    
    void printSingleAverageDaysInCourse(string studentID); /*Avg number of days in the 3 courses for a single student*/
    
    void removeStudent(string studentID); /*Finds the student with given ID and removes them*/
    
    ~Roster();
};

#endif /* roster_h */
