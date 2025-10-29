#pragma once
using namespace std;
#include "../../Screen.h"

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
    static void DeleteAFile(const char *Filename)
    {
        const char *name = Filename;
        if (remove(name) == 0)
        {
            cout << "File deleted successfully.\n";
        }
        else
        {
            perror("Error Deliting File.\n");
        }
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
            string filename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Students/" + StudentId + ".txt";
            DeleteAFile(filename.c_str());
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
        DeleteStudent();
    }
};
