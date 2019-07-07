

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Student{
    
public:
    string m_strName;
    int m_iAge;
    int getScore();
    void initScore();
    void setScore(int _score);
    void setAge(int _age);
    void setName(string _name);
    
//构造函数
    Student();
    Student(string name);
    
    ~ Student();
private:
    int m_iScore;
    
};


#endif /* Student_hpp */
