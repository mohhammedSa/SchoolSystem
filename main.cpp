#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Screens/ManagerMenu/MainManagerScreen.h"
#include "Screens/LoginScreen.h"
#include "Logic/Manager.h"
#include "Screens/StudentMenu/01_ShowEnrolledCoursesScreen.h"
using namespace std;

void CreateAnEmptyFile(string filename)
{
    fstream aFile;
    aFile.open(filename, ios::out);
    aFile.close();
}

void AddManagerScreen()
{
    string ManagerId;
    cout << "Enter manager id: ";
    cin >> ManagerId;
    ClsManager Manager = ClsManager::Find(ManagerId);
    if (Manager.isManagerExist(ManagerId))
    {
        cout << "\nManager already exist.\n";
    }
    else
    {
        Manager = ClsManager::EmptyObjForAdding(ManagerId);
        ClsManager::ReadManagerInfo(Manager);

        ClsManager::enSaveResult result = Manager.Save();
        switch (result)
        {
        case ClsManager::enSaveResult::enSvSuceed:
            cout << "\nManager added successfully.\n";
            Manager.PrintManagerInfo();
            break;

        default:
            cout << "\nOperation Failed.\n";
            break;
        }
    }
}

static void DeleteAFile(const char *Filename)
{
    const char *name = Filename;
    if (remove(name) == 0)
    {
        cout << "File deleted successfully.\n";
    }
    else
    {
        perror("Error Deliting File.\n");
    }
}

int main()
{
    while (true)
    {
        ClsLoginScreen::ShowLoginScreen();
    }
    return 0;
}