#pragma once
#include "Word.h"

class Dictionary {
private:
    Word* words = nullptr;
    size_t count = 0;
    size_t capacity = 0;

    void reallocate(size_t newCapacity);
    void push(const Word& word);

public:
    Dictionary() = default;
    Dictionary(const Word* arr, size_t n);
    Dictionary(const Dictionary& other);
    Dictionary& operator=(const Dictionary& other);
    ~Dictionary();

    size_t size() const { return count; }

    Dictionary operator+(const Word& word) const;
    Dictionary operator-(const char* ukrWord) const;

    void sort(bool byEnglish = false) const;

    Word find(const char* ukrWord) const;

    friend std::ostream& operator<<(std::ostream& os, const Dictionary& dict);
};