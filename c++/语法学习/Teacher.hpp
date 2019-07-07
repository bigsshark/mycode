

#ifndef Teacher_hpp
#define Teacher_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Teacher {
    
    
public:
    
    string m_strName;
    int m_iAge;
    string m_strObject;
    Teacher();
//    Teacher(string name = "name", int age = 10);
    Teacher(const Teacher &tea);
//    析构函数
    ~Teacher();
    
private:
    
    const string m_strSex;
    
};

#endif /* Teacher_hpp */
