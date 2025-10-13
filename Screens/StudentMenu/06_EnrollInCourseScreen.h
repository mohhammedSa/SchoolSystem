#pragma once
#include <iostream>
#include <vector>
#include "../Screen.h"
#include "../../Logic/Course.h"
#include "../CourseMenu/01_ListCoursesScreen.h"
using namespace std;

class ClsEnrollInCourseScreen : protected ClsScreen
{
private:
    static void enrollInCourse()
    {
        vector<ClsCourse> Courses = ClsCourse::LoadCourses();
        ClsListCoursesScreen::CoursesList(Courses);

        cout << "Choose which course you want to enroll: ";
        string id;
        cin >> id;
        ClsCourse Course = ClsCourse::Find(id);
        Course.PrintCourseInfo();

        cout << "Do you want to confirm this operation: [y/n]: ";
        char answer;
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            cout << "\nYou are successfully enrolled in this course.\n";
            // Open the file with student name, and save all courses he was enrolled in.
            // Add Student id and name to the course file he enrolled in.
        }
        else
        {
            cout << "Operation failed./n";
        }
    }

public:
    static void ShowEnrollInCourseScreen()
    {
        DrawScreenHeader("Enroll in course.");
        enrollInCourse();
    }
};