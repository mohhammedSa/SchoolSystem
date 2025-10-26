#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "Person.h"
using namespace std;

string TeacherFileName = "./Files/TeacherFile.txt";

class ClsTeacher : public ClsPerson
{
private:
    enum enMode
    {
        EmpyMode = 1,
        AddMode = 2,
        UpdateMode = 3
    };

    enMode _Mode;
    string _Subject;

    static string ReadString(string message)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string word;
        cout << message;
        cin >> word;
        return word;
    }

    static short ReadAge()
    {
        cout << "Enter your age: ";
        short age;
        cin >> age;
        return age;
    }

    static ClsTeacher _EmptyTeacherObject()
    {
        return ClsTeacher(enMode::EmpyMode, "", "", "", "", "", 0, "", "");
    }

    static vector<string> _Split(string line, string delim = "#//#")
    {
        vector<string> vStrings;
        int pos = 0;
        string word = "";

        while ((pos = line.find(delim)) != line.npos)
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

    static ClsTeacher _ConvertLineToObject(string line)
    {
        vector<string> vStrings = _Split(line);
        return ClsTeacher(
            enMode::UpdateMode,
            vStrings[0],
            vStrings[1],
            vStrings[2],
            vStrings[3],
            vStrings[4],
            stoi(vStrings[5]),
            vStrings[6],
            vStrings[7]);
    }

    static string _ConvertObjectToLine(ClsTeacher Teacher, string delim = "#//#")
    {
        return Teacher.GetId() + delim +
               Teacher.GetFullname() + delim +
               Teacher.GetPhoneNumber() + delim +
               Teacher.GetAdress() + delim +
               Teacher.GetEmail() + delim +
               to_string(Teacher.GetAge()) + delim +
               Teacher.getSubject() + delim +
               Teacher.GetPAssword();
    }

    static void _AddLineToFile(ClsTeacher Teacher)
    {
        fstream TeacherFile;
        TeacherFile.open(TeacherFileName, ios::out | ios::app);
        if (TeacherFile.is_open())
        {
            TeacherFile << _ConvertObjectToLine(Teacher) << "\n";
            TeacherFile.close();
        }
    }

    static void ClearFile(string filename)
    {
        fstream File;
        File.open(filename, ios::out | ios::trunc);
        File.close();
    }

    void _SaveTeachers(vector<ClsTeacher> vTeachers)
    {
        ClearFile(TeacherFileName);
        fstream TeacherFile;
        TeacherFile.open(TeacherFileName, ios::out | ios::app);
        for (ClsTeacher T : vTeachers)
        {
            _AddLineToFile(T);
        }
        TeacherFile.close();
    }

    void _AddTeacher()
    {
        _AddLineToFile(*this);
    }
    void _UpdateTeacher()
    {
        vector<ClsTeacher> vTeachers = LoadTeachers();
        for (ClsTeacher &T : vTeachers)
        {
            if (T.GetId() == this->GetId())
            {
                T = *this;
                break;
            }
        }
        _SaveTeachers(vTeachers);
    }
    void _update()
    {
        _UpdateTeacher();
    }

public:
    static string readString(string message)
    {
        string S;
        cout << message;
        getline(cin, S);
        return S;
    }
    bool isEmpty()
    {
        return _Mode == enMode::EmpyMode;
    }

    ClsTeacher() {};
    ClsTeacher(enMode mode, string ID, string fullName, string phoneNumber, string email, string adress, short age, string subject, string password)
        : ClsPerson(ID, fullName, phoneNumber, email, adress, age, password)
    {
        _Mode = mode;
        _Subject = subject;
    }

    static ClsTeacher _EmptyTeacherObjectForAdding(string teacherID)
    {
        return ClsTeacher(enMode::AddMode, teacherID, "", "", "", "", 0, "", "");
    }

    void setSubject(string subject)
    {
        _Subject = subject;
    }

    string getSubject()
    {
        return _Subject;
    }

    void setMode(enMode mode)
    {
        _Mode = mode;
    }

    enMode getMode()
    {
        return _Mode;
    }

    static void ReadTeacherInfo(ClsTeacher &Teacher)
    {
        Teacher.SetFullname(ReadString("Enter your full name: "));
        Teacher.SetPhoneNumber(ReadString("Enter your phone number: "));
        Teacher.SetEmail(ReadString("Enter your email: "));
        Teacher.SetAdress(ReadString("Enter your adress: "));
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Teacher.SetAge(ReadAge());
        Teacher.setSubject(ReadString("What is your subject: "));
        Teacher.SetPassword(ReadString("Enter teacher's password: "));
    }

    static ClsTeacher Find(string teacherId)
    {
        ClsTeacher Teacher;
        fstream TeacherFile;
        TeacherFile.open(TeacherFileName, ios::in);
        if (TeacherFile.is_open())
        {
            string line;
            while (getline(TeacherFile, line))
            {
                Teacher = _ConvertLineToObject(line);
                if (Teacher.GetId() == teacherId)
                {
                    TeacherFile.close();
                    return Teacher;
                }
            }
        }
        return _EmptyTeacherObject();
    }

    static ClsTeacher Find(string teacherId, string password)
    {
        ClsTeacher Teacher;
        fstream TeacherFile;
        TeacherFile.open(TeacherFileName, ios::in);
        if (TeacherFile.is_open())
        {
            string line;
            while (getline(TeacherFile, line))
            {
                Teacher = _ConvertLineToObject(line);
                if (Teacher.GetId() == teacherId && Teacher.GetPAssword() == password)
                {
                    TeacherFile.close();
                    return Teacher;
                }
            }
        }
        return _EmptyTeacherObject();
    }

    static bool isTeacherExists(string teacherId)
    {
        return !Find(teacherId).isEmpty();
    }

    enum enSaveResult
    {
        enSvSuccess = 1,
        enSvFailed = 2
    };

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::AddMode:
            _AddTeacher();
            _Mode = enMode::UpdateMode;
            return enSaveResult::enSvSuccess;

        case enMode::UpdateMode:
            _UpdateTeacher();
            return enSvSuccess;

        default:
            return enSaveResult::enSvFailed;
        }
    }

    static vector<ClsTeacher> LoadTeachers()
    {
        vector<ClsTeacher> Teachers;

        fstream TeachersFile;
        TeachersFile.open(TeacherFileName, ios::in);

        if (TeachersFile.is_open())
        {
            string line;
            while (getline(TeachersFile, line))
            {
                Teachers.push_back(_ConvertLineToObject(line));
            }
            TeachersFile.close();
        }
        return Teachers;
    }

    bool Delete()
    {
        vector<ClsTeacher> vTeachers = LoadTeachers();
        ClearFile(TeacherFileName);

        fstream TeacherFile;
        TeacherFile.open(TeacherFileName, ios::out | ios::app);

        for (ClsTeacher T : vTeachers)
        {
            if (TeacherFile.is_open())

                if (T.GetId() != GetId())
                {
                    TeacherFile << _ConvertObjectToLine(T) << "\n";
                }
        }
        TeacherFile.close();
        *this = _EmptyTeacherObject();
        return true;
    }

    void PrintInfo()
    {
        cout << "\nTeacher Info: \n";
        cout << "----------------------------\n";
        cout << "Teacher ID: " << GetId() << "\n";
        cout << "Teacher Fullname: " << GetFullname() << "\n";
        cout << "Teacher phone Number: " << GetPhoneNumber() << "\n";
        cout << "Teacher Email: " << GetEmail() << "\n";
        cout << "Teacher Adress: " << GetAdress() << "\n";
        cout << "Teacher Age: " << GetAge() << "\n";
        cout << "Teacher Subject: " << getSubject() << "\n";
        cout << "----------------------------\n";
    }
};