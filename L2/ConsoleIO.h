#pragma once
#include <iostream>

class ConsoleIO {
public:
    static int GetInt() {
        int value;
        while (true) {
            if (std::cin >> value) {
                return value;
            } else {
                std::cout <<  "Некоректний ввід! Введіть ціле число: ";
                std::cin.clear();
                while (std::cin.get() != '\n') {};
            }
        }
    }
};