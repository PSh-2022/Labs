#include "person_keeper.h"

void PersonKeeper::readPersons(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // проверяем, возможно ли открыть файл на чтение. если нет - выбрасываем исключение
    {
        throw "Error: readPersons(): Error of opening file for reading. File cannot be opened.";
    }

    QTextStream stream(&file); // создаем поток, содержащие текстовые данные файла
    QString line; //содержит строки из файла

    while (stream.readLineInto(&line)) // строки из файла в line, читаем до конца файла
    {
        stack_.Push(Person(line)); //добавляем в стек объект класса Person. для создания объекта передаем в конструктор line, содержащий ФИО одного человека
    }

    file.close(); // закрываем файл
}

void PersonKeeper::writePersons(QString path) const
{
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) // проверяем, возможно ли открыть файл на чтение. если нет - выбрасываем исключение
    {
        throw "Error: writePersons():  Error of opening file for writening. File cannot be opened.";
    }
    QTextStream stream(&file);  // создаем поток, содержащие текстовые данные файла
    stack_.forEach([&](const Person &value) // перебираем значения в стеке
    {
        stream << value.last_name() << '\t' << value.first_name() << '\t' << value.patronymic() << Qt::endl; // записываем значения из стека в файл построчно
    });
    file.close(); // закрываем файл
}

// экспортируем данные в виде списка строк
QStringList PersonKeeper::toQStringList() const
{
    QStringList string_list; // создаем список строк
    stack_.forEach([&](const Person &value) // перебирая все личности
    {
        string_list.prepend(value.last_name() + " " + value.first_name() + " " + value.patronymic()); // записываем в список строк ФИО текущей личности
    });

    return string_list;
}

int PersonKeeper::Size()
{
    return stack_.Size();
}

void PersonKeeper::Clear()
{
    return stack_.Clear();
}
