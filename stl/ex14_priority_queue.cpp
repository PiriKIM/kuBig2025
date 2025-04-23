#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Task
{
public:
    string name_;
    int priority_;

    bool operator<(const Task& rhs) const {
        return priority_ > rhs.priority_;   // 오름차순
    }
};

int main()
{
    priority_queue<Task> scheduler;

    scheduler.push({"Write report", 2});    // 생성자 없을 때 {멤버변수값} 방식으로 사용 가능
    scheduler.push({"Fix bug", 3});
    scheduler.push({"Email team", 1});

    cout << "작업 처리 순서" << endl;
    while (!scheduler.empty())
    {
        Task t = scheduler.top();
        scheduler.pop();
        cout << t.name_ << " 우선순위 " << t.priority_ << endl;
    }

    return 0;
}