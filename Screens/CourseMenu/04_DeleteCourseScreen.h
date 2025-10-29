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

    static void DeleteAFile(const char *Filename)
    {
        const char *name = Filename;
        if (remove(name) == 0)
        {
            cout << "File deleted successfully.\n";
        }
        else
        {
            perror("Error Deliting File.\n");
        }
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
                // string filename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Students/" + StudentId + ".txt";
                // DeleteAFile(filename.c_str());
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