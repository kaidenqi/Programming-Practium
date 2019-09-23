
// File Name: PasswordManager.h
// assign4_k_q23.cpp
// Author: Kai Qi
// Date: 3/20/2019
// Assignment Number: 4
// CS 5301 Spring 2019
// Instructor: Jill Seaman
//
// PasswordManager.h
//
// The PasswordManager class
// This class manages a single password for a given username
// Class declaration (specification) in a separate file

#include <string>
using namespace std;

class PasswordManager
{
private:
    string userName;
    string encryptedPw;
    string encrypt(string);
    bool meetsCriteria(string);
public:
    void setUsername(string);
    string getUsername() const;
    void setEncryptedPassword(string);
    string getEncryptedPassword() const;
    bool setNewPassword(string);
    bool authenticate(string);
};
