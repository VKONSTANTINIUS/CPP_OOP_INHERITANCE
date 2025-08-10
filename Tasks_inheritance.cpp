#include <iostream>
#include <string>
#include <windows.h> 
#include <vector>

using namespace std;

//За допомогою механізму успадкування, реалізуйте клас Aspirant, 
//похідний від Student(аспірант - це студент, який готується 
//до захисту кандидатської роботи).
//Тема кандидатської роботи - звичайне поле типу string.
//Переконатися в наявності 1 - 2 конструкторів, 
//і всіх необхідних геттерів / сеттерів у кожному з двох класів.
//Застосувати виклик конструктора базового класу, 
//а також для виклику 1 - 2 інших методів(наприклад, Print).

// --- Базовий клас: Student ---
class Student {

private:

    string name;
    string surname;
    string faculty;
    string group;

public:
    // Конструктор за замовчуванням
    Student(): Student("Тарас", "Шевченко", "Розробка ПЗ", "СПР411"){} 
    
    // Параметризований конструктор
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

    // --- Сетери ---
    void setName    (string name)    { this->name = name; }
    void setSurname (string surname) { this->surname = surname; }
    void setFaculty (string faculty) { this->faculty = faculty; }
    void setGroup   (string group)   { this->group = group; }

    // --- Гетери ---
    string getName()    const { return name; }
    string getSurname() const { return surname; }
    string getFaculty() const { return faculty; }
    string getGroup()   const { return group; }

   // Виведення інформації
    void Print () const {
        cout << "Ім'я, Прізвище - " << getName() << " " << getSurname() << endl;
        cout << "Факультет      - " << getFaculty() << endl;
        cout << "Група          - " << getGroup() << endl;   
    }

};

// --- Похідний клас: Aspirant ---
class Aspirant : public Student {

private:

    string science_work;

public:

    // Конструктор за замовчуванням
    Aspirant() { setScience_work("Computer vision in defence"); }

    // Параметризований конструктор
    Aspirant(string name, 
             string surname, 
             string faculty, 
             string group, 
             string science_work ): 
        Student(name, surname, faculty, group) { 

        setScience_work(science_work);
    }

    // --- Сетер ---
    void setScience_work(string science_work) { this->science_work = science_work; }

    // --- Гетери ---
    string getScience_work() const { return science_work; }

    // Виведення інформації
    void Print() const {
        Student::Print(); // Виклик методу базового класу
        cout << "Тема кандидатської роботи: " << getScience_work() << endl;
    }
};



//Створіть клас Passport(паспорт), який міститиме паспортну інформацію про громадянина України.
//За допомогою механізму успадкування, реалізуйте клас ForeignPassport(Закордонний паспорт), 
//похідний від Passport.Загран.паспорт містить крім паспортних даних, також дані про візи.
//Віза має бути представлена окремим класом.

// --- Клас для візи ---
class Visa {

private:

    string country;      
    string expirydate;

public:
    // Конструктор з параметрами
    Visa(string country,
        string expirydate) {

        setCountry(country);
        setExpirydate(expirydate);

    }
    // Вивід інформації
    void Printvisa() const {

        cout << "   Країна - " << getCountry() << ", строк дії - " << getExpirydate() << endl;
    }
    // Сетери
    void setCountry(string country) { this->country = country; }
    void setExpirydate(string expirydate) { this->expirydate = expirydate; }
    // Гетери
    string getCountry()     const { return country; }
    string getExpirydate()  const { return expirydate; }

};

// --- Базовий клас Passport ---
class Passport {

private:

    string name;          // Ім'я
    string surname;       // Прізвище 
    string dateofbirth;   // Дата народження
    string placeofbirth;  // Місце народження
    string gender;        // Стать
    string passnumber;    // Номер паспорту
    string authority;     // Орган видачі
    string dateofissue;   // Дата видачі
    string dateofexpiry;  // Строк дії документу

public:
    // Констуктор з параметрами Passport
    Passport(string name,        
             string surname,
             string dateofbirth, 
             string placeofbirth,
             string gender,      
             string passnumber,  
             string authority, 
             string dateofissue, 
             string dateofexpiry) {

        setName(name);               
        setSurname(surname);
        setDateofbirth(dateofbirth); 
        setPlaceofbirth(placeofbirth);
        setGender(gender);
        setPassnumber(passnumber);   
        setAuthority(authority);
        setDateofissue(dateofissue); 
        setDateofexpiry(dateofexpiry);
    };

    // Сетери
    void setName         (string name)         { this->name = name; }
    void setSurname      (string surname)      { this->surname = surname; }
    void setDateofbirth  (string dateofbirth)  { this->dateofbirth = dateofbirth; }
    void setPlaceofbirth (string placeofbirth) { this->placeofbirth = placeofbirth; }
    void setGender       (string gender)       { this->gender = gender; }
    void setPassnumber   (string passnumber)   { this->passnumber = passnumber; }
    void setAuthority    (string authority)    { this->authority = authority; }
    void setDateofissue  (string dateofissue)  { this->dateofissue = dateofissue; }
    void setDateofexpiry (string dateofexpiry) { this->dateofexpiry = dateofexpiry; }
   
    // Гетери
    string getName()         const { return name; }
    string getSurname()      const { return surname; }
    string getDateofbirth()  const { return dateofbirth; }
    string getPlaceofbirth() const { return placeofbirth; }
    string getGender()       const { return gender; }
    string getPassnumber()   const { return passnumber; }
    string getAuthority()    const { return authority; }
    string getDateofissue()  const { return dateofissue; }
    string getDateofexpiry() const { return dateofexpiry; }

    // Вивід інформації
    void Print() const {
        cout << "\n======================================\n";
        cout << "Ім'я, Прізвище    - " << getName() << " " << getSurname() << endl;
        cout << "Дата народежння   - " << getDateofbirth() << endl;
        cout << "Місце народженння - " << getPlaceofbirth() << endl;
        cout << "Стать             - " << getGender() << endl;
        cout << "Номер             - " << getPassnumber() << "    Орган видачі - " << getAuthority() << endl;
        cout << "Дата видачі       - " << getDateofissue() << "  Сток дії - " << getDateofexpiry() << endl;
        
    }

};

// --- Похіднй клас ForeignPassport ---
class ForeignPassport : public Passport {

private: 
    
    vector <Visa> visalist;  // Масив, що зберігає перелік віз

public:
    // Констуктор з параметрами ForeignPassport
    ForeignPassport(string name,
                    string surname,
                    string dateofbirth,
                    string placeofbirth,
                    string gender,
                    string passnumber,
                    string authority,
                    string dateofissue,
                    string dateofexpiry):
        Passport(name, 
                 surname, 
                 dateofbirth, 
                 placeofbirth, 
                 gender, 
                 passnumber, 
                 authority, 
                 dateofissue, 
                 dateofexpiry){ 
    }

    // Додавання нової візи 
    void Addvisa(Visa visa) { visalist.push_back(visa); }

    // Вивід інформації
    void PrintForeign() const {

        Passport::Print();

        cout << "" << endl;
        if (visalist.empty()) { cout << "Візи відсутні" << endl; }
        else{
            for (auto const& visa : visalist) visa.Printvisa(); // Вивід переліку віз       
        }
    }
};



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

    // Тест виконання І завдання 
    Student Sevchenko;             //Створення об'єкта базового класу
    Sevchenko.Print();             //Виведення інформації 
    cout << "\n";

    Aspirant Franko("Іван",        //Створення об'єкта похідного класу 
                    "Франко", 
                    "Гуманітарні науки", 
                    "Гр-2025", 
                    "Самовизнання штучного інтелекту");

    Franko.Print();                //Виведення інформації 
    cout << "\n";

    // Тест виконання ІI завдання 
    Passport Ukr("Тарас",                 //Створення об'єкта базового класу
                 "Шевченко", 
                 "09.03.1814", 
                 "с.Моринці, Україна", 
                 "чол.", 
                 "АА123456", 
                 "7110", 
                 "01.02.1834", 
                 "02.02.1844");
    Ukr.Print();                         //Виведення інформації 

    Visa USA("США", "90 днів");          //Сворення об'єктів Visa
    Visa Schengen("Країни Шенгену", "120 днів");
    Visa Britain("Велика Британія", "30 днів");
    Visa Igypt("Єгипет", "360 днів");
    

    ForeignPassport Foreign1("Петро",       //Створення об'єкта похідного класу 
                             "Петренко", 
                             "01.02.2002", 
                             "Україна", 
                             "чол.", 
                             "FE456789",
                             "7115",
                             "03.04.2025", 
                             "03.04.2035");

    Foreign1.Addvisa(USA);                  //Додавання об'єктів Visa до паспорту
    Foreign1.Addvisa(Britain);

    Foreign1.PrintForeign();                //Виведення інформації 

    ForeignPassport Foreign2("Пес",
                             "Патрон",
                             "28.02.2022",
                             "Україна",
                             "чол.",
                             "FA111222",
                             "7110",
                             "03.04.2025",
                             "03.04.2035");

    Foreign2.Addvisa(USA);
    Foreign2.Addvisa(Schengen);
    Foreign2.Addvisa(Igypt);
    Foreign2.Addvisa(Britain);

    Foreign2.PrintForeign();

}

