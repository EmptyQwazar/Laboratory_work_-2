#include "lab2.h"

void task1() {
    std::cout << std::endl << "--- Задание 1 (Задача 3) ---" << std::endl;

    int numElements = 0;
    while (true) {
        std::cout << "Введите четное количество элементов: ";
        if (std::cin >> numElements && numElements > 0 && numElements % 2 == 0) {
            break;
        }
        std::cout << "Ошибка: введите четное положительное число." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<int> v;
    std::cout << "Введите " << numElements << " чисел: ";
    for (int i = 0; i < numElements; ++i) {
        int val = 0;
        while (!(std::cin >> val)) {
            std::cout << "Ошибка: введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        v.push_back(val);
    }

    std::cout << "Вектор V: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    auto mid = v.begin() + v.size() / 2;

    std::cout << "Вторая половина: ";
    for (auto it = mid; it != v.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl << "Первая половина: ";
    for (auto it = v.begin(); it != mid; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

void task2() {
    std::cout << std::endl << "--- Задание 2 (Задача 3) ---" << std::endl;

    int numElements = 0;
    while (true) {
        std::cout << "Введите количество элементов (кратное 3): ";
        if (std::cin >> numElements && numElements > 0 && numElements % 3 == 0) {
            break;
        }
        std::cout << "Ошибка: число должно делиться на 3." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::list<int> l;
    std::cout << "Введите " << numElements << " чисел: ";
    for (int i = 0; i < numElements; ++i) {
        int val = 0;
        while (!(std::cin >> val)) {
            std::cout << "Ошибка: введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        l.push_back(val);
    }

    std::cout << "Исходный список: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    const int thirdSize = numElements / 3;
    std::vector<int> firstThird;
    auto it = l.begin();
    for (int i = 0; i < thirdSize; ++i) {
        firstThird.push_back(*it);
        ++it;
    }

    l.insert(l.end(), firstThird.rbegin(), firstThird.rend());

    std::cout << "Результат: ";
    for (auto listIt = l.begin(); listIt != l.end(); ++listIt) {
        std::cout << *listIt << ' ';
    }
    std::cout << std::endl;
}

void task3() {
    std::cout << std::endl << "--- Задание 3 (Задача 10) ---" << std::endl;

    int numElements = 0;
    while (true) {
        std::cout << "Введите четное количество элементов: ";
        if (std::cin >> numElements && numElements > 0 && numElements % 2 == 0) {
            break;
        }
        std::cout << "Ошибка: число должно быть четным." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::list<int> l;
    std::cout << "Введите " << numElements << " чисел: ";
    for (int i = 0; i < numElements; ++i) {
        int val = 0;
        while (!(std::cin >> val)) {
            std::cout << "Ошибка: введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        l.push_back(val);
    }

    std::cout << "Исходный список: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    auto i = l.begin();
    auto r = std::prev(l.end());

    for (int k = 0; k < numElements / 2; ++k) {
        auto currentR = r;

        if (k < numElements / 2 - 1) {
            --r;
        }

        l.splice(i++, l, currentR);
    }

    std::cout << "Результат: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

void task4() {
    std::cout << std::endl << "Задание 4 (Задача 5)" << std::endl;

    int numElements = 0;
    while (true) {
        std::cout << "Введите количество символов: ";
        if (std::cin >> numElements && numElements > 0) {
            break;
        }
        std::cout << "Ошибка: введите положительное число." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<char> v;
    std::cout << "Введите " << numElements << " символов: ";
    for (int i = 0; i < numElements; ++i) {
        char c = ' ';
        std::cin >> c;
        v.push_back(c);
    }

    std::cout << "Исходный набор: ";
    for (const char c : v) {
        std::cout << c << ' ';
    }
    std::cout << std::endl << "Результат: ";

    std::replace_copy_if(
        v.begin(), v.end(),
        std::ostream_iterator<char>(std::cout, " "),
        [](char c) { return c >= '0' && c <= '9'; }, '_');
    std::cout << std::endl;
}

void task5() {
    std::cout << std::endl << "Задание 5 (Задача 1)" << std::endl;

    int numElements = 0;
    while (true) {
        std::cout << "Введите количество элементов: ";
        if (std::cin >> numElements && numElements > 0) {
            break;
        }
        std::cout << "Ошибка: введите положительное число." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<int> v;
    std::cout << "Введите " << numElements << " чисел: ";
    for (int i = 0; i < numElements; ++i) {
        int val = 0;
        while (!(std::cin >> val)) {
            std::cout << "Ошибка: введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        v.push_back(val);
    }

    std::cout << "Исходный вектор: ";
    for (const int x : v) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    auto it1 = std::find(v.begin(), v.end(), 0);
    if (it1 != v.end()) {
        auto it2 = std::find(it1 + 1, v.end(), 0);
        if (it2 != v.end()) {
            v.erase(it2);
        }
    }

    std::cout << "Результат: ";
    for (const int x : v) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

void task6() {
    std::cout << std::endl << "Задание 6 (Задача 1)" << std::endl;

    int a = 0;
    int b = 0;
    while (true) {
        std::cout << "Введите число A: ";
        if (std::cin >> a) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    while (true) {
        std::cout << "Введите число B: ";
        if (std::cin >> b) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    int n1 = 0;
    while (true) {
        std::cout << "Введите размер V1 (не менее 10): ";
        if (std::cin >> n1 && n1 >= 10) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    int n2 = 0;
    while (true) {
        std::cout << "Введите размер V2 (не менее 10): ";
        if (std::cin >> n2 && n2 >= 10) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<int> v1(n1, 0);
    std::vector<int> v2(n2, 0);

    std::fill(v1.begin(), v1.begin() + 5, a);
    std::fill(v1.begin() + 5, v1.end(), b);

    std::fill_n(v2.begin(), 5, a);
    std::fill_n(v2.begin() + 5, n2 - 5, b);

    std::cout << "V1: ";
    for (const int x : v1) {
        std::cout << x << ' ';
    }
    std::cout << std::endl << "V2: ";
    for (const int x : v2) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

void task7() {
    std::cout << std::endl << "Задание 7 (Задача 11)" << std::endl;

    int numWords = 0;
    while (true) {
        std::cout << "Введите количество слов: ";
        if (std::cin >> numWords && numWords > 0) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::deque<std::string> d;
    std::cout << "Введите " << numWords << " слов: ";
    for (int i = 0; i < numWords; ++i) {
        std::string s = "";
        std::cin >> s;
        d.push_back(s);
    }

    std::sort(d.begin(), d.end(),
        [](const std::string& left, const std::string& right) {
            if (left.length() != right.length()) {
                return left.length() > right.length();
            }
            return left < right;
        });

    std::cout << "Результат: ";
    for (const auto& s : d) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
}

void task8() {
    std::cout << std::endl << "Задание 8 (Задача 2)" << std::endl;

    int numWords = 0;
    while (true) {
        std::cout << "Введите количество слов: ";
        if (std::cin >> numWords && numWords > 0) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::list<std::string> l;
    std::cout << "Введите " << numWords << " слов (заглавными): ";
    for (int i = 0; i < numWords; ++i) {
        std::string s = "";
        std::cin >> s;
        l.push_back(s);
    }

    std::deque<std::string> d;
    auto combine = [](const std::string& current, const std::string& previous) {
        return std::string(1, previous.front()) + current.back();
        };

    std::adjacent_difference(l.begin(), l.end(),
        std::back_inserter(d), combine);
    d.erase(d.begin());

    std::cout << "Результат (дек D): ";
    for (const auto& s : d) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
}

void task9() {
    std::cout << std::endl << "--- Задание 9 (Задача 1) ---" << std::endl;

    int n0 = 0;
    while (true) {
        std::cout << "Сколько элементов в V0? ";
        if (std::cin >> n0 && n0 > 0) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<int> v0;
    for (int i = 0; i < n0; ++i) {
        int val = 0;
        while (true) {
            std::cout << "Элемент V0: ";
            if (std::cin >> val) break;
            std::cout << "Ошибка." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        v0.push_back(val);
    }

    int numVecs = 0;
    while (true) {
        std::cout << "Сколько векторов проверять (N)? ";
        if (std::cin >> numVecs && numVecs > 0) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<std::vector<int>> vecs(numVecs);

    for (int i = 0; i < numVecs; ++i) {
        int size = 0;
        while (true) {
            std::cout << "Размер вектора V" << i + 1 << ": ";
            if (std::cin >> size && size > 0) break;
            std::cout << "Ошибка." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        for (int j = 0; j < size; ++j) {
            int val = 0;
            while (true) {
                std::cout << "Элемент: ";
                if (std::cin >> val) break;
                std::cout << "Ошибка." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            vecs[i].push_back(val);
        }
    }

    const std::set<int> set0(v0.begin(), v0.end());
    int count = 0;

    for (const auto& v : vecs) {
        const std::set<int> setV(v.begin(), v.end());
        if (std::includes(setV.begin(), setV.end(),
            set0.begin(), set0.end())) {
            ++count;
        }
    }
    std::cout << "Количество подходящих векторов: " << count << std::endl;
}

void task10() {
    std::cout << std::endl << "--- Задание 10 (Задача 1) ---" << std::endl;

    int numElements = 0;
    while (true) {
        std::cout << "Введите количество элементов: ";
        if (std::cin >> numElements && numElements > 0) break;
        std::cout << "Ошибка." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<int> v;
    for (int i = 0; i < numElements; ++i) {
        int val = 0;
        while (true) {
            std::cout << "Введите число: ";
            if (std::cin >> val) break;
            std::cout << "Ошибка." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        v.push_back(val);
    }

    std::map<int, int> m;
    for (auto it = v.begin(); it != v.end(); ++it) {
        m[*it]++;
    }

    std::cout << "Элемент : Количество" << std::endl;
    for (auto it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}