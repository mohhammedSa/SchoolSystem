#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Person.h"
using namespace std;

string ManageFileName = "Files/ManagersFile.txt";

class ClsManager : public ClsPerson
{
private:
    enum enMode
    {
        emptyMode = 1,
        addMode = 2,
        updateMode = 3
    };

    enMode _Mode;

    static vector<string> Split(string line, string delim = "#//#")
    {
        vector<string> vStrings;
        short pos = 0;
        string word = "";

        while ((pos = (line.find(delim))) != line.npos)
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

    static string ConvertManagerObjToLine(ClsManager Manager, string delim = "#//#")
    {
        return Manager.GetId() + delim + Manager.GetFullname() + delim + Manager.GetPhoneNumber() +
               delim + Manager.GetEmail() + delim + Manager.GetAdress() + delim + to_string(Manager.GetAge()) + delim + Manager.GetPAssword();
    }

    static ClsManager ConvertLineToManagerObj(string line)
    {
        vector<string> vString = Split(line);
        return ClsManager(enMode::updateMode,
                          vString[0], vString[1], vString[2], vString[3], vString[4], stoi(vString[5]), vString[6]);
    }

    static vector<string> LoadLinesFromFile()
    {
        vector<string> vStrings;
        fstream ManagerFile;

        ManagerFile.open(ManageFileName, ios::in);
        if (ManagerFile.is_open())
        {
            string line;
            while (getline(ManagerFile, line))
            {
                vStrings.push_back(line);
            }
            ManagerFile.close();
        }
        return vStrings;
    }

    static ClsManager _EmptyManagerObject()
    {
        return ClsManager(enMode::emptyMode, "", "", "", "", "", 0, "");
    }

    void AddLineToFile(string filename, string line)
    {
        fstream ManagerFile;
        ManagerFile.open(filename, ios::out | ios::app);

        if (ManagerFile.is_open())
        {
            ManagerFile << line << "\n";
        }
        ManagerFile.close();
    }

    void _AddManager()
    {
        AddLineToFile(ManageFileName, ConvertManagerObjToLine(*this));
    }

public:
    ClsManager() : ClsPerson() {};
    ClsManager(enMode mode, string ID, string fullName, string phoneNumber, string email, string adress, short age, string password)
        : ClsPerson(ID, fullName, phoneNumber, email, adress, age, password)
    {
        _Mode = mode;
    }

    bool isEmpty()
    {
        return _Mode == enMode::emptyMode;
    }

    void SetMode(enMode mode)
    {
        _Mode = mode;
    }

    enMode GetMode()
    {
        return _Mode;
    }

    static string readString(string message)
    {
        string S;
        cout << message;
        getline(cin, S);
        return S;
    }

    static short readNumber(string message)
    {
        short Number;
        cout << message;
        cin >> Number;
        return Number;
    }

    static ClsManager EmptyObjForAdding(string id)
    {
        return ClsManager(enMode::addMode, id, "", "", "", "", 0, "");
    }

    static void ReadManagerInfo(ClsManager &Manager)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Manager.SetFullname(readString("Enetr Full name: "));
        Manager.SetPhoneNumber(readString("Enter your phoneNumber: "));
        Manager.SetEmail(readString("Enter your Email: "));
        Manager.SetAdress(readString("Enter your address: "));
        Manager.SetAge(readNumber("How old are you: "));
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Manager.SetPassword(readString("Enter a Password: "));
    }

    static ClsManager Find(string id)
    {
        ClsManager Manager;
        fstream File;
        File.open(ManageFileName, ios::in);

        if (File.is_open())
        {
            string line;
            while (getline(File, line))
            {
                Manager = ConvertLineToManagerObj(line);
                if (Manager.GetId() == id)
                {
                    File.close();
                    return Manager;
                }
            }
            File.close();
        }
        return _EmptyManagerObject();
    }
    static ClsManager Find(string id, string password)
    {
        ClsManager Manager;
        fstream File;
        File.open(ManageFileName, ios::in);

        if (File.is_open())
        {
            string line;
            while (getline(File, line))
            {
                Manager = ConvertLineToManagerObj(line);
                if (Manager.GetId() == id && Manager.GetPAssword() == password)
                {
                    File.close();
                    return Manager;
                }
            }
            File.close();
        }
        return _EmptyManagerObject();
    }

    static bool isManagerExist(string id)
    {
        return !Find(id).isEmpty();
    }

    enum enSaveResult
    {
        enSvSuceed = 1,
        enSvFailed = 2
    };

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::addMode:
            _AddManager();
            SetMode(enMode::updateMode);
            return enSvSuceed;

        case enMode::updateMode:
            return enSvSuceed;

        default:
            return enSvFailed;
        }
    }

    static vector<ClsManager> LoadManagers()
    {
        vector<ClsManager> vManagers;
        vector<string> vStrings = LoadLinesFromFile();

        for (string s : vStrings)
        {
            vManagers.push_back(ConvertLineToManagerObj(s));
        }
        return vManagers;
    }

    void PrintManagerInfo()
    {
        cout << "\nManager Info: \n";
        cout << "-----------------------------------\n";
        cout << "Mode             : " << GetMode() << "\n";
        cout << "Manager Id       : " << GetId() << "\n";
        cout << "Manager Fullname : " << GetFullname() << "\n";
        cout << "Manager phNumber : " << GetPhoneNumber() << "\n";
        cout << "Manager Email    : " << GetEmail() << "\n";
        cout << "Manager Adress   : " << GetAdress() << "\n";
        cout << "Manager Age      : " << GetAge() << "\n";
        cout << "-----------------------------------\n";
    }
};
