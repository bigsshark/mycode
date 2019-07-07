

#ifndef MyQueue_hpp
#define MyQueue_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

/*
 环形队列
 
 队列容量
 队列当前长度
 队列队首元素
 队列尾部元素
 存放元素数组
 
 构造函数
 入队列
 出队列
 队列是否为空
 队列是否满了
 清空队列
 遍历队列
 
 template 改造使用所有类型
 
 对应的类型实现了operator <<
 //    friend ostream &operator <<(ostream &out, MyQueue &queue);

 */

template <typename T>
class MyQueue {
public:
    
    MyQueue(int queCapacity); // InitQueue(&Q)
    virtual ~MyQueue();       //DestoryQueue(&Q)
    bool enQueue(T element);//ClearQueue(&Q element)
    bool deQueue(T &element);//QueueEmpty(&Q, &element)
    bool queueEmpty() const;//QueueEmpty(&Q)
    int queueLength() const;
    bool queueFull() const;
    void queueClear() ;
    void queueTraverse() ;//QueueTraverse(Q,visit())
    
    
private:
    
    T *m_iQueue;
    int m_iQueCapacity;
    int m_iQueueLength;
    int m_iQueueHead;
    int m_iQueueTail;
};


template <typename T>
MyQueue<T>::MyQueue(int queCapacity)// InitQueue(&Q)
{
    m_iQueCapacity = queCapacity;
    
    queueClear();
    //可能申请失败
    m_iQueue = new int(queCapacity);
    
}

template <typename T>
MyQueue<T>::~MyQueue()      //DestoryQueue(&Q)
{
    delete []m_iQueue;
    m_iQueue = NULL;
}

template <typename T>
void MyQueue<T>::queueClear()
{
    
    m_iQueueHead = 0;
    m_iQueueTail = 0;
    m_iQueueLength = 0;
    
}

template <typename T>
bool MyQueue<T>::queueEmpty() const{
    
    return m_iQueueLength == 0;
    
}

template <typename T>
bool MyQueue<T>::queueFull() const {
    
    return m_iQueCapacity == m_iQueueLength;
    
}

template <typename T>
int MyQueue<T>::queueLength() const {
    return m_iQueueLength;
}

template <typename T>
bool MyQueue<T>::enQueue(T element){
    
    if (queueFull()) {
        
        return false;
        
    }else{
        
        //队尾向后移动
        m_iQueue[m_iQueueTail] = element;
        m_iQueueTail++;
        // 队列插入，出队, 操作频繁可能超过容量的值，d要回归到队列的数字中来
        m_iQueueTail = m_iQueueTail % m_iQueCapacity;
        m_iQueueLength++;
        return true;
    }
    
}

template <typename T>
bool MyQueue<T>::deQueue(T &element){
    
    if (queueEmpty()) {
        
        return false;
        
    }else{
        
        element = m_iQueue[m_iQueueHead];
        m_iQueueHead++;
        m_iQueueHead = m_iQueueHead % m_iQueCapacity;
        
        m_iQueueLength--;
        return true;
    }
    
}

template <typename T>
void MyQueue<T>::queueTraverse() {
    
    for (int i = m_iQueueHead; i < m_iQueueLength+m_iQueueHead; i++) {
        
        //遍历队列
        cout << m_iQueue[i%m_iQueCapacity];
        
    }
    
}




#endif /* MyQueue_hpp */
