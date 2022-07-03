#include"person_keeper.h"
#include "Stack.h"
#include <iostream>
#include<fstream>
#include "iostream"
int main()
{
    //тестрирование
  /* //Часть 1: Стек
   //1: Пустой стек
    std::cout << "Test 1: Empty stack\n";
    Stack <int> S;//пустой стек
    try{S.Pop();//пытаемся достать голову стека
    }
    catch(EStackEmpty& e){
        std::cout << e.what() <<"\n";
    }
    S.Clear();
    std::cout <<"\n";
    //2: Проверка функции Push()
    std::cout << "Test 2: function Push\n";
    for(int i = 3; i > 0 ; i--)
        S.Push(i);//пробуем добавить узел в стек
    //6.1: Проверка функции Print(): непустой стек
    S.Print();//выводим стек
    std::cout <<"\n\n";
    //3: Проверка функции Pop()
    std::cout << "Test 3: function Pop\n";
    S.Pop();
    S.Print();//выводим стек
    std::cout <<"\n\n";
    //4: Проверка функции Size(): непустой стек
    std::cout << "Test 4: Size of an unempty stack\n";
    std::cout<<S.Size();//выводим размер стека
    //7.1: Проверка функции Clear(): непустой стек
    S.Clear();
    std::cout <<"\n\n";
    //5: Проверка функции Size(): пустой стек
    std::cout << "Test 5: Size of an empty stack\n";
    std::cout<<S.Size();//выводим размер стека
    //6.2: Проверка функции Print(): пустой стек
    std::cout <<"\n6.2: Check function Print(): empty stack\n";
    S.Print();//выводим стек
    //7.2: Проверка функции Clear(): пустой стек
    std::cout <<"\n6.2: Check function Clear(): empty stack\n";
    S.Clear();
    std::cout <<"end of 1 part of testing\n\n";

*/

    //Часть 2: Person keeper
    std::fstream File, File1;

/*
    //1. файл пуст
    File.open("file1.txt", std::ios_base::in); // Открываем пустой файл на чтение
    Stack<Person> Persons1 = PersonKeeper::instance().readPersons(File); // Считываем из файла
    File1.open("file1.txt",std::ios_base::out); // Открываем пустой файл на запись
    PersonKeeper::instance().writePersons(Persons1, File1); // Записываем в файл

*/    //2. файл существует, данные корректны
    File.open("C:\\Labs\\file.txt", std::ios_base::in); // Открываем файл на чтение

    Stack<Person> Persons2 = PersonKeeper::instance().readPersons(File); // Считываем из файла
    File1.open("C:\\Labs\\file1.txt",std::ios_base::out); // Открываем файл на запись
    PersonKeeper::instance().writePersons(Persons2, File1); // Записываем в файл

  /* //3. данные введены некорректно
    File1.open("C:\\Labs\\incor.txt", std::ios_base::in); // Открываем файл на чтение
    try {
    PersonKeeper::instance().readPersons(File1);
    }
    catch( std::exception& e) {
    std::cerr << e.what() << std::endl;
    }

  //4. файл не существует
    File.open("ex4.txt", std::ios_base::in); // Открываем несуществующий файл на чтение
    Stack<Person> Persons4 = PersonKeeper::instance().readPersons(File); // Считываем из файла
    File1.open("ex4.txt",std::ios_base::out); // Открываем несуществующий файл на запись
    PersonKeeper::instance().writePersons(Persons4, File1); // Записываем в файл
*/
    return 0;
}
