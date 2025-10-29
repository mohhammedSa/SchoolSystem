#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../Global.h"
#include "../CourseMenu/01_ListCoursesScreen.h"
using namespace std;

class ClsChooseCourseToTeachScreen : protected ClsScreen
{
private:
    static void AddLineToFile(string filename, string id)
    {
        fstream File;
        File.open(filename, ios::out | ios::app);

        if (File.is_open())
        {
            File << id << "\n";
            File.close();
        }
    }

    static void enrollInCourse()
    {
        vector<ClsCourse> Courses = ClsCourse::LoadCourses();
        ClsListCoursesScreen::CoursesList(Courses);

        cout << "Which course do you teach: ";
        string id;
        cin >> id;
        ClsCourse Course = ClsCourse::Find(id);
        Course.PrintCourseInfo();

        cout << "Do you want to confirm this operation: [y/n]: ";
        char answer;
        cin >> answer;
        string TeacherFilename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Teachers/" + CurrentTeacher.GetId() + ".txt";
        string CourseFileName = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Courses/" + Course.GetId() + ".txt";
        if (tolower(answer) == 'y')
        {
            cout << "\nYou are successfully enrolled in this course.\n";
            // Open the file with student id, and save all courses he was enrolled in.
            AddLineToFile(TeacherFilename, Course.GetId());
            // Add Student id and name to the course file he enrolled in.
            AddLineToFile(CourseFileName, CurrentTeacher.GetId());
        }
        else
        {
            cout << "Operation failed./n";
        }
    }

public:
    static void ShowChooseCurseScreen()
    {
        DrawScreenHeader("Choose Courses To teach Screen.\n");
        enrollInCourse();
    }
};