#include <iostream>
#include <vector>
#include <iomanip>
#include "./Logic/Teacher.h"
#include "Screens/TeacherMenu/MainTeacherScreen.h"
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    cin >> word;
    return word;
}

void addTeacher()
{
    string id = ReadString("Enter Id: ");
    ClsTeacher Teacher = ClsTeacher::Find(id);
    if (Teacher.isTeacherExists(id))
    {
        cout << "\nTeacher Already exists.\n\n";
        Teacher.PrintInfo();
    }
    else
    {
        cout << "Teacher does not exist.\n";
        Teacher = ClsTeacher::_EmptyTeacherObjectForAdding(id);
        ClsTeacher::ReadTeacherInfo(Teacher);
        Teacher.Save();
        Teacher.PrintInfo();
    }
}

void updateTeacher()
{
    string id = ReadString("Enter Id: ");
    ClsTeacher Teacher = ClsTeacher::Find(id);
    if (Teacher.isTeacherExists(id))
    {
        cout << "\nTeacher exists.\n\n";
        Teacher.PrintInfo();
        ClsTeacher::ReadTeacherInfo(Teacher);
        Teacher.Save();
        Teacher.PrintInfo();
    }
    else
    {
        cout << "Teacher does not exist.\n";
    }
}

void Delete()
{
    string id = ReadString("Enter Id: ");
    ClsTeacher Teacher = ClsTeacher::Find(id);
    if (Teacher.isTeacherExists(id))
    {
        cout << "\nTeacher exists.\n\n";
        Teacher.PrintInfo();
        Teacher.Delete();
    }
    else
    {
        cout << "eacher does not exist.\n";
    }
}

int main()
{
    ClsMainTeacherMenuScreen::ShowMainStudentMenu();
}