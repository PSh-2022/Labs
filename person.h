#ifndef PERSON_H
#define PERSON_H

#include <string>
class Person
{
    //содержит ФИО, разбитое на поля
    std::string lastName_{};
    std::string firstName_{};
    std::string patronymic_{};

public:
    Person(){lastName_=""; firstName_=""; patronymic_="";}//конструктор по умолчанию
    Person(const std::string& last_name, const std::string& first_name, const std::string& patronimic)
    {lastName_= last_name; firstName_= first_name; patronymic_= patronimic;}; // конструктор из строк
    // функции для взаимодействия с член-данными
    //Устанавливаем значения член данных - lastName_, firstName_, patronymic_ соответственно
    void setLastName(const std::string &lastName) { lastName_ = lastName; }
    void setFirstName(const std::string &firstName) { firstName_ = firstName; }
    void setPatronymic(const std::string &patronymic) { patronymic_ = patronymic; }
    /*const удобен, если нужно передать параметры в
функцию, но при этом надо обязательно знать, что
переданный параметр не будет изменен.*/
    //Возвращаем значения член данных - lastName_, firstName_, patronymic_ соответственно
    std::string &getLastName() { return lastName_; }
    std::string &getFirstName() { return firstName_; }
    std::string &getPatronymic() { return patronymic_; }
};

#endif // PERSON_H
