#include <iostream>
using namespace std;

class ClsPerson
{
private:
    string _ID, _FullName, _PhoneNumber, _Email, _Adress;
    short _Age;

public:
    
    ClsPerson(){};
    ClsPerson(string ID, string fullName, string phoneNumber, string email, string adress, short age)
    {
        _ID = ID;
        _FullName = fullName;
        _PhoneNumber = phoneNumber;
        _Email = email;
        _Adress = adress;
        _Age = age;
    }

    string GetId()
    {
        return _ID;
    }

    void SetFullname(string fullname)
    {
        _FullName = fullname;
    }
    string GetFullname()
    {
        return _FullName;
    }

    void SetPhoneNumber(string phNumber)
    {
        _PhoneNumber = phNumber;
    }
    string GetPhoneNumber()
    {
        return _PhoneNumber;
    }

    void SetEmail(string email)
    {
        _Email = email;
    }
    string GetEmail()
    {
        return _Email;
    }

    void SetAdress(string adress)
    {
        _Adress = adress;
    }
    string GetAdress()
    {
        return _Adress;
    }

    void SetAge(short age)
    {
        _Age = age;
    }
    short GetAge()
    {
        return _Age;
    }
};