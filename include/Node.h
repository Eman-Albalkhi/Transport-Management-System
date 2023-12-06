#ifndef NODE_H
#define NODE_H
#include<iostream>
template <class T>
class LinkedListTemplate;

template <class T>
class Node
{
    friend class LinkedListTemplate<T>;

public:
    Node<T>();
    Node<T>(T *dataIn);
    T* getData();
    void setData(T*);

private:
    T *data;
    Node<T>* nextPtr;
};


template <class T>
Node<T>::Node(T *dataIn)
{
    data = dataIn;
    nextPtr = NULL;
}
template <class T>
Node<T>::Node()
{

    data = NULL; nextPtr = NULL;
}

template <class T>
T* Node<T>::getData()
{
    return data;
}
template <class T>
void Node<T>::setData(T *dataIn)
{
    data = dataIn;
    nextPtr = NULL;
}



#endif // NODE_H
