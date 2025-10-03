#pragma once
#include <iostream>
#include "../Screen.h"
using namespace std;

class ClsAddCourseScreen : protected ClsScreen
{
private:
    static string ReadString(string message)
    {
        string word;
        cout << message;
        cin >> word;
        return word;
    }
    static void _AddCourse()
    {
        string CourseId = ReadString("Enter course Id: ");
        ClsCourse Course = ClsCourse::Find(CourseId);

        if (Course.GetId() == CourseId)
        {
            Course.PrintCourseInfo();
        }
        else
        {
            ClsCourse::ReadCourseInfo(Course);
            cout << "Do you want to add this course: [y/n]: ";
            char answer;
            cin >> answer;
            if (tolower(answer) == 'y')
            {
                Course.AddCourse();
                cout << "\nCourse added successfully.\n";
                Course.PrintCourseInfo();
            }
            else
            {
                cout << "\nOperation Failed.\n";
            }
        }
    }

public:
    static void ShowAddCourseScreen()
    {
        DrawScreenHeader("Add Course Screen.");
        _AddCourse();
    }
};
