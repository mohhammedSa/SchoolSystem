#pragma once
#include <iostream>
#include "../Screen.h"
using namespace std;

class ClsUpdateCourseScreen : protected ClsScreen
{
private:
    static string ReadString(string message)
    {
        string word;
        cout << message;
        cin >> word;
        return word;
    }

    static void _UpdateCourse()
    {
        string CourseId = ReadString("Enter course Id: ");
        ClsCourse Course = ClsCourse::Find(CourseId);

        if (Course.GetId() == CourseId)
        {
            Course.PrintCourseInfo();

            cout << "Do you want to update this course: [y/n]: ";
            char answer;
            cin >> answer;
            if (tolower(answer) == 'y')
            {
                ClsCourse::ReadCourseInfo(Course);
                Course.Update();
                Course.PrintCourseInfo();
            }
        }
    }

public:
    static void ShowUpdateCourseScreen()
    {
        DrawScreenHeader("Update Course Screen.");
        _UpdateCourse();
    }
};