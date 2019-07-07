
//

#include "Student.hpp"

inline void Student::initScore(){
    
    m_iScore = 0;
    
}

inline void Student::setName(string _name){
    
    m_strName = _name;
    
}


Student::Student(){
    
}


Student::Student(string name){
    
    m_strName = name;
    
}
