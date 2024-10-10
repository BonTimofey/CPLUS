#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <numeric>

using namespace std;

// 1. Заполнение дека D и вывод первой и второй половины в обратном порядке
void processDeque() {
    deque<int> D = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Первая половина в обратном порядке: ";
    for (auto it = D.rbegin() + D.size() / 2; it != D.rend(); ++it)
        cout << *it << " ";
    cout << "\nВторая половина в обратном порядке: ";
    for (auto it = D.rbegin(); it != D.rbegin() + D.size() / 2; ++it)
        cout << *it << " ";
    cout << endl;
}

// 2. Вставка последних 5 элементов дека перед пятым с конца элементом списка
void insertDequeElements() {
    deque<int> D = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> L = {11, 12, 13, 14, 15, 16, 17, 18};
    
    auto insertPos = L.end();
    advance(insertPos, -5);
    L.insert(insertPos, D.rbegin(), D.rbegin() + 5);
    
    cout << "Список после вставки: ";
    for (int x : L) cout << x << " ";
    cout << endl;
}

// 3. Перемещение среднего элемента списка в конец вектора
void moveMiddleElement() {
    list<int> L = {1, 2, 3, 4, 5};
    vector<int> V = {1, 4};

    auto mid = L.begin();
    advance(mid, L.size() / 2);

    V.push_back(*mid);
    L.erase(mid);

    cout << "Список после удаления среднего элемента: ";
    for (int x : L) cout << x << " ";
    cout << "\nВектор после добавления среднего элемента: ";
    for (int x : V) cout << x << " ";
    cout << endl;
}

// 5. Удаление элементов между первым и вторым отрицательным элементом
void removeBetweenNegatives(list<int> &L) {
    auto firstNeg = find_if(L.begin(), L.end(), [](int x) { return x < 0; });
    if (firstNeg == L.end()) return;

    auto secondNeg = find_if(next(firstNeg), L.end(), [](int x) { return x < 0; });
    if (secondNeg == L.end()) {
        L.erase(next(firstNeg), L.end());
    } else {
        L.erase(next(firstNeg), secondNeg);
    }
}

// 6. Копирование положительных элементов второй половины списка в начало
void copyPositives(list<int> &L) {
    list<int> result;
    auto mid = next(L.begin(), L.size() / 2);
    remove_copy_if(mid, L.end(), front_inserter(result), [](int x) { return x <= 0; });
    L.insert(L.begin(), result.begin(), result.end());
}

// 7. Сортировка дека по длине слов и алфавиту
void sortDequeByLength(deque<string> &D) {
    sort(D.begin(), D.end());
    cout << "После сортировки по алфавиту: ";
    for (const auto &s : D) cout << s << " ";
    cout << endl;

    stable_sort(D.begin(), D.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    cout << "После сортировки по длине: ";
    for (const auto &s : D) cout << s << " ";
    cout << endl;
}

// 8. Построение нового дека из списка слов
void adjacentPairs(list<string> &L, deque<string> &D) {
    adjacent_difference(L.begin(), L.end(), back_inserter(D),
                        [](const string &a, const string &b) {
                            return string(1, b[0]) + string(1, a.back());
                        });
    D.pop_front(); // Убираем первый элемент, который возвращает adjacent_difference

    cout << "Новый дек: ";
    for (const auto &s : D) cout << s << " ";
    cout << endl;
}

// 9. Поиск векторов, содержащих все элементы V0
int countVectorsWithV0(const vector<int> &V0, const vector<vector<int>> &vectors) {
    set<int> setV0(V0.begin(), V0.end());
    int count = 0;
    
    for (const auto &V : vectors) {
        set<int> setV(V.begin(), V.end());
        if (includes(setV.begin(), setV.end(), setV0.begin(), setV0.end())) {
            count++;
        }
    }
    return count;
}

// 10. Подсчёт повторений чисел в векторе
void countOccurrences(const vector<int> &V) {
    map<int, int> freq;
    for (const auto &x : V) freq[x]++;

    cout << "Частота элементов: ";
    for (const auto &p : freq) {
        cout << p.first << " - " << p.second << "; ";
    }
    cout << endl;
}

// Главное меню программы
void showMenu() {
    cout << "Выберите действие:\n";
    cout << "1. Первая задача (Дек)\n";
    cout << "2. Вторая задача (Дек и список)\n";
    cout << "3. Третья задача (Список и вектор)\n";
    cout << "5. Пятая задача (Удаление элементов)\n";
    cout << "6. Шестая задача (Копирование положительных)\n";
    cout << "7. Седьмая задача (Сортировка)\n";
    cout << "8. Восьмая задача (Создание дека)\n";
    cout << "9. Девятая задача (Поиск векторов)\n";
    cout << "10. Десятая задача (Подсчёт повторений)\n";
    cout << "0. Выход\n";
}

int main() {
    int choice;
    do {
        showMenu();
        cout << "Введите номер задачи: ";
        cin >> choice;
        switch (choice) {
            case 1:
                processDeque();
                break;
            case 2:
                insertDequeElements();
                break;
            case 3:
                moveMiddleElement();
                break;
            case 5: {
                list<int> L = {1, 2, -3, 4, 5, -6, 7};
                removeBetweenNegatives(L);
                for (int x : L) cout << x << " ";
                cout << endl;
                break;
            }
            case 6: {
                list<int> L = {-1, -2, 3, 4, 5, 6};
                copyPositives(L);
                for (int x : L) cout << x << " ";
                cout << endl;
                break;
            }
            case 7: {
                deque<string> D = {"apple", "pear", "banana", "kiwi", "plum"};
                sortDequeByLength(D);
                break;
            }
            case 8: {
                list<string> L = {"ABC", "DEF", "KLM", "XYZ"};
                deque<string> D;
                adjacentPairs(L, D);
                break;
            }
            case 9: {
                vector<int> V0 = {1, 2};
                vector<vector<int>> vectors = {{1, 2, 3}, {1, 2, 4}, {2, 3, 4}};
                cout << "Количество подходящих векторов: " << countVectorsWithV0(V0, vectors) << endl;
                break;
            }
            case 10: {
                vector<int> V = {1, 2, 2, 3, 3, 3, 4};
                countOccurrences(V);
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
