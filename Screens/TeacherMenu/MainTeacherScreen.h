#pragma once
#include <iostream>
#include "../Screen.h"
#include "01_ChooseCoursesToTeachScreen.h"
#include "02_TeachingCoursesScreen.h"
using namespace std;

class ClsMainTeacherMenuScreen : protected ClsScreen
{
private:
    enum enTeacherMenu
    {
        enChooseCourses = 1,
        enTeachingCoursesList = 2,
        enLogout = 3
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
        return enTeacherMenu(_ReadNumberInRange("Choose what do you want to do: [1->3]: ", 1, 3, "Numebr out of range."));
    }

    static void ChooseCoursesScreen()
    {
        ClsChooseCourseToTeachScreen::ShowChooseCurseScreen();
    }
    static void TeachingCoursesListScreen()
    {
        ClsTeachingCoursesScreen::ShowTeachingCoursesScreen();
    }

    static void Logout()
    {
        CurrentTeacher = ClsTeacher::Find("");
    }

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
        cout << "[1] Choose Courses To Teach.\n";
        cout << "[2] Teaching Course List.\n";
        cout << "[3] Main Menu.\n";
        cout << "---------------------------------------------\n";
        _PerformTeacherOption(_ReadTeacherMenuOption());
    }

    static void _PerformTeacherOption(enTeacherMenu option)
    {
        switch (option)
        {
        case enTeacherMenu::enChooseCourses:
            system("clear");
            ChooseCoursesScreen();
            GoBackToMainMenu();
            break;
        case enTeacherMenu::enTeachingCoursesList:
            system("clear");
            TeachingCoursesListScreen();
            GoBackToMainMenu();
            break;
        default:
            Logout();
            break;
        }
    }

public:
    static void ShowMainTeacherMenu()
    {
        ShowMainMenu();
    }
};