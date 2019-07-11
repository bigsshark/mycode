//
//  Coordinate.cpp
//  CDeeplearning
//
//  Created by zqj on 2019/7/5.
//  Copyright © 2019 xywy. All rights reserved.
//

#include "Coordinate.hpp"
#include <iostream>
using namespace std;

Coordinate::Coordinate(int x,int y){
    
    m_fX = x;
    m_fY = y;
    
}

 ostream &operator <<(ostream &out,Coordinate &coor) {
    
     out << "(" << coor.m_fY <<  "," << coor.m_fX  <<  ")" <<endl;
    
     return out;
     
}

void Coordinate::setCoor(int x, int y){
    
    m_fX = x;
    m_fY = y;
    
}


Coordinate::~Coordinate(){
    
}


int Coordinate::getX(){
    return this->m_fX;
}
int Coordinate::getY(){
    
    return this->m_fY;
    
}

void Coordinate::setX(int x){
    this->m_fX = x;
}

void Coordinate::setY(int y){
    this->m_fY = y;
}



void Coordinate::printinfo()const {
    
    cout << "(" << this->m_fX << "," << this->m_fY << ")" << endl;
    
}













