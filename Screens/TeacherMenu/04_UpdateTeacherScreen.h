#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../Logic/Teacher.h"
using namespace std;

class ClsUpdateTeachersScreen : protected ClsScreen
{
private:
    static string _ReadString(string message)
    {
        string S;
        cout << message;
        cin >> S;
        return S;
    }

    static void _UpdateTeacherInfo()
    {
        string teacherId = _ReadString("Enter Teacher Id: ");
        ClsTeacher Teacher = ClsTeacher::Find(teacherId);
        if (!Teacher.isTeacherExists(teacherId))
        {
            cout << "Teacher does not exist.\n";
        }
        else
        {
            ClsTeacher::ReadTeacherInfo(Teacher);
            ClsTeacher::enSaveResult result = Teacher.Save();
            switch (result)
            {
            case ClsTeacher::enSaveResult::enSvSuccess:
                cout << "\nTeacher info updated successfully.";
                Teacher.PrintInfo();
                break;

            default:
                cout << "Operation Failed.\n";
                break;
            }
        }
    }

public:
    static void ShowUpdateTeachersScreen()
    {
        DrawScreenHeader("Update Teacher Screen.\n");
        _UpdateTeacherInfo();
    }
};