#pragma once
#include <iostream>
#include "../Screen.h"
#include "ManageStudents/MainStudentsScreen.h"
#include "../TeacherMenu/MainTeacherScreen.h"
#include "../CourseMenu/MainMenu.h"
using namespace std;

class ClsMainManagerScreen : protected ClsScreen
{
private:
    enum enManagerOptions
    {
        enManageStudents = 1,
        enManageTeachers = 2,
        enManageCourses = 3,
        enLogout = 4
    };

    static short ReadNumberInRange(string message, short from, short to, string errorMsg = "Out of range.")
    {

        short number;
        bool answer = false;
        do
        {
            if (answer == true)
            {
                cout << "\n"
                     << errorMsg << "\n";
            }

            cout << message;
            cin >> number;
            answer = (number < from || number > to);
        } while (answer);

        return number;
    }

    static enManagerOptions ReadManagerOption()
    {
        return (enManagerOptions)ReadNumberInRange("Choose what do you want: [1 -> 4]: ", 1, 4);
    }

    static void ManagerMenu()
    {
        system("clear");
        DrawScreenHeader("Main Manager Screen.");
        cout << "[1] Manage Students.\n";
        cout << "[2] Manage Teachers.\n";
        cout << "[3] Manage Courses.\n";
        cout << "[4] Logout.\n";
        cout << "---------------------------------\n";
        PerformManageOptions(ReadManagerOption());
    }

    static void ReturnToMainMenu()
    {
        cout << "Press any key to go back to main menu..." << flush;
        system("bash -c 'read'");
        ManagerMenu();
    }

    static void PerformManageOptions(enManagerOptions option)
    {
        switch (option)
        {
        case enManagerOptions::enManageStudents:
            ClsMainStudentsMenuScreen::ShowMainMenuScreen();
            ManagerMenu();
            break;

        case enManagerOptions::enManageTeachers:
            ClsMainTeacherMenuScreen::ShowMainTeacherMenu();
            ManagerMenu();
            break;

        case enManagerOptions::enManageCourses:
            ClsCourseMainMenu::ShowMainMenuScreen();
            ManagerMenu();
            break;

        case enManagerOptions::enLogout:
            break;

        default:
            break;
        }
    }

public:
    static void ShowMainManagerScreen()
    {
        ManagerMenu();
    }
};