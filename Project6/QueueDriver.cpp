
// File Name: QueueDriver.cpp
// Author: Kai Qi, Aditi Abhang
// Date: 4/19/2019
// Assignment Number: 6
// CS2308.255 and CS5301 Spring 2019
// Instructor: Jill Seaman
//
// This program uses a Queue to simulate the management of the line of people waiting
// to ride a roller coaster in an amusement park.
#include "Queue.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    int numSeat;          // store the number of seats of a train
    string groupName;     // store group name
    int groupNumber;      // store number of ppl contained in the group
    int totalRider = 0;   // store total riders
    int train = 0;        // stror total trains
    Queue stringQueue;   // a instance of queue to simulate the waiting line
    
    // read data from txt file
    ifstream fin;
    fin.open("riders.txt");
    
    fin >> numSeat; // read the number of seats of coaster
    
    // read the first line of data of the input file
    fin >> groupName; 
    fin >> groupNumber;
    
    do
    {
        int counter = 0; // store the number of ppl in a train
        do
        {
            // let all the ppl in the same group go on the same train
            for (int i=0; i<groupNumber; i++)
                stringQueue.enqueue(groupName);
            
            counter = stringQueue.size();// get the number of ppl in a train
            
            // read data of next line
            fin >> groupName;
            fin >> groupNumber;
          
          // control the number of ppl in a train
        } while (groupNumber <= (numSeat - counter) && !fin.eof());
        
        totalRider += counter; // store total riders
        train++;               // store how many trains are used for those groups

        cout << "Train #" << train << endl;
        cout << "--------------" << endl;
        
        int order = 1; // number the member of the group
        string pre = stringQueue.dequeue(); // dequeue the first element of the queue
        cout << pre << " " << order << endl;
        
        while(!stringQueue.isEmpty())
        {
            string next = stringQueue.dequeue(); // dequeue another element of the queue
            cout << next << " " ;
            if (next==pre) // if the two elements are from the same group
            {
                order++;
                cout << order << endl;
            }
            else // if the two elements are from different groups
            {
                order = 1;
                cout << order << endl;
            }
            pre = next;
        }
        cout << endl;
        
    } while (!fin.eof());
    
    fin.close(); // close txt file
    
    cout << "Total Riders: " << totalRider << endl;
    cout << "Total Trains: " << train << endl;
   
    return 0;
}
