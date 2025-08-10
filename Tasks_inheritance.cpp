#include <iostream>
#include <string>
#include <windows.h> 

using namespace std;

//За допомогою механізму успадкування, реалізуйте клас Aspirant, 
//похідний від Student(аспірант - це студент, який готується 
//до захисту кандидатської роботи).
//Тема кандидатської роботи - звичайне поле типу string.
//Переконатися в наявності 1 - 2 конструкторів, 
//і всіх необхідних геттерів / сеттерів у кожному з двох класів.
//Застосувати виклик конструктора базового класу, 
//а також для виклику 1 - 2 інших методів(наприклад, Print).

class Student {

private:

    string name;
    string surname;
    string faculty;
    string group;

public:

    Student(): Student("Тарас", "Шевченко", "Розробка ПЗ", "СПР411"){}
    
    Student(
        string name, 
        string surname, 
        string faculty, 
        string group) {

        setName(name);
        setSurname(surname);
        setFaculty(faculty);
        setGroup(group);  

    }

    void setName    (string name)    { this->name = name; }
    void setSurname (string surname) { this->surname = surname; }
    void setFaculty (string faculty) { this->faculty = faculty; }
    void setGroup   (string group)   { this->group = group; }

    string getName()    const { return name; }
    string getSurname() const { return surname; }
    string getFaculty() const { return faculty; }
    string getGroup()   const { return group; }

   
    void Print () const {
        cout << "Ім'я, Прізвище - " << getName() << " " << getSurname() << endl;
        cout << "Факультет      - " << getFaculty() << endl;
        cout << "Група          - " << getGroup() << endl;   
    }

};

class Aspirant : public Student {

private:

    string science_work;

public:

    Aspirant() { setScience_work("Computer vision in defence"); }

    Aspirant(string name, string surname, string faculty, string group, string science_work ): 
        Student(name, surname, faculty, group) { 

        setScience_work(science_work);
    }

    void setScience_work(string science_work) { this->science_work = science_work; }

    string getScience_work() const { return science_work; }

    void Print() const {
        Student::Print();
        cout << "Тема кандидатської роботи: " << getScience_work() << endl;
    }
};



//Створіть клас Passport(паспорт), який міститиме паспортну інформацію про громадянина України.
//За допомогою механізму успадкування, реалізуйте клас ForeignPassport(Закордонний паспорт), 
//похідний від Passport.Загран.паспорт містить крім паспортних даних, також дані про візи.
//Віза має бути представлена окремим класом.
//
//Створіть базовий клас Транспорт і його дочірні класи 
//Автомобіль, Таксі, Трамвай, Тролейбус, Маршрутка, Електросамокат, Поїзд, Літак, Велосипед.
//Створіть методи для розрахунку часу та вартості поїздки з Одеси до Харкова.
//
//Створіть базовий клас Фігура.Створіть похідні від нього Точка, Пряма, Еліпс, Багатокутник.
//Створіть похідний від Еліпса клас Коло.
//Створіть похідні від Багатокутника класи Трикутник і Чотирикутник.
//Створіть похідні від Трикутника класи 
//- ЗвичайнийГострокутнийТрикутник, 
//- РівнобедренийГострокутнийТрикутник, 
//- РівностороннійГострокутнийТрикутник, 
//- ЗвичайнийТупокутнийТрикутник, 
//- РівнобедренийТупокутнийТрикутник, 
//- ЗвичайнийПрямокутнийТрикутник, 
//- РівнобедренийПрямокутнийТрикутник.
//Створіть похідні від Чотирикутника класи 
//- Паралелограм, 
//- Трапеція, 
//- Дельтоїд.
//Створіть похідні від Паралелограма класи Прямокутник і Ромб.
//Створіть похідний від Прямокутника клас Квадрат.
//У базовому класі Фігура потрібно зробити методи Площа, Периметр, Намалювати.
//У похідних класах - перевизначити ці методи.
//
//Створіть базовий клас Pen с з методом Draw, 
//який відповідатиме за налаштування контуру(є поля : колір, товщина, тип).
//Створіть базовий клас Brush з методом Fill, який відповідає за налаштування заливки(є поля : колір).
//Створіть п'ять класів-спадкоємців класу Brush - 
//- SolidBrush, 
//- GradientBrush (додається масив кольорів), 
//- MatchBrush (додається другий колір і тип візерунка), 
//- TextureBrush (додається рядковий шлях до картинки),
//- VisualBrush (додається рядковий ідентифікатор елемента управління). 
//Створіть два класи-спадкоємці GradientBrush - 
//- LinearGradientBrush 
//- RadialGradientBrush. 
//Створіть базовий клас Geometry з полями типу Pen і Brush*. 
//Створіть похідні від Geometry класи Rectangle, Ellipse і Polyline. 
//Створіть клас Font, з такими параметрами, як 
//- розмір шрифту, 
//- сімейство шрифту, 
//- жирність, 
//- курсив, 
//- підкресленість, 
//- колір тексту шрифту. 
//- На основі деяких за допомоги множинного успадкування із цих типів спробуйте створити 
//- клас Button, для відображення кнопки (на кнопці має бути текст)!



int main()
{
    SetConsoleOutputCP(1251);

    Student Sevchenko;
    Sevchenko.Print();
    cout << "\n";

    Aspirant Franko("Іван", 
                    "Франко", 
                    "Гуманітарні науки", 
                    "Гр-2025", 
                    "Самовизнання штучного інтелекту");

    Franko.Print();
    cout << "\n";
}

