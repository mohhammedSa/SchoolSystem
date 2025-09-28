#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../Logic/Teacher.h"
using namespace std;

class ClsAddTeachersScreen : protected ClsScreen
{
private:
    static string _ReadString(string message)
    {
        string S;
        cout << message;
        cin >> S;
        return S;
    }
    static void _AddTeacher()
    {
        string teacherId = _ReadString("Enter Id: ");
        ClsTeacher Teacher = ClsTeacher::Find(teacherId);

        if (Teacher.isTeacherExists(teacherId))
        {
            cout << "\nTeacher already exists\n";

            Teacher.PrintInfo();
        }
        else
        {
            Teacher = ClsTeacher::_EmptyTeacherObjectForAdding(teacherId);
            ClsTeacher::ReadTeacherInfo(Teacher);
            ClsTeacher::enSaveResult result = Teacher.Save();

            switch (result)
            {
            case ClsTeacher::enSaveResult::enSvSuccess:
                cout << "Teacher added successfully.\n";
                Teacher.PrintInfo();
                break;

            default:
                cout << "Operation Failled\n";
                break;
            }
        }
    }

public:
    static void ShowAddTeacherScreen()
    {
        DrawScreenHeader("Add Teacher screen.");
        _AddTeacher();
    }
};