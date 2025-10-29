#pragma once
#include <iostream>
#include <vector>
#include "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Logic/Student.h"
// #include "../Logic/Student.h"
#include "../../Screen.h"
using namespace std;

class ClsListStudentsScreen : protected ClsScreen
{
private:
    static void PrintStudentInfo(ClsStudent Student)
    {
        cout << "| " << left << setw(11) << Student.GetId()
             << "| " << setw(19) << Student.GetFullname()
             << "| " << setw(13) << Student.GetPhoneNumber()
             << "| " << setw(19) << Student.GetEmail()
             << "| " << setw(39) << Student.GetAdress()
             << "| " << setw(5) << to_string(Student.GetAge())
             << "| " << setw(6) << Student.getGrade() << "\n";
    }

public:
    static void ListStudents(vector<ClsStudent> Students)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------\n";
        cout << "|" << left << setw(12) << " Student ID"
             << "|" << setw(20) << " Fullname"
             << "|" << setw(12) << " Phone number "
             << "|" << setw(20) << " Email"
             << "|" << setw(40) << " Adress"
             << "|" << setw(5) << " Age"
             << "|" << setw(6) << " Grade";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------\n";
        if (Students.size() == 0)
        {
            cout << "\nNo student available.\n";
        }
        else
            for (ClsStudent S : Students)
            {
                PrintStudentInfo(S);
            }
        cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
    }
    static void ShowListStudentsScreen()
    {
        vector<ClsStudent> Students = ClsStudent::LoadStudents();
        string subtitle = to_string(Students.size()) + " Student(s)";
        DrawScreenHeader("List Studetns Screen.", subtitle);
        ListStudents(Students);
    }
};