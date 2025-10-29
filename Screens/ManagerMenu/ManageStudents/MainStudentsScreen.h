
#pragma once
#include <iostream>
#include "../../Screen.h"
#include "../../../Logic/Course.h"
#include "01_ListStudentsScreen.h"
#include "02_AddStudentScreen.h"
#include "03_FindStudentScree.h"
#include "04_UpdateStudentscreen.h"
#include "05_DeleteStudentScreen.h"
using namespace std;

class ClsMainStudentsMenuScreen : protected ClsScreen
{
private:
    enum enMainStudentMenuOption
    {
        enListStudents = 1,
        enAddStudent = 2,
        enFidStudent = 3,
        enUpdteStudent = 4,
        enDeleteStudent = 5,
        enLogout = 6
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

    static void StudentsList()
    {
        ClsListStudentsScreen::ShowListStudentsScreen();
    }
    static void AddStudent()
    {
        ClasAddStudentScreen::ShowAddStudentScreen();
    }
    static void FindStudents()
    {
        ClsFindStudentScreen::ShowFindStudentScreen();
    }
    static void UpdateStudents()
    {
        ClsUpdateStudentscreen::ShowUpdateStudentScreen();
    }
    static void DeleteStudents()
    {
        ClsDeleteStudentScreen::ShowDeleteStudentScreen();
    }
    static void Logout()
    {
        CurrentStudent = ClsStudent::Find("");
    }

    static enMainStudentMenuOption ReadOption()
    {
        return (enMainStudentMenuOption)ReadNumberInRange("Choose what you want to do: [1 to 6]: ", 1, 6, "Number out of range.");
    }

    static void ReturnToMainMenu()
    {
        cout << "Press any key to go back to main menu..." << flush;
        system("bash -c 'read'");
        ShowMainMenu();
    }

    static void PerformMainOption(enMainStudentMenuOption option)
    {
        switch (option)
        {
        case enMainStudentMenuOption::enListStudents:
            system("clear");
            StudentsList();
            ReturnToMainMenu();
            break;

        case enMainStudentMenuOption::enAddStudent:
            system("clear");
            AddStudent();
            ReturnToMainMenu();
            break;

        case enMainStudentMenuOption::enFidStudent:
            system("clear");
            FindStudents();
            ReturnToMainMenu();
            break;

        case enMainStudentMenuOption::enUpdteStudent:
            system("clear");
            UpdateStudents();
            ReturnToMainMenu();
            break;

        case enMainStudentMenuOption::enDeleteStudent:
            system("clear");
            DeleteStudents();
            ReturnToMainMenu();
            break;

        case enMainStudentMenuOption::enLogout:
            Logout();
            break;

        default:
            break;
        }
    }

    static void ShowMainMenu()
    {
        system("clear");
        DrawScreenHeader("Main Student Menu.");
        cout << "[1] List Students.\n";
        cout << "[2] Add Student.\n";
        cout << "[3] Find Student.\n";
        cout << "[4] Update Student.\n";
        cout << "[5] Delete Student.\n";
        cout << "[6] Main Menu\n";
        cout << "------------------------------\n";
        PerformMainOption(ReadOption());
    }

public:
    static void ShowMainMenuScreen()
    {
        ShowMainMenu();
    }
};