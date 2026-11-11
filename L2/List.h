#pragma once
class List {
private:
    int* data{};
    int size{};
    int capacity{};
    void resize(int newCapacity);
public:
    List();
    ~List();
    void pushBack(int value);
    void popBack();
    int getLast() const;
    bool isEmpty() const;
    int getSize() const;
    void show() const;
};