

#include "Teacher.hpp"


Teacher::~Teacher(){
    
    cout << "Teacher::~Teacher()" << endl;
    
}

Teacher::Teacher(const Teacher &tea){
    
    cout << "Teacher::Teacher(const Teacher &tea)" << endl;
    
}


//Teacher::Teacher(string name, int age){
//    
//    cout << "Teacher::Teacher(string name, int age)" << endl;
//
//}


Teacher::Teacher():m_strName("james"), m_strSex ( "女") {
    cout << "Teacher::Teacher():m_strName(\"james\"), m_strSex (\"女\")" << endl;

}
