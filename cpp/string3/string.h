#ifndef STRING_H
#define STRING_H
#include <iostream>

class String {
friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
    char *str_;
    int len_;

public:
    String();
    String(const char *s);
    String(const String& rhs);
    ~String();

    String& operator=(const String& rhs);

    bool operator==(const String& rhs) const;

    const String operator+(const String& rhs) const;

    // String *operator&() { return this; }
    // const String *operator&() const { return this; }

    const char *c_str() const;
    int size() const;
    
};

inline std::ostream& operator<<(std::ostream& out , const String& rhs)
{
    return out << rhs.str_;
}

inline String::~String()
{
    delete [] str_;
}

inline const char *String::c_str() const
{
    return str_;
}

inline int String::size() const
{
    return len_;
}

#endif