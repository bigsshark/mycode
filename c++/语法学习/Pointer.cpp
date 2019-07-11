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
    cout << p->getX() << p->getY() << endl;
    p++;
    p->setCoor(10,10);
    cout << p->getX() << p->getY() << endl;
    p--;
    delete []p;

    p = NULL;

}

void pointer(){

    
    Pointer *p = new Pointer(3);

    p->printInfp().setX(10).printInfp();


}


void testConst(){
    
    
    Pointer *p = new Pointer(3);
    const Pointer *q = new Pointer(3);
    p->printInfp();
    q->printInfp();
    
    p->printInfp().setX(10).printInfp();
    
    Coordinate coor;
    const Coordinate &b = coor;
    
    b.printinfo();
    
    Coordinate * const c = &coor;
    c->getX();
    
    delete p;
    delete q;
    p = NULL;
    q = NULL;
    
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
        
        coors[i].setCoor(p.coors[i].getX(), p.coors[i].getY());
        
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
    
    this->coor_A.printinfo();
    this->coor_B.printinfo();
    
    return *this;
}

const Pointer& Pointer::printInfp() const{
    
    cout << this->m_iX <<endl;
    
    this->coor_A.printinfo();
    this->coor_B.printinfo();
    
    return *this;
}
