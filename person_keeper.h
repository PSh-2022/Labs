#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H
#include "person.h"
#include "Stack.h"
#include <fstream>
//шаблон singleton
class PersonKeeper
{
    PersonKeeper()= default;//конструктор по умолчанию, приватный
    ~PersonKeeper()= default;// нет член-данных, задаваемых динамически
public:
    static PersonKeeper& instance(); //статическая метод. Создается ссылка на объект класса.
   //используется для получения одиночки
    Stack<Person> readPersons(std::fstream& file); // ФИО из файла в стек
    void writePersons(Stack<Person> s, std::fstream& file); // ФИО из стека в файл
};
/*Статический метод или член класс означает, что он один и тот же на
все экземпляры (объекты) класса.
Статический член класса - это свойство, относящееся к классу в
целом, а не конкретному объекту.
• Статический член класса инициализируется вне класса, для того
чтобы была выделенная память компилятором в глобальном участке.
• static метод класса не имеет доступа к нестатическим членам
класса , так как у него нет указателя this. Для организации
работы с объектом, можно передать указатель на экземпляр класса.
• Статический член класс /метод класс можно использовать и без
создания экземпляра класса*/
/*здесь - расширенный singleton Майерса*/
#endif // PERSON_KEEPER_H
