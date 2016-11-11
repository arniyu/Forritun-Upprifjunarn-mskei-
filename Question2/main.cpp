#include <iostream>
#include <vector>

using namespace std;

struct Student
{
    string Name;
    double Grade;
};

int Prompt()
{
    int number;
    cout << "Number of students: " << endl;
    cin >> number;
    cout << "--- Reading students ---" << endl;
    return number;
}

double CalculateAverage(double total, int number )
{
    return total / number;
}

vector<Student> ReadStudents(int number)
{
    vector<Student> myVector;
    for(int i = 0; i < number; i++)
    {
        Student student;
        cin >> student.Name;
        cin >> student.Grade;
        myVector.push_back(student);
    }
    return myVector;
}

Student FindTopStudent(vector<Student> students, double &total)
{
    Student topStudent;
    int highestGrade = 0;
    for(int i = 0; i < students.size(); i++)
    {
        if(students.at(i).Grade > highestGrade)
        {
            topStudent = students.at(i);
        }
        total += students.at(i).Grade;
    }
    return topStudent;
}

void EndPrompt(double total, int number, Student topStudent)
{
    cout << "Highest student: " << endl;
    cout << "Name: " << topStudent.Name << endl;
    cout << "Grade: " << topStudent.Grade << endl;
    cout << "Average grade: " << CalculateAverage(total, number) << endl;
}
int main()
{
    double total = 0;

    int number = Prompt();
    vector<Student> myVector = ReadStudents(number);
    Student topStudent = FindTopStudent(myVector, total);
    EndPrompt(total, number, topStudent);
    return 0;
}
