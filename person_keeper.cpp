#include "person_keeper.h"
#include "person.h"
#include<fstream>
#include<iostream>
#include<string>

Stack<Person> PersonKeeper::readPersons( std::fstream& file)
{
     if (!file) // проверяем, возможно ли открыть файл. если нет - выбрасываем исключение(runtime_error - класс служит базовым для всех исключений, создаваемых для сообщения об ошибках, которые можно обнаружить только при выполнении программы)
        std::cout<<("Error: readPersons():  Error of opening file for reading. File cannot be opened.\n");
     Stack<Person> stack, tstack;//стек временный(перевернутый) и итоговый
     std::string string_;//строка с ФИО
     while (std::getline(file, string_)) // пока файл не пуст, получаем строку из файла в переменную string_
     {
         std::string *name = partition(string_);
         tstack.Push(Person(*name, *(name+1), *(name+2))); // добавляем ФИО во временный стек
         delete[] name;
     }
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

std::string* PersonKeeper::partition(const std::string& full_name)
{
    std::string *name = new std::string[3];
    int count_numbers = 0;//count_numbers - счетчик слов
    bool isntalpha = 0;// 0 - все символы в слове корректны, 1 - есть некорректный символ в слове
    for (unsigned i = 0; i < full_name.size(); i++) // пока не конец строки, идем по ней
        {
        //если пробел - переходим к следующему символу
            if (full_name[i] == ' '){
                if(full_name[i+1] != ' ')
                {
                    count_numbers++;//если следующий символ - не пробел, переходим к следующему слову
                    isntalpha = 0;
                }
            }
            else if(!isntalpha)//если все ранее встреченные символы в слове - буквы
            {
                if (!isalpha(full_name[i])) // если не буква
                   {
                        std::cout<<(" Error: incorrect character");//сообщение в консоли об ошибке - запись некорректна
                        if(count_numbers == 2)
                            std::cout<<"\n";
                        name[count_numbers] = "";//часть ФИО, в которой найдена ошибка, заменяется на пустую строку
                        isntalpha = 1;//отмечаем, что нашли неккорректный символ
                }
                else
                    name[count_numbers] += full_name[i];
            }
    }
    return name;
}
