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
#include "iostream"
#include <functional>
template <class T>
class Stack
{
private:
    //структура используется только внутри класса и только как
    //private-член => рационально объявить структуру в определении класса
    struct Node//узел
    {
        T value;//значение узла
        Node *next = nullptr;//указатель на потомка в стеке
    };
    Node *head = nullptr; //указатель на первый узел
    int size = 0;//размер стека
    //стек в начале пуст
public:
    Stack(const T* array = nullptr, int n = 0);//конструктор стека из массива
    Stack(const Stack <T>&copy);//конструктор копирования
    ~Stack();//деструктор
    void Push(const T &val);//помещение объекта в стек
    const T Pop();//извлечение объекта из стека(извлекаю первый)
    /*Функция класса, объявленная const, трактует this как указатель на константу.( Ключевое слово this представляет указатель на текущий объект данного класса.)
     В константных методах не может быть ничего присвоено переменным класса, которые не объявлены как static*/

    int Size(){return size;};//получение размера стека
    void Print(); //вывод стека
    bool Empty(){
        if (head)return false;
        return true;};// проверка на пустоту
    void Clear();//освободить стек
};
template <class T>
Stack<T>::Stack(const T* array, int n)//конструктор стека из массива
{
    if ((array && n == 0) || (!array && n != 0))    //проверяем, есть ли элементы в массиве и существует ли массив
    {
        //при ошибке в переданном массиве -  построим пустой стек
        head = nullptr; //указатель на первый узел
        size = 0;
    }
    else{//создаем стек
    head = nullptr;//первый узел стека пуст
    size = 0;//размер равен нулю
    for (int i = 0; i < n; i++)                     //запись элементов массива в стек
    {
        Node* head1 = head;//сохраняем вершину стека, создавая место для нового элемента
        head = new Node;//создаем элемент в вершине стека
        head->value = array[i];//задаем значение элемента
        head->next = head1;//ссылка на новую вершину
        size++;
    }}
}
template<typename T>
Stack<T>::Stack(const Stack& copy) // конструктор копирования
{
    head = nullptr;
    size = 0;

    if (copy.head ) // запись первого элемента в стек
    {
        head  = new Node;//новый узел - голова
        head ->value = copy.head ->value;//копируем значение головы
        size++;//увеличиваем размер

        Node* copyElem = copy.head ->next;//элемент для добавления в стек
        Node* thisElem = head;//элемент-предок copyElem
        while (copyElem) // записываем, пока стек не пуст
        {
            //запись нового элемента copyElem
            thisElem->next = new Node;
            thisElem = thisElem->next;
            thisElem->value = copyElem->value;

            copyElem = copyElem->next;//переход к следующему элементу в стеке
            size++;//увеличиваем размер
        }
        thisElem->next = nullptr; // элементы для записи кончились
    }
}
template <class T> Stack<T>::~Stack()
{
   Clear();
}
//помещает в начало стека узел с заданым значением
template <class T> void Stack<T>:: Push(const T &val)
{
    Node *node = new Node{val};//создаем узел с указанным значением
    node->next = head;//сдвигаем голову
    head = node;//ставим новый узел в голову стека
    size++;//отражаем увеличение размера стека
}
//извлекает объект из стека
template <class T> const T Stack<T>:: Pop()
{
    if(head == nullptr){throw EStackEmpty();}//для пустого стека - выбрасываем исключение
    const T val = head->value;//запоминаем значение головы
    Node *tmp = head;//ссылка на голову
    head = head->next;//передвигаем голову на следующий за ней элемент
    delete tmp;//удаляем старую голову

    size--;//отражаем уменьшение размера стека
    return val;//возвращаем значение удаленной головы
}
// вывод стека
template <class T> void Stack<T>::Print()
{
    Node* p = head;//создание нового узла хранящего голову
    while (p) {
        std::cout<< p->value <<" "; //вывод значений узлов
        p = p->next; //переход к следующему узлу
    }
}
template <class T> void Stack<T>::Clear(){
    while (head != nullptr)//пока есть элементы
    {
        while (head)// пока стек не пуст
            {
                Node* h=head; //ссылка на голову стека
                head=head->next; //перемещаем голову на следующий за ней узел
                delete h;// удаляем исходную голову
            }
        size = 0;//размер пустого стека равен 0
    }
}

#endif // STACK_H
