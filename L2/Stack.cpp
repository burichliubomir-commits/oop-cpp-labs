#include "Stack.h"

void Stack::push(const int value) {
    list.pushBack(value);
}
void Stack::pop() {
    list.popBack();
}

int Stack::top() const {
    return list.getLast();
}

bool Stack::isEmpty() const {
    return list.isEmpty();
}

void Stack::show() const {
    list.show();
}
