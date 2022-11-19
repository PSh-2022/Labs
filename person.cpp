#include "person.h"
#include<iostream>

Person::Person(const std::string& full_name) // конструктор копирования строки
{
    std::string temp;//временная строка для записи частей ФИО
    unsigned i = 0;//переменная-счетчик для движения по строке в стеке
    int count = 0;//счетчик числа слов
    //запись фамилии
    for (;count <3; i++) // идем по строке, пока не заполнилось ФИО
    {
        if (full_name[i] == ' ' ) // если пробел
            break; // выходим из цикла
        else {
            if (!isalpha(full_name[i])) // если не буква
                throw std::runtime_error("Error: Person: incorrect character");//запись некорректна
            else  // иначе запоминаем слово
                temp +=full_name[i];}
    }

    lastName_ = temp;
    count++;

    //запись имени
   temp.clear();//отчищаем для нового слова
    for (i++ ;i < full_name.size(); i++) // пока не конец строки, идем по ней
    {
        if (full_name[i] == ' ' ) //  если пробел
            break; // Выходим из цикла
        else{
            if (!isalpha(full_name[i])) // если не буква
                throw std::runtime_error("Error: Person: incorrect character");//запись некорректна
           else // иначе запоминаем слово
                temp +=full_name[i];}
    }

    firstName_ = temp;
    count++;

    //запись отчества
    temp.clear();//отчищаем для нового слова
    for (i++;i < full_name.size(); i++) // пока не конец строки, идем по ней
    {
        if (full_name[i] == ' ' ) //  если пробел
            break; // Выходим из цикла
        else{
            if (!isalpha(full_name[i])) // если не буква
                throw std::runtime_error("Error: Person: incorrect character");//запись некорректна
            else // иначе запоминаем слово
                temp +=full_name[i];}
    }

        patronymic_ = temp;
        count++;
}
