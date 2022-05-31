#include "person.h"

Person::Person(){
}

Person::Person(QString last_name, QString first_name, QString patronymic): lastName_(last_name), firstName_(first_name), patronymic_(patronymic){
}

Person::Person(QString full_name)
{
    QStringList words = full_name.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts); // разбиваем полученную строку слова, слова не пусты( Qt::SkipEmptyParts)
    {
    if (words.size() != 2 && words.size() != 3) //определяем, соответствуют лиданные формату ввода: если в строке менее двух или более трех слов - ввод не соответствует формату, выводим сообщение об ошибке{
        throw "Error: Person(): Incorrect format of enter";
    }

    lastName_ = words[0]; // первое слово в строке - фамилия
    firstName_ = words[1]; // второе - имя

    if (words.size() == 3) // если есть 3-е слово - записываем отчество
    {
        patronymic_ = words[2];
    }
}
