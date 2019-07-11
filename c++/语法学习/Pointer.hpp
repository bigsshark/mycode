//
//  Pointer.hpp
//  CDeeplearning
//
//  Created by zqj on 2019/7/11.
//  Copyright © 2019 xywy. All rights reserved.
//

#ifndef Pointer_hpp
#define Pointer_hpp

#include <stdio.h>
#include "Coordinate.hpp"
#include <iostream>

using namespace std;


class Pointer {
    
    
public:
    
    Pointer(int x);
    Pointer(const Pointer &p);
    ~Pointer();
    
    const Pointer& printInfp() const;
    
    Pointer& printInfp();
    
    Pointer& setX(int x);
    int getX();
    
    Coordinate *coors;
    
    
    const Coordinate coor_A;
    Coordinate coor_B;
    
private:
    
    int m_iX;
    
    /*
     * this 指针是函数对象地址的一个引用
     * 用作函数参数名和数据成员名冲突的时候的解决办法
     * 用作成员函数方法c数据成员的方法:  对象的逻辑函数都在代码块，要保证不同的对象使用的逻辑函数的结果是自己的，就需要绑定自己d对象的地址
     * 用作返回值，语法更加精炼
     */
    
    
    /*
     *  对象成员: 某个对象的数据成员是对象类型, 这里先讨论是堆中的情况， 也就是Pointer m_pP;
     *  对象成员初始化: 如果对象成员有默认初始化方法，那么在对象的构造函数中可以不用初始化对象成员
     * 如果对象成员没有默认初始化方法，需要在对象成员初始化f列表中初始化对象成员
     */
    
    /*
     * 深拷贝和浅拷贝: 发生在拷贝构造函数中，用一个对象初始化另外一个对象
     * 浅拷贝: 在对象的拷贝构造函数中将值简单的赋值，如果只是基本数据类型没多大问题，但是如果有指针类型的话，简单的复制可能会指向同一块内存空间
     * 在值改变的时候影响改变，在释放的时候影响释放
     * 这个时候就用深拷贝
     */
    
    /*
     * const
     * 常成员函数
     * 常数据成员
     *
     *
     */
    
    
    
};


#endif /* Pointer_hpp */
