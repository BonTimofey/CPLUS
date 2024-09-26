#include <iostream>
#include <string>
using namespace std;

// задача 1: Числа подряд.
string listNums(int x) {
    string result = "";
    for (int i = 0; i <= x; i++) {
        result += to_string(i) + " ";
    }
    return result;
}

// задача 2: Числа наоборот. 
string reverseListNums(int x) {
    string result = "";
    for (int i = x; i >= 0; i--) {
        result += to_string(i) + " ";
    }
    return result;
}

// задача 3: Четные числа
string chet(int x) {
    string result = "";
    for (int i = 0; i <= x; i += 2) {
        result += to_string(i) + " ";
    }
    return result;
}

// задача 4: Степень числа.
int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

// задача 5: Длина числа. 
int numLen(long x) {
    int length = 0;
    do {
        length++;
        x /= 10;
    } while (x != 0);
    return length;
}

// вывод меню
void showMenu() {
    cout << "Выберите действие:\n";
    cout << "1. задача 1 Числа подряд (от 0 до x)\n";
    cout << "2. задача 2 Числа наоборот (от x до 0)\n";
    cout << "3. задача 3 Чётные числа (от 0 до x)\n";
    cout << "4. задача 4 Возведение числа в степень\n";
    cout << "5. задача 5 Количество знаков в числе\n";
    cout << "0. Выход\n";
}

int main() {
    int choice;
    cout << "Задание 3 "<< endl;
    do {
        showMenu();
        cout << "Введите номер функции: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x;
                cout << "Введите число x: ";
                cin >> x;
                cout << "Числа от 0 до " << x << ": " << listNums(x) << endl;
                break;
            }
            case 2: {
                int x;
                cout << "Введите число x: ";
                cin >> x;
                cout << "Числа от " << x << " до 0: " << reverseListNums(x) << endl;
                break;
            }
            case 3: {
                int x;
                cout << "Введите число x: ";
                cin >> x;
                cout << "Чётные числа от 0 до " << x << ": " << chet(x) << endl;
                break;
            }
            case 4: {
                int x, y;
                cout << "Введите основание x и степень y: ";
                cin >> x >> y;
                cout << x << " в степени " << y << " = " << pow(x, y) << endl;
                break;
            }
            case 5: {
                long x;
                cout << "Введите число x: ";
                cin >> x;
                cout << "Количество знаков в числе " << x << ": " << numLen(x) << endl;
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
