#pragma once
#include "List.h"

class Stack {
private:
    List list;
public:
    Stack() = default;
    ~Stack() = default;

    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    void show() const;
};
