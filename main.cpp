#include <iostream>
#include <vector>
#include <iomanip>
#include "./Logic/Course.h"
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    cin >> word;
    return word;
}

void DeleteCourse()
{
    string CourseId = ReadString("Enter course Id: ");
    ClsCourse Course = ClsCourse::Find(CourseId);

    if (Course.GetId() == CourseId)
    {
        Course.PrintCourseInfo();
        char answer;
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            Course.Delete();
            cout << "Course deleted successfully.\n";
        }
        else
        {
            cout << "Operation Failed.\n";
        }
    }
    else
    {
        cout << "Course does not exist.\n";
    }
}

void UpdateCourse()
{
    string CourseId = ReadString("Enter course Id: ");
    ClsCourse Course = ClsCourse::Find(CourseId);

    if (Course.GetId() == CourseId)
    {
        Course.PrintCourseInfo();

        cout << "Do you want to update this course: [y/n]: ";
        char answer;
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            ClsCourse::ReadCourseInfo(Course);
            Course.Update();
            Course.PrintCourseInfo();
        }
    }
}

void AddCourse()
{
    string CourseId = ReadString("Enter course Id: ");
    ClsCourse Course = ClsCourse::Find(CourseId);

    if (Course.GetId() == CourseId)
    {
        Course.PrintCourseInfo();
    }
    else
    {
        ClsCourse::ReadCourseInfo(Course);
        cout << "Do you want to add this course: [y/n]: ";
        char answer;
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            Course.AddCourse();
            cout << "\nCourse added successfully.\n";
            Course.PrintCourseInfo();
        }
        else
        {
            cout << "\nOperation Failed.\n";
        }
    }
}
int main()
{
    AddCourse();
}