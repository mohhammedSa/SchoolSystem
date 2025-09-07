#include <iostream>
#include "Person.h"
using namespace std;

class ClsStudent : public ClsPerson
{
private:
    string _Grade;

public:
    ClsStudent(string id, string fullname, string phNumberm, string email, string adress, short age, string grade)
        : ClsPerson(id, fullname, phNumberm, email, adress, age)
    {
        _Grade = grade;
    }

    void setGrade(string grade)
    {
        _Grade = grade;
    }
    string getGrade()
    {
        return _Grade;
    }

    void PrintStudentInfo()
    {
        cout << "Student Info: \n";
        cout << "-----------------------------------\n";
        cout << "Student Id       : " << GetId() << "\n";
        cout << "Student Fullname : " << GetFullname() << "\n";
        cout << "Student phNumber : " << GetPhoneNumber() << "\n";
        cout << "Student Email    : " << GetEmail() << "\n";
        cout << "Student Adress   : " << GetAdress() << "\n";
        cout << "Student Age      : " << GetAge() << "\n";
        cout << "Student Grade    : " << getGrade() << "\n";
        cout << "-----------------------------------\n";
    }
};