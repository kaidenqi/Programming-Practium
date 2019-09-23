
// File Name: Stack.h
// Author: Kai Qi, Aditi Abhang
// Date: 4/19/2019
// Assignment Number: 6
// CS2308.255 and CS5301 Spring 2019
// Instructor: Jill Seaman
//
// use a linked list to implement the stack operations
#include <string>
using namespace std;

class Stack
{
private:
    // define a Node to store strings and the head
    struct Node
    {
        string name;
        Node * next;
    };
    Node * head;
    
public:
    // constructor
    Stack()
    {
        head = NULL;
    }
    
    // push function
    void push(string x)
    {
        Node *newNode = new Node;
        newNode->name = x;
        
        newNode->next = head;
        head = newNode;
    }
    
    // pop function
    string pop()
    {
        assert (!isEmpty());
        
        string result = head->name;
        Node *p = head;
        head = head->next;
        delete p;
        
        return result;
    }
    
    // isEmpty function
    bool isEmpty()
    {
        return (head == NULL);
    }
};
