#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int mark;
    char grade = ' ';
};

int main()
{
    vector<Student> students = {
        {"Arun", 85, ' '},
        {"Bala", 72, ' '},
        {"Kumar", 91, ' '},
        {"Ravi", 65, ' '}
    };

    // Sort students by marks
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b)
         {
             return a.mark > b.mark;
         });

    // Assign grades
    transform(students.begin(), students.end(),
              students.begin(),
              [](Student s)
              {
                  if (s.mark >= 90)
                      s.grade = 'A';
                  else if (s.mark >= 75)
                      s.grade = 'B';
                  else if (s.mark >= 50)
                      s.grade = 'C';
                  else
                      s.grade = 'F';

                  return s;
              });

    // Find first student scoring above 80
    auto it = find_if(
        students.begin(),
        students.end(),
        [](const Student& s)
        {
            return s.mark > 80;
        });

    // Calculate total marks
    int total = accumulate(
        students.begin(),
        students.end(),
        0,
        [](int sum, const Student& s)
        {
            return sum + s.mark;
        });

    double average = students.empty()
        ? 0.0
        : static_cast<double>(total) / students.size();

    cout << "Student Grade Analyzer\n";
    cout << "---------------------\n";

    cout << "Name\tMark\tGrade\n";

    for (const Student& s : students)
    {
        cout << s.name << '\t'
             << s.mark << '\t'
             << s.grade << '\n';
    }

    if (it != students.end())
    {
        cout << "\nFirst student scoring above 80: "
             << it->name << '\n';
    }

    cout << "Total Marks: " << total << '\n';

    cout << fixed << setprecision(2);
    cout << "Average Mark: " << average << '\n';

    return 0;
}