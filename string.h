#ifndef STRING_H
#define STRING_H



class String
{
public:
    char * str = nullptr;
public:
    String(const char * s = "none");
    String( const String & strObj );
    ~String();

    String & operator=(const String & strObj);
    friend String operator+(const String & str1, const String & str2);

};

#endif // STRING_H
