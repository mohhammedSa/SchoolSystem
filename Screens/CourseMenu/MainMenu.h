#pragma once
#include <iostream>
#include "../Screen.h"
#include "01_ListCoursesScreen.h"
#include "02_AddCourseScreen.h"
#include "03_UpdateCourseScreen.h"
#include "04_DeleteCourseScreen.h"
using namespace std;

class ClsCourseMainMenu : protected ClsScreen
{
private:
    enum enMenuOption
    {
        enListCourses = 1,
        enAddCourse = 2,
        enUpdateCourse = 3,
        enDeleteCourse = 4,
        enLogout = 5
    };

    static short ReadNumberInRange(string message, short from, short to, string errorMsg)
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

    static enMenuOption ReadOption()
    {
        short Option = ReadNumberInRange("Choose what do you want to do: [1/5]: ", 1, 5, "Out of range");
        return enMenuOption(Option);
    }

    static void GoBackToMainMenu()
    {
        cout << "Press any key to go back to main menu..." << flush;
        system("bash -c 'read'");
        ShowMainMenu();
    }

    static void ListCoursesScreen() { ClsListCoursesScreen::ShowCoursesListScreen(); }
    static void AddCourseScreen() { ClsAddCourseScreen::ShowAddCourseScreen(); }
    static void UpdateCourseScreen() { ClsUpdateCourseScreen::ShowUpdateCourseScreen(); }
    static void DeleteCourseScreen() { ClsDeleteCourseScreen::ShowDeleteCourseScreen(); }
    static void Logout() {}

    static void _PerformMenuOption(enMenuOption Option)
    {
        switch (Option)
        {
        case enMenuOption::enListCourses:
            system("clear");
            ListCoursesScreen();
            GoBackToMainMenu();
            break;
        case enMenuOption::enAddCourse:
            system("clear");
            AddCourseScreen();
            GoBackToMainMenu();
            break;
        case enMenuOption::enUpdateCourse:
            system("clear");
            UpdateCourseScreen();
            GoBackToMainMenu();
            break;
        case enMenuOption::enDeleteCourse:
            system("clear");
            DeleteCourseScreen();
            GoBackToMainMenu();
            break;
        default:
            Logout();
            break;
        }
    }

    static void ShowMainMenu()
    {
        system("clear");
        DrawScreenHeader("Courses Screen.");
        cout << "[1] List Courses.\n";
        cout << "[2] Add Course.\n";
        cout << "[3] Update Course.\n";
        cout << "[4] Delete Course.\n";
        cout << "[5] Logout.\n";
        cout << "-------------------------\n";
        _PerformMenuOption(ReadOption());
    }

public:
    static void ShowMainMenuScreen()
    {
        ShowMainMenu();
    }
};