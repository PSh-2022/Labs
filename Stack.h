#ifndef STACK_H
#define STACK_H

/*Класс должен поддерживать следующие операции:
1. Помещение объекта в стек
2. Извлечение объекта из стека
3. Получение размерности стека.*/
/*для реализации стека использую односвязный список(ос), т.к.
1. ос занимает меньший объем памяти чем, например, динамический массив
2. ос больше других структур данных отвечает принципу LIFO,
 в соответствии с которым организован стек*/
#include "EStackException.h"
#include "EStackEmpty.h"

#include <functional>
template <class T> class Stack
{
private:
    struct Node//узел
    {
        const T value_f;//значение узла
        Node *prev_f = nullptr;//указатель на предка в стеке
    };
    Node *last_f = nullptr; //последний узел
    int size_f = 0;//размер стека
public:
    ~Stack();//деструктор
    void Push(const T &val);//помещение объекта в стек
    const T Pop();//извлечение объекта из стека(извлекаю последний)
    int Size(){return size_f;};//получение размера стека
    void forEach(std::function<void(const T &value)> f) const; // функция перебора всех значений стека
    void Clear(); // удаление из стека всех узлов
};
template <class T> Stack<T>::~Stack()
{
    Clear();
}
template <class T> void Stack<T>:: Push(const T &val)
{
    Node *node = new Node{val, last_f};//создаем узел с указаннымзначением
    //проверяем, был ли создан узел
    if(node==nullptr)
    {
        throw EStackException("Unable to add element to stack: not enough memory\n");
    }
    last_f = node;//ставим новый узел в конец стека
    size_f++;//отражаем увеличение размера стека
}
template <class T> const T Stack<T>:: Pop()
{
    if(last_f == nullptr){throw EStackEmpty();}
    const T value = last_f->value_f;//запоминаем значение последнего узла

    //отмечаем предпоследний узел как последний
    Node *tmp = last_f;
    last_f = last_f->prev_f;
    delete tmp;

    size_f--;//отражаем уменьшение размера стека
    return value;//возвращаем значение последнего узла
}
// значения не удаляются, поэтому передаем их по ссылке
template <class T>void Stack<T>::forEach(std::function<void(const T &value)> f) const
{
    Node *it = last_f; // перебор всех элементов, начиная с последнего

    while (it != nullptr) // заканчивая первым
    {
        f(it->value_f); // функция обратной связи
        it = it->prev_f;
    }
}

template <class T> void Stack<T>::Clear(){
    while (last_f != nullptr)//пока есть элементы
    {
        //привязываем к last_f предпоследний узел и удаляем последний
        Node *tmp = last_f;
        last_f = last_f -> prev_f;
        delete tmp;
    }
}

#endif // STACK_H
