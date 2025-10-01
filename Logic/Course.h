#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string CourseFileName = "./Files/CourseFile.txt";

class ClsCourse
{
private:
    string CourseId, CoursName, AssignedTeacherId;

    static vector<string> _LoadLinesFromFile()
    {
        vector<string> vStrings;
        fstream CourcesFile;
        CourcesFile.open(CourseFileName, ios::in);

        if (CourcesFile.is_open())
        {
            string line;
            while (getline(CourcesFile, line))
            {
                vStrings.push_back(line);
            }
            CourcesFile.close();
        }
        return vStrings;
    }

    static vector<string> _Split(string line, string delim = "#//#")
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

    static ClsCourse _ConvertLineToCourseObject(string line)
    {
        vector<string> vStrings = _Split(line);
        return ClsCourse(vStrings[0], vStrings[1], vStrings[2]);
    }

    void _UpdateCourseInformation()
    {
    }

public:
    ClsCourse(string courseId, string coursename, string assignedTeacher)
        : CourseId(courseId), CoursName(coursename), AssignedTeacherId(assignedTeacher) {

          };
    ClsCourse() {};

    string GetId()
    {
        return CourseId;
    }

    void SetCoursename(string name)
    {
        CoursName = name;
    }
    string GetCoursename()
    {
        return CoursName;
    }

    void SetAssignedTeacher(string assignedTeacher)
    {
        AssignedTeacherId = assignedTeacher;
    }
    string GetAssignedTeacher()
    {
        return AssignedTeacherId;
    }

    static void ReadCourseInfo(ClsCourse &Course)
    {
        cout << "Enter Course name: ";
        string name;
        cin >> name;
        Course.SetCoursename(name);
        cout << "Enter Assigned teacher: ";
        string assignedTeacher;
        cin >> assignedTeacher;
        Course.SetAssignedTeacher(assignedTeacher);
    }

    void PrintCourseInfo()
    {
        cout << "\nCourse Info:\n";
        cout << "-------------------------\n";
        cout << "Course Id: " << GetId() << "\n";
        cout << "Course Name: " << GetCoursename() << "\n";
        cout << "Course Id: " << GetAssignedTeacher() << "\n";
        cout << "-------------------------\n";
    }

    static vector<ClsCourse> LoadCourses()
    {
        vector<ClsCourse> vCourses;
        vector<string> vStrings = _LoadLinesFromFile();

        for (string S : vStrings)
        {
            vCourses.push_back(_ConvertLineToCourseObject(S));
        }
        return vCourses;
    }

    void ClearFile()
    {
        fstream File;
        File.open(CourseFileName, ios::out | ios::trunc);
        File.close();
    }

    string ConvertCourceObjectToLine(ClsCourse Course, string delim = "#//#")
    {
        return Course.GetId() + delim + Course.GetCoursename() + delim + Course.GetAssignedTeacher();
    }

    static ClsCourse Find(string CourseId)
    {
        ClsCourse Course;
        fstream CourseFile;
        CourseFile.open(CourseFileName, ios::in);
        if (CourseFile.is_open())
        {
            string line;
            while (getline(CourseFile, line))
            {
                Course = _ConvertLineToCourseObject(line);
                if (Course.GetId() == CourseId)
                {
                    CourseFile.close();
                    return Course;
                }
            }
        }
        return Course;
    }

    void Delete()
    {
        vector<ClsCourse> vCources = LoadCourses();
        ClearFile();

        fstream File;
        File.open(CourseFileName, ios::out | ios::app);
        for (ClsCourse &Course : vCources)
        {
            if (File.is_open())
            {
                if (Course.GetId() != GetId())
                {
                    File << ConvertCourceObjectToLine(Course) << "\n";
                }
            }
        }
        File.close();
    }

    void Update()
    {
        vector<ClsCourse> vCources = LoadCourses();
        ClearFile();

        fstream File;
        File.open(CourseFileName, ios::out | ios::app);
        for (ClsCourse &Course : vCources)
        {
            if (File.is_open())
            {
                if (Course.GetId() == GetId())
                {
                    Course = *this;
                }
                File << ConvertCourceObjectToLine(Course) << "\n";
            }
        }
        File.close();
    }
};
