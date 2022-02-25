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
private:
    char *msg_f;//диагностическое сообщение
public:
    //конструктор
    EStackException(const char *msg)
    {
        //size_t sizeError; //strlcpy не видит
        msg_f = new char[strlen(msg)];//выделяем память для сообщения
        strcpy(msg_f,msg);//записываем сообщение. strlcpy не видит
    }
    //конструктор копирования
    EStackException(const  EStackException &obj)
    {
        msg_f = new char[strlen(obj.msg_f)];//выделяем память для сообщения
        strcpy(msg_f,obj.msg_f);//записываем сообщение. strlcpy не видит
    }
    //деструктор
    ~EStackException()
    {
        delete msg_f;//возвращаем память
    }
   // публичный метод char* what(), возвращающий диагностическое сообщение
    const char* what(){return msg_f;}
};

#endif // ESTACKEXCEPTION_H
