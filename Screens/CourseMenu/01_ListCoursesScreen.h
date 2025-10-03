#pragma once
#include <iostream>
#include <vector>
#include "../Screen.h"
#include "../../Logic/Course.h"
using namespace std;

class ClsListCoursesScreen : protected ClsScreen
{
private:
    static void PrintCourseInfo(ClsCourse Course)
    {
        cout << "| "<< left << setw(10) << Course.GetId() << "| " << setw(18) << Course.GetCoursename() << "|" << setw(8) << Course.GetAssignedTeacher() << "\n";
    }

    static void CoursesList()
    {
        vector<ClsCourse> Courses = ClsCourse::LoadCourses();
        string subtitle = "(" + to_string(Courses.size()) + ")";

        DrawScreenHeader("Course List Screen.", subtitle);

        cout << "\n------------------------------------------\n";
        cout << left << setw(12) << "| Course Id" << setw(20) << "| Course name" << setw(10) << "| Teacher";
        cout << "\n------------------------------------------\n";
        for (ClsCourse &C : Courses)
        {
            PrintCourseInfo(C);
        }
        cout << "------------------------------------------\n\n";
    }

public:
    static void ShowCoursesListScreen()
    {
        CoursesList();
    }
};