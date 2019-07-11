
#include "MyStack.hpp"


#include <iostream>
using namespace std;



/**
 栈实现十进制转换
 tobinary 为转换为的进制
 */
void stackBinaryChange(int value, int toBinary){
    
    char num[] = "0123456789abcdef";
    
    int to = 10;
    
    if (toBinary == 2) {
        to = 2;
    }else if (toBinary == 8){
        to = 8;
    }else if (toBinary == 16){
        to = 16;
    }
    
    MyStack<int> *stack = new MyStack<int>(30);
    
    int mod = 0;
    while (value > 0) {
        
        mod = value%to;
        value = value/to;
        stack->push(mod);
    }
    
    for (int i = stack->length() -1 ; i >= 0; i--) {
        
        int element = 0;
        
        stack->pop(element);
        
        cout << num[element];
        
    }
    
    delete stack;
    stack = NULL;
    
}





/**
 括号匹配
 [()[]]
 
 如果是[(])这种呢！待解决
 */
void bracketsMatches(){
    
    char brackets[] = "[()()]";
    
    MyStack<char> *origin = new MyStack<char>(20);
    MyStack<char> *wait = new MyStack<char>(20);
    
    char currentNeed = 0;
    
    for (int i = 0; i < strlen(brackets); i++) {
        
        if (brackets[i] != currentNeed) {
            
            origin->push(brackets[i]);
            
            switch (brackets[i]) {
                    
                case '[':
                    if(currentNeed != 0){
                        wait->push(currentNeed);
                    }
                    currentNeed = ']';
                    break;
                case '(':
                    if(currentNeed != 0){
                        wait->push(currentNeed);
                    }
                    currentNeed = ')';
                    break;
                default:
                    cout << "括号不匹配";
                    return;
                    break;
            }
            
        }else{
            
            char element;
            
            origin->pop(element);
            
            if (!wait->pop(currentNeed)) {
                currentNeed = 0;
            }
            
        }
        
    }
    
    if (origin->empty()) {
        cout << "括号匹配";
    }else {
        cout << "l括号不匹配";
    }
    
    
}
