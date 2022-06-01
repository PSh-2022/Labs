#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H

#include <QString>
#include <QTextStream>
#include <QFile>

#include "person.h"
#include "Stack.h"
class PersonKeeper
{
public:
    static PersonKeeper &instance(){
        static PersonKeeper instance;
        return instance;
    }; //вернет ссылку на объект класса. static позволяет не создавать новый объект при вызове функции

    void readPersons(QString path); // ФИО из стека в файл
    void writePersons(QString path) const; // ФИО из файла в стек

    QStringList toQStringList() const; // конвертер из стека в список строк

    int Size(); // размер стека (возвращает количество личностей)
    void Clear(); // очистить хранилище личностей

private:
    //Замечания по способу создания объекта:
    //1. объект класса создается через создание ссылки на объект (метод instance)
    //2. все член-данные можно задать присвоением
    PersonKeeper(){};
    PersonKeeper(const PersonKeeper &);
    ~PersonKeeper(){// нет член-данных, задаваемых динамически
    };

    PersonKeeper &operator=(const PersonKeeper &);
    Stack<Person> stack_; // стэк ФИО
};
#endif // PERSON_KEEPER_H
