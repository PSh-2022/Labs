#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <QRegularExpression>

class Person
{
private:
    //содержит ФИО, разбитое на поля
    std::string lastName_{};
    std::string firstName_{};
    std::string patronymic_{};

public:
    Person(){lastName_=""; firstName_=""; patronymic_="";}//конструктор но умолчанию
    Person(const std::string& full_name); // конструктор копирования строки

    // функции для взаимодействия с член-данными
    //Устанавливаем значения член данных - lastName_, firstName_, patronymic_ соответственно
    void setLastName(const std::string &last_name) { lastName_ = last_name; }
    void setFirstName(const std::string &first_name) { firstName_ = first_name; }
    void setPatronymic(const std::string &patronymic) { patronymic_ = patronymic; }

    //Возвращаем значения член данных - lastName_, firstName_, patronymic_ соответственно
    const std::string &last_name() const { return lastName_; }
    const std::string &first_name() const { return firstName_; }
    const std::string &patronymic() const { return patronymic_; }

};

#endif // PERSON_H
