#pragma once
using namespace std;
#include "./Screen.h"

class ClsDeleteStudentScreen : protected ClsScreen
{
private:
    static string readString(string message)
    {
        string S;
        cout << message;
        cin >> S;
        return S;
    }
    static void DeleteStudent()
    {
        string StudentId = readString("Enter student Id: ");
        ClsStudent St1 = ClsStudent::Find(StudentId);
        if (St1.isStudentExists(StudentId))
        {
            St1.PrintStudentInfo();
            cout << "\nDo you want to delete this student: [y/n]: ";
            char answer;
            cin >> answer;

            St1.Delete();
            cout << "\nStudent deleted successfuly.\n";
            St1.PrintStudentInfo();
        }
        else
        {
            cout << "Student does not exist./";
        }
    }

public:
    static void ShowDeleteStudentScreen()
    {
        DrawScreenHeader("Delete Student Screen.");
    }
};
