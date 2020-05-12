#include "struct.h"
#include <iostream>

bool operator==(Data d1, Data d2)
{
    if(d1 == d2) return true;
    return false;
}

Node* first(Data d)
{
    Node *p = new Node;
    p->d = d;
    p->next = p->prev = nullptr;

    return p;
}

Node* find(Node* pbeg, Data d)
{
    Node* p = pbeg;

    while(p)
    {
        if(p->d == d) break;
        p = p->next;
    }
    return p;
}

void add(Node **pend, Data d)
{
    Node *p = new Node;
    p->d = d;
    p->next = nullptr;
    //TODO add elements on list
    //TODO print 
    //TODO main switch techo
    p->prev = *pend;

    (*pend)->next = p;
    *pend = p;
}

bool remove(Node** pbeg, Node** pend, Data d)
{
    if(Node* pkey = find(*pbeg, d))
    {
        if(pkey == *pbeg)
        {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = nullptr;
        }
        else if(pkey == *pend)
        {
            *pend = (*pend)->prev;
            (*pend)->next = nullptr;
        }
        else
        {
            (pkey->prev)->next == pkey->next;
            (pkey->next)->prev == pkey->prev;
        }
        delete pkey;
        return true;
    }
    return false;
}
void print_all(Node* pbeg)
{
    Data d;
    Node *p = pbeg;
    while(p)
    {
        std::cout << "Title:                  " << p->d.title  << '\n' 
        << "Author name:            " << p->d.name << '\n'
        << "Author second name:     " << p->d.sname << '\n'
        << "Date of publish:        " << p->d.pdata << '\n'
        << "UDK number:             " << p->d.udk << '\n'
        << "Count:                  " << p->d.count << '\n';
        p = p->next;
    }
}

Node* improve_search(Node* pbeg, Data d)
{
    Node *p = new Node;
    p = pbeg;
    while(p)
    {
        if(p->d.udk == d.udk) return p;
        p = p->next;

    }
    return nullptr;
}
