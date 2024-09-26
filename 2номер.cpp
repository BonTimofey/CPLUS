#include <iostream>
#include <string>
using namespace std;

// Задача 1: Модуль числа. 
int abs(int x) {
    return x >= 0 ? x : -x;
}

// Задача 4: Строка сравнения
string makeDecision(int x, int y) {
    if (x > y) {
        return to_string(x) + " > " + to_string(y);
    } else if (x < y) {
        return to_string(x) + " < " + to_string(y);
    } else {
        return to_string(x) + " == " + to_string(y);
    }
}

// Задача 5:  Тройной максимум.
int max3(int x, int y, int z) {
    return (x > y ? (x > z ? x : z) : (y > z ? y : z));
}

// Задача 6: Тройная сумма. 
bool sum3(int x, int y, int z) {
    return (x + y == z) || (x + z == y) || (y + z == x);
}

// Задача 9: День недели
string day(int x) {
    switch (x) {
        case 1: return "понедельник";
        case 2: return "вторник";
        case 3: return "среда";
        case 4: return "четверг";
        case 5: return "пятница";
        case 6: return "суббота";
        case 7: return "воскресенье";
        default: return "это не день недели";
    }
}

// вывод меню
void showMenu() {
    cout << "Выберите действие:\n";
    cout << "1. Задача 1 Модуль числа\n";
    cout << "2. Задача 4 Сравнение двух чисел\n";
    cout << "3. Задача 5 Максимум из трех чисел\n";
    cout << "4. Задача 6 Проверка тройной суммы\n";
    cout << "5. Задача 9 Определение дня недели\n";
    cout << "0. Выход\n";
}

int main() {
    int choice;
    cout << "Задание 2 "<< endl;
    do {
        showMenu();
        cout << "Введите номер функции: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x;
                cout << "Введите число для нахождения модуля: ";
                cin >> x;
                cout << "Модуль числа: " << abs(x) << endl;
                break;
            }
            case 2: {
                int x, y;
                cout << "Введите два числа для сравнения: ";
                cin >> x >> y;
                cout << "Результат сравнения: " << makeDecision(x, y) << endl;
                break;
            }
            case 3: {
                int x, y, z;
                cout << "Введите три числа для нахождения максимума: ";
                cin >> x >> y >> z;
                cout << "Максимальное число: " << max3(x, y, z) << endl;
                break;
            }
            case 4: {
                int x, y, z;
                cout << "Введите три числа для проверки тройной суммы: ";
                cin >> x >> y >> z;
                cout << (sum3(x, y, z) ? "true" : "false") << endl;
                break;
            }
            case 5: {
                int x;
                cout << "Введите число для определения дня недели (1-7): ";
                cin >> x;
                cout << "День недели: " << day(x) << endl;
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
                break;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}
