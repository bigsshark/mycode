//
//  Pointer.cpp
//  CDeeplearning
//
//  Created by zqj on 2019/7/11.
//  Copyright © 2019 xywy. All rights reserved.
//

#include "Pointer.hpp"
//对象数组实战
void objectArray(){

    Coordinate *p = new Coordinate[4];

    for (int i = 0; i < 4; i++) {

        p->setCoor(i, i+1);
        p++;

    }
    p -= 4;
    cout << p->m_fX << p->m_fY << endl;
    p++;
    p->setCoor(10,10);
    cout << p->m_fX << p->m_fY << endl;
    p--;
    delete []p;

    p = NULL;

}

void pointer(){

    
    Pointer *p = new Pointer(3);

    p->printInfp().setX(10).printInfp();


}

Pointer::Pointer(int x){
    
    m_iX = x;
    coors = new Coordinate[4];
    
}

Pointer::~Pointer(){
    
}

Pointer::Pointer(const Pointer &p){
    
    this->m_iX = p.m_iX;

    coors = new Coordinate[4];

    for (int i = 0; i<4;i ++) {
        
        coors[i].setCoor(p.coors[i].m_fX, p.coors[i].m_fY);
        
    }
    
}

Pointer& Pointer::setX(int x){
    
    this->m_iX = x;
    return *this;
    
}

int Pointer::getX(){
    return this->m_iX;
}


Pointer& Pointer::printInfp(){
    
    cout << this->m_iX <<endl;
    return *this;
}
