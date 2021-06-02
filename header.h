/*
*	Rose Luciano
*	Honor Roll Procedural
*	2/4/21
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

std::string fullName();
int numCourses(std::string name);
std::vector <std::string> courseNames(int courseNum, std::string name);
std::vector <int> userGrades(std::vector <std::string> courseInfo);
int average(std::vector <int> grades);
std::string hasDisciplineIssue();