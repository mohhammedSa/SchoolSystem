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
    static void AddLineToFile(string filename, string courseId)
    {
        fstream File;
        File.open(filename, ios::out | ios::app);

        if (File.is_open())
        {
            File << courseId << "\n";
            File.close();
        }
    }

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
        string StudentFilename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Students/" + CurrentStudent.GetId() + ".txt";
        string CourseFileName = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Courses/" + Course.GetId() + ".txt";
        if (tolower(answer) == 'y')
        {
            cout << "\nYou are successfully enrolled in this course.\n";
            // Open the file with student id, and save all courses he was enrolled in.
            AddLineToFile(StudentFilename, Course.GetId());
            // Add Student id and name to the course file he enrolled in.
            AddLineToFile(CourseFileName, CurrentStudent.GetId());
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