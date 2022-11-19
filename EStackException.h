#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H

/*В случае попытки вызова операции извлечение объекта из
 *   стека при условии, что стек пуст, должно
 *   генерироваться исключение класса
 *    EStackEmpty(наследник класса EStackException)*/
/*класс должен содержать публичный метод char* what(),
 *  возвращающий диагностическое сообщение*/

#include <cstring>
class EStackException
{
    char *msg_d;//диагностическое сообщение
public:
    //конструктор
    EStackException(const char *msg)
    {
        //size_t sizeError; //strlcpy не видит
        msg_d = new char[strlen(msg)];//выделяем память для сообщения
        strcpy(msg_d,msg);//записываем сообщение.
    }
    //конструктор копирования
    EStackException(const  EStackException &obj)
    {
        msg_d = new char[strlen(obj.msg_d)];//выделяем память для сообщения
        strcpy(msg_d,obj.msg_d);//записываем сообщение.
    }
    //деструктор
    ~EStackException()
    {
        delete msg_d;//удаляем сообщение, освобождая память
    }
   // публичный метод char* what(), возвращающий диагностическое сообщение
    const char* what() const { return msg_d;}
};

#endif // ESTACKEXCEPTION_H
