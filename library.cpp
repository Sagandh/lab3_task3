#include <iostream>
#include <limits>
#include "list.h"

std::string get_string()
{
    return 0;
}
int int_check(void)
{
    int tmp;
    while(!(std::cin >> tmp) || tmp <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You should write a natural number! Please, try again!";
        std::cin.ignore(1024, '\n');
        std::cout << "Press enter to continue . . . ";
        std::cin.get();
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
    return tmp;
}

int date_check(void)
{
    int tmp;
    bool trigger = true;
    while(trigger)
    {
        tmp = int_check();
        if(tmp > 2050 || tmp < 1500)
        {
            std::system("clear");
            std::cout << "Incorect input!";
            std::cout << "Enter the year of publishing of this book"<< std::endl;
        }
        else
        {
            trigger = false;
        }
        
    }
    return tmp;
    
}




void start(Node** pbeg, Node** pend)
{
    std::system("clear");
    Data d;
    std::cout << "What a title of book do you want to add?"<< std::endl;
    std::cin.ignore(-1);
    getline(std::cin, d.title);
    std::cout << "What is an author name?"<< std::endl;
    std::cin.ignore(-1);
    getline(std::cin, d.name);
    std::cout << "What an author second name??"<< std::endl;
    std::cin.ignore(-1);
    getline(std::cin, d.sname);
    std::cout << "Enter the count of this books"<< std::endl;
    
    int tbook = int_check();
    std::cout << "Enter the udk number of this books"<< std::endl;
    int tudk = int_check();
    std::cout << "Enter the year of publishing of this books"<< std::endl;
    int tyear = date_check();


    d.count = tbook;
    d.udk = tudk;
    d.pdata = tyear;

    *pbeg = first(d);
    *pend = *pbeg;
}

void add_books(Node** pend)
{
    std::system("clear");
    Data d;
    std::cout << "What a title of book do you want to add?" << std::endl;
    std::cin.ignore(-1);
    getline(std::cin, d.title);
    std::cout << "What is an author name?"<< std::endl;
    std::cin.ignore(-1);
    getline(std::cin, d.name);
    std::cout << "What an author second name??"<< std::endl;
    std::cin.ignore(-1);
    getline(std::cin, d.sname);
    std::cout << "Enter the count of this books"<< std::endl;
    int tbook = int_check();
    std::cout << "Enter the udk number of this books"<< std::endl;
    int tudk = int_check();
    std::cout << "Enter the year of publishing of this books"<< std::endl;
    int tyear = date_check();

    d.count = tbook;
    d.udk = tudk;
    d.pdata = tyear;

    add(pend, d);
}

void print_all_data(Node** pbeg)
{
    std::system("clear");
    std::cout << "There are all data of library:    " << std::endl;
    print_all(*pbeg);
    
    std::cin.ignore(1024, '\n');
    std::cout << "Press enter to continue . . . ";
    std::cin.get();
}

void bring_book(Node** pbeg)
{
    Data tmp;
    Data d;
    Node* p;
    std::cout << "Enter the udk number:    "<< std::endl;
    tmp.udk = int_check();

    if(p = improve_search(*pbeg, tmp))
    {
        p->d.count++;
        std::cout <<"Success"<< std::endl;
    }
    else
    {
        std::cout <<"You wrote the wrong udk number! Try again!" << std::endl;
    }
}

void take_book(Node** pbeg)
{
    Data tmp, d;
    Node *p;

    std::cout << "Enter the udk number:    "<< std::endl;
    tmp.udk = int_check();

    if(p = improve_search(*pbeg, tmp))
    {
        if(p->d.count <= 0)
        {
            std::cout << "There are no this books in the library!"<< std::endl;
        }
        else if(p->d.count > 0)
        {
            p->d.count--;
            std::cout << "Succes!"<< std::endl;
        }
        else
        {
            std::cout << "ERROR"<< std::endl;
        }
        std::cin.ignore(1024, '\n');
        std::cout << "Press enter to continue . . . ";
        std::cin.get();
        
    }
}