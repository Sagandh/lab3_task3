#include <iostream>
#include "struct.h"
#include "list.h"
#include "library.h"
//TODO rest of task needs (DONE)
    //TODO add elements on list (DONE)
    //TODO print (DONE)
    //TODO main switch techo

/*
Составить программу, которая содержит текущую информацию о
книгах в библиотеке. Сведения о книгах включают:
номер УДК; фамилию и инициалы автора;
название; год издания;
количество экземпляров данной книги в библиотеке. Программа
должна обеспечивать:
начальное формирование данных обо всех книгах в библиотеке в
виде списка;
при выдаче каждой книги на руки вводится номер УДК, и программа
уменьшает значение количества книг на единицу или выдает
сообщение о том, что требуемой книги в библиотеке нет или
требуемая книга находится на руках;
при возвращении каждой книги вводится номер УДК, и программа
увеличивает значение количества книг на единицу;
по запросу выдаются сведения о наличии книг в библиотеке.
*/

int main (int argc, char const *argv[])
{   
    Node *pbeg = nullptr, *pend = nullptr;
    Data d;
    bool trigger = true;

    start(&pbeg, &pend);
    short int key;
    while(trigger)
    {
        std::system("clear");
        std::cout << "[1]   Добавить книгу в библиотеку" << std::endl
        << "[2]    Вывести всю информацию о книгах" << std::endl
        << "[3]    Добавить книгу" << std::endl
        << "[4]    Взять книгу" << std::endl
        << "[9]    Выйти из программы" << std::endl;
        std::cin >> key;
        
            switch (key)
            {
                case 1:
                    add_books(&pend);
                    break;
                case 2:
                    print_all_data(&pbeg);
                    break;
                case 3:
                    bring_book(&pbeg);
                    break;
                case 4:
                    take_book(&pbeg);
                    break;
                case 9:
                    trigger = false;
                    break;
                default:
                    break;
            }   
    }   
    return 0;
}