#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class FileTasks {
public:
    static void task1(const string& inputFile, const string& outputFile);
    static void task2(const string& inputFile, int n);
    static void task3(const string& inputFile, int maxPrice);
    static bool task4(const string& inputFile, int target);
    static int task5(const string& inputFile, int k);
    static void task6(const string& inputFile, const string& outputFile);
};

// Задание 1
void FileTasks::task1(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);
    if (!inFile || !outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    set<int> uniqueNumbers;
    int num;
    while (inFile.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        uniqueNumbers.insert(num);
    }
    for (int number : uniqueNumbers) {
        outFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
    }
    cout << "Задание 1 выполнено. Уникальные числа записаны." << endl;
}

// Задание 2
void FileTasks::task2(const string& inputFile, int n) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    vector<int> numbers;
    int num;
    while (inFile.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        numbers.push_back(num);
    }
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int idx = 0;
    for (int i = 0; i < n && idx < numbers.size(); i++) {
        for (int j = 0; j < n && idx < numbers.size(); j++) {
            matrix[i][j] = numbers[idx++];
        }
    }
    int maxProduct = 0, maxRow = 0;
    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            product *= matrix[i][j];
        }
        if (product > maxProduct) {
            maxProduct = product;
            maxRow = i;
        }
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = matrix[maxRow];
    }
    cout << "Задание 2 выполнено. Матрица обновлена." << endl;
}

// Задание 3
struct Toy {
    char name[50];
    int price;
    int minAge;
    int maxAge;
};

void FileTasks::task3(const string& inputFile, int maxPrice) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    Toy toy;
    cout << "Игрушки с ценой <= " << maxPrice << " руб. и подходящие для детей 5 лет:" << endl;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        if (toy.price <= maxPrice && toy.maxAge >= 5 && toy.minAge <= 5) {
            cout << "- " << toy.name << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Подходящих игрушек не найдено." << endl;
    }
}

// Задание 4
bool FileTasks::task4(const string& inputFile, int target) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return false;
    }
    int num;
    while (inFile >> num) {
        if (num == target) {
            return true;
        }
    }
    return false;
}

// Задание 5
int FileTasks::task5(const string& inputFile, int k) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 0;
    }
    int sum = 0, num;
    while (inFile >> num) {
        if (num % k == 0) {
            sum += num;
        }
    }
    return sum;
}

// Задание 6
void FileTasks::task6(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    if (!inFile || !outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        if (none_of(line.begin(), line.end(), ::isdigit)) {
            outFile << line << endl;
        }
    }
    cout << "Задание 6 выполнено. Строки без цифр переписаны." << endl;
}

// Главная функция
int main() {
    int choice;
    cout << "Выберите задание (1-6): ";
    cin >> choice;
    switch (choice) {
        case 1:
            FileTasks::task1("binary1.dat", "binary1_out.dat");
            break;
        case 2:
            FileTasks::task2("binary2.dat", 3);
            break;
        case 3:
            FileTasks::task3("toys.dat", 200);
            break;
        case 4:
            cout << (FileTasks::task4("text1.txt", 10) ? "Число найдено" : "Число не найдено") << endl;
            break;
        case 5:
            cout << "Сумма: " << FileTasks::task5("text2.txt", 5) << endl;
            break;
        case 6:
            FileTasks::task6("text3.txt", "text3_out.txt");
            break;
        default:
            cout << "Некорректный выбор." << endl;
    }
    return 0;
}

