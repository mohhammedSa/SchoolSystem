#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../Logic/Teacher.h"
#include "../../Logic/Course.h"
using namespace std;

class ClsAddTeachersScreen : protected ClsScreen
{
private:
    static void CreateAnEmptyFile(string filename)
    {
        fstream aFile;
        aFile.open(filename, ios::out);
        aFile.close();
    }
    static string _ReadString(string message)
    {
        string S;
        cout << message;
        cin >> S;
        return S;
    }

    static string ReadTeacherCourse()
    {
        vector<ClsCourse> Courses = ClsCourse::LoadCourses();
        string course = "";
        cout << "what is the course do you teach: \n";
        for (ClsCourse C : Courses)
        {
            cout << "Do you teach:  " + C.GetCoursename() << " [y/n]: ";
            char answer;
            cin >> answer;
            if (tolower(answer) == 'y')
            {
                course = C.GetCoursename();
                break;
            }
        }
        return course;
    }

    static void _AddTeacher()
    {
        string teacherId = _ReadString("Enter Id: ");
        ClsTeacher Teacher = ClsTeacher::Find(teacherId);

        if (Teacher.isTeacherExists(teacherId))
        {
            cout << "\nTeacher already exists\n";

            Teacher.PrintInfo();
        }
        else
        {
            Teacher = ClsTeacher::_EmptyTeacherObjectForAdding(teacherId);
            ClsTeacher::ReadTeacherInfo(Teacher);
            Teacher.setSubject(ReadTeacherCourse());
            ClsTeacher::enSaveResult result = Teacher.Save();
            string filename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Teachers/" + teacherId + ".txt";
            switch (result)
            {
            case ClsTeacher::enSaveResult::enSvSuccess:
                cout << "Teacher added successfully.\n";
                Teacher.PrintInfo();
                CreateAnEmptyFile(filename);
                break;

            default:
                cout << "Operation Failled\n";
                break;
            }
        }
    }

public:
    static void ShowAddTeacherScreen()
    {
        DrawScreenHeader("Add Teacher screen.");
        _AddTeacher();
    }
};