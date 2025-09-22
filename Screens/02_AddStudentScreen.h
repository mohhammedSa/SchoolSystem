#pragma once
#include <iostream>
#include "./Screen.h"
#include "../Logic/Student.h"
using namespace std;

class ClasAddStudentScreen : protected ClsScreen
{
private:
    static string readString(string message)
    {
        string S;
        cout << message;
        cin >> S;
        return S;
    }
    static void AddStudent()
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
            cout << "Do you want to add student with id : " << StudentId << " [y/n]: ";
            char answer;
            cin >> answer;

            if (tolower(answer) == 'y')
            {
                St1 = ClsStudent::EmptyObjectForAdding(StudentId);
                ClsStudent::ReadStudentInfo(St1, "\nRead Student's info for add: ");
                St1.PrintStudentInfo();

                cout << "Do you want to add " << St1.GetFullname() << " : [y/n]: ";
                char answer;
                cin >> answer;
                if (tolower(answer) == 'y')
                {
                    ClsStudent::enSvResult result = St1.save();
                    switch (result)
                    {
                    case ClsStudent::enSvResult::enSvSucceeded:
                        cout << "\nStudent added succussfully\n";
                        break;

                    case ClsStudent::enSvResult::enSvFailedEmptyObejct:
                        cout << "\nOperation failed, Empty object.\n";
                        break;

                    default:
                        break;
                    }
                }
                else
                {
                    cout << "\nOperation failed.\n";
                }
            }
            else
            {
                cout << "Operation Failed.\n";
            }
        }
    }

public:
    static void ShowAddStudentScreen()
    {
        DrawScreenHeader("Add Student Screen.");
        AddStudent();
    }
};