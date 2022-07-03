#include "person_keeper.h"
#include "person.h"
#include<fstream>
#include<iostream>
#include<string>

PersonKeeper& PersonKeeper::instance()
{
    static PersonKeeper keeper;// static, тк создаем единственный объект
    return keeper;
}

Stack<Person> PersonKeeper::readPersons( std::fstream& file)
{
     if (!file) // проверяем, возможно ли открыть файл на чтение. если нет - выбрасываем исключение
        throw std::runtime_error("Error reading file. File not found\n");


       Stack<Person> stack;
       std::string string_;

       while (std::getline(file, string_)) // пока файл не пуст
           stack.Push(Person(string_)); // добавляем личность в стек
       return stack;
}
//ФИО из стека в файл
void PersonKeeper::writePersons(Stack<Person> s, std::fstream& file)
{
    if (!file) // проверяем, возможно ли открыть файл на запись. если нет - выбрасываем исключение
        throw std::runtime_error("Error: writePersons():  Error of opening file for writening. File cannot be opened.");


    Stack <Person> sp(s), ts;//копия стека и временный пустой стек
    Person P, tmp;//личность и временная переменная, чтобы не потерять информацию в стеке

    int i = 0;
    //заполняем временный стек значениями из копии исходного стека
    while(i < s.Size()){
    tmp = sp.Pop();
    ts.Push(tmp);
    i++;}

    i = 0;
    //из временного стека переписываем данные ФИО в файл
    while(i < s.Size()){
        P = ts.Pop();
    file<<P.last_name()<<" "<<P.first_name()<<" "<<P.patronymic()<<"\n";//запись в файл
    i++;}
}
