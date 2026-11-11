#include "StackIO.h"
#include <iostream>

#include "ConsoleIO.h"

void StackIO::InputElement(Stack& stack) {
    std::cout << "Введіть ціле число для занесення у стек: ";
    const int value = ConsoleIO::GetInt();
    stack.push(value);
    std::cout << "Елемент " << value << " успішно додано у стек.\n";
}

void StackIO::FillStack(Stack& stack) {
    std::cout << "Введіть кількість елементів для додавання: ";
    const int count = ConsoleIO::GetInt();
    for (int i = 0; i < count; ++i) {
        std::cout << "[" << i + 1 << "/" << count << "] ";
        InputElement(stack);
    }
}

void StackIO::ShowTop(const Stack& stack) {
    if (stack.isEmpty()) {
        std::cout << "Стек порожній, немає верхнього елемента.\n";
    } else {
        std::cout << "Верхній елемент стека: " << stack.top() << "\n";
    }
}

void StackIO::Output(const Stack& stack) {
    std::cout << "\n--- Вміст стека ---\n";
    stack.show();
    std::cout << "-------------------\n";
}

void StackIO::ShowMenu(Stack& stack) {
    int choice = 0;
    do {
        std::cout << "\n=== МЕНЮ КЕРУВАННЯ СТЕКОМ ===\n";
        std::cout << "1. Додати елемент (push)\n";
        std::cout << "2. Видалити елемент (pop)\n";
        std::cout << "3. Переглянути верхній елемент (top)\n";
        std::cout << "4. Вивести весь стек\n";
        std::cout << "5. Заповнити декількома елементами\n";
        std::cout << "0. Вихід\n";
        std::cout << "Ваш вибір: ";

        choice = ConsoleIO::GetInt();

        switch (choice) {
            case 1:
                InputElement(stack);
                break;
            case 2:
                if (!stack.isEmpty()) {
                    std::cout << "Видалено елемент зі значенням: " << stack.top() << "\n";
                    stack.pop();
                } else {
                    std::cout << "Стек порожній, нічого видаляти!\n";
                }
                break;
            case 3:
                ShowTop(stack);
                break;
            case 4:
                Output(stack);
                break;
            case 5:
                FillStack(stack);
                break;
            case 0:
                std::cout << "Завершення роботи з меню.\n";
                break;
            default:
                std::cout << "Некоректний вибір! Спробуйте ще раз.\n";
                break;
        }
    } while (choice != 0);
}