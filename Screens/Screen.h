#include <iostream>
#include "../Logic/Student.h"
using namespace std;

class ClsScreen
{
private:
public:
    static void DrawScreenHeader(string title, string subtitle)
    {
        cout << "--------------------------------------------------------------\n";
        cout << "\t\t\t" << title << "\n";
        cout << "\t\t\t    " << subtitle << "\n";
        cout << "--------------------------------------------------------------\n";
    }
};