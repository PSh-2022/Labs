#include "person_keeper.h"
#include "person.h"
#include<fstream>
#include<iostream>
#include<string>

Stack<Person> PersonKeeper::readPersons( std::fstream& file)
{
     if (!file) // проверяем, возможно ли открыть файл. если нет - выбрасываем исключение(runtime_error - класс служит базовым для всех исключений, создаваемых для сообщения об ошибках, которые можно обнаружить только при выполнении программы)
        throw std::runtime_error("Error: readPersons():  Error of opening file for reading. File cannot be opened.\n");
     Stack<Person> stack, tstack;//стек временный(перевернутый) и итоговый
     std::string string_;//строка с ФИО
     while (std::getline(file, string_)) // пока файл не пуст, получаем строку из файла в переменную string_
         tstack.Push(Person(string_)); // добавляем ФИО во временный стек
     int tsize = tstack.Size();//получаем размер временного стека
     for (int i=0;i<tsize;i++)//добавляем ФИО из временного стека в исходный
         stack.Push(tstack.Pop());
     return stack;//возвращаем стек
}
//ФИО из стека в файл
void PersonKeeper::writePersons(Stack<Person> s, std::fstream& file)
{
    Stack <Person> sp(s);//копия стека s
    Person P;//временная переменная с ФИО
    //переписываем данные ФИО в файл
    for (int i=0;i<s.Size();i++){
        P = sp.Pop();//извлекаем одно ФИО из стека
    file<<P.getLastName()<<" "<<P.getFirstName()<<" "<<P.getPatronymic()<<"\n";//записываем в файл ФИО
    }
}
