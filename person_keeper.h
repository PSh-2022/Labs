#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H
#include "person.h"
#include "Stack.h"
#include <fstream>
//шаблон singleton
class PersonKeeper
{
private:
    //Замечание по способу создания объекта:
    //1. объект класса создается через создание ссылки на объект (метод instance)
    PersonKeeper()= default;//конструктор по умолчанию: см пункт 1. и функцию instance
    ~PersonKeeper()= default;// нет член-данных, задаваемых динамически
   // Stack<Person> stack_; // стек ФИО
public:
    static PersonKeeper& instance(); //вернет ссылку на объект класса. static позволяет не создавать новый объект при вызове функции

    Stack<Person> readPersons(std::fstream& file); // ФИО из файла в стек
    void writePersons(Stack<Person> s, std::fstream& file); // ФИО из стека в файл

};
#endif // PERSON_KEEPER_H
