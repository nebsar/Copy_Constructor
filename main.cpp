/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 13, 2018, 6:29 PM
 */

#include <iostream>
#include <string>
#include <string.h>

class Base {
private:
    int mSize;
    char* content;

public:

    Base(char* c) {
        this->mSize = strlen(c);
        this->content = new char[mSize + 1];
        strcpy(this->content, c);
    }

    Base(const Base& b) { //Copy constructor
        this->mSize = b.mSize;
        this->content = new char[mSize + 1];
        strcpy(this->content, b.content);
    }

    ~Base() {
        delete this->content;
        this->content = NULL;
    }

};

class Person {
private:
    std::string* m_name;
    int m_age;

public:
    Person(std::string name, int age)
    :
    //  m_age(age),m_name(name) or below line of code is same
    m_age{age}, m_name{new std::string(name)}

    {
        //  this->m_name = name;
        // this->m_age = age;
    }

    Person(const Person& p) // Copy constructor
    : m_name{new std::string(*p.m_name)},
    m_age{p.m_age}
    {

    }

    ~Person() {
        delete m_name;
    }

};

int main() {

    Base b("deneme");

    Base d(b);

    Base be = d; // you can also use this for copy construction

    return 0;
}

