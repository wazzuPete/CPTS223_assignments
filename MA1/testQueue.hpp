#include "queue.hpp"
#include <iostream>



class testqueue
{
 
 public:

  void test_size(){
    queue temp;

    if(temp.size() != 0)
    {
        cout<<"Queue size inaccurate: expected 0: Had:"<<temp.size()<<endl;
        return;
    }


    temp.enqueue(1);
    if(temp.size() != 1)
    {
       cout<< "Queue size inaccurate: expected 1: Had:"<<temp.size()<<endl;
       return;
    }
    else{
        cout<< "Success Size"<<endl;
    }







  }
  

  void test_empty()
  {
    queue temp;
    if(!temp.isEmpty())
    {
        cout<<"Failed, Should be Empty"<<endl;
        return;
    }
    temp.enqueue(1);
    if(temp.isEmpty())
    {
        cout<<"Failed, should Have 1"<<endl;
        return;
    }
    cout<<"Success empty"<<endl;
  }

  void test_full()
  {

    queue temp;

    for(int i =1; i <11; i++)
    {
        temp.enqueue(i);
    }
  
    if(!temp.isFull())
    {
        cout<<"Failed, Should be True"<<endl;
        return;
    }
    temp.dequeue();
      
    if(temp.isFull())
    {
        cout<<"Failed: Should only have 9/10"<<endl;
        return;
    }
    cout<<"Success Full"<<endl;
  }
  
  void test_dequeue()
  {
     queue temp;

    for(int i =1; i<11 ;i++)
    {
        temp.enqueue(i);
    }
    for(int i =0; i<10;i++)
    {
        if(temp.peek() != i)
        {
            cout<<"failed"<<endl;
            return;
        }
        temp.dequeue();
    }

    cout<< "Success Denqueue"<<endl;
    return;
  }

  

  void test_enqueue()
  {
    queue temp;

    for(int i =1; i<11; i++)
    {
        temp.enqueue(i);
    }
    for(int i =0; i<10;i++)
    {
        if(temp.peek() != i)
        {
            cout<<"failed"<<endl;
            return;
        }
        temp.dequeue();
    }

    cout<< "Success Enqueue"<<endl;
    return;
  }



};

