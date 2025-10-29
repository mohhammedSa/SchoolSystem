#pragma once
#include <istream>
#include <fstream>
#include "../Screen.h"
#include "../../Global.h"
#include "../../Logic/Course.h"
using namespace std;

class ClsShowEnrolledCoursesScreen : protected ClsScreen
{
private:
    static vector<string> LoadEnrolledCourses()
    {
        vector<string> vEnrolledCourses;
        string filename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Students/" + CurrentStudent.GetId() + ".txt";
        fstream EnrolledCoursesFile;
        EnrolledCoursesFile.open(filename, ios::in);

        if (EnrolledCoursesFile.is_open())
        {
            string line;
            while (getline(EnrolledCoursesFile, line))
            {
                vEnrolledCourses.push_back(line);
            }
            EnrolledCoursesFile.close();
        }
        return vEnrolledCourses;
    }

    static void EnrolledCoursesList(vector<string> vEnrolledCourses)
    {
        cout << "You are Enrolled in: " << "\n";
        for (string S : vEnrolledCourses)
        {
            ClsCourse Course = ClsCourse::Find(S);
            Course.PrintCourseInfo();
        }
    }

public:
    static void ShowEnroledCoursesScreen()
    {
        DrawScreenHeader("Show Enroled Courses Screen.");
        EnrolledCoursesList(LoadEnrolledCourses());
    }
};
