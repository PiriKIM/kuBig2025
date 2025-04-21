#include <iostream>
#include <vector>
#include <string>

using namespace std;
// using std::cout;
// using std::endl;

int main()
{
    vector<string> sentence;
    string name;

    cout << "이름을 5개 입력 하시오! " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << i + 1 << ">>";
        getline(cin, name);
        sentence.push_back(name);
    }
    name = sentence.at(0);
    for (int i = 0; i < sentence.size(); ++i)
    {
        if (name < sentence[i]) // string의 비교 연산자 오버라이딩
            name = sentence[i];
    }
    cout << "사전에서 가장 뒤에 나오는 이름은 : " << name << endl;
}
