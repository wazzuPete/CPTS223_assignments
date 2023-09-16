#pragma once
#include <fstream>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std;


template <typename T>


class List {
private:
    Node<T>* mpHead;
    Node<T>* mpTail;
    

public:
    List();

    ~List();

    void insert(T data);

    void delete_node(string name);

    Node<T>* trav_node(int x);

    Node<T>* getHead();
    Node<T>* getTail();
    void setTail(Node<T>* new_one);


    
    int num;

};

template <typename T>
inline List<T>::List()
{
    mpHead = nullptr;
    mpTail = nullptr;

}

template <typename T>
inline List<T>::~List()
{
    ////N/*ode<T>* temp = mpHead;
    //Node<T>* next;

    //while (temp != nullptr)
    //{
    //    next = temp->getNextPtr();
    //    delete temp;
    //    temp = next;
    //};*/

}

template <typename T>
inline void List<T>::insert(T data)
{
    Node<T>* newNode = new Node<T>(data);

    if (mpHead == nullptr)
    {
        mpHead = newNode;
        mpTail = newNode;
        mpTail->setNextPtr(mpHead);
    }
    else
    {

        mpTail->setNextPtr(newNode);
        mpTail = newNode;
        mpTail->setNextPtr(mpHead);
    }
    num++;
}

template <typename T>
inline Node<T>* List<T>::trav_node(int x)
{
   
    Node<T>* temp_2 = mpHead;

    for (int i = 0; i < x; i++)
    {
        temp_2 = temp_2->getNextPtr();

    }


    return temp_2;
}

template <typename T>
inline Node<T>* List<T>::getHead()
{
    return mpHead;
}

template <typename T>
inline Node<T>* List<T>::getTail()
{
    return mpTail;
}

template<typename T>
inline void List<T>::setTail(Node<T>* new_one)
{
    mpTail = new_one;
}

//I decided to put my delete from list into the app.cpp for no reason, does the same thing but with a couple more pointers