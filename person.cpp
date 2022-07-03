#include "person.h"

Person::Person(const std::string& full_name) // конструктор копирования строки
{
    bool isAlph = true;//проверка на корректность: корректной считаестя запись только из букв
    std::string temp;
    unsigned i = 0;
    int count = 0;
    for (;count <3; i++) // идем по строке, пока не заполнилось ФИО
    {
        if (full_name[i] == ' ' ) // если пробел
            break; // выходим из цикла
        else {
            if (!isalpha(full_name[i])) // если не буква
            isAlph = false;//запись некорректна
            else  // иначе запоминаем слово
                temp +=full_name[i];}
    }

    if(isAlph) //если слово корректно, записываем его в фамилию
    {
        lastName_ = temp;
        count++;
    }

    isAlph = true;//проверка на корректность: корректной считаестя запись только из букв
    temp.clear();//отчищаем для нового слова
    for (i++ ;i < full_name.size(); i++) // пока не конец строки, идем по ней
    {
        if (full_name[i] == ' ' ) //  если пробел
            break; // Выходим из цикла
        else{
            if (!isalpha(full_name[i])) // если не буква
                isAlph = false;//запись некорректна
            else // иначе запоминаем слово
                temp +=full_name[i];}
    }

    if(isAlph) //если слово корректно, записываем его в имя
    {
        firstName_ = temp;
        count++;
    }

    isAlph = true;//проверка на корректность: корректной считаестя запись только из букв
    temp.clear();//отчищаем для нового слова
    for (i++;i < full_name.size(); i++) // пока не конец строки, идем по ней
    {
        if (full_name[i] == ' ' ) //  если пробел
            break; // Выходим из цикла
        else{
            if (!isalpha(full_name[i])) // если не буква
                isAlph = false;//запись некорректна
            else // иначе запоминаем слово
                temp +=full_name[i];}
    }

    if(isAlph) //если слово корректно, записываем его в отчество
    {
        patronymic_ = temp;
        count++;
    }
}
