#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QRegularExpression>

class Person
{
public:
    Person();
    Person(QString last_name, QString first_name, QString patronymic);
    Person(QString full_name);

    // функции для взаимодействия с член-данными
    void setLastName(const QString &last_name) { lastName_ = last_name; }
    void setFirstName(const QString &first_name) { firstName_ = first_name; }
    void setAtronymic(const QString &patronymic) { patronymic_ = patronymic; }

    const QString &last_name() const { return lastName_; }
    const QString &first_name() const { return firstName_; }
    const QString &patronymic() const { return patronymic_; }

private:
    //содержит ФИО, разбитое на поля
    QString lastName_;
    QString firstName_;
    QString patronymic_;
};

#endif // PERSON_H
