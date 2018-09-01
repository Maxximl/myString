#include "string.h"
#include <cstring>
using namespace std;


String::String(const char * s)
{
  str = new char[std::strlen(s)+1];
  std::strcpy(str, s);
}

String & String::operator =(const String & strObj)
{
    if (this == &strObj)
        return *this;
    delete [] str;
    str = new char[std::strlen(strObj.str)+1];
    std::strcpy(str, strObj.str);
}

String operator+(const String & s1, const String & s2)
{
    return String(strcat(s1.str, s2.str));
}

String::~String()
{
    delete [] str;
}

