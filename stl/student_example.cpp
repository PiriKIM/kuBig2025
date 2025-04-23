// 학생들의 이름과 점수를 저장한 클래스로 벡터를 이용해서 정렬하는 프로그램.
// 정렬 기준은 내림차순(높은 점수가 앞에) 점수가 같으면 이름 오름차순.
// algorithm 에서는 stable_sort 로 변경.
// 데이터는 1000.txt 테스트.
// 참고 - sort_fstream2.cpp
// 학점 grade private -> A(<=100), B(<90), C(<80), D(<70), F(<60)
// print() 에 표현 될 수 있게 변경.
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
    char grade_;
    string a = "FFFFFFDCBAA";

public:
    Student(const string& name, const vector<int> scores)
    : name_(name), scores_(scores)
    {
        double avg = averageScore();
        grade_ = a[avg / 10];
    }

    int totalScore() const
    {
        return accumulate(scores_.begin(), scores_.end(), 0);
    }

    int averageScore() const
    {
        return totalScore() / scores_.size();
    }

    const char grade() const
    {
        return grade_;
    }

    const string name() const
    {
        return name_;
    }

    void print() const
    {
        cout << "점수 : ";
        for (const auto &score : scores_)
            cout << score << " ";
        cout << "/ 총점 : " << totalScore() << " ";
        cout << "/ 평균 (등급) : " << averageScore() << " (" << grade_ << ") ";
        cout << "/ 이름 : " << name_ << endl;
    }

    bool operator<(const Student &rhs) const
    {
        return (totalScore() > rhs.totalScore()) || (totalScore() == rhs.totalScore() && (name() < rhs.name()));
    }
};

int main()
{
    ifstream file("/home/piri/kuBig2025/stl/1000.txt");
    vector<Student> students;

    string line, name;
    vector<int> scores;
    int score;

    while(getline(file, line))
    {
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

    stable_sort(students.begin(), students.end(),
                [](const Student &a, const Student &b)
                { 
                    return (a.totalScore() > b.totalScore()) || (a.totalScore() == b.totalScore() && (a.name() < b.name()));
                });

    cout << "---------- Sorted by Grade & Name ----------" << endl;

    for (const auto& student : students)
    {
        student.print();
    }

    return 0;
}