#include <iostream>
#include <cmath>
using namespace std;

// задача 1: Поиск первого значения. 
int findFirst(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// задача 2: Поиск последнего значения
int findLast(int arr[], int size, int x) {
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// задача 3: Поиск максимального.
int maxAbs(int arr[], int size) {
    int max_value = arr[0];
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) > abs(max_value)) {
            max_value = arr[i];
        }
    }
    return max_value;
}

// задача 6: Реверс 
void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}



// вывод массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// вывод меню
void showMenu() {
    cout << "Выберите действие:\n";
    cout << "1. Поиск первого вхождения числа\n";
    cout << "2. Поиск последнего вхождения числа\n";
    cout << "3. Поиск максимального по модулю значения\n";
    cout << "4. Реверс массива\n";
    cout << "0. Выход\n";
}

int main() {
    int choice;
    cout << "Задание 4 "<< endl;
    do {
        showMenu();
        cout << "Введите номер функции: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int size, x;
                cout << "Введите размер массива: ";
                cin >> size;
                int arr[size];
                cout << "Введите элементы массива: ";
                for (int i = 0; i < size; i++) {
                    cin >> arr[i];
                }
                cout << "Введите число для поиска: ";
                cin >> x;
                int result = findFirst(arr, size, x);
                if (result != -1) {
                    cout << "Первое вхождение числа " << x << " на позиции: " << result << endl;
                } else {
                    cout << "Число " << x << " не найдено в массиве." << endl;
                }
                break;
            }
            case 2: {
                int size, x;
                cout << "Введите размер массива: ";
                cin >> size;
                int arr[size];
                cout << "Введите элементы массива: ";
                for (int i = 0; i < size; i++) {
                    cin >> arr[i];
                }
                cout << "Введите число для поиска: ";
                cin >> x;
                int result = findLast(arr, size, x);
                if (result != -1) {
                    cout << "Последнее вхождение числа " << x << " на позиции: " << result << endl;
                } else {
                    cout << "Число " << x << " не найдено в массиве." << endl;
                }
                break;
            }
            case 3: {
                int size;
                cout << "Введите размер массива: ";
                cin >> size;
                int arr[size];
                cout << "Введите элементы массива: ";
                for (int i = 0; i < size; i++) {
                    cin >> arr[i];
                }
                cout << "Максимальное по модулю значение в массиве: " << maxAbs(arr, size) << endl;
                break;
            }
            case 4: {
                int size;
                cout << "Введите размер массива: ";
                cin >> size;
                int arr[size];
                cout << "Введите элементы массива: ";
                for (int i = 0; i < size; i++) {
                    cin >> arr[i];
                }
                reverse(arr, size);
                cout << "Массив после реверса: ";
                printArray(arr, size);
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
