// File Name: PasswordDriver.cpp
// assign4_k_q23.cpp
// Author: Kai Qi
// Date: 3/20/2019
// Assignment Number: 4
// CS 5301 Spring 2019
// Instructor: Jill Seaman
//
// PasswordDriver.cpp
//
// The PasswordManager class
/*This main function reads data from a file, and uses those data
 to set the usernames and passwords in the password manager class array.
 This program lets users enter their netID, old password and new
 password. This program outputs three new encrypted passwords
 to the file "password.txt". */


#include <iostream>
#include <fstream>
#include "PasswordManager.h"
using namespace std;

int main()
{
    PasswordManager pwSample[3];/*Create an array of 3 instances
                                 of the PasswordManger class*/
    string name;// Store usernames that were read from file
    string password;// Store passwords that were read from file
    
    ifstream fin;
    fin.open("passwords.txt"); // Open file
    
    if (!fin)// Exit with an error massage if the file doesn't exist
        cout << "ERROR - File failed to open. make sure that "
        << "the input file and this file are in the"
        << "same directory" << endl;
    else
    {
        /*Read data from the file, and then use the data from the file
         to set the usernames and encrypted passwords in the password
         manager array*/
        for (int i=0;i<3;i++)
        {
            fin >> name;
            //cout <<  "debug1  " << name << endl;
            pwSample[i].setUsername(name);
            //cout <<  "debug2  " << pwSample[i].getUsername() << endl;
            fin >> password;
            pwSample[i].setEncryptedPassword(password);
            //cout <<  "debug3  " << pwSample[i].getEncryptedPassword() << endl;
            fin >> ws;
        }
    }
    
    fin.close(); // Close file
    
    cout << "Valid password must meet the following "
         << "criteria: it is at least 8 characters long "
         << "it contains at least one uppercase letter,"
         << "one lowercase letter and one digit."
         << endl;
    
    PasswordManager test;// Store new password that user enters to test if it meets criteria
    string testName;     // Store username that user enters
    string oldPassword;  // Store old password that user enters
    string newPassword;  // Store new password that user enters
    
    // Ask user to enter their netID,old password and new password
    cout << "Please enter your username: ";
    cin >> testName;
    cout << "Please enter your old password: "<< endl;
    cin >> oldPassword;
    cout << "Please enter your new password: ";
    cin >> newPassword;
        
    /*Debug:
    cout <<  "debug4  " << testName << "  "
    << oldPassword <<  "  " << newPassword << endl;
    */
    
    
    int flagName = 0; //Flag to see if netID is valid
    for(int i=0; testName != pwSample[i].getUsername() && i<3;i++)
    {
        flagName++;
    }
    
    if(flagName == 3) //Test if netID is valid
    {
       cout << "NetID is invalid, password not changed." << endl;
    }
    else
    {
        for (int i=0; i<3; i++)
        {
            // If user enters a valid username
            if (testName == pwSample[i].getUsername())
            {   // Test if old password is correct
                if(!pwSample[i].authenticate(oldPassword))
                    cout << "Old password is incorrect." << endl;
                else
                {
                    if (!test.setNewPassword(newPassword))
                        cout << "New Password does not meet criteria." << endl;
                    else
                    {
                        pwSample[i].setNewPassword(newPassword);
                        cout << "Password has been changed for netID: "
                        << pwSample[i].getUsername() << endl;
                    }
                }
                break;
            }
        }
    }
    
    
    ofstream fout;
    fout.open("passwords.txt"); // Open file
    for (int i = 0; i < 3; i++) // Output data to the file
        fout << pwSample[i].getUsername() << " "
             << pwSample[i].getEncryptedPassword() << endl;

    fout.close(); // Close file
    
    return 0;
}
