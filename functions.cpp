/*
*
*	Rose Luciano
*	Honor Roll Procedural
*	2/4/21
*	
*	Revisions:
*		2/22/21 - Takes One Character Names
*
*/

#include "header.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
using namespace std;

//Will get the name of the user
string fullName() //Gets the full name of the user.
{
	string name;
	bool valid = false;

	do {
		cout << "Please enter your full name: "; //Asks the useer to enter their name
		getline(cin, name);

		if (name.length() < 1) { //If the user doesn't enter anything the input is invalid and it will ask the user again
			cout << "Sorry, that input was invalid. Please try again. \n";
			valid = false;
		}
		else { //If the input is valid

			valid = true;

		}
	} while (!valid);

	return name; //Returns the name of the user
}

//Will get the number of courses
int numCourses(string name) { //Collects the number of courses the user is taking.

	float enteredNum;
	int numCourses = 0;
	bool valid = false;

	do {
		cout << name << ", please enter the number of courses you are taking. (No more than 8, no less than 1): "; //Asks the user to enter a number
		cin >> enteredNum;

		if (name.length() < 1 || (floor(enteredNum) != enteredNum)) { //If the user doesn't enter anything the input is invalid and it will ask the user again
			cout << "Sorry, that input was invalid. Please try again. \n";
			valid = false;
		}

		else if (cin.fail()) {
			cin.clear();
			cin.ignore(250, '\n');
			cout << "Sorry, that input was invalid. Please try again. \n";
		}

		else {
			numCourses = (int)enteredNum;
			/*(userInput != "1" || userInput != "2" || userInput != "3" || userInput != "4" || userInput != "5" || userInput != "6" || userInput != "7" || userInput != "8")*/
			if (numCourses < 1 || numCourses > 8) { //If the user entered something other than numbers 1-8
				cout << "Sorry, that input was invalid. Please try again. \n";
				valid = false;
			}
			else { //If the user entered a number from 1-8
				//numCourses = stoi(userInput);
				valid = true;
			}
		}
	} while (!valid);

	return numCourses; //Returns number of courses taken by the user

}

//Will get a vector with the names of the courses
vector <string> courseNames(int courseNum, string name) { //Gets the names of courses from the user

	string course;
	bool valid = false;
	vector <string> courses;

	cin.ignore(1000, '\n');

	cout << "If course name exceeds 20 characters, it will be truncated down to 20.\n"; //Tells user that the course name will be truncated down to 20 characters if more than 20 are entered

	for (int i = 0; i < courseNum; i++) {
		do {
			cout << name << " please enter the name of course " << (i + 1) << ": "; //Asks the user to enter the name of the course
			getline(cin, course);

			if (course.length() < 1) { //If the user doesn't enter anything the input is invalid and it will ask the user again
				cout << "Sorry, that input was invalid. Please try again. \n";
				valid = false;
				cin.clear();
			}
			if (course.length() > 20) { //Will cut down the length of the course name if it exceeds 20 characters
				course = course.substr(0, 20);
				courses.push_back(course);
				valid = true;
			}
			else if (course.length() > 0) {
				courses.push_back(course); //Puts the user input into the vector (will be used later).
				valid = true;
			}
			else {
				continue;
			}

		} while (!valid);
	}

	return courses; //Returns vector with the course names

}

//Will get a vector with the grades for each course
vector <int> userGrades(vector <string> courseInfo) { //Gets the grades in each course from the user
	vector <int> grades;
	int grade;
	float enteredNum;
	bool valid = false, isString = true;
	cout << "Grades range from 0-120.\n";

	for (int i = 0; i < courseInfo.size(); i++) { //For each course

			do {
				cout << "Please enter your grade for " << courseInfo[i] << ": "; //Asks the user to enter the grade of the course
				cin >> enteredNum;

				grade = (int)enteredNum;

				if (grade < 0 || grade > 120 || floor(enteredNum) != enteredNum || cin.fail()) { //If the user enters an invalid input (out of bounds or a decimal)
					cout << "Sorry, that input was invalid. Please try again. \n";
					valid = false;
					cin.clear();
					cin.ignore(250, '\n');
					continue;
				}
				else {
					grades.push_back(grade); //Puts the user input into the vector (will be used later).
					valid = true;
					isString = true;
				}

			} while (!valid);
		}

	return grades;
}

//Will calculate the average of the grades
double average(vector<int> grades) { //Calcualtes the average

	double avg = 0;

	for (int i = 0; i < grades.size(); i++) { //Runs for the the number of grades
		avg += grades[i]; //Adds the grade to avg
	}
	avg /= grades.size(); //Avg is divided vy the number of grades to find the average

	return avg;

}

//Will run a rng with 5% chance of having a dicipline issue
string hasDisciplineIssue() {
	string result = "";
	srand(time(0)); //Set random seed to time
	int num = rand() % 20 + 1;

	if (num == 1) {
		result = "Yes";
	}
	else {
		result = "No";
	}
	return result;
}
