// 코드에서 쓸 때마다 네임스페이스 명시
#include <iostream>

int main()
{
    std::cout << "hello" << std::endl;

    operator << (std::cout, "hello");

    std::cout.operator << ("hello");

    return 0;
}

/* // 사용할 거만 처음에 using으로 정의
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << "hello" << endl;

    return 0;
}*/

/* // std namespace를 처음 코드 시작할 때 정의
#include <iostream>
using namespace std;

int main()
{
    cout << "hello" << endl;

    return 0;
}*/

/* //  namespace가 생기기 전 C++ 코드
#include <iostream.h>

int main()
{
    cout << "hello" << endl;

    return 0;
}*/