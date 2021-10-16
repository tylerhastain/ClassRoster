//
//  main.cpp
//  C867-Task1
//
//  Created by Tyler Hastain on 4/26/21.
//

/*Course Title: Scripting and Programming - Applications – C867, Programming Language: C++, My Student ID: 001052526, My Name: Tyler Hastain*/

#include <iostream>
#include "roster.h"

using namespace std;

int main() {
    
    /*The course title, programming language used, WGU student ID and student name are not evident.*/
    
    cout << "Course Title: Scripting and Programming - Applications – C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "My Student ID: 001052526" << endl;
    cout << "My Name: Tyler Hastain" << endl << endl;
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Tyler,Hastain,thastai@my.wgu.edu,28,50,45,40,SOFTWARE"
    };
    
    const int numberOfStudents = 5;
    Roster roster;
    
    for (int i = 0; i < numberOfStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all Students: " << endl;
    roster.printAll();
    cout << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << "Displaying by Degree Program: " << degreeProgramString[i] << endl;
        roster.printByDegreeProgram((degreeProgramOptions)i); /*cast the int to a degreeProgramOptions type*/
    }
    
    cout << "Displaying Students with Invalid Email Addresses: " << endl;
    roster.printInvalidEmails();
    cout << endl;
    
    cout << "Displaying Average Days in Courses: " << endl;
    roster.printAverageDaysInCourse();
    cout << endl;
    
    cout << "Displaying Average Days in Courses for a Single Student: " << endl;
    roster.printSingleAverageDaysInCourse("A4");
    cout << endl;
    
    cout << "Removing Student with ID A3: " << endl;
    roster.removeStudent("A3");
    cout << endl;
    
    cout << "Removing Student with ID A3: " << endl;
    roster.removeStudent("A3");
    cout << endl;
    
    system("pause");
    return 0;
}
