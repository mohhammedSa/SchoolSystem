#include <iostream>
#include <vector>
#include "./Logic/Student.h"
using namespace std;

string StFileName = "./Files/StudentsFile.txt";

/* string ConvertStudentObjToLine(ClsStudent Student, string delim = "#//#")
{
    return Student.GetId() + delim + Student.GetFullname() + delim + Student.GetPhoneNumber() +
           delim + Student.GetEmail() + delim + Student.GetAdress() + delim + to_string(Student.GetAge()) +
           delim + Student.getGrade();
}

vector<string> Split(string line, string delim = "#//#")
{
    vector<string> vStrings;
    short pos = 0;
    string word = "";

    while ((pos = line.find("#//#")) != line.npos)
    {
        word = line.substr(0, pos);
        if (word != "")
        {
            vStrings.push_back(word);
        }
        line.erase(0, pos + delim.length());
    }

    if (line != "")
    {
        vStrings.push_back(line);
    }

    return vStrings;
}

ClsStudent ConvertLineToStudentObj(string line)
{
    vector<string> vString = Split(line);
    return ClsStudent(1,vString[0], vString[1], vString[2], vString[3], vString[4], stoi(vString[5]), vString[6]);
} */

string readString(string message)
{
    string S;
    cout << message;
    cin >> message;
    return S;
}

void AddStudent()
{
    string StudentId = readString("Enter student Id: ");
    ClsStudent St1 = ClsStudent::Find(StudentId);
    if (St1.isStudentExists(StudentId))
    {
        St1.PrintStudentInfo();
    }
    else
    {
        cout << "Student does not exist.\n";
    }
}

int main()
{
    AddStudent();
}