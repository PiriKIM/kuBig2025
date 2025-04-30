#include <iostream>
#include <thread>
#include <mutex>    // mutually exclusive
using namespace std;

int counter = 0;
mutex mtx;

void increment()
{
    for (int i = 0; i < 1000; ++i)
    {
        lock_guard<mutex> lock(mtx);
        ++counter;
    }
}

int main()
{
    thread t1(increment);
    cout << "최종 카운터 값1 : " << counter << endl;
    thread t2(increment);
    cout << "최종 카운터 값2 : " << counter << endl;
    // excution.
    // ...
    t1.join();  // t1 에서 실행되는 상황이 끝나면 대기하라!
    // ... main 끝, t1 끝난 상황...
    cout << "최종 카운터 값3 : " << counter << endl;
    t2.join();  // t2 에서 실행되는 상황이 끝나면 대기하라!
    // excution - main thread, t1 thread, t2 thread. 끝난 다음
    cout << "최종 카운터 값4 : " << counter << endl;

    return 0;
}