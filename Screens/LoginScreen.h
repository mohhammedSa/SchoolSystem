#include <iostream>
using namespace std;
#include "Screen.h"
#include "../Logic/Student.h"
#include "../Logic/Teacher.h"
#include "StudentMenu/MainStudentScreen.h"
#include "TeacherMenu/MainTeacherScreen.h"
#include "ManagerMenu/MainManagerScreen.h"
#include "../Global.h"

class ClsLoginScreen : protected ClsScreen
{
private:
    static string readString(string message)
    {

        string S;
        cout << message;
        getline(cin, S);
        return S;
    }

    static int ReadUserType()
    {
        int userType;
        cout << "\nLogin as a: " << endl;
        cout << "1. Student" << endl;
        cout << "2. Teacher" << endl;
        cout << "--------------------\n";
        cout << "Enter your choice: ";
        cin >> userType;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return userType;
    }

    static void ReadIdAndPassword(string &id, string &password)
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> password;
    }

    static void Login()
    {

        cout << "Are you a manager [y/n]: ";
        char answer;
        cin >> answer;

        if (tolower(answer) == 'y')
        {
            ClsMainManagerScreen::ShowMainManagerScreen();
        }
        else
        {
            enum enUserType
            {
                Student = 1,
                Teacher = 2
            };

            enUserType userType = (enUserType)ReadUserType();

            string id, password;

            switch (userType)
            {
            case enUserType::Student:
            {
                ReadIdAndPassword(id, password);
                ClsStudent Student = ClsStudent::Find(id, password);
                if (!Student.isEmpty())
                {
                    CurrentStudent = Student;
                    ClsMainStudentMenuScreen::ShowMainMenuScreen();
                }
                else
                {
                    cout << "Student not found!" << endl;
                }
                break;
            }

            case enUserType::Teacher:
                ReadIdAndPassword(id, password);
                ClsTeacher Teacher = ClsTeacher::Find(id, password);
                if (!Teacher.isEmpty())
                {
                    CurrentTeacher = Teacher;
                    ClsMainTeacherMenuScreen::ShowMainTeacherMenu();
                }
                else
                {
                    cout << "Teacher not found!" << endl;
                }
                break;
            }
        }
    };

public:
    static void ShowLoginScreen()
    {
        system("clear");
        DrawScreenHeader("Login Screen.");
        Login();
    }
};