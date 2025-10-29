#pragma once
#include <iostream>
#include "../Screen.h"
using namespace std;

class ClsFindTeacherScreen : protected ClsScreen
{
private:
    static string _ReadString(string message)
    {
        string S;
        cout << message;
        cin >> S;
        return S;
    }
    static void FindTeacher()
    {
        string teacherId = _ReadString("Enter teacher id your are searching for: ");
        ClsTeacher Teacher = ClsTeacher::Find(teacherId);
        if (Teacher.isTeacherExists(teacherId))
        {
            Teacher.PrintInfo();
        }
        else
        {
            cout << "\nTeacher with Id: " << teacherId << " does not exist.\n";
        }
    }

public:
    static void ShowFindTeacherScreen()
    {
        DrawScreenHeader("Find Teacher Screen.");
        FindTeacher();
    }
};