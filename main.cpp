#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Screens/StudentMenu/MainStudentScreen.h"
#include "Logic/Student.h"
using namespace std;

void CreateAnEmptyFile(string filename)
{
    fstream aFile;
    aFile.open(filename, ios::out);
    aFile.close();
}

int main()
{
    ClsMAinStudentMenuScreen::ShowMainMenuScreen();
}