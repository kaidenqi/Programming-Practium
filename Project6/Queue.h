
// File Name: Queue.h
// Author: Kai Qi, Aditi Abhang
// Date: 4/19/2019
// Assignment Number: 6
// CS2308.255 and CS5301 Spring 2019
// Instructor: Jill Seaman
//
// use a linked list of string to implement the queue operations

#include <string>
using namespace std;

class  Queue{
private:
    // define a Node to store strings and any other memeber variables here
    struct Node
    {
        string name;
        Node * next;
    };
    Node * front;
    Node * rear;
    
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    
    void enqueue(string n)
    {
        Node *newNode = new Node;
        newNode->name = n;
        newNode->next = NULL;
        
        if(isEmpty())
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    string dequeue()
    {
        assert(!isEmpty());
        
        string result = front -> name;
        
        Node *p = front;
        front = front->next;
        delete p;
        
        return result;
    }
    
    bool isEmpty()
    {
        return (front == NULL);
    }
    
    int size()  //returns the number of elements in the queue
    {
        int count = 0;
        Node *p = front;
        while(p)
        {
            count++;
            p = p->next;
        }
        return count;
    }
};
