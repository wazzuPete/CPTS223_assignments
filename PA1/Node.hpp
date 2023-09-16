#pragma once
#include <fstream>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


template <typename T>
class Node
{
public:

    Node(T newData) : mpNext(nullptr)
    {
        mpData = newData;
    }
    Node<T>* getNextPtr() const;

    void setNextPtr(Node<T>* pNewNext);

    void setData(const T& newData);

    T& getData();

    void if_read();

    int get_read();


   
private:

    Node<T>* mpNext;
    T mpData;
    int read = 0;

};



template <typename T>
inline Node<T>* Node<T>::getNextPtr() const
{
    return mpNext;
}

template <typename T>
inline void Node<T>::setNextPtr(Node<T>* pNewNext)
{
    mpNext = pNewNext;
}

template <typename T>
inline T& Node<T>::getData()
{
    return mpData;
}

template <typename T>
inline void Node<T>::if_read()
{
    read = 1;
}

template<typename T>
inline int Node<T>::get_read()
{
    return read;
}

template <typename T>
inline void Node<T>::setData(const T& newData)
{
    mpData = newData;
}


