#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Student
{
private:
    string name_;
    vector<int> scores_;

public:
    Student(const string& name, const vector<int> scores)
    : name_(name), scores_(scores)
    {
    }

    int totalScore() const
    {
        return accumulate(scores_.begin(), scores_.end(), 0);
    }

    double averageScore() const
    {
        return (double)totalScore() / scores_.size();
    }

    void print() const
    {
        cout << "점수 : ";
        for (const auto &score : scores_)
            cout << score << " ";
        cout << "/ 총점 : " << totalScore() << " ";
        cout << "/ 평균 : " << averageScore();
        cout << "/ 이름 : " << name_ << endl;
    }

    bool operator<(const Student &other) const
    {
        return averageScore() < other.averageScore(); // 총점이 낮은 학생이 "더 작다"
    }
};

int main()
{
    ifstream file("/home/piri/kuBig2025/stl/10.txt");
    vector<Student> students;

    string line, name;
    vector<int> scores;
    int score;
    cout << "---------- getline ----------" << endl;
    while(getline(file, line))
    {
        cout << line << endl;
        istringstream iss(line);
        iss >> name;
        while (iss >> score)
        {
            scores.push_back(score);
        }
        students.emplace_back(name, scores);
        scores.clear();
    }
    file.close();

    cout << "---------- for index ----------" << endl;
    for (int i = 0; i < students.size(); ++i)
    {
        students[i].print();
    }
    cout << "---------- for range ----------" << endl;
    for (const auto &student : students)
    {
        student.print();
    }
    cout << "---------- begin-end ----------" << endl;
    students.begin()->print();
    students.end()->print();

    sort(students.begin(), students.end(), [](const Student &a, const Student &b) { return a.averageScore() > b.averageScore(); });
    cout << "---------- Sorted by Average Score Descending Order ----------" << endl;
    for (const auto& student : students)
    {
        student.print();
    }

    sort(students.begin(), students.end(), [](const Student &a, const Student &b) { return a.averageScore() < b.averageScore(); });
    cout << "---------- Sorted by Average Score Ascending Order ----------" << endl;
    for (const auto& student : students)
    {
        student.print();
    }

    // partition
    auto fail_bound = partition(students.begin(), students.end(), [](const Student &st) { return st.averageScore() < 60; });
    cout << "-------------- fail_bound --------------" << endl;
    (*fail_bound).print();

    vector<Student> fail_students(students.begin(), fail_bound);
    cout << "-------------- 불합격 --------------" << endl;
    for (const auto& student : fail_students)
    {
        student.print();
    }

    vector<Student> pass_students(fail_bound, students.end());
    cout << "-------------- 합격 --------------" << endl;
    for (const auto& student : pass_students)
    {
        student.print();
    }

    vector<Student> merge_students;
    // merge(fail_students.begin(), fail_students.end(), pass_students.begin(), pass_students.end(), back_inserter(merge_students));
    merge(fail_students.begin(), fail_students.end(),
            pass_students.begin(), pass_students.end(), back_inserter(merge_students),
            [](const Student &a, const Student &b) { return a.averageScore() < b.averageScore();
        });

    cout << "-------------- 합체 --------------" << endl;
    for (const auto& student : merge_students)
    {
         student.print();
    }

    return 0;
}