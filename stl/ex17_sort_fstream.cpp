#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
    string name_;
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int sub5;

    int totalScore() const
    {
        return sub1 + sub2 + sub3 + sub4 + sub5;
    }

    void print() const
    {
        cout << name_ << " : " << sub1 << "+" << sub2 << "+" << sub3 << "+" << sub4 << "+" << sub5 << " = " << totalScore() << endl;
    }
};

int main()
{
    ifstream file("/home/piri/kuBig2025/stl/10.txt");
    vector<Student> students;

    string name;
    int s1, s2, s3, s4, s5;

    while(file >> name >> s1 >> s2 >> s3 >> s4 >> s5)
    {
        students.push_back({name, s1, s2, s3, s4, s5});
    }
    file.close();
    for (const auto &student : students)
    {
        student.print();
    }

    sort(students.begin(), students.end(), [](const Student &a, const Student &b) { return a.totalScore() < b.totalScore(); });

    cout << "----- Sorted by Total Score -----" << endl;

    for (const auto& student : students)
    {
        student.print();
    }

    return 0;
}