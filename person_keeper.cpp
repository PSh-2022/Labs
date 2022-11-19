#include "person_keeper.h"
#include "person.h"
#include<fstream>
#include<iostream>
#include<string>

Stack<Person> PersonKeeper::readPersons( std::fstream& file)
{
     if (!file) // проверяем, возможно ли открыть файл на чтение. если нет - выбрасываем исключение
        throw std::runtime_error("Error: readPersons():  Error of opening file for reading. File cannot be opened.\n");
     Stack<Person> stack;//создаем стек, в который будем добавлять ФИО
     std::string string_;//временная переменная для сохранения строки с одним ФИО и последующей записи его в стек
     while (std::getline(file, string_)) // пока файл не пуст, получаем строку из файла в переменную string_
         stack.Push(Person(string_)); // добавляем личность в стек
     return stack;//возвращаем стек
}
//ФИО из стека в файл
void PersonKeeper::writePersons(Stack<Person> s, std::fstream& file)
{
    Stack <Person> sp(s), ts;//копия стека и временный пустой стек
    Person P;//временная переменная с ФИО
    //заполняем временный стек значениями из копии исходного стека
    for (int i=0;i<s.Size();i++)
        ts.Push(sp.Pop());
    //из временного стека переписываем данные ФИО в файл
    for (int i=0;i<s.Size();i++){
        P = ts.Pop();
    file<<P.getLastName()<<" "<<P.getFirstName()<<" "<<P.getPatronymic()<<"\n";//запись в файл
    }
}
