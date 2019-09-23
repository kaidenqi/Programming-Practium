// File Name: StringList.cpp
// assign5_k_q23.cpp
// Author: Kai Qi
// Date: 4/8/2019
// Assignment Number: 5
// CS 5301 Spring 2019
// Instructor: Jill Seaman
//
// StringList.cpp
//
// Member function definitions (implementation) in a separate file

#include <string>
#include <cstring>
#include <iostream>
#include "StringList.h"
using namespace std;

StringList::StringList()
{
    head = NULL; // set up empty list
}

StringList::~StringList()
{
    StringNode *p = head; ; // traversal ptr
    StringNode *n; // saves the next node
    
    // start at head of list
    while(p != NULL)
    {
      n = p->next; // save the next
      delete p;     // delete current
      p = n;       // advance ptr
    }
}

int StringList::count()
{
    int count = 0;         // set count to 0
    StringNode *p = head; // start at head of list
    
    while (p != NULL)
    {    count++;         // increment of counter
         p = p->next;     // advance ptr
    }
    return count;
}

void StringList::push_front(string d)
{
    StringNode *newNode;     // ptr to new node
    newNode = new StringNode;// allocate new node
    newNode->data = d;
    
    // insert before first
    newNode->next = head;
    head = newNode;
}

void StringList::push_back(string d)
{
    StringNode *newNode;     // ptr to new node
    newNode = new StringNode;// allocate new node
    newNode->data = d;
    newNode->next = NULL;
    
    if(head==NULL)
        head = newNode;
    else
    {
        StringNode *p = head;// traversal ptr
        while(p->next)        // find the last node
            p = p->next;
        p->next = newNode;   // append to the end
    }
}

void StringList::pop_front()
{
    StringNode *p = head;// ptr points to first node
    if (p)
    {
        head = p->next;      // remove first node
        delete p;             // deallocate the removed node
    }
}

void StringList::display()
{
    StringNode *p = head; // start at head of list
    while (p != NULL)
    {   //display the value in the current node
        cout << p->data << endl;
        p = p->next; // move to the next node
    }
}

void StringList::remove(StringNode *m)
{
    StringNode *p = head;// traverse the list
    StringNode *n;       // trailing node ptr
    
    /*skip nodes not equal to value that m points to,
      stop at last*/
    while (p && (p->data != m->data))
    {
        n = p;      // save ptr
        p = p->next;// advance ptr
    }
    
    if(p)
    {
        if (p == head) // delete the first node
            head = p->next;
        else          // p and n are not NULL
            n->next = p->next;
    }
}

StringList::StringNode * StringList:: maximum()
{
    StringNode *p = head; // start at head of list to traverse list
    if (head == NULL)      // return NULL if list is empty
        return NULL;
    else
    {
            StringNode *maxP = p; // set maximum to value in first node
            while(p)               // taverse list
            {
                if (maxP->data < p->data) // if a bigger value is found
                    maxP = p;
                p = p->next; // advance ptr
            }
            return maxP; // return the ptr containing the maximum string
    }
}

void StringList::sort()
{
    StringNode *newNode = NULL; // ptr to be the head of the new list
    StringNode *p = head;      // traverse the old list
    while(p)
    {
        p = maximum();         // find the maximum string in old list
        remove(p);             // remove the maximum string from the old list
        
        p->next = newNode;     // insert the node after the new node's head
        newNode = p;
        
        p = head;              // let taversal ptr point to the head of old list
    }
    head = newNode;            // make old head ptr point to the new list
}
