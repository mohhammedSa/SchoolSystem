#include <iostream>
#include "../Screen.h"
#include "../../Logic/Course.h"
#include "./01_ListStudentsScreen.h"
#include "./02_AddStudentScreen.h"
#include "./03_FindStudentScree.h"
#include "./04_UpdateStudentscreen.h"
#include "./05_DeleteStudentScreen.h"
#include "./06_EnrollInCourseScreen.h"
using namespace std;

class ClsMAinStudentMenuScreen : protected ClsScreen
{
private:
    enum enMainStudentMEnuOption
    {
        enListStudents = 1,
        enAddStudent = 2,
        enFidStudent = 3,
        enUpdteStudent = 4,
        enDeleteStudent = 5,
        enAvailableCourses = 6,
        enLogout = 7
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
    static void EnrollInCourse()
    {
        ClsEnrollInCourseScreen::ShowEnrollInCourseScreen();
    }
    static void Logout() {}

    static enMainStudentMEnuOption ReadOption()
    {
        return (enMainStudentMEnuOption)ReadNumberInRange("Choose what you want to do: [1 to 6]: ", 1, 7, "Number out of range.");
    }

    static void ReturnToMainMenu()
    {
        cout << "Press any key to go back to main menu..." << flush;
        system("bash -c 'read'");
        ShowMainMenu();
    }

    static void PerformMainOption(enMainStudentMEnuOption option)
    {
        switch (option)
        {
        case enMainStudentMEnuOption::enListStudents:
            system("clear");
            StudentsList();
            ReturnToMainMenu();
            break;

        case enMainStudentMEnuOption::enAddStudent:
            system("clear");
            AddStudent();
            ReturnToMainMenu();
            break;

        case enMainStudentMEnuOption::enFidStudent:
            system("clear");
            FindStudents();
            ReturnToMainMenu();
            break;

        case enMainStudentMEnuOption::enUpdteStudent:
            system("clear");
            UpdateStudents();
            ReturnToMainMenu();
            break;

        case enMainStudentMEnuOption::enDeleteStudent:
            system("clear");
            DeleteStudents();
            ReturnToMainMenu();
            break;

        case enMainStudentMEnuOption::enAvailableCourses:
            system("clear");
            EnrollInCourse();
            ReturnToMainMenu();
            break;

        case enMainStudentMEnuOption::enLogout:
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
        cout << "[6] Enroll In Courses\n";
        cout << "[7] Logout\n";
        cout << "------------------------------\n";
        PerformMainOption(ReadOption());
    }

public:
    static void ShowMainMenuScreen()
    {
        ShowMainMenu();
    }
};