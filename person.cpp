#include "person.h"
#include<iostream>

Person::Person(const std::string& full_name) // конструктор копирования строки
{
    //count_numbers - счетчик слов
    for (unsigned i = 0, count_numbers = 0; i < full_name.size(); i++) // пока не конец строки, идем по ней
        {
        //если пробел - переходим к следующему символу
            if (full_name[i] == ' '){
                if(full_name[i+1] != ' ') count_numbers++;//если следующий символ - не пробел, переходим к следующему слову
            }
            else if (!isalpha(full_name[i])) // если не буква
                throw std::runtime_error("Error: Person: incorrect character");//сообщение об ошибке - запись некорректна
            //runtime_error - класс служит базовым для всех исключений, создаваемых для сообщения об ошибках, которые можно обнаружить только при выполнении программы
            else  // иначе записываем букву в соответствующее поле
                switch(count_numbers){
                case(0):
                    lastName_ +=full_name[i];//запись буквы в фамилию
                    break;
                case(1):
                    firstName_ +=full_name[i];//запись буквы в имя
                    break;
                case(2):patronymic_ +=full_name[i];//запись буквы в отчество
                }
        }
}
