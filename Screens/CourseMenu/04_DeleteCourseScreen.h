#pragma once
#include <iostream>
#include "../Screen.h"
using namespace std;

class ClsDeleteCourseScreen : protected ClsScreen
{
private:
    static string ReadString(string message)
    {
        string word;
        cout << message;
        cin >> word;
        return word;
    }

    static void _DeleteCourse()
    {
        string CourseId = ReadString("Enter course Id: ");
        ClsCourse Course = ClsCourse::Find(CourseId);

        if (Course.GetId() == CourseId)
        {
            Course.PrintCourseInfo();
            char answer;
            cin >> answer;
            if (tolower(answer) == 'y')
            {
                Course.Delete();
                cout << "Course deleted successfully.\n";
            }
            else
            {
                cout << "Operation Failed.\n";
            }
        }
        else
        {
            cout << "Course does not exist.\n";
        }
    }

public:
    static void ShowDeleteCourseScreen()
    {
        DrawScreenHeader("Delete Course Screen.");
        _DeleteCourse();
    }
};