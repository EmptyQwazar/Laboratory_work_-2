#include <clocale>
#include <iostream>
#include <string>
#include "lab2.h"

int main() {
    std::setlocale(LC_ALL, "Russian");

    int choice = -1;
    while (choice != 0) {
        std::cout << std::endl << "=== МЕНЮ ===" << std::endl
            << "1. Задание 1" << std::endl
            << "2. Задание 2" << std::endl
            << "3. Задание 3" << std::endl
            << "4. Задание 4" << std::endl
            << "5. Задание 5" << std::endl
            << "6. Задание 6" << std::endl
            << "7. Задание 7" << std::endl
            << "8. Задание 8" << std::endl
            << "9. Задание 9" << std::endl
            << "10. Задание 10" << std::endl
            << "0. Выход" << std::endl;

        std::cout << "Выбор: ";
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода. Введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 8: task8(); break;
        case 9: task9(); break;
        case 10: task10(); break;
        case 0: std::cout << "Выход." << std::endl; break;
        default: std::cout << "Неверный пункт." << std::endl; break;
        }
    }

    return 0;
}