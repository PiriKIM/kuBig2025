#ifndef STRING_REP_H
#define STRING_REP_H

class StringRep
{
friend class String;    // String클래스의 멤버함수는 StirngRep의 privat에 접근 가능.(handle-body class idium)

private:
    char *str_;
    int len_;
    int rc;     // reference count
    
    StringRep();
    StringRep(const char* s);
    ~StringRep();

public:

};

#endif