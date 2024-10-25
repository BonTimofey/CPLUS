#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

// Задача 1.1: Точка координат
class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
// красивенький вывод
    string print() const {
        ostringstream oss;
        oss.precision(2);
        oss << fixed << "{" << x << ";" << y << "}";
        return oss.str();
    }

};
//создание точек и их вывод
void task1() {
    Point p1(1, 2), p2(3.5, 4.6), p3(-1.2, 7.8);
    cout << "Точка 1: " << p1.print() << endl;
    cout << "Точка 2: " << p2.print() << endl;
    cout << "Точка 3: " << p3.print() << endl;
}

// Задача 1.3: Имена
class Name {
// прописываем объекты, которые используем
private:
    string surname;
    string firstName;
    string middleName;
// прописываем переменные для имён
public:
    Name(string surname = "", string firstName = "", string middleName = "")
        : surname(surname), firstName(firstName), middleName(middleName) {}
// для красивого вывода
    string print() const {
        ostringstream oss;
        if (!surname.empty()) oss << surname;
        if (!firstName.empty()) oss << (oss.str().empty() ? "" : " ") << firstName;
        if (!middleName.empty()) oss << (oss.str().empty() ? "" : " ") << middleName;
        return oss.str();
    }
};

void task2() {
    Name n1("", "Клеопатра", "");
    Name n2("Пушкин", "Александр", "Сергеевич");
    Name n3("Маяковский", "Владимир", "");

    cout << "Имя 1: " << n1.print() << endl;
    cout << "Имя 2: " << n2.print() << endl;
    cout << "Имя 3: " << n3.print() << endl;
}

// Задача 2.1: Прямая
class Line {
private:
    Point start;
    Point end;
public:
    Line(Point start, Point end) : start(start), end(end) {}
    string print() const {
        return "Линия от " + start.print() + " до " + end.print();
    }
    Point getStart() const { return start; }
    Point getEnd() const { return end; }
    
    void setStart(Point p) { start = p; }
    void setEnd(Point p) { end = p; }
};

void task3() {
    // создаём наши изначальные линии
    Point p1(1, 3), p2(23, 8), p3(5, 10), p4(25, 10);

    Line line1(p1, p2);
    Line line2(p3, p4);
    Line line3(line1.getStart(), line2.getEnd());

    cout << line1.print() << endl;
    cout << line2.print() << endl;
    cout << line3.print() << endl;

    // меняем координаты
    line1.setStart(Point(2, 4));
    line1.setEnd(Point(20, 10));
    line2.setStart(Point(10, 10));
    line2.setEnd(Point(30, 10));
    line3.setStart(line1.getStart());
    line3.setEnd(line2.getEnd());

    cout << "Измененные линии:" << endl;
    cout << line1.print() << endl;
    cout << line2.print() << endl;
    cout << line3.print() << endl;
    

    line1.setStart(Point(50, 80));
    line1.setEnd(Point(40, 50));
    
    cout << "ещё раз измененные линии:" << endl;
    cout << line1.print() << endl;
    cout << line2.print() << endl;
    cout << line3.print() << endl;  
  
}

// Задача 3.3: Города
class City {
private:
    string name;
    vector<pair<City*, int>> paths;
public:
    City(const string& name) : name(name) {}
    City(const string& name, const vector<pair<City*, int>>& paths) : name(name), paths(paths) {}
    void addPath(City* Marshrut, int cost) {
        paths.push_back(make_pair(Marshrut, cost));
    }

    string print() const {
        ostringstream oss;
        oss << "Город: " << name << endl << "Пути:" << endl;
        for (const auto& path : paths) {
            oss << "  " << path.first->name << ": " << path.second << endl;
        }
        return oss.str();
    }
};

void task4() {
    // градостроение
    City A("A"), B("B"), C("C"), D("D"), E("E"), F("F");

    // копируем рисунок
    A.addPath(&B, 5);
    A.addPath(&D, 6);
    A.addPath(&F, 1);
    B.addPath(&A, 5);
    B.addPath(&C, 3);
    C.addPath(&D, 3);
    C.addPath(&B, 4);
    D.addPath(&E, 2);
    D.addPath(&C, 4);
    D.addPath(&A, 6);
    E.addPath(&F, 2);
    F.addPath(&B, 1);
    F.addPath(&E, 2);

    // вывод
    cout << A.print() << endl;
    cout << B.print() << endl;
    cout << C.print() << endl;
    cout << D.print() << endl;
    cout << E.print() << endl;
    cout << F.print() << endl;
}

// Задача 4.8: Создаём города
void task5() {
    // просто имя
    City MOSCOW("MOSCOW");

    // с путями
    vector<pair<City*, int>> paths = { {new City("B"), 5}, {new City("C"), 10} };
    City PERM("PERM", paths);

    cout << MOSCOW.print() << endl;
    cout << PERM.print() << endl;
}

// ----- Главное меню -----
int main() {
    int choice;

    do {
        cout << "Выберите задачу:\n";
        cout << "1 - Задача 1.1: Точка координат\n";
        cout << "2 - Задача 1.3: Имена\n";
        cout << "3 - Задача 2.1: Прямая\n";
        cout << "4 - Задача 3.3: Города\n";
        cout << "5 - Задача 4.8: Создаём города \n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 0:
                cout << "Выход." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
