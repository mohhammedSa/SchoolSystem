#pragma once
#include <iostream>
#include "../../Screen.h"
using namespace std;

class ClsFindStudentScreen : protected ClsScreen
{
private:
    static string readString(string message)
    {
        string S;
        cout << message;
        cin >> S;
        return S;
    }
    static void FindStudent()
    {
        string StudentId = readString("Enter student Id: ");
        ClsStudent St1 = ClsStudent::Find(StudentId);
        if (St1.isStudentExists(StudentId))
        {
            St1.PrintStudentInfo();
        }
        else
        {
            cout << "Student does not exist.\n\n";
        }
    }

public:
    static void ShowFindStudentScreen()
    {
        DrawScreenHeader("Find Student Screen.");
        FindStudent();
    }
};