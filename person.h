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
    Person(const std::string& full_name); // конструктор из строки
    // функции для взаимодействия с член-данными
    //Устанавливаем значения член данных - lastName_, firstName_, patronymic_ соответственно
    void setLastName(const std::string &lastName) { lastName_ = lastName; }
    void setFirstName(const std::string &firstName) { firstName_ = firstName; }
    void setPatronymic(const std::string &patronymic) { patronymic_ = patronymic; }

    //Возвращаем значения член данных - lastName_, firstName_, patronymic_ соответственно
    std::string &getLastName() { return lastName_; }
    std::string &getFirstName() { return firstName_; }
    std::string &getPatronymic() { return patronymic_; }
};

#endif // PERSON_H
