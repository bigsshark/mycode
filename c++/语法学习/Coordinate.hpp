//
//  Coordinate.hpp
//  CDeeplearning
//
//  Created by zqj on 2019/7/5.
//  Copyright © 2019 xywy. All rights reserved.
//

#ifndef Coordinate_hpp
#define Coordinate_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Coordinate {
    
    friend ostream &operator <<(ostream &out,Coordinate &coor);
    
public:
    
    Coordinate(int x = 0, int y = 0);
    ~Coordinate();
    
    
    void setCoor(int x, int y);
    
    int getX();
    int getY();
    
    void setX(int x);
    void setY(int y);
    
    void printinfo() const;
    
private:
    int m_fX;
    int m_fY;
    
};

#endif /* Coordinate_hpp */
