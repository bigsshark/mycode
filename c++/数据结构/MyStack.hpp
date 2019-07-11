
#ifndef MyStack_hpp
#define MyStack_hpp

#include <stdio.h>

#include <iostream>
using namespace std;


template <typename  T>
class MyStack {
    
public:
    
    MyStack(int intCapicaty);
    ~MyStack();
    
    bool push(T element);
    bool pop(T &element);
    
    bool empty();
    bool full();
    
    void clear();
    
    void travelerse(bool fromBottom);
    
    int length();
    
private:
    
    T *m_pBuffer;
    int m_iLength;
    int m_iTop;
    int m_iCapicaty;;
    
};

template <typename T>
MyStack<T>::MyStack(int intCapicaty){
    
    m_iCapicaty = intCapicaty;
    m_iLength = 0;
    m_iTop  = 0;
    m_pBuffer = new T[intCapicaty];
    
}

template <typename T>
MyStack<T>::~MyStack<T>(){
    
    delete []m_pBuffer;
    m_pBuffer = NULL;
    
}

template <typename T>
void MyStack<T>::clear(){
    
    m_iTop = 0;
    
}

template <typename T>
int MyStack<T>::length() {
    
    return m_iLength;
    
}

template <typename T>
bool MyStack<T>::empty() {
    
    return m_iTop == 0;
    
}

template <typename T>
bool MyStack<T>::full() {
    
    return m_iTop == m_iCapicaty;
    
}


template <typename T>
bool MyStack<T>::push(T element) {
    
    if (full()) {
        
        return false;
        
    }
    
    m_pBuffer[m_iTop] = element;
    m_iTop++;
    m_iLength++;
    
    return true;
    
}

template <typename T>
bool MyStack<T>::pop(T &element){
    
    if (empty()) {
        return false;
    }
    
    m_iTop--;
    element = m_pBuffer[m_iTop];
    m_iLength--;
    return true;
    
}

template <typename T>
void MyStack<T>::travelerse(bool fromBottom){
    
    if (fromBottom) {
        
        for (int i = 0; i < m_iLength; i++) {
            cout << m_pBuffer[i];
        }
        
    }else{
        
        //从栈顶遍历
        for (int i = m_iTop-1; i >=0; i--) {
            cout << m_pBuffer[i];
        }
    }
    
}


#endif /* MyStack_hpp */
