#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../Logic/Teacher.h"
#include "../../Logic/Course.h"
using namespace std;

class ClsTeachingCoursesScreen : protected ClsScreen
{
private:
    static vector<string> LoadLinesFromFile(string filename)
    {
        vector<string> vStrings;
        fstream AFile;
        AFile.open(filename, ios::in);
        if (AFile.is_open())
        {
            string line;
            while (getline(AFile, line))
            {
                vStrings.push_back(line);
            }
            AFile.close();
        }
        return vStrings;
    }
    static void TeachngCoursesList()
    {
        string filename = "/home/hamouda/01_Desk/Programming/ProjectsRepo/C++_Projects/OOP_Projects/SchoolSystem/Files/Teachers/" + CurrentTeacher.GetId() + ".txt";
        vector<string> vStrings = LoadLinesFromFile(filename);

        cout << "Teacher " << CurrentTeacher.GetId() << " you are teaching:\n";
        cout << "----------------------------------\n";
        for (string S : vStrings)
        {
            ClsCourse::Find(S).PrintCourseInfo();
        }
        cout << "----------------------------------\n";
    }

public:
    static void ShowTeachingCoursesScreen()
    {
        DrawScreenHeader("Teaching Courses Screen.\n");
        TeachngCoursesList();
    }
};