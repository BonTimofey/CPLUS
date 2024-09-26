#include <iostream>
using namespace std;

// Задача 2: Сумма знаков.
int sumLastNums(int x) {
    if (x < 10) {
        cout << "Число должно содержать не менее двух цифр!" << endl;
        return -1;
    }
    int last = x % 10;
    int secondLast = (x / 10) % 10;
    return last + secondLast;
}

// Задача 4: Есть ли позитив. 
bool isPositive(int x) {
    return x > 0;
}

// Задача 5: Двузначное. 
bool is2Digits(int x) {
    return (x >= 10 && x <= 99) || (x <= -10 && x >= -99);
}

// Задача 9: Равенство. 
bool isEqual(int a, int b, int c) {
    return (a == b && b == c);
}

// Задача 8: Делитель. 
bool isDivisor(int a, int b) {
    return (a % b == 0 || b % a == 0);
}
// вывод меню
void showMenu() {
    cout << "Выберите действие:\n";
    cout << "1. Задача 2 Сумма двух последних цифр числа\n";
    cout << "2. Задача 4 Проверка на положительность числа\n";
    cout << "3. Задача 5 Проверка, является ли число двузначным\n";
    cout << "4. Задача 9 Проверка равенства трёх чисел\n";
    cout << "5. Задача 8 Проверка, делится ли одно число на другое\n";
    cout << "0. Выход\n";
}

int main() {
    int choice;
    cout << "Задание 1 "<< endl;
    do {
        showMenu();
        cout << "Введите номер функции: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x;
                cout << "Введите число для суммирования двух последних цифр: ";
                cin >> x;
                int result = sumLastNums(x);
                if (result != -1) {
                    cout << "Сумма двух последних цифр: " << result << endl;
                }
                break;
            }
            case 2: {
                int x;
                cout << "Введите число для проверки на положительность: ";
                cin >> x;
                cout << (isPositive(x) ? "true" : "false") << endl;
                break;
            }
            case 3: {
                int x;
                cout << "Введите число для проверки на двузначность: ";
                cin >> x;
                cout << (is2Digits(x) ? "true" : "false") << endl;
                break;
            }
            case 4: {
                int a, b, c;
                cout << "Введите три числа для проверки на равенство: ";
                cin >> a >> b >> c;
                cout << (isEqual(a, b, c) ? "true" : "false") << endl;
                break;
            }
            case 5: {
                int a, b;
                cout << "Введите два числа для проверки на деление одного на другое: ";
                cin >> a >> b;
                cout << (isDivisor(a, b) ? "true" : "false") << endl;
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