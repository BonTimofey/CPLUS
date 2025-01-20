#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <set>
#include <cctype>
using namespace std;

// Задание 1: Однонаправленный список
class SingleLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };
    Node* head;
    Node* tail; 

public:
    SingleLinkedList() : head(nullptr), tail(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void remove(int value) {
        Node** current = &head;
        while (*current) {
            if ((*current)->value == value) {
                Node* temp = *current;
                *current = (*current)->next;
                if (temp == tail) {
                    tail = nullptr;
                }
                delete temp;
            } else {
                current = &(*current)->next;
            }
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Задание 2: Двунаправленный список
class DoubleLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
        Node(int val) : value(val), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void reverseBetween(int value) {
        Node* first = nullptr;
        Node* last = nullptr;
        Node* current = head;

        while (current) {
            if (current->value == value) {
                if (!first) first = current;
                last = current;
            }
            current = current->next;
        }

        if (!first || !last || first == last) {
            cout << "Перестановка невозможна. Элемент встречается менее двух раз." << endl;
            return;
        }

        Node* left = first;
        Node* right = last;

        while (left != right && left->prev != right) {
            swap(left->value, right->value);
            left = left->next;
            right = right->prev;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Задания 3 и 4: Уникальный список
class UniqueList {
private:
    unordered_set<string> elements;

public:
    void add(const string& value) {
        elements.insert(value);
    }

    void remove(const string& value) {
        elements.erase(value);
    }

    UniqueList Union(const UniqueList& other) const {
        UniqueList result = *this;
        for (const auto& elem : other.elements) {
            result.add(elem);
        }
        return result;
    }

    UniqueList Except(const UniqueList& other) const {
        UniqueList result;
        for (const auto& elem : elements) {
            if (other.elements.find(elem) == other.elements.end()) {
                result.add(elem);
            }
        }
        return result;
    }

    UniqueList Intersect(const UniqueList& other) const {
        UniqueList result;
        for (const auto& elem : elements) {
            if (other.elements.find(elem) != elements.end()) {
                result.add(elem);
            }
        }
        return result;
    }

    void display() {
        for (const auto& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};



// Задание 5: Словарь
class Dictionary {
private:
    map<string, string> data;

public:
    void add(const string& key, const string& value) {
        data[key] = value;
    }

    void remove(const string& key) {
        data.erase(key);
    }

    void display() {
        for (const auto& [key, value] : data) {
            cout << key << ": " << value << endl;
        }
    }

    double averagePerDepartment() {
        map<string, int> departmentCount;

        for (const auto& [key, value] : data) {
            string department = value.substr(0, value.size() - 2);
            departmentCount[department]++;
        }

        int totalEmployees = data.size();
        int totalDepartments = departmentCount.size();

        return totalDepartments > 0 ? (double)totalEmployees / totalDepartments : 0.0;
    }
};

int main() {
    int choice;
    cout << "Выберите задание (1-5): ";
    cin >> choice;

    switch (choice) {
    case 1: {
        SingleLinkedList list;
        int n, value, toRemove;
        cout << "Введите количество элементов в списке: ";
        cin >> n;
        cout << "Введите элементы списка: ";
        for (int i = 0; i < n; ++i) {
            cin >> value;
            list.add(value);
        }
        cout << "Введите значение для удаления: ";
        cin >> toRemove;
        list.remove(toRemove);
        cout << "Результат: ";
        list.display();
        break;
    }
    case 2: {
        DoubleLinkedList list;
        int n, value, toReverse;
        cout << "Введите количество элементов в списке: ";
        cin >> n;
        cout << "Введите элементы списка: ";
        for (int i = 0; i < n; ++i) {
            cin >> value;
            list.add(value);
        }
        cout << "Введите значение, между первым и последним вхождениями которого нужно переставить элементы: ";
        cin >> toReverse;
        cout << "Изначальный список: ";
        list.display();
        list.reverseBetween(toReverse);
        cout << "Список после перестановки: ";
        list.display();
        break;
    }
    case 3: {
        UniqueList list1, list2;
        int n1, n2;
        string value;
        cout << "Введите количество фильмов в первом списке: ";
        cin >> n1;
        cout << "Введите фильмы первого списка: ";
        for (int i = 0; i < n1; ++i) {
            cin >> value;
            list1.add(value);
        }
        cout << "Введите количество фильмов во втором списке: ";
        cin >> n2;
        cout << "Введите фильмы второго списка: ";
        for (int i = 0; i < n2; ++i) {
            cin >> value;
            list2.add(value);
        }

        UniqueList unionList = list1.Union(list2);
        UniqueList exceptList = list1.Except(list2);
        UniqueList intersectList = list1.Intersect(list2);

        cout << "Union: "; unionList.display();
        cout << "Except: "; exceptList.display();
        cout << "Intersect: "; intersectList.display();
        break;
    }
    case 4: {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось открыть файл." << endl;
            break;
        }
        
        unordered_set<char> voicedConsonants = {'b', 'v', 'g', 'd', 'z', 'l', 'm', 'n', 'r'};
        map<char, int> consonantCount; 
        string word;
        
        while (file >> word) {
            unordered_set<char> wordSet; 
            for (char ch : word) {
                ch = tolower(ch); 
                if (voicedConsonants.count(ch)) {
                    wordSet.insert(ch); 
                }
            }
            for (char ch : wordSet) {
                consonantCount[ch]++; 
            }
        }
        
        file.close();
        
        cout << "Звонкие согласные, входящие более чем в одно слово:" << endl;
        for (const auto& [ch, count] : consonantCount) {
            if (count > 1) {
                cout << ch << " ";
            }
        }
        cout << endl;
        break;
    }
    case 5: {
        Dictionary dict;
        int n;
        string surname, initials, phone;

        cout << "Введите количество сотрудников: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << "Введите фамилию, инициалы и телефон: ";
            cin >> surname >> initials >> phone;
            dict.add(surname + " " + initials, phone);
        }

        dict.display();
        cout << "Среднее количество сотрудников в подразделении: " << dict.averagePerDepartment() << endl;
        break;
    }

    default:
        cout << "Неверный выбор!" << endl;
        break;
    }

    return 0;
}
