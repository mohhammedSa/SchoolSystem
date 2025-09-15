#pragma once
#include <iostream>
#include <fstream>
#include <limits>
#include "Person.h"
using namespace std;

string StudentFileName = "./Files/StudentsFile.txt";

class ClsStudent : public ClsPerson
{
private:
    enum enMode
    {
        EmptyMode = 1,
        AddMode = 2,
        updateMode = 3
    };

    string _Grade;
    enMode _mode;

    static ClsStudent _EmptyStudentObject()
    {
        return ClsStudent(enMode::EmptyMode, "", "", "", "", "", 0, "");
    }

    static string readString(string message)
    {
        string S;
        cout << message;
        getline(cin, S);
        return S;
    }

    static string ConvertStudentObjToLine(ClsStudent Student, string delim = "#//#")
    {
        return Student.GetId() + delim + Student.GetFullname() + delim + Student.GetPhoneNumber() +
               delim + Student.GetEmail() + delim + Student.GetAdress() + delim + to_string(Student.GetAge()) +
               delim + Student.getGrade();
    }

    static vector<string> Split(string line, string delim = "#//#")
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

    static ClsStudent ConvertLineToStudentObj(string line)
    {
        vector<string> vString = Split(line);
        return ClsStudent(enMode::updateMode, vString[0], vString[1], vString[2], vString[3], vString[4], stoi(vString[5]), vString[6]);
    }

    static vector<string> LoadLinesFromFile()
    {
        vector<string> vStrings;
        fstream StudentsFile;
        StudentsFile.open(StudentFileName, ios::in);
        if (StudentsFile.is_open())
        {
            string line;
            while (getline(StudentsFile, line))
            {
                vStrings.push_back(line);
            }
            StudentsFile.close();
        }
        return vStrings;
    }

    void AddStudentToFile(string filename)
    {
        fstream StudentsFile;
        StudentsFile.open(StudentFileName, ios::out | ios::app);

        if (StudentsFile.is_open())
        {
            StudentsFile << ConvertStudentObjToLine(*this) << "\n";
            StudentsFile.close();
        }
    }

    void _AddStudent()
    {
        AddStudentToFile(StudentFileName);
    }

    void ClearFile(string filename){
        fstream File;
        File.open(filename,ios::out | ios::trunc);
        File.close();
    }

    void _SaveStudentsToFile(vector<ClsStudent> Students)
    {
        ClearFile(StudentFileName);
        fstream File;
        File.open(StudentFileName, ios::out | ios::app);
        for (ClsStudent &S : Students)
        {
            if (File.is_open())
            {
                File << ConvertStudentObjToLine(S) << "\n";
            }
        }
        File.close();
    }

    void UpdateSudentInfo()
    {
        vector<ClsStudent> Students = LoadStudents();
        for (ClsStudent &S : Students)
        {
            if (S.GetId() == this->GetId())
            {
                S = *this;
                break;
            }
        }
        _SaveStudentsToFile(Students);
    }

    void _update()
    {
        UpdateSudentInfo();
    }

public:
    bool isEmpty()
    {
        return _mode == enMode::EmptyMode;
    }

    ClsStudent() {};

    ClsStudent(enMode mode, string id, string fullname, string phNumber, string email, string adress, short age, string grade)
        : ClsPerson(id, fullname, phNumber, email, adress, age)
    {
        _mode = mode;
        _Grade = grade;
    }

    static ClsStudent EmptyObjectForAdding(string id)
    {
        return ClsStudent(enMode::AddMode, id, "", "", "", "", 0, "");
    }

    static void ReadStudentInfo(ClsStudent &Student, string message)
    {
        cout << message << "\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Student.SetFullname(readString("Enter student's fullname: "));
        Student.SetPhoneNumber(readString("Enter student's phonenumber: "));
        Student.SetEmail(readString("Enter student's email: "));
        Student.SetAdress(readString("Enter student's address: "));
        short age;
        cout << "Enter Student's age: ";
        cin >> age;
        Student.SetAge(age);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Student.setGrade(readString("Enter student's grade: "));
    }

    void SetMode(enMode mode)
    {
        _mode = mode;
    }

    enMode GetMode()
    {
        return _mode;
    }

    void setGrade(string grade)
    {
        _Grade = grade;
    }
    string getGrade()
    {
        return _Grade;
    }

    static ClsStudent Find(string Id)
    {
        ClsStudent Student;
        ifstream file(StudentFileName);
        if (file.good())
        {
            fstream StudentsFile;
            StudentsFile.open(StudentFileName, ios::in);
            if (StudentsFile.is_open())
            {
                string line;
                while (getline(StudentsFile, line))
                {
                    Student = ConvertLineToStudentObj(line);
                    if (Id == Student.GetId())
                    {
                        StudentsFile.close();
                        return Student;
                    }
                }
            }
        }
        else
        {
            return _EmptyStudentObject();
        }
        return _EmptyStudentObject();
    }

    static bool isStudentExists(string id)
    {
        return !Find(id).isEmpty();
    }

    enum enSvResult
    {
        enSvSucceeded = 1,
        enSvFailedStudentIdExists = 2,
        enSvFailedEmptyObejct = 3
    };

    enSvResult save()
    {
        switch (_mode)
        {
        case enMode::EmptyMode:
            return enSvResult::enSvFailedEmptyObejct;

        case enMode::AddMode:
            _AddStudent();
            SetMode(enMode::updateMode);
            return enSvResult::enSvSucceeded;

        case enMode::updateMode:
            _update();
            return enSvResult::enSvSucceeded;

        default:
            return enSvResult::enSvFailedEmptyObejct;
        }
    }

    void PrintStudentInfo()
    {
        cout << "\nStudent Info: \n";
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

    static vector<ClsStudent> LoadStudents()
    {
        vector<ClsStudent> StudentObjects;
        vector<string> vStrings = LoadLinesFromFile();

        for (string &S : vStrings)
        {
            StudentObjects.push_back(ConvertLineToStudentObj(S));
        }
        return StudentObjects;
    }
};