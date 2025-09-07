#include <iostream>
#include "./Logic/Student.h"
using namespace std;

string StudentFileName = "./Files/StudentsFile.txt";

string ConvertStudentObjToLine(ClsStudent Student, string delim = "#//#")
{
    return Student.GetId() + delim + Student.GetFullname() + delim + Student.GetPhoneNumber() +
           delim + Student.GetEmail() + delim + Student.GetAdress() + delim + to_string(Student.GetAge()) +
           delim + Student.getGrade();
}

void AddStudent()
{
}

int main()
{
    ClsStudent st1("1", "Mohammed Sabbar", "11111111", "ha@gmail.com", "42, Sale", 30, "Shi haja");
    st1.PrintStudentInfo();
    cout << "\n"
         << ConvertStudentObjToLine(st1) << "\n";
}