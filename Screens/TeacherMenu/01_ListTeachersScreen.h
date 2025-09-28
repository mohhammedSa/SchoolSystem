#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "../../Logic/Teacher.h"
#include "../Screen.h"
using namespace std;

class ClsListTeachersScreen : protected ClsScreen
{
private:
    static void _PrintTeacherLine(ClsTeacher Teacher)
    {
        cout << "| " << left << setw(11) << Teacher.GetId()
             << "| " << setw(19) << Teacher.GetFullname()
             << "| " << setw(13) << Teacher.GetPhoneNumber()
             << "| " << setw(19) << Teacher.GetEmail()
             << "| " << setw(39) << Teacher.GetAdress()
             << "| " << setw(5) << to_string(Teacher.GetAge())
             << "| " << setw(6) << Teacher.getSubject() << "\n";
    }

    static void _ListTeachers()
    {
        vector<ClsTeacher> vTeachers = ClsTeacher::LoadTeachers();
        string subtitle = "(" + to_string(vTeachers.size()) + ") Teacher(s)";
        DrawScreenHeader("Teachers list screen.", subtitle);

        cout << "\n-------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "|" << left << setw(12) << " Student ID"
             << "|" << setw(20) << " Fullname"
             << "|" << setw(12) << " Phone number "
             << "|" << setw(20) << " Email"
             << "|" << setw(40) << " Adress"
             << "|" << setw(5) << " Age"
             << "|" << setw(6) << " Subject";
        cout << "\n-------------------------------------------------------------------------------------------------------------------------------\n";

        for (ClsTeacher T : vTeachers)
        {
            _PrintTeacherLine(T);
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    }

public:
    static void ShowListTeachersScreen()
    {
        _ListTeachers();
    }
};
