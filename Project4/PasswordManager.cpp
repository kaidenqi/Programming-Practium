// File Name: PasswordManager.cpp
// assign4_k_q23.cpp
// Author: Kai Qi
// Date: 3/20/2019
// Assignment Number: 4
// CS 5301 Spring 2019
// Instructor: Jill Seaman
//
// PasswordManager.cpp
//
// The PasswordManager class
// Member function definitions (implementation) in a separate file

#include <string>
using namespace std;
#include <iostream>
#include "PasswordManager.h"


/* This private function takes a password(a string)
 and returns the encrypted form of the password.*/
string PasswordManager:: encrypt(string pw)
{
    string newPw;    /*pw[index] != '\0'*/
    for(int index=0; index < pw.length(); index++)
    {
        int val =(pw[index]-33) + 25;
        int val2 = val % 94 + 33;
        char element = (char) val2;
        newPw = newPw + element;
    }
    
    return newPw;
}

/* This private function takes a string(a password)
 and returns true if it meets the criteria.*/
bool PasswordManager:: meetsCriteria(string pw)
{
    bool upper_flag =0, lower_flag = 0, digit_flag = 0;
    if (pw.length() < 8)
        return false;
    else                 /*pw[index] != '\0'*/
        for(int index=0; index < pw.length(); index++)
        {
            if (isupper(pw[index]))
                upper_flag = 1;
            if(islower(pw[index]))
                lower_flag = 1;
            if (isdigit(pw[index]))
                digit_flag = 1;
        }
    if (upper_flag && lower_flag && digit_flag)
        return true;
    else
        return false;
}

/* A setter function: this member function takes
 a string and stores it in the proper menber variable.*/
void PasswordManager:: setUsername(string name)
{
    userName = name;
}

/* A getter function: this member function returns
 the value of the proper member variable.*/
string PasswordManager:: getUsername() const
{
    return userName;
}

/* A setter function: this member function takes a string
 (encrypted password) and stores it in the proper member
 variable.8*/
void PasswordManager:: setEncryptedPassword(string pw)
{
    encryptedPw = pw;
}

/* A getter function: this member function returns the
 value of the encrypted password stored in the proper
 member variable.*/
string PasswordManager:: getEncryptedPassword() const
{
    return encryptedPw;
}

/* This member function takes a string(a proposed,
 unencrypted, password).If it meets the criterria
 in meetsCriteria, it encrypts the password
 and stores it in the member variable and
 returns true. Otherwise returns false.*/
bool PasswordManager::setNewPassword(string pw)
{
    if (meetsCriteria(pw))
    {
        encryptedPw = encrypt(pw);
        return true;
    }
    else
        return false;
}


/* This member function takes a string(a password)
 and returns true if,once encrypted, it matches
 the encrypted string stored in the member variable.
 Else returns false.*/
bool PasswordManager:: authenticate(string pw)
{
    string pwTem = encrypt(pw);
    if (pwTem == encryptedPw)
        return true;
    else
        return false;
}
