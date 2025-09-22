#pragma once
#include <iostream>
#include "./Screen.h"
using namespace std;

class ClsUpdateStudentscreen : protected ClsScreen
{
private:
    static string readString(string message)
    {
        string S;
        cout << message;
        cin >> S;
        return S;
    }
    static void UpdateStudent()
    {
        string StudentId = readString("Enter student Id: ");
        ClsStudent St1 = ClsStudent::Find(StudentId);
        if (St1.isStudentExists(StudentId))
        {
            St1.PrintStudentInfo();
            ClsStudent::ReadStudentInfo(St1, "\nRead Student's info for update: ");
            St1.PrintStudentInfo();

            cout << "\nDo you want to update " << St1.GetFullname() << " : [y/n]: ";
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
                cout << "Operation Failed.\n";
            }
        }
        else
        {
            cout << "Student does not exist./";
        }
    }

public:
    static void ShowUpdateStudentScreen()
    {
        DrawScreenHeader("Updte Student Screen.");
        UpdateStudent();
    }
};
