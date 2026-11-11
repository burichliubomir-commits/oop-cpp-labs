#include <cstring>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "Word.h"
#include "Dictionary.h"

static void printMenu() {
    std::cout << "\n================ МЕНЮ СЛОВНИКА ================\n";
    std::cout << "1. Вивести весь словник\n";
    std::cout << "2. Відсортувати словник за абеткою\n";
    std::cout << "3. Додати нове слово\n";
    std::cout << "4. Видалити слово\n";
    std::cout << "5. Знайти слово\n";
    std::cout << "6. Порівняти два слова за абеткою (оператори < та >=)\n";
    std::cout << "0. Вийти з програми\n";
    std::cout << "Виберіть опцію (0-6): ";
}

int main() {
    const Word initialList[] = {
        Word("Яблуко", "Apple", "Соковитий фрукт"),
        Word("Книга", "Book", "Джерело знань"),
        Word("Сонце", "Sun", "Центральна зоря"),
        Word("Вода", "Water"),
        Word("Дерево", "Tree", "Багаторічна рослина"),
        Word("Будинок", "House"),
        Word("Машина", "Car", "Транспортний засіб"),
        Word("Кіт", "Cat", "Домашній улюбленець"),
        Word("Собака", "Dog"),
        Word("Місто", "City", "Великий населений пункт")
    };

    const size_t initialCount = sizeof(initialList) / sizeof(initialList[0]);
    Dictionary dict(initialList, initialCount);
    int choice = -1;

    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Некоректне введення! Введіть число від 0 до 6.\n";
            continue;
        }

        if (choice == 0) {
            std::cout << "Завершення роботи програми.\n";
            break;
        }

        switch (choice) {
            case 1: {
                std::cout << "\n" << dict << "\n";
                break;
            }
            case 2: {
                int mode = 0;
                std::cout << "Сортувати за: 1 - українським словом, 2 - англійським: ";
                std::cin >> mode;
                if (mode == 2) {
                    dict.sort(SortBy::English);
                } else {
                    dict.sort();
                }
                std::cout << "\nСловник успішно відсортовано за абеткою!\n";
                std::cout << dict << "\n";
                break;
            }
            case 3: {
                char ukr[256];
                char eng[256];
                char details[1024];

                std::cout << "Введіть українське слово: ";
                std::cin >> std::setw(sizeof(ukr)) >> ukr;
                std::cout << "Введіть англійський переклад: ";
                std::cin >> std::setw(sizeof(eng)) >> eng;

                std::cout << "Введіть опис (Enter, щоб пропустити): ";
                std::cin.ignore(10000, '\n');
                std::cin.getline(details, sizeof(details));

                if (std::strlen(details) == 0) {
                    dict = dict + Word(ukr, eng);
                } else {
                    dict = dict + Word(ukr, eng, details);
                }

                std::cout << "Слово '" << ukr << "' успішно додано до словника!\n";
                break;
            }
            case 4: {
                char ukr[256];
                std::cout << "Введіть українське слово для видалення: ";
                std::cin >> std::setw(sizeof(ukr)) >> ukr;
                try {
                    dict = dict - ukr;
                    std::cout << "Видалення слова '" << ukr << "' виконано.\n";
                } catch (const std::exception& e) {
                    std::cout << "Помилка: " << e.what() << "\n";
                }
                break;
            }
            case 5: {
                char ukr[256];
                std::cout << "Введіть українське слово для пошуку: ";
                std::cin >> std::setw(sizeof(ukr)) >> ukr;

                try {
                    Word found = dict.find(ukr);
                    std::cout << "\n[ЗНАЙДЕНО]: " << found << "\n";

                    try {
                        std::cout << "Опис: " << found.getDetails() << "\n";
                    }
                    catch (const std::exception& e) {
                        std::cout << "Увага: " << e.what() << "\n";
                    }
                }
                catch (const std::exception& e) {
                    std::cout << "\nПомилка: " << e.what() << "\n";
                }
                break;
            }
            case 6: {
                char ukr1[256];
                char ukr2[256];
                std::cout << "Введіть перше українське слово: ";
                std::cin >> std::setw(sizeof(ukr1)) >> ukr1;
                std::cout << "Введіть друге українське слово: ";
                std::cin >> std::setw(sizeof(ukr2)) >> ukr2;

                Word word1(ukr1, "Temp1");
                Word word2(ukr2, "Temp2");

                std::cout << "\n--- РЕЗУЛЬТАТ ПОРІВНЯННЯ ---\n";

                if (word1 < word2) {
                    std::cout << "[operator< ]: '" << ukr1 << "' йде раніше за абеткою ніж '" << ukr2 << "'\n";
                } else {
                    std::cout << "[operator< ]: '" << ukr1 << "' не йде раніше за абеткою ніж '" << ukr2 << "'\n";
                }

                if (word1 >= word2) {
                    std::cout << "[operator>=]: '" << ukr1 << "' йде пізніше (або так само) за абеткою ніж '" << ukr2 << "'\n";
                } else {
                    std::cout << "[operator>=]: '" << ukr1 << "' не йде пізніше ніж '" << ukr2 << "'\n";
                }
                break;
            }
            default:
                std::cout << "Невірний вибір. Оберіть пункт від 0 до 6.\n";
                break;
        }
    }
    return 0;
}