#pragma once
#include <string>

//main struct
struct Data
{
    int count;
    unsigned int udk;
    unsigned int pdata;
    std::string name;
    std::string sname;
    std::string title;
};


struct Node
{
    //adress
    Node* next;
    Node* prev;
    //data
    Data d;
};