#pragma once

#include <fstream>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>



using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::getline;

#define SIZE 10

//**********This ideally would have a template***********
class queue
{
private:
    int arr[SIZE];		// array to store queue elements
    int capacity;	// maximum capacity of the queue
    int front;		// front points to front element in the queue (if any)
    int rear;		// rear points to last element in the queue
    int count;		// current size of the queue

public:
    queue(int size = SIZE); 	// constructor
    ~queue();   				// destructor

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};



inline queue::queue(int size)
{
    arr[size];
    capacity = SIZE;
    front = 0;
    rear  = 0;
    count = 0;
}



//*****This doesnt even free the memory
queue::~queue()
{
    //delete arr; // you are not required to test this function;
    // however, are there issues with it?
}

// Utility function to remove front element from the queue
void queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return;
    }

    //cout << "Removing " << arr[front] << '\n';

    front = (front + 1);
    count--;
}

// Utility function to add an item to the queue
void queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        return;
    }

    //cout << "Inserting " << item << '\n';

    rear = (rear + 1);
    arr[rear] = item;
    count++;
}

// Utility function to return front element in the queue
int queue::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return std::numeric_limits<int>::min();
    }
    return arr[front];
}

// Utility function to return the size of the queue

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
    if(count == 0)
    {
        return 1;
    }

    
    return 0;
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{
    if(count == capacity)
    {
        return 1;
    }

    
    return 0;
}

int queue::size()
{
    return count;
}
