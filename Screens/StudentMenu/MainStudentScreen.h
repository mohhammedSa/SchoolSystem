
#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../Logic/Course.h"
#include "./01_ShowEnrolledCoursesScreen.h"
#include "./02_EnrollInCourseScreen.h"
using namespace std;

class ClsMainStudentMenuScreen : protected ClsScreen
{
private:
    enum enMainStudentMenuOption
    {
        enShowEnrolledCourses = 1,
        enAvailableCourses = 2,
        enLogout = 3
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

    static void ShowEnrolledCourses()
    {
        ClsShowEnrolledCoursesScreen::ShowEnroledCoursesScreen();
    }
    static void EnrollInCourse()
    {
        ClsEnrollInCourseScreen::ShowEnrollInCourseScreen();
    }
    static void Logout()
    {
        CurrentStudent = ClsStudent::Find("");
    }

    static enMainStudentMenuOption ReadOption()
    {
        return (enMainStudentMenuOption)ReadNumberInRange("Choose what you want to do: [1 to 3]: ", 1, 3, "Number out of range.");
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

        case enMainStudentMenuOption::enShowEnrolledCourses:
            system("clear");
            ShowEnrolledCourses();
            ReturnToMainMenu();
            break;

        case enMainStudentMenuOption::enAvailableCourses:
            system("clear");
            EnrollInCourse();
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
        cout << "[1] Show Enroleld Courses.\n";
        cout << "[2] Enroll In Courses\n";
        cout << "[3] Main Menu\n";
        cout << "------------------------------\n";
        PerformMainOption(ReadOption());
    }

public:
    static void ShowMainMenuScreen()
    {
        ShowMainMenu();
    }
};