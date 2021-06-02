/*
*    Rose Luciano
*    Honor Roll Procedural
*    2/4/21
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "header.h"


using namespace std;

int main()
{
    string name = fullName(); //Will get user input for the full name of the user
    cout << "\n";
    int courseNum = numCourses(name); //User input for the number of courses taken by the user
    cout << "\n";
    vector <string> courseInfo = courseNames(courseNum, name); //Collects the names of the courses
    cout << "\n";
    vector <int> grades = userGrades(courseInfo); //Collects the grades for the courses
    cout << "\n";
    double avg = average(grades); //Calculates the average of the grades

    string discipline = hasDisciplineIssue(); //Checks if there is a discipline issue with the user

    cout << "\n\n";

    //Prints formatted output

    cout << "\n\n" << name << "\n"; //Prints the name of the user
    printf("%-25s%-10s\n", "Class", "Grade"); //Prints the headers

    for (int i = 0; i < courseNum; i++) { //Course Name        Grade%
        printf("%-25s%-10i\n", courseInfo[i].c_str(), grades[i]);
    }

    printf("%-2s%-3.2f%-5s\n", "Average: ", avg, "%"); //Prints average grade
    cout << "Disciplinary Infraction: " << discipline << "\n"; //Prints wether or not the user has a dicipline issue

    if (avg > 90 && courseNum >= 5 && discipline == "No") { //If the user does not meet the requirements
        cout << "Congratulations " << name << "! You have made the honor roll.\n";
    }
    else { //If they meet the requirements
        cout << "I am sorry " << name << ", but you did not qualify for the honor roll.\n";
    }

}
