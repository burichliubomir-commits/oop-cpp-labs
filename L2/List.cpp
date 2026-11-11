#include "List.h"
#include <iostream>

List::List()
    : data(new int[4]), size(0), capacity(4) {}

List::~List() {
    delete[] data;
}

void List::resize(const int newCapacity) {
    int *newData = new int[newCapacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void List::pushBack(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size] = value;
    size++;
}

void List::popBack() {
    if (!isEmpty()) {
        size--;
    } else {
        std::cout << "Список порожній." << std::endl;
    }
}

int List::getLast() const {
    if (!isEmpty()) {
        return data[size - 1];
    } else {
        std::cout << "Список порожній." << std::endl;
        return 0;
    }
}

void List::show() const {
    if (!isEmpty()) {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Список порожній." << std::endl;
    }
}

bool List::isEmpty() const {
    return size == 0;
}

int List::getSize() const {
    return size;
}