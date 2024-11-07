#include <iostream>
#include <cmath>
#include <limits>
#include <locale>

using namespace std;

class LineSegment {
private:
    double x;
    double y;

public:
    // Конструкторы
    LineSegment() : x(0.0), y(0.0) {}
    LineSegment(double start) : x(start), y(start + 1.0) {}
    LineSegment(double start, double end) : x(start), y(end) {}

    // Метод для проверки, находится ли число в отрезке
    bool isInSegment(double number) const {
        return number >= x && number <= y;
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const LineSegment& segment) {
        out << "Отрезок(" << segment.x << ", " << segment.y << ")";
        return out;
    }

    // Унарный оператор !
    double operator!() const {
        return abs(y - x);
    }

    // Унарный оператор ++ 
    LineSegment& operator++() {
        x += 1.0;
        y += 1.0;
        return *this;
    }

    // Оператор приведения к int (x)
    void toIntX() {
        x = static_cast<int>(x);
    }

    // Оператор приведения к double (y)
    void toDoubleY() {
        y = static_cast<double>(y);
    }

    // Бинарный оператор +
    LineSegment& operator+=(double d) {
        x += d;
        y += d;
        return *this;
    }

    // Бинарный оператор >
    bool operator>(int d) const {
        return d >= static_cast<int>(x) && d <= static_cast<int>(y);
    }
};

// Функция для проверки корректности ввода чисел типа double
bool getValidatedInput(double &start, double &end) {
    cout << "Введите начало и конец отрезка: ";
    if (cin >> start >> end) {
        return true;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Пожалуйста, введите числа типа double.\n";
        return false;
    }
}

// Функция для выполнения Задания 1
void runTask1() {
    double start, end, num;
    while (!getValidatedInput(start, end)) {}
    LineSegment segment(start, end);

    cout << "Введите число для проверки, находится ли оно в отрезке: ";
    while (!(cin >> num)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Пожалуйста, введите число типа double.\n";
    }

    cout << segment << "\n";
    cout << "Число " << num << (segment.isInSegment(num) ? " входит в отрезок." : " не входит в отрезок.") << "\n";
}

// Функция для выполнения Задания 2
void runTask2() {
    double start, end;
    while (!getValidatedInput(start, end)) {}
    LineSegment segment(start, end);

    int operation;
    do {
        cout << "\nТекущий отрезок: " << segment << "\n";
        cout << "Выберите операцию:\n";
        cout << "1. Вычислить длину отрезка (!)\n";
        cout << "2. Увеличить координаты границ на 1 (++ отрезок)\n";
        cout << "3. Привести координату x к типу int\n";
        cout << "4. Привести координату y к типу double\n";
        cout << "5. Увеличить границы отрезка на число d (+ d)\n";
        cout << "6. Проверить, входит ли целое число в отрезок (>)\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        if (!(cin >> operation)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
            continue;
        }

        switch (operation) {
            case 1:
                cout << "Длина отрезка: " << !segment << "\n";
                break;
            case 2:
                ++segment;
                cout << "Отрезок после увеличения: " << segment << "\n";
                break;
            case 3:
                segment.toIntX();
                cout << "Отрезок после приведения x к int: " << segment << "\n";
                break;
            case 4:
                segment.toDoubleY();
                cout << "Отрезок после приведения y к double: " << segment << "\n";
                break;
            case 5: {
                double d;
                cout << "Введите число для увеличения границ отрезка: ";
                while (!(cin >> d)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка ввода. Пожалуйста, введите число типа double.\n";
                }
                segment += d;
                cout << "Отрезок после увеличения на " << d << ": " << segment << "\n";
                break;
            }
            case 6: {
                int d;
                cout << "Введите целое число для проверки: ";
                while (!(cin >> d)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
                }
                cout << "Число " << d << (segment > d ? " входит в отрезок.\n" : " не входит в отрезок.\n");
                break;
            }
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Повторите попытку.\n";
        }
    } while (operation != 0);
}

int main() {
    int taskChoice;
    cout << "Выберите задание (1 или 2): ";
    while (!(cin >> taskChoice) || (taskChoice != 1 && taskChoice != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный выбор. Пожалуйста, введите 1 или 2: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (taskChoice == 1) {
        runTask1();
    } else {
        runTask2();
    }

    return 0;
}
