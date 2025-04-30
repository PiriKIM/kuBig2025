// 목표: STL과 스마트포인터를 사용해서 데이터베이스 엔진을 만드세요.
// 스마트포인터 활용 shared_ptr, unique_ptr
// 쓰레드 활용 multi-thread, mutex, atomic -> 내부 동기화 위한 락 구조 설계
// 데이터 삽입 insert(key(int), value(string));
// 데이터 검색 find(key);
// 데이터 삭제 remove(key);
// class DataBase
// 저장용 컨테이너 - unordered_map 참조에 특화된!!
// 컬럼 추가 (타입 정하기)
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <thread>
#include <mutex>
#include <shared_mutex>
using namespace std;

class DataBase
{
private:
    unordered_map<int, shared_ptr<string>> db_;
    mutable shared_mutex mtx_;

public:
    void insert(int key, const string &value)
    {
        unique_lock lock(mtx_);
        db_[key] = make_shared<string>(value);
    }
    shared_ptr<string> find(int key) const
    {
        shared_lock lock(mtx_);
        auto it = db_.find(key);
        return (it != db_.end()) ? it->second : nullptr;       // first는 key / second는 value
    }
    void remove(int key)
    {
        unique_lock lock(mtx_);
        db_.erase(key);
    }
    void printAll() const
    {
        shared_lock lock(mtx_);
        for (const auto &[key, value] : db_)
        {
            cout << key << " : " << *value << endl;
        }
    }

};

void threadTask(DataBase &db, int id)
{
    for (int i = 0; i < 6; ++i)
    {
        db.insert(id * 10 + i, "Data from main " + to_string(id));
        this_thread::sleep_for(50ms);
    }
}

int main()
{
    DataBase db;
    vector<thread> threads;
    for (int i = 0; i < 10; ++i)
    {
        threads.emplace_back(threadTask, ref(db), i);
    }
    for (auto &t : threads)
        t.join();
    db.printAll();
    for (int i = 0; i < 100; ++i)
    {
        if (i % 3 == 2)
            db.remove(i);
    }
    for (int i = 0; i < 100; ++i)
    {
        if (i % 5 == 2)
            cout << "find " << i << " : " << (db.find(i) != nullptr ? *(db.find(i)) : "null") << endl; 
    }
    
    return 0;
}