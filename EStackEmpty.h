#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H
/*В случае попытки вызова операции извлечение объекта из
 *   стека при условии, что стек пуст, должно
 *   генерироваться исключение класса
 *    EStackEmpty(наследник класса EStackException)*/

#include "EStackException.h"

class EStackEmpty : public EStackException // EStackEmpty - наследник класса EStackException
{
public:
    //конструктор
    EStackEmpty():EStackException("This stack is empty. "){}
};

#endif // ESTACKEMPTY_H
