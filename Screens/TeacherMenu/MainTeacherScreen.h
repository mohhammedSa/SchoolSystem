#pragma once
#include <iostream>
#include "../Screen.h"
#include "01_ListTeachersScreen.h"
#include "02_FindTeacherScreen.h"
#include "03_AddTeacherScreen.h"
#include "04_UpdateTeacherScreen.h"
#include "05_DeleteTeacherScreen.h"
using namespace std;

class ClsMainTeacherMenuScreen : protected ClsScreen
{
private:
    enum enTeacherMenu
    {
        enListTeachers = 1,
        enAddTeacher = 2,
        enFindTeacher = 3,
        enUpdateTeacher = 4,
        enDeleteTeacher = 5,
        enLogout = 6
    };

    static short _ReadNumberInRange(string message, short from, short to, string errorMsg)
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

    static enTeacherMenu _ReadTeacherMenuOption()
    {
        return enTeacherMenu(_ReadNumberInRange("Choose what do you want ot do: [1/6]: ", 1, 6, "Numebr out of range."));
    }

    static void ListTeachersScreen()
    {
        ClsListTeachersScreen::ShowListTeachersScreen();
    }
    static void FindTeacherScreen()
    {
        ClsFindTeacherScreen::ShowFindTeacherScreen();
    }
    static void AddTeacherScreen()
    {
        ClsAddTeachersScreen::ShowAddTeacherScreen();
    }
    static void UpdateTeacherScreen()
    {
        ClsUpdateTeachersScreen::ShowUpdateTeachersScreen();
    }
    static void DeleteTeacherScreen()
    {
        ClsDeleteTeachersScreen::ShowDeleteTeachersScreen();
    }
    static void Logout() {}

    static void GoBackToMainMenu()
    {
        cout << "Press any key to go back to main menu..." << flush;
        system("bash -c 'read'");
        ShowMainMenu();
    }

    static void ShowMainMenu()
    {
        system("clear");
        DrawScreenHeader("Teacher Menu Screen.");
        cout << "[1] Teachers List.\n";
        cout << "[2] Add Teacher.\n";
        cout << "[3] Find Teacher.\n";
        cout << "[4] Update Teacher.\n";
        cout << "[5] Delete Teacher.\n";
        cout << "[6] Logout.\n";
        cout << "---------------------------------------------\n";
        _PerformTeacherOption(_ReadTeacherMenuOption());
    }

    static void _PerformTeacherOption(enTeacherMenu option)
    {
        switch (option)
        {
        case enTeacherMenu::enListTeachers:
            system("clear");
            ListTeachersScreen();
            GoBackToMainMenu();
            break;
        case enTeacherMenu::enFindTeacher:
            system("clear");
            FindTeacherScreen();
            GoBackToMainMenu();
            break;
        case enTeacherMenu::enAddTeacher:
            system("clear");
            AddTeacherScreen();
            GoBackToMainMenu();
            break;
        case enTeacherMenu::enUpdateTeacher:
            system("clear");
            UpdateTeacherScreen();
            GoBackToMainMenu();
            break;
        case enTeacherMenu::enDeleteTeacher:
            system("clear");
            DeleteTeacherScreen();
            GoBackToMainMenu();
            break;
        default:
            Logout();
            break;
        }
    }

public:
    static void ShowMainStudentMenu()
    {
        ShowMainMenu();
    }
};