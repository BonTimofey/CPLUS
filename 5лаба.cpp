#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

class FileTasks {
public:
    static void generateRandomBinaryFile(const string& inputFile, int numElements);
    static void generateTextFileWithNumbers(const string& inputFile, int numLines, int numPerLine);
    static void generateToyFile(const string& inputFile);
    static void task1(const string& inputFile, const string& outputFile);
    static void task2(const string& inputFile, int n);
    static void task3(const string& inputFile, int maxPrice);
    static bool task4(const string& inputFile, int target);
    static int task5(const string& inputFile, int k);
    static void task6(const string& inputFile, const string& outputFile);
};

//для бинарных файлов
void FileTasks::generateRandomBinaryFile(const string& inputFile, int numElements) {
    ofstream outFile(inputFile, ios::binary);
    if (!outFile) {
        cerr << "Ошибка при открытии файла для записи!" << endl;
        return;
    }
    srand(time(0));
    for (int i = 0; i < numElements; ++i) {
        int num = rand() % 100; //генерация случайного числа
        outFile.write(reinterpret_cast<const char*>(&num), sizeof(num));
    }
    cout << "Бинарный файл сгенерирован: " << inputFile << endl;
}

//для текстовых файлов
void FileTasks::generateTextFileWithNumbers(const string& inputFile, int numLines, int numPerLine) {
    ofstream outFile(inputFile);
    if (!outFile) {
        cerr << "Ошибка при открытии файла для записи!" << endl;
        return;
    }
    srand(time(0));
    for (int i = 0; i < numLines; ++i) {
        for (int j = 0; j < numPerLine; ++j) {
            outFile << rand() % 100 << " "; //генерация случайного числа
        }
        outFile << endl;
    }
    cout << "Текстовый файл сгенерирован: " << inputFile << endl;
}

// Задание 1: Бинарные файлы, исключение повторных чисел
void FileTasks::task1(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return;
    }

    ofstream outFile(outputFile, ios::binary);
    if (!outFile) {
        cerr << "Ошибка открытия выходного файла!" << endl;
        return;
    }

    vector<int> allNumbers; //для хранения всех чисел из файла.
    set<int> uniqueNumbers; //для хранения уникальных чисел.
    int num;

    //читаем числа из файла.
    while (inFile.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        allNumbers.push_back(num);
        uniqueNumbers.insert(num);
    }

    //записываем уникальные числа в выходной файл.
    for (int number : uniqueNumbers) {
        outFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
    }

    //вывод результатов.
    cout << "Задание 1 выполнено." << endl;
    cout << "Сгенерированные числа: ";
    for (int number : allNumbers) {
        cout << number << " ";
    }
    cout << endl;

    cout << "Уникальные числа: ";
    for (int number : uniqueNumbers) {
        cout << number << " ";
    }
    cout << endl;
}

// Задание 2: Бинарные файлы и матрица
void FileTasks::task2(const string& inputFile, int n) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return;
    }

    vector<int> numbers; //для хранения всех чисел из файла.
    int num;

    //читаем числа из файла.
    while (inFile.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        numbers.push_back(num);
    }

    //вывод сгенерированных чисел.
    cout << "Сгенерированные числа: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    //создаём квадратную матрицу n x n и заполняем её числами.
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int idx = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (idx < numbers.size()) {
                matrix[i][j] = numbers[idx++];
            } else {
                matrix[i][j] = 0; //заполнение нулями, если данных недостаточно.
            }
        }
    }

    //вывод первоначальной матрицы.
    cout << "Исходная матрица:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << setw(5) << val;
        }
        cout << endl;
    }

    //находим строку с максимальным произведением элементов.
    int maxProduct = 0, maxRow = 0;

    for (int i = 0; i < n; ++i) {
        int product = 1;
        for (int j = 0; j < n; ++j) {
            product *= matrix[i][j];
        }
        if (product > maxProduct) {
            maxProduct = product;
            maxRow = i;
        }
    }

    //заменяем все строки на строку с максимальным произведением.
    vector<int> maxRowData = matrix[maxRow];
    for (int i = 0; i < n; ++i) {
        matrix[i] = maxRowData;
    }

    //вывод обновлённой матрицы.
    cout << "Обновленная матрица:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << setw(5) << val;
        }
        cout << endl;
    }
}

//для игрушек
struct Toy {
    char name[50];
    int price;
    int minAge;
    int maxAge;
};

// Задание 3: Бинарные файлы и структуры
void FileTasks::task3(const string& inputFile, int maxPrice) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    Toy toy;
    bool found = false; //флаг

    cout << "Игрушки с ценой не более " << maxPrice << " и подходящие для детей 5 лет:" << endl;

    //считываем данные
    while (inFile.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        toy.name[sizeof(toy.name) - 1] = '\0'; // Убедимся, что имя игрушки корректное.

        //проверяем условия: 5 лет, и цена не превышает maxPrice
        if (toy.price <= maxPrice && toy.minAge <= 5 && toy.maxAge >= 5) {
            cout << "Название: " << toy.name
                 << ", Цена: " << toy.price
                 << ", Возраст: " << toy.minAge << "-" << toy.maxAge << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Подходящих игрушек не найдено." << endl;
    }
}
void generateToyFile(const string& inputFile) {
    ofstream outFile(inputFile, ios::binary);
    if (!outFile) {
        cerr << "Ошибка при открытии файла для записи!" << endl;
        return;
    }

    //создаём игрушки
    vector<Toy> toys = {
            {"Медведь плюшевый", 1000, 3, 8},
            {"Конструктор LEGO", 3000, 6, 12},
            {"Кукла Барби", 1500, 5, 10},
            {"Машинка Hot Wheels", 800, 4, 9},
            {"Пазл 500 деталей", 600, 7, 14}
    };

    // Записываем игрушки в бинарный файл
    for (const Toy& toy : toys) {
        outFile.write(reinterpret_cast<const char*>(&toy), sizeof(Toy));
    }

    cout << "Бинарный файл с игрушками успешно сгенерирован: " << inputFile << endl;
}
// Задание 4: Текстовые файлы
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

// Задание 5: Текстовые файлы
int FileTasks::task5(const string& inputFile, int k) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 0;
    }
    int sum = 0, num;
    cout << "Числа, кратные " << k << ": ";
    while (inFile >> num) {
        if (num % k == 0) {
            cout << num << " ";  //выводим числа, кратные k
            sum += num;
        }
    }
    cout << endl;
    return sum;
}

// Задание 6: Текстовые файлы
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

int main() {
    int choice;
    cout << "Выберите задание (3-6) (1-2 в разработке): ";
    cin >> choice;

    switch (choice) {
        case 1:
            FileTasks::generateRandomBinaryFile("binary1.dat", 20); //генерация 20 элементов
            FileTasks::task1("binary1.dat", "binary1_out.dat");
            break;
        case 2:
            int n;
            cout << "Введите n: ";
            cin >> n;
            FileTasks::generateRandomBinaryFile("binary2.dat", 20); //генерация 20 элементов
            FileTasks::task2("binary2.dat", n);
            break;
        case 3: {
            generateToyFile("toys.dat"); // Генерация файла с игрушками
            int maxPrice;
            cout << "Введите максимальную цену игрушки: ";
            cin >> maxPrice;
            FileTasks::task3("toys.dat", maxPrice);
            break;
        }
        case 4: {
            int target;
            cout << "Введите число для поиска в файле: ";
            cin >> target;
            FileTasks::generateTextFileWithNumbers("text1.txt", 100, 1); // генерация 100 чисел
            cout << (FileTasks::task4("text1.txt", target) ? "Число найдено" : "Число не найдено") << endl;
            break;
        }
        case 5: {
            int k;
            cout << "Введите число для подсчета суммы элементов, кратных k: ";
            cin >> k;
            FileTasks::generateTextFileWithNumbers("text2.txt", 10, 1); // генерация 10 чисел
            cout << FileTasks::task5("text2.txt", k) << endl;
            break;
        }
        case 6:
            FileTasks::task6("text3.txt", "text3_out.txt"); 
            break;
        default:
            cout << "Некорректный выбор." << endl;
    }
    return 0;
}
