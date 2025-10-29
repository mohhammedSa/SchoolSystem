#pragma once
#include <iostream>
#include "../../Screen.h"
#include "../../../Logic/Student.h"
#include "../../../Global.h"
using namespace std;

class ClasAddStudentScreen : protected ClsScreen
{
private:
    static void CreateAnEmptyFile(string filename)
    {
        fstream aFile;
        aFile.open(filename, ios::out);
        aFile.close();
    }
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
        ClsStudent Student = ClsStudent::Find(StudentId);
        if (Student.isStudentExists(StudentId))
        {
            Student.PrintStudentInfo();
        }
        else
        {
            cout << "Student does not exist.\n\n";
            cout << "Do you want to add student with id : " << StudentId << " [y/n]: ";
            char answer;
            cin >> answer;

            if (tolower(answer) == 'y')
            {
                Student = ClsStudent::EmptyObjectForAdding(StudentId);
                ClsStudent::ReadStudentInfo(Student, "\nRead Student's info for add: ");
                Student.PrintStudentInfo();

                cout << "Do you want to add " << Student.GetFullname() << " : [y/n]: ";
                char answer;
                cin >> answer;

                
                string filename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Students/" + Student.GetId() + ".txt";
                if (tolower(answer) == 'y')
                {
                    ClsStudent::enSvResult result = Student.save();
                    switch (result)
                    {
                    case ClsStudent::enSvResult::enSvSucceeded:
                        cout << "\nStudent added succussfully\n";
                        CurrentStudent = Student;
                        CreateAnEmptyFile(filename);
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