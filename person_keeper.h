#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H
#include "person.h"
#include "Stack.h"
#include <fstream>
//шаблон singleton
class PersonKeeper
{
    PersonKeeper()= default;//конструктор по умолчанию
    ~PersonKeeper()= default;// нет член-данных, задаваемых динамически
public:
    static PersonKeeper& instance(){
        static PersonKeeper keeper;// static, тк создаем единственный объект
        return keeper;
    }; //статическая метод. Создается ссылка на объект класса.
    Stack<Person> readPersons(std::fstream& file); // ФИО из файла в стек
    void writePersons(Stack<Person> s, std::fstream& file); // ФИО из стека в файл

};
#endif // PERSON_KEEPER_H
