#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../Logic/Teacher.h"
using namespace std;

class ClsDeleteTeachersScreen : protected ClsScreen
{
private:
    static string _ReadString(string message)
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

    static void _DeleteTeacher()
    {
        string teacherId = _ReadString("Enter teacher id: ");
        ClsTeacher Teacher = ClsTeacher::Find(teacherId);

        if (!Teacher.isTeacherExists(teacherId))
        {
            cout << "Teacher does not exist.\n";
        }
        else
        {
            Teacher.PrintInfo();
            cout << "Do you want to delete this teacher: [y/n]: ";
            char answer;
            cin >> answer;
            if (tolower(answer) == 'y')
            {
                Teacher.Delete();
                string filename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Teachers/" + teacherId + ".txt";;
                DeleteAFile(filename.c_str());
                cout << "\nTeacher deleted successfully.";
                Teacher.PrintInfo();
            }
        }
    }

public:
    static void ShowDeleteTeachersScreen()
    {
        DrawScreenHeader("Delete Teacher Screen.");
        _DeleteTeacher();
    }
};